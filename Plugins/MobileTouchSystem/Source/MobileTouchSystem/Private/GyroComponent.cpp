/* Copyright (C) 2022 IQRA IQBAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/

#include "GyroComponent.h"
#include "TouchDelegates.h"


// Sets default values for this component's properties
UGyroComponent::UGyroComponent()
{
	bShouldInvertYaw = false;
	bSmoothInterp = true;
	bShouldInvertPitch = false;
	bShouldInvertRoll = false;
	InterpRate = 2.3f;
	CurrentRR = FVector(0.f);
	PrimaryComponentTick.bCanEverTick = false;

}


void UGyroComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UGyroComponent::OnRegister()
{
	Super::OnRegister();
	UTouchDelegates::RotationRate.AddUObject(this,&UGyroComponent::OnGyro);
}
void UGyroComponent::OnUnregister()
{
	Super::OnUnregister();
	UTouchDelegates::RotationRate.RemoveAll(this);
}




void UGyroComponent::OnGyro(FVector RotationRate)
{
	if (bSmoothInterp)
	{
		float DeltaTime = GetWorld()->GetDeltaSeconds();
		CurrentRR = FMath::Lerp(RotationRate,CurrentRR,DeltaTime*InterpRate);
	}
	else
	{
		CurrentRR = RotationRate;
	}
	
	FVector DispatchRate = CurrentRR;
	DispatchRate.Z *= (bShouldInvertRoll)?-1.f:1.f;
	DispatchRate.Y *= (bShouldInvertPitch)?-1.f:1.f;
	DispatchRate.X *= (bShouldInvertYaw)?-1.f:1.f;
	OnGyroTick.Broadcast(DispatchRate.X,DispatchRate.Y,DispatchRate.Z);
}
