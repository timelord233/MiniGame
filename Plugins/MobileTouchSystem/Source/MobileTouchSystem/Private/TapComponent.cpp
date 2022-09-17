/* Copyright (C) 2022 IQRA IQBAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/
#include "TapComponent.h"
#include "TimerManager.h"
#include "GameFramework/Actor.h"
#include "TouchScreenHud.h"


void UTapComponent::OnTouchBegin(FVector2D TouchLocation, int32 TouchCount)
{
	Super::OnTouchBegin(TouchLocation, TouchCount);
	AActor* MyOwner = GetOwner();
	if (MyOwner == nullptr)
	{
		return;
	}
	
	if (bIsTouched)
	{
		FTimerManager& TimerManager = MyOwner->GetWorldTimerManager();
		TimerManager.ClearTimer(TimerHandle);
		++Taps;
		CallOnEachTap.Broadcast(Taps);
		if (Taps>= MaxTaps)
		{
			CallOnLastTap.Broadcast();
			ResetTaps();
			return;
		}
		TimerManager.SetTimer(TimerHandle,this,&UTapComponent::ResetTaps,
			TimeBetweenEachTap);
	}
}

void UTapComponent::OnTouchMoved(FVector2D TouchLocation, int32 TouchCount)
{
	Super::OnTouchMoved(TouchLocation, TouchCount);
}

void UTapComponent::OnTouchReleased(FVector2D TouchLocation, int32 TouchCount)
{
	Super::OnTouchReleased(TouchLocation, TouchCount);
}

void UTapComponent::BeginPlay()
{
	Super::BeginPlay();
	if (bShouldDrawDebug)
	{
		if (MyHud)
		{
			MyHud->AddCompToDebugList(this);
		}
	}
}

void UTapComponent::ResetTaps()
{
	Taps = 0;
	AActor* MyOwner = GetOwner();
	if (MyOwner == nullptr)
	{
		return;
	}
	MyOwner->GetWorldTimerManager().ClearTimer(TimerHandle);
}
