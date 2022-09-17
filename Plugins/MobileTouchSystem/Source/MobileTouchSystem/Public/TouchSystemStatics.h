/* Copyright (C) 2022 IQRA IQBAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/
#pragma once

#include "CoreMinimal.h"
#include "TouchSystemStatics.generated.h"



class UBaseTouchComp;
UCLASS()
class MOBILETOUCHSYSTEM_API UTouchSystemStatics : public UObject
{
	GENERATED_BODY()
public:
	/**
	 * Toggle The Debugs on all the Touch Components
	 * @param Owner is the owner of the components
	 * @param bTurnOn Whether to turn on or off the debugs
	 */
	UFUNCTION(BlueprintCallable,Category="TouchStatics")
	static void ToggleDebugOnAllTouchComps(AActor* Owner,bool bTurnOn);
	/**
	 * Toggle Can be touch bool on all the Touch Components
	 * @param Owner the owner of the components
	 * @param bTurnOn Whether to can be touched or not
	 */
	UFUNCTION(BlueprintCallable,Category="TouchStatics")
	static void ToggleCanbeTouched(AActor* Owner,bool bTurnOn);
	
};
