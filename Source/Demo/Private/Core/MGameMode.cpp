// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/MGameMode.h"
#include "Character/MPlayerController.h"
#include "Components/MHealthComponent.h"
#include "Core/MGameState.h"
#include "Character/MPlayerState.h"
#include "TimerManager.h"
#include "Item/MonsterStart.h"
#include "AI/MWaveConfig.h"
#include "EngineUtils.h"


void AMGameMode::SpawnMonster(FAIToSpawn AIToSpawn)
{
	if (AIToSpawn.NormalMonsterClass && AIToSpawn.SpawnLocation)
	{
		int32 SpawnNum = AIToSpawn.SpawnNum[SpawnTimes];
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
		for (int i = 0; i < SpawnNum; i++)
		{
			GetWorld()->SpawnActor<AActor>(AIToSpawn.NormalMonsterClass, AIToSpawn.SpawnLocation->GetActorLocation(), FRotator(0), SpawnParams);
		}
	}
	SpawnTimes++;
	if (SpawnTimes == AIToSpawn.SpawnNum.Num()) 
	{
		EndWave();
	}
}

void AMGameMode::StartWave()
{
	FAIToSpawn AIToSpawn = WaveConfig->AIToSpawnArray[WaveNum];
	FTimerDelegate SpawnDelegate = FTimerDelegate::CreateUObject(this, &AMGameMode::SpawnMonster, AIToSpawn);
	SpawnTimes = 0;
	GetWorldTimerManager().SetTimer(TimerHandle_BotSpawner, SpawnDelegate, AIToSpawn.SpawnDuration, true, 0.0f);
}

void AMGameMode::EndWave()
{
	GetWorldTimerManager().ClearTimer(TimerHandle_BotSpawner);

	WaveNum++;
	if (WaveNum < WaveConfig->AIToSpawnArray.Num())
	{
		PrepareForNextWave();
	}
}

void AMGameMode::PrepareForNextWave()
{
	GetWorldTimerManager().SetTimer(TimerHandle_NextWaveStart, this, &AMGameMode::StartWave, WaveConfig->TimeBetweenWaves, false);
}

AMGameMode::AMGameMode()
{
	GameStateClass = AMGameState::StaticClass();
	PlayerStateClass = AMPlayerState::StaticClass();
}

void AMGameMode::PostLogin(APlayerController* NewPlayer)
{
	AMPlayerController* PC = Cast<AMPlayerController>(NewPlayer);
	AMPlayerState* PS = PC->GetPlayerState<AMPlayerState>();
	if (PS == nullptr)
	{
		return;
	}
	PS->TeamNum = 0;
	Super::PostLogin(NewPlayer);
}

void AMGameMode::StartPlay()
{
	Super::StartPlay();

	UWorld* World = GetWorld();
	for (TActorIterator<AMWaveConfig> It(World); It; ++It)
	{
		AMWaveConfig* config = (AMWaveConfig*)(*It);
		if (config)
		{
			WaveConfig = config;
		}
	}

	WaveNum = 0;
	PrepareForNextWave();
}
