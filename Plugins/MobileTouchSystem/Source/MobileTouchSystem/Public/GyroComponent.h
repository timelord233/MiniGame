/* Copyright (C) 2022 IQRA IQBAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GyroComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnGyroTick,float ,Yaw,float,Pitch,float,Roll);
UCLASS(ClassGroup=(MobileTouch), meta=(BlueprintSpawnableComponent))
class MOBILETOUCHSYSTEM_API UGyroComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UGyroComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable,Category="Gyroscope")
	FOnGyroTick OnGyroTick;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Gyroscope")
	bool bShouldInvertYaw;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Gyroscope")
	bool bShouldInvertRoll;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Gyroscope")
	bool bShouldInvertPitch;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Gyroscope")
	bool bSmoothInterp;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Gyroscope",meta=(EditCondition="bSmoothInterp"))
	float InterpRate;
public:
	virtual void OnRegister() override;
	virtual void OnUnregister() override;

	
private:
	FVector CurrentRR;
	void OnGyro(FVector RotationRate);
};

