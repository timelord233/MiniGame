/* Copyright (C) 2022 IQRA IQBAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/

#include "BaseTouchComp.h"
#include "TouchScreenHud.h"
#include "TouchDelegates.h"
//#include "TouchGameViewportClient.h"

#include "Blueprint/WidgetLayoutLibrary.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values for this component's properties
UBaseTouchComp::UBaseTouchComp():
bAlreadyHaveAWidget(false),
bIsTouched(false),
MyCurrentTouchIndex(-1),
bCanBeTouched(true)
{
	DeltaSeconds = 0.f;

	
	

	PrimaryComponentTick.bCanEverTick = true;

	BoxSize = FVector2D(.25f,.25f);
	BoxOrigin = FVector2D(.25f,.75f);
	// ...
}

void UBaseTouchComp::OnRegister()
{
	Super::OnRegister();

	UTouchDelegates::TouchBegan.AddUObject(this,&UBaseTouchComp::OnTouchBegin);
	UTouchDelegates::TouchMoved.AddUObject(this,&UBaseTouchComp::OnTouchMoved);
	UTouchDelegates::TouchEnded.AddUObject(this,&UBaseTouchComp::OnTouchReleased);
}

void UBaseTouchComp::OnUnregister()
{
	Super::OnUnregister();
	UTouchDelegates::TouchBegan.RemoveAll(this);
	UTouchDelegates::TouchEnded.RemoveAll(this);
	UTouchDelegates::TouchMoved.RemoveAll(this);
}


// Called when the game starts
void UBaseTouchComp::BeginPlay()
{
	Super::BeginPlay();
	SetupHitBox(BoxOrigin,BoxSize);
	//SetupOwners();
	if(APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(),0))
	{
		MyHud =Cast<ATouchScreenHud>(PC->GetHUD());
	}

	
	
	if (bShouldDrawDebug)
	{
		AddToDebug();
	}
	
}
void UBaseTouchComp::AddToDebug()
{
	if (MyHud)
	{
		if (bShouldDrawDebug)
		{
			MyHud->AddCompToDebugList(this);
		}
	}
}

void UBaseTouchComp::ToggleDebug(bool bShouldTurnOn)
{
	
	if (bShouldDrawDebug != bShouldTurnOn)
	{
		bShouldDrawDebug = bShouldTurnOn;
		if (MyHud)
		{
			if (bShouldDrawDebug)
			{
				MyHud->AddCompToDebugList(this);
				
			}
			else
			{
				MyHud->RemoveCompFromDebugList(this);
				
			}
		}
	}
}

void UBaseTouchComp::ToggleCanBeTouched(bool bInCanBeTouched)
{
	bCanBeTouched = bInCanBeTouched;
}

// Called every frame
void UBaseTouchComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	DeltaSeconds = DeltaTime;
	// ...
}



#pragma region Priorities
bool UBaseTouchComp::ComparePriorties( UBaseTouchComp* OtherComp,const FVector2D& Location)const
{
	if (OtherComp)
	{
		if (this->bCanBeTouched && this->bShouldBlockLowerPriorty)
		{
			
			if (OtherComp->GetPriority() >= this->TouchPriorty)
			{
				
				return false;
			}
			return CheckIsInBounds(Location);
		}
		else
			return false;
	}
	return false;
}



bool UBaseTouchComp::CheckForPeriorty(const FVector2D& Location)
{
	TInlineComponentArray<UBaseTouchComp*>TouchComps;
	GetOwner()->GetComponents<UBaseTouchComp>(TouchComps);
	for ( UBaseTouchComp* TouchComp:TouchComps)
	{
		if (TouchComp)
		{
			if (TouchComp ==this)
			{
				continue;
			}
			//check if we should block the input
			if (TouchComp->ComparePriorties(this,Location))
			{
				// this input is blocked
				// cannot continue
				return false;
			}
		}
	}
	//continue input
	return true;
}
#pragma endregion



#pragma region OnTouchBegin

void UBaseTouchComp::OnTouchBegin(FVector2D TouchLocation, int32 TouchCount)
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
	
	bIsTouched = true;
	MyCurrentTouchIndex = TouchCount;
	TouchStartLocation = TouchLocation;
	CurrentTouchLocation = TouchStartLocation;
	OnStart();
}

bool UBaseTouchComp::CheckIsInBounds(const FVector2D& Location) const
{

	const FVector2D NormalizedLocation {NormalizeScreenSize(Location)};
	
	
	const bool IsInBounds = (UKismetMathLibrary::InRange_FloatFloat(NormalizedLocation.X,
		BoxOrigin.X-BoxSize.X,BoxOrigin.X+BoxSize.X)
		&&
		UKismetMathLibrary::InRange_FloatFloat(NormalizedLocation.Y,
		BoxOrigin.Y-BoxSize.Y,BoxOrigin.Y+BoxSize.Y)
		);
	
	return IsInBounds;
}


void UBaseTouchComp::OnStart()
{
}

#pragma endregion

#pragma region TouchMoved

void UBaseTouchComp::OnTouchMoved(FVector2D TouchLocation, int32 TouchCount)
{
	if (!bIsTouched || TouchCount!= MyCurrentTouchIndex)
	{
		return;
	}
	CurrentTouchLocation = TouchLocation;
	OnMoved();
	
}


void UBaseTouchComp::OnMoved()
{
	// child classes will expand the functionality
}

#pragma endregion 

#pragma region TouchReleased
void UBaseTouchComp::OnTouchReleased(FVector2D TouchLocation, int32 TouchCount)
{
	if (TouchCount == MyCurrentTouchIndex && bIsTouched)
	{
		ForceEndTouch();
	}
	
	
}



void UBaseTouchComp::OnEnd()
{
	// child classes will expand the functionality
}

void UBaseTouchComp::ForceEndTouch()
{
	if ( bIsTouched)
	{
		TouchStartLocation = FVector2D(0.f);
		CurrentTouchLocation = TouchStartLocation;
		bIsTouched = false;
		MyCurrentTouchIndex = -1;
		OnEnd();
	}
	
}
#pragma endregion 


void UBaseTouchComp::SetupHitBox(const FVector2D& InBoxOrigin, const FVector2D& InBoxSize)
{
	float ValueX = FMath::Clamp(InBoxOrigin.X,0.f,1.f);
	float ValueY = FMath::Clamp(InBoxOrigin.Y,0.f,1.f);
	this->BoxOrigin.X = ValueX;
	this->BoxOrigin.Y = ValueY;
	ValueX = FMath::Clamp(InBoxSize.X,0.f,1.f);
	ValueY = FMath::Clamp(InBoxSize.Y,0.f,1.f);
	this->BoxSize.X = ValueX;
	this->BoxSize.Y = ValueY;
}

#pragma region Helpers

FVector2D UBaseTouchComp::ConvertResToScreen(FVector2D InLoc)
{
	//float ResY = GetSizeXY();
	FVector2D ResXY = GetSizeXY();
	//float ScreenY = UWidgetLayoutLibrary::GetViewportSize(GetWorld()).Y;
	FVector2D ScreenXY = UWidgetLayoutLibrary::GetViewportSize(GetWorld());
	// resy center
	//ResY /=2.f;
	ResXY /=2.f;
	// Screen Y center
	//ScreenY /=2.f;
	ScreenXY /=2.f;
	
	//float Diff = ScreenY -ResY;
	FVector2D Diff = ScreenXY -ResXY;
	
	return InLoc + Diff;
}


float UBaseTouchComp::CalculateAngle(float Offset) const
{
	FVector2D Diff = CurrentTouchLocation - TouchStartLocation;
	Diff.Normalize();
	float Angle = UKismetMathLibrary::DegAtan2(Diff.Y,Diff.X);
	Angle += Offset;
	Angle = (Angle<0.f)?(360.f+Angle) : Angle;
	
	return Angle;
}

float UBaseTouchComp::CalculateAngle(const FVector2D& StartLocation,
	const FVector2D& CurrentLocation,float Offset ) const
{
	FVector2D Diff = CurrentLocation - StartLocation;
	Diff.Normalize();
	float Angle = UKismetMathLibrary::DegAtan2(Diff.Y,Diff.X);
	Angle += Offset;
	Angle = (Angle<0.f)?(360.f+Angle) : Angle;
	
	return Angle;
}

FVector2D UBaseTouchComp::NormalizeScreenSize(const FVector2D& InScreenLocation) const
{
	const FVector2D ScreenSize= UWidgetLayoutLibrary::GetViewportSize(GetWorld());
	return (InScreenLocation/ScreenSize);
	
}

FVector2D UBaseTouchComp::GetSizeXY()
{
	FVector2D Size;
	if (MyHud)
	{
		//sizeY = MyHud->GetSizeY();
		Size = MyHud->GetSizeXY();
		if (Size.X <=0.f || Size.Y<=0.f)
		{
			Size = UWidgetLayoutLibrary::GetViewportSize(GetWorld());
		}
	}
	else
	{
		//const FVector2D ViewportSize = UWidgetLayoutLibrary::GetViewportSize(GetWorld());
		
		//sizeY = FMath::Min(ViewportSize.X,ViewportSize.Y);
		//sizeY = UWidgetLayoutLibrary::GetViewportSize(GetWorld()).Y;
		Size = UWidgetLayoutLibrary::GetViewportSize(GetWorld());
	}
	// if (sizeY <= 0.f)
	// {
	// 	return 1080.f;
	// }
	return Size;
}

float UBaseTouchComp::GetScale() const
{
	if (MyHud)
	{
		return MyHud->GetScaleUI();
	}
	return UWidgetLayoutLibrary::GetViewportScale(GetWorld());
	//return UTouchGameViewportClient::GetDPIScreenScale();
}

#pragma endregion 
