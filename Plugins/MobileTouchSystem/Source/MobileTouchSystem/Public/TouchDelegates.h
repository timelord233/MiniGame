/* Copyright (C) 2022 IQRA IQBAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/
#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TouchDelegates.generated.h"


UCLASS(NotBlueprintable)
class MOBILETOUCHSYSTEM_API UTouchDelegates : public UObject
{
	GENERATED_BODY()

public:
	DECLARE_MULTICAST_DELEGATE_TwoParams(FTouchDelegate,FVector2D,int32);
	DECLARE_MULTICAST_DELEGATE_OneParam(FRotationRateDelegate,FVector)

	static FTouchDelegate TouchBegan;
	static FTouchDelegate TouchMoved;
	static FTouchDelegate TouchEnded;
	static FRotationRateDelegate RotationRate;
};
