/* Copyright (C) 2022 IQRA IQBAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/
#include "PinchComponent.h"
#include "TimerManager.h"
#include "TouchScreenHud.h"

UPinchComponent::UPinchComponent()
{
	bFinger1Touched = false;
	bFinger2Touched = false;
	Finger1 = -1;
	Finger2 = -1;
	StartAngle = 0.f;
	DeltaAngle = 0.f;
	bPCDebug1FingerTouch = false;
	
}

void UPinchComponent::SetFinger1Debug()
{
	FVector2D Location = BoxOrigin - FVector2D(BoxSize.X,0.f);
	FVector2D SizeXY;
	if (MyHud)
	{
		SizeXY = MyHud->GetSizeXY();
	}
	Location *= SizeXY;
	
	bFinger1Touched = true;
	// Finger1 touch start location
	TouchStartFinger1 = Location;
	// finger1 touch index
	Finger1 = 34;
	TouchCurrentFinger1 = Location;
}

void UPinchComponent::BeginPlay()
{
	Super::BeginPlay();
	if (bPCDebug1FingerTouch)
	{
		
		GetWorld()->GetTimerManager().SetTimer(TimerHandle,this,&UPinchComponent::SetFinger1Debug,.3f,false);
		
		
	}
}

void UPinchComponent::OnTouchBegin(FVector2D TouchLocation, int32 TouchCount)
{
	if (!bCanBeTouched || bIsTouched)
	{
		return;
	}
	if (!CheckIsInBounds(TouchLocation))
	{
		return;
	}

	if (!CheckForPeriorty(TouchLocation))
	{
		return;
	}
	// If finger 1 is not touched
	if (!bFinger1Touched)
	{
		bFinger1Touched = true;
		// Finger1 touch start location
		TouchStartFinger1 = TouchLocation;
		// finger1 touch index
		Finger1 = TouchCount;
		TouchCurrentFinger1 = TouchLocation;
		// We will return from here because We will activate the other
		// Functionality when we also have the finger2 touched
		return;
	}
	if (!bFinger2Touched)
	{
		bFinger2Touched = true;
		// Finger2 touch start location
		TouchStartFinger2 = TouchLocation;
		// finger2 touch index
		Finger2 = TouchCount;
		TouchCurrentFinger2 = TouchLocation;

		// Now both fingers are touched
		bIsTouched = true;
		OnStart();
	}
	
	
	
}

void UPinchComponent::OnTouchMoved(FVector2D TouchLocation, int32 TouchCount)
{
	if (bFinger1Touched || bFinger2Touched)
	{
		if (Finger1 == TouchCount)
		{
			TouchCurrentFinger1 = TouchLocation;
			
		}
		if(Finger2 == TouchCount)
		{
			TouchCurrentFinger2 = TouchLocation;
		}

		// If both fingers are touched and touch index is equal to one of
		// this class finger index then call on move function
		if(bFinger1Touched && bFinger2Touched)
		{
			if (TouchCount == Finger1 || TouchCount == Finger2)
			{
				// Note this will be called only when both fingers are touched
				OnMoved();
			}
		}
	}
	
}

void UPinchComponent::OnTouchReleased(FVector2D TouchLocation, int32 TouchCount)
{
	// If one of the finger is touched
	if (bFinger1Touched || bFinger2Touched)
	{
		if (Finger1 == TouchCount || Finger2 == TouchCount)
		{
			// If the finger one is released
			if (TouchCount == Finger1)
			{
				// if the second finger is also touched then move the
				// finger one data into finger1
				if (bFinger2Touched)
				{
					TouchStartFinger1 = TouchStartFinger2;
					Finger1 = Finger2;
					TouchCurrentFinger1 = TouchCurrentFinger2;
					Finger2 = -1;
					bFinger2Touched = false;
				}
				else
				{
					Finger1 = -1;
					bFinger1Touched = false;
				}
			}
			else
			{
				Finger2 = -1;
				bFinger2Touched = false;
			}

			// Call OnEnd only if Pinch was happening
			if(bIsTouched)
			{
				bIsTouched = false;
            	OnEnd();
			}
			
			
		}
	}
}

void UPinchComponent::OnMoved()
{
	//Super::OnMoved();

	TouchStartLocation = TouchCurrentFinger1;
	CurrentTouchLocation = TouchCurrentFinger2;
	CurrentAngle = CalculateAngle(TouchCurrentFinger1,TouchCurrentFinger2);
	CurrentDistance = FVector2D::Distance(TouchCurrentFinger1,TouchCurrentFinger2);

	DeltaAngle =CalculateAngle(TouchCurrentFinger1,TouchCurrentFinger2,90.f-StartAngle);

	OnPinchMoved.Broadcast(CurrentDistance/StartDistance,DeltaAngle,
		TouchCurrentFinger1,TouchCurrentFinger2);
}

void UPinchComponent::OnEnd()
{
//	Super::OnEnd();
	
	OnPinchEnd.Broadcast(TouchCurrentFinger1,TouchCurrentFinger2,StartAngle,DeltaAngle,CurrentDistance/StartDistance);
	CurrentDistance = 0.f;
	StartAngle = 0.f;
	CurrentAngle = 0.f;
}

void UPinchComponent::OnStart()
{
	//Super::OnStart();
	StartAngle = CalculateAngle(TouchStartFinger1,TouchCurrentFinger2);
	StartDistance = FVector2D::Distance(TouchStartFinger1,TouchStartFinger2);
	CurrentDistance = StartDistance;
	CurrentAngle = StartAngle;
	OnPinchStart.Broadcast(TouchStartFinger1,TouchStartFinger2,
		StartAngle,0.f,1.f);
}
