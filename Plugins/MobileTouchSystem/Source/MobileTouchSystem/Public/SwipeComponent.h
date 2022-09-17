/* Copyright (C) 2022 IQRA IQBAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/
#pragma once

#include "CoreMinimal.h"
#include "BaseTouchComp.h"
#include "SwipeComponent.generated.h"

UENUM(BlueprintType)
enum class ESwipeDirection:uint8
{
	Esd_UP UMETA(DisplayName="Up"),
	Esd_Rightup UMETA(DisplayName="RightUp"),
	Esd_Right UMETA(DisplayName="Right"),
	Esd_Rightdown UMETA(DisplayName="RightDown"),
	Esd_Down UMETA(DisplayName="Down"),
	Esd_Downleft UMETA(DisplayName="DownLeft"),
	Esd_Left UMETA(DisplayName="Left"),
	Esd_Leftup UMETA(DisplayName="LeftUp")
};

UENUM(BlueprintType)
enum class ESwipeFailureReason:uint8
{
	Esf_TimedOut UMETA(DisplayName="TimedOut"),
	Esf_AngleLimitExceeds UMETA(DisplayName="AngleLimitExceeded"),
	Esf_TouchReleased UMETA(DisplayName="TouchReleased")
	
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnSwipeSuccess,float,Angle,float, TimeTaken,ESwipeDirection,SwipeDirection);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSwipeFailed,ESwipeFailureReason,FailureReason);
UCLASS(ClassGroup=(MobileTouch),meta=(BlueprintSpawnableComponent))
class MOBILETOUCHSYSTEM_API USwipeComponent : public UBaseTouchComp
{
	GENERATED_BODY()
private:
	ESwipeDirection GetDirectionBasedOnAngle(float InAngle)const;

	void OnTimedOut();
	FTimerHandle TimerHandle;
	// If the end was called becuse of touch released
	bool bWasATouchReleased= true;
	float AngleBeforeEnd{0.f};
protected:
	virtual void BeginPlay() override;
	virtual void OnMoved() override;
	virtual void OnStart() override;
	virtual void OnEnd() override;
	bool CheckAngleInRange(float Tolerance, float InCurrentAngle, float TargetAngle) const;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="SwipeComponent",meta=(ClampMin="0",ClampMax="1"))
	float SwipeRadius{.3f};
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="SwipeComponent",meta=(ClampMin="0",ClampMax="360"))
	float SwipeTargetAngle{0.f};
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="SwipeComponent",meta=(ClampMin="0",ClampMax="180"))
	float SwipeToleranceAngle{180.f};
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="SwipeComponent")
	float TimeForSwipe{1.4f};
	
	UPROPERTY(BlueprintAssignable,Category="SwipeComponent")
	FOnSwipeSuccess OnSwipeSuccess;
	UPROPERTY(BlueprintAssignable,Category="SwipeComponent")
	FOnSwipeFailed OnSwipeFailed;
public:
	FORCEINLINE float GetSwipeTargetAngle()const{return SwipeTargetAngle;}
	FORCEINLINE float GetSwipeTolerance()const{return SwipeToleranceAngle;}
	// Returns Swipe Target radius in range 0-1  
	FORCEINLINE float GetSwipeRadius()const{return SwipeRadius;}
};
