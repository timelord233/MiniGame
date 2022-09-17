/* Copyright (C) 2022 IQRA IQBAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/
#pragma once

#include "CoreMinimal.h"
#include "BaseTouchComp.h"
#include "TapComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCallOnEachTap,int32,Count);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCallOnLastTap);


UCLASS(ClassGroup=(MobileTouch),meta=(BlueprintSpawnableComponent))
class MOBILETOUCHSYSTEM_API UTapComponent : public UBaseTouchComp
{
	GENERATED_BODY()
private:
	int32 Taps;
	
protected:
	virtual void OnTouchBegin(FVector2D TouchLocation, int32 TouchCount) override;
	virtual void OnTouchMoved(FVector2D TouchLocation, int32 TouchCount) override;
	virtual void OnTouchReleased(FVector2D TouchLocation, int32 TouchCount) override;

	virtual void BeginPlay() override;
	UPROPERTY(BlueprintAssignable,Category="TapComponent")
	FCallOnEachTap CallOnEachTap;
	UPROPERTY(BlueprintAssignable,Category="TapComponent")
	FCallOnLastTap CallOnLastTap;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="TapComponent",meta=(ToolTip="When this time exceeds the tap count will be reset"))
	float TimeBetweenEachTap;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="TapComponent",meta=(ToolTip="Max Taps for the tap component"))
	int32 MaxTaps{3};
	
	FTimerHandle TimerHandle;

	// Resets the taps back to zero 
	UFUNCTION(BlueprintCallable,Category="TapComponent")
	void ResetTaps();

	
	
};
