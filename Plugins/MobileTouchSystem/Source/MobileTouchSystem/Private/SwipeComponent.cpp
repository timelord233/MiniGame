/* Copyright (C) 2022 IQRA IQBAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/
#include "SwipeComponent.h"
#include "TimerManager.h"
#include "GameFramework/Actor.h"
#include "TouchScreenHud.h"
#include "Kismet/KismetMathLibrary.h"



ESwipeDirection USwipeComponent::GetDirectionBasedOnAngle(float InAngle) const
{
	int32 SingleDiv= UKismetMathLibrary::FFloor(InAngle/(360.f/8.f));
	
	return static_cast<ESwipeDirection>(SingleDiv);
}

void USwipeComponent::OnTimedOut()
{
	bWasATouchReleased = false;
	GetOwner()->GetWorldTimerManager().ClearTimer(TimerHandle);
	//GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
	ForceEndTouch();
}

void USwipeComponent::BeginPlay()
{
	Super::BeginPlay();
	if (MyHud && bShouldDrawDebug)
	{
		MyHud->AddDebugSwipe(this);
	}
}

void USwipeComponent::OnStart()
{
	Super::OnStart();
	AActor* MyOwner = GetOwner();
	if (MyOwner == nullptr)
	{
		return;
	}
	FTimerManager& TimerManager = MyOwner->GetWorldTimerManager();
	if (TimerManager.IsTimerActive(TimerHandle))
	{
		TimerManager.ClearTimer(TimerHandle);
	}
	
	TimerManager.SetTimer(TimerHandle,
		this,
		&USwipeComponent::OnTimedOut,TimeForSwipe,false);
}
void USwipeComponent::OnMoved()
{
	Super::OnMoved();
	CurrentAngle = CalculateAngle(90.f);
	AngleBeforeEnd = CurrentAngle;
	float Dist = FVector2D::Distance(TouchStartLocation,CurrentTouchLocation);
	const FVector2D SizeXY = GetSizeXY();
	if ((Dist) > (FMath::Min(SizeXY.X,SizeXY.Y)*SwipeRadius))
	{
		
		bWasATouchReleased = false;
		ForceEndTouch();
	}
}


void USwipeComponent::OnEnd()
{
	Super::OnEnd();
	AActor* MyOwner = GetOwner();
	if (MyOwner == nullptr)
	{
		return;
	}
	if (!bWasATouchReleased)
	{
		FTimerManager& TimerManager = MyOwner->GetWorldTimerManager();
		//Reset Back to true So next again can be checked
		bWasATouchReleased = true;
		if (TimerManager.IsTimerActive(TimerHandle))
		{
			float TimeElapsed = TimerManager.GetTimerElapsed(TimerHandle);
			TimerManager.ClearTimer(TimerHandle);
			if (CheckAngleInRange(SwipeToleranceAngle,AngleBeforeEnd,SwipeTargetAngle))
			{
				OnSwipeSuccess.Broadcast(AngleBeforeEnd,TimeElapsed,GetDirectionBasedOnAngle(AngleBeforeEnd));
				AngleBeforeEnd = 0.f;
			}
			else
			{
				OnSwipeFailed.Broadcast(ESwipeFailureReason::Esf_AngleLimitExceeds);
			}
		}
		else
		{
			OnSwipeFailed.Broadcast(ESwipeFailureReason::Esf_TimedOut);
		}
	}
	else
	{
		OnSwipeFailed.Broadcast(ESwipeFailureReason::Esf_TouchReleased);
	}
}
bool USwipeComponent::CheckAngleInRange(float Tolerance, float InCurrentAngle, float TargetAngle) const
{
	float Delta = InCurrentAngle -TargetAngle;
	float TempValue{Delta+180.f};
	TempValue /=360.f;
	int32 Floored = UKismetMathLibrary::FFloor(TempValue);
	float AbsDelta = UKismetMathLibrary::Abs((Floored*360.f)-Delta);
	return AbsDelta<=Tolerance;
}
