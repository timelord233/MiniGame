// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MGameMode.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnActorKilled, AActor*, VictimActor, AActor*, KillerActor, AController*, KillerController);
/**
 * 
 */
UCLASS()
class DEMO_API AMGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	int32 TeamScore[2];
	int32 TeamMemberNum[2];

public:
	AMGameMode();

	virtual void PostLogin(APlayerController* NewPlayer) override;

	virtual void StartPlay() override;

	virtual void RestartPlayer(AController* NewPlayer) override;

	UPROPERTY(BlueprintAssignable, Category = "GameMode") 
	FOnActorKilled OnActorKilled;
};
