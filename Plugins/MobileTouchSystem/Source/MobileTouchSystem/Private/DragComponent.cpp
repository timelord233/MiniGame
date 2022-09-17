/* Copyright (C) 2022 IQRA IQBAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/

#include "DragComponent.h"


UDragComponent::UDragComponent()
{
	SmoothnessMultiplier = 45.f;
}

void UDragComponent::OnTouchBegin(FVector2D TouchLocation, int32 TouchCount)
{
	Super::OnTouchBegin(TouchLocation, TouchCount);
	
}

void UDragComponent::OnTouchMoved(FVector2D TouchLocation, int32 TouchCount)
{
	Super::OnTouchMoved(TouchLocation, TouchCount);
	if (!bIsTouched || TouchCount!= MyCurrentTouchIndex)
	{
		return;
	}
	CurrentTouchLocation = TouchLocation;
	FVector2D Diff = CurrentTouchLocation - TouchStartLocation;
	Diff.X *= (bShouldInvertX)?-1.f:1.f;
	Diff.Y *= (bShouldInvertY)?-1.f:1.f;
	Diff *= DeltaSeconds * SmoothnessMultiplier;
	OnXYValueChanged.Broadcast(Diff.X,Diff.Y);
	TouchStartLocation = CurrentTouchLocation;
}

void UDragComponent::OnTouchReleased(FVector2D TouchLocation, int32 TouchCount)
{
	Super::OnTouchReleased(TouchLocation, TouchCount);
}
