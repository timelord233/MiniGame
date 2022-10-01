// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MGameMode.generated.h"

class AMWaveConfig;
struct FAIToSpawn;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnActorKilled, AActor*, VictimActor, AActor*, KillerActor, AController*, KillerController);
/**
 * 
 */
UCLASS()
class DEMO_API AMGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	FTimerHandle TimerHandle_BotSpawner;

	FTimerHandle TimerHandle_NextWaveStart;

	AMWaveConfig* WaveConfig;

	int32 WaveNum;

	int32 SpawnTimes;

	void SpawnMonster(FAIToSpawn AIToSpawn);

	void StartWave();

	void EndWave();

	void PrepareForNextWave();

public:
	AMGameMode();

	virtual void PostLogin(APlayerController* NewPlayer) override;

	virtual void StartPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "GameMode") 
	FOnActorKilled OnActorKilled;
};
