/* Copyright (C) 2022 IQRA IQBAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/

#include "JoystickComp.h"
#include "TouchScreenHud.h"


UJoystickComp::UJoystickComp()

{
	JoystickDragLimit = .25f;
}

void UJoystickComp::AddJoystickWidget(const FJoyStickWidgetInfo& JoyStickWidgetInfo)
{
	MyJoyStickWidgetInfo = JoyStickWidgetInfo;
	if (MyHud)
	{
		MyHud->AddJoyStickWidget(this);
	}
}

void UJoystickComp::TickComponent(float DeltaTime, ELevelTick Tick, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, Tick, ThisTickFunction);
	AdjustStartLocation();
	
	CurrentAngle = CalculateXYValueAndAngle(CurrentXYValue);
	CurrentXYValue.X *= (bShouldInvertX)?-1.f:1.f;
	CurrentXYValue.Y *= (bShouldInvertY)?-1.f:1.f;
	XValueChanged.Broadcast(CurrentXYValue.X);
	YValueChanged.Broadcast(CurrentXYValue.Y);
	// if (GEngine)
	// {
	// 	GEngine->AddOnScreenDebugMessage(1,4.f,FColor::Green,
	// 		FString::Printf(TEXT("Current Angle is %f"),CurrentAngle));
	// }

}

void UJoystickComp::BeginPlay()
{
	Super::BeginPlay();
	AddJoystickWidget(MyJoyStickWidgetInfo);
	JoyStickCenter = MyJoyStickWidgetInfo.WidgetLocation;
}

void UJoystickComp::OnTouchBegin(FVector2D TouchLocation, int32 TouchCount)
{
	Super::OnTouchBegin(TouchLocation, TouchCount);
	
}

void UJoystickComp::OnTouchMoved(FVector2D TouchLocation, int32 TouchCount)
{
	Super::OnTouchMoved(TouchLocation, TouchCount);

}

void UJoystickComp::OnTouchReleased(FVector2D TouchLocation, int32 TouchCount)
{
	Super::OnTouchReleased(TouchLocation, TouchCount);
	
	if (TouchCount == MyCurrentTouchIndex && bIsTouched)
	{
		CurrentAngle = 0.f;
	}
}

/*
void UJoystickComp::OnTouchPressed(const FVector& Location, ETouchIndex::Type TouchIndex)
{
	Super::OnTouchPressed(Location, TouchIndex);
	
}
*/

float UJoystickComp::CalculateXYValueAndAngle(FVector2D& OutRefXY)
{
	
	
	float Angle{0.f};
	if (bIsTouched)
	{
		Angle = CalculateAngle();
	}
	OutRefXY = TouchStartLocation - CurrentTouchLocation;
	FVector2D SizeXY = GetSizeXY();
	float DragLimit{JoystickDragLimit*GetScale()*FMath::Min(SizeXY.X,SizeXY.Y)};

	//OutRefXY.X =FMath::Clamp(-1.f*(OutRefXY.X/(JoystickDragLimit*GetScale())),-1.f,1.f);
	OutRefXY.X =FMath::Clamp(-1.f*(OutRefXY.X/(DragLimit)),-1.f,1.f);
	//OutRefXY.Y =FMath::Clamp(OutRefXY.Y/(JoystickDragLimit*GetScale()),-1.f,1.f);
	OutRefXY.Y =FMath::Clamp(OutRefXY.Y/(DragLimit),-1.f,1.f);

	return Angle;
}


void UJoystickComp::AdjustStartLocation()
{
	const float ScaleValue = GetScale();
	FVector2D Diff = CurrentTouchLocation - TouchStartLocation;
	FVector2D SizeXY = GetSizeXY();
	float DragLimit{JoystickDragLimit*GetScale()*FMath::Min(SizeXY.X,SizeXY.Y)};
	
	if (FMath::Abs((Diff.X*ScaleValue)) > DragLimit )
	{
		// horizontal Limit is exceeded

		const float OffsetValue = (Diff.X<0.f)?1.f:-1.f;
		// How many units exceeded
		const float HorizontalValue = (Diff.X * ScaleValue) + DragLimit*OffsetValue;
		//add these units back to start location
		TouchStartLocation.X += HorizontalValue;
		
	}
	if (FMath::Abs((Diff.Y*ScaleValue)) > DragLimit )
	{
		// Vertical Limit is exceeded
		const float OffsetValue = (Diff.Y<0.f)?1.f:-1.f;
		// How many units exceeded
		const float VerticalValue = (Diff.Y * ScaleValue) + OffsetValue*DragLimit;
		//add these units back to start location
		TouchStartLocation.Y += VerticalValue;
		
	}
	
}

void UJoystickComp::OnStart()
{
	Super::OnStart();
	JoyStickCenter = NormalizeScreenSize(TouchStartLocation);
}
