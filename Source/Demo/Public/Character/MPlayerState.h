// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "MPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class DEMO_API AMPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	UPROPERTY(ReplicatedUsing = OnRep_TeamNum, BlueprintReadWrite, Category = PlayerState)
	uint8 TeamNum;

	UFUNCTION(BlueprintCallable, Category = "PlayerState")
	void AddScore(float ScoreDelta);

	UFUNCTION()
	void OnRep_TeamNum();

};
