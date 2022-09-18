// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "nertc_engine_ex.h"
#include "MGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class DEMO_API UMGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UMGameInstance(const FObjectInitializer& ObjectInitializer);

	virtual void OnStart() override;

	virtual void Shutdown() override;

	UFUNCTION(BlueprintCallable, Category = "NERTCSDK")
	void InitNERTCSDK();

private:
	nertc::IRtcEngineEx* rtc_engine_;
};
