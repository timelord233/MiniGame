// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MWaveConfig.generated.h"

class AMonsterStart;

USTRUCT(BlueprintType)
struct FAIToSpawn
{
	GENERATED_BODY()

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "WaveConfig")
	AMonsterStart* SpawnLocation;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "WaveConfig")
	int32 SpawnDuration = 12;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "WaveConfig")
	TSubclassOf<AActor> NormalMonsterClass;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "WaveConfig")
	TArray<int32> SpawnNum;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "WaveConfig")
	TSubclassOf<AActor> EliteMonsterClass;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "WaveConfig" ,meta = (ClampMax = 1,ClampMin = 0))
	float EliteMonsterNumPercent;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "WaveConfig")
	TSubclassOf<AActor> BossClass;
};

UCLASS()
class DEMO_API AMWaveConfig : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WaveConfig")
	TArray<FAIToSpawn> AIToSpawnArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WaveConfig")
	int32 TimeBetweenWaves = 10;
};
