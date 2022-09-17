// Fill out your copyright notice in the Description page of Project Settings.


#include "MGameMode.h"
#include "MPlayerController.h"
#include "Components/MHealthComponent.h"
#include "MGameState.h"
#include "MPlayerState.h"

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
	if (TeamMemberNum[0] > TeamMemberNum[1])
	{
		PS->TeamNum = 1;
		TeamMemberNum[1]++;
	}
	else
	{
		PS->TeamNum = 0;
		TeamMemberNum[0]++;
	}
	Super::PostLogin(NewPlayer);
}

void AMGameMode::StartPlay()
{
	Super::StartPlay();
	memset(TeamMemberNum, 0, sizeof(TeamMemberNum));
	memset(TeamScore, 0, sizeof(TeamScore));
}

void AMGameMode::RestartPlayer(AController* NewPlayer)
{
	if (NewPlayer == nullptr || NewPlayer->IsPendingKillPending())
	{
		return;
	}
	AActor* StartSpot;
	AMPlayerState* PS = NewPlayer->GetPlayerState<AMPlayerState>();
	if (PS)
	{
		StartSpot = FindPlayerStart(NewPlayer, FString::FromInt(PS->TeamNum));
	}
	else
	{
		StartSpot = FindPlayerStart(NewPlayer);
	}

	// If a start spot wasn't found,
	if (StartSpot == nullptr)
	{
		// Check for a previously assigned spot
		if (NewPlayer->StartSpot != nullptr)
		{
			StartSpot = NewPlayer->StartSpot.Get();
			UE_LOG(LogGameMode, Warning, TEXT("RestartPlayer: Player start not found, using last start spot"));
		}
	}

	RestartPlayerAtPlayerStart(NewPlayer, StartSpot);
}
