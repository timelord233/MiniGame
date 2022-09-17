/* Copyright (C) 2022 IQRA IQBAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/

#include "TouchGameViewportClient.h"

#include "TouchDelegates.h"
#include "Engine/UserInterfaceSettings.h"



bool UTouchGameViewportClient::InputTouch(FViewport* InViewport, int32 ControllerId, uint32 Handle, ETouchType::Type Type,
                                          const FVector2D& TouchLocation, float Force, FDateTime DeviceTimestamp, uint32 TouchpadIndex)
{
	switch (Type) {
	case ETouchType::Began:
		UTouchDelegates::TouchBegan.Broadcast(TouchLocation,Handle);
		break;
	case ETouchType::Moved:
		UTouchDelegates::TouchMoved.Broadcast(TouchLocation,Handle);
		break;
	case ETouchType::Stationary: break;
	case ETouchType::ForceChanged: break;
	case ETouchType::FirstMove: break;
	case ETouchType::Ended:
		UTouchDelegates::TouchEnded.Broadcast(TouchLocation,Handle);
		break;
	case ETouchType::NumTypes: break;
	default: ;
	}


	return Super::InputTouch(InViewport, ControllerId, Handle, Type, TouchLocation, Force, DeviceTimestamp,
	                         TouchpadIndex);

	
}

bool UTouchGameViewportClient::InputMotion(FViewport* InViewport, int32 ControllerId, const FVector& Tilt,
	const FVector& RotationRate, const FVector& Gravity, const FVector& Acceleration)
{
	
	UTouchDelegates::RotationRate.Broadcast(RotationRate);
	return Super::InputMotion(InViewport, ControllerId, Tilt, RotationRate, Gravity, Acceleration);
}
