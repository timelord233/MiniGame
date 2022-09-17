// Fill out your copyright notice in the Description page of Project Settings.


#include "MPlayerState.h"
#include "Net/UnrealNetwork.h"
#include "Components/MHealthComponent.h"

void AMPlayerState::AddScore(float ScoreDelta)
{
	SetScore(GetScore() + ScoreDelta);
}

void AMPlayerState::OnRep_TeamNum()
{

}

void AMPlayerState::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	FDoRepLifetimeParams SharedParams;
	SharedParams.bIsPushBased = true;

	DOREPLIFETIME_WITH_PARAMS_FAST(AMPlayerState, TeamNum, SharedParams);
}
