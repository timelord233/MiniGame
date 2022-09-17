/* Copyright (C) 2022 IQRA IQBAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/
#pragma once

#include "CoreMinimal.h"
#include "BaseTouchComp.h"
#include "PinchComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FOnPinchStart,FVector2D,Finger1Location,FVector2D,Finger2Location,float,StartAngle,float,DeltaAngle,float,ZoomLevel);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnPinchMoved,float,ZoomLevel,float,DeltaAngle,FVector2D,Finger1Location,FVector2D,Finger2Location);
UCLASS(ClassGroup=(MobileTouch),meta=(BlueprintSpawnableComponent))
class MOBILETOUCHSYSTEM_API UPinchComponent : public UBaseTouchComp
{
	GENERATED_BODY()
public:
	UPinchComponent();

	UPROPERTY(BlueprintAssignable,Category="PinchComponent",meta=(ToolTip="Angle is the start angle and Angle delta is the delta between current and start angle"))
	FOnPinchStart OnPinchStart;
	UPROPERTY(BlueprintAssignable,Category="PinchComponent")
	FOnPinchMoved OnPinchMoved;
	UPROPERTY(BlueprintAssignable,Category="PinchComponent",meta=(ToolTip="Angle is the start angle and Angle delta is the delta between current and start angle"))
	FOnPinchStart OnPinchEnd;

	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly,Category="PinchComponent",meta=(ToolTip="If Testing on Pc, Can't have two touches at same time , this bool will help us to test on pc"))
	bool bPCDebug1FingerTouch;
	
private:
	// Location of finger1 start touch
	FVector2D TouchStartFinger1;
	// Location of finger2 start touch
	FVector2D TouchStartFinger2;
	// Location of finger1 current touch
	FVector2D TouchCurrentFinger1;
	// Location of finger2 current touch
	FVector2D TouchCurrentFinger2;
	// Bool Is one finger touched
	bool bFinger1Touched;
	// Bool is second finger touched
	bool bFinger2Touched;
	// Index of first touch
	int32 Finger1;
	// Index of second finger touch
	int32 Finger2;
	
	float StartAngle;
	float StartDistance;
	float CurrentDistance;
	float DeltaAngle;

	FTimerHandle TimerHandle;
	void SetFinger1Debug();
protected:
	virtual void BeginPlay() override;
	virtual void OnTouchBegin(FVector2D TouchLocation, int32 TouchCount) override;
	virtual void OnTouchMoved(FVector2D TouchLocation, int32 TouchCount) override;
	virtual void OnTouchReleased(FVector2D TouchLocation, int32 TouchCount) override;
	virtual void OnMoved() override;
	virtual void OnEnd() override;
	virtual void OnStart() override;
};


