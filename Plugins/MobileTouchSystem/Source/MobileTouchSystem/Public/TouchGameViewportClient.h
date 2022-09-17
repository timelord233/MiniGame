/* Copyright (C) 2022 IQRA IQBAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/
#pragma once

#include "CoreMinimal.h"
#include "Engine/GameViewportClient.h"
#include "TouchGameViewportClient.generated.h"

/**
 * 
 */
UCLASS()
class MOBILETOUCHSYSTEM_API UTouchGameViewportClient : public UGameViewportClient
{
	GENERATED_BODY()
public:
	

	virtual bool InputTouch(FViewport* InViewport, int32 ControllerId, uint32 Handle, ETouchType::Type Type, const FVector2D& TouchLocation, float Force, FDateTime DeviceTimestamp, uint32 TouchpadIndex) override;
	virtual bool InputMotion(FViewport* InViewport, int32 ControllerId, const FVector& Tilt, const FVector& RotationRate, const FVector& Gravity, const FVector& Acceleration) override;
};
