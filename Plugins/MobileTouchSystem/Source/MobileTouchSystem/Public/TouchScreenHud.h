/* Copyright (C) 2022 IQRA IQBAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/
#pragma once

#include "CoreMinimal.h"
#include "JoystickComp.h"
#include "TouchButton.h"
#include "SwipeComponent.h"
#include "Engine/Canvas.h"
#include "GameFramework/HUD.h"
#include "TouchScreenHud.generated.h"


UCLASS()
class MOBILETOUCHSYSTEM_API ATouchScreenHud : public AHUD
{
	GENERATED_BODY()

public:
	explicit ATouchScreenHud(const FObjectInitializer& ObjectInitializer);
	UPROPERTY()
	FCanvasIcon myCanvasIcon;
	UPROPERTY()
	UTexture2D *mMyTexture;
	virtual void DrawHUD() override;
	
private:
	UPROPERTY()
	TArray<UJoystickComp*>JoystickComps;

	// Only used for debug
	UPROPERTY()
	TArray<USwipeComponent*>SwipeComponentsDebug;

	UPROPERTY()
	TArray<UTouchButton*>TouchButtons;

	
	float ScaleUI;

	// Only used for debug
	UPROPERTY()
	TArray<UBaseTouchComp*>DebugsToDrawFor;
	
	FVector2D ScreenXY;
	void LoopJoysticks();
	void LoopTouchButtons();

	void DrawTouchButton(UTouchButton* TouchButton);
	void DrawJoystick(UJoystickComp* JoystickCompToDraw);

	//This loop draws all the debugs
	void DrawDebugLoop();
	UPROPERTY()
	UFont* Font;
	
#pragma region DebugShapes
	void DrawDebugBox(const FVector2D&BoxSize,const FVector2D& BoxOrigin,const FColor& Color);
	void DrawDebugCircle(int32 Sections,float Radius,const FVector2D& Center);
	// Draws A circle With Target Tolerance Angle Highlighted
	void DrawDebugCircle(int32 Sections,float Radius,const FVector2D& Center,float Target,float AngleTolerance,bool bAutoScaleRadius=true);
	FVector2D GetLocationBasedOnAngle(float Angle,float Radius,const FVector2D& Center,float Rotation=0.f,bool Clockwise=false,bool bAutoScaleRadius=true);
	bool CheckAngleInRange(float Tolerance,float CurrentAngle,float TargetAngle)const;
#pragma endregion

	
public:

	FORCEINLINE float GetSizeY()const
	{
		//return FMath::Min(ScreenXY.X,ScreenXY.Y);
		return ScreenXY.Y;
	}
	FORCEINLINE FVector2D GetSizeXY()const{return ScreenXY;}
	bool AddJoyStickWidget(UJoystickComp* JoystickComp);
	bool RemoveJoyStickWidget(UJoystickComp* JoystickComp);

	void AddTouchButton(UTouchButton* TouchButton)
	{
		if (TouchButton)
		{
			TouchButtons.AddUnique(TouchButton);
		}
	}
	void RemoveTouchButton(UTouchButton* TouchButton)
	{
		if (TouchButton)
		{
			if (TouchButtons.Contains(TouchButton))
			{
				TouchButtons.Remove(TouchButton);
			}
		}
	}

	
	void AddCompToDebugList(UBaseTouchComp* TouchComp){DebugsToDrawFor.AddUnique(TouchComp);}
	void RemoveCompFromDebugList(UBaseTouchComp* TouchComp){
		if (DebugsToDrawFor.Contains(TouchComp))
		{
			DebugsToDrawFor.Remove(TouchComp);
		}
	}

	void AddDebugSwipe(USwipeComponent* SwipeComponent)
	{
		if (SwipeComponent == nullptr)
		{
			return;
		}
		SwipeComponentsDebug.AddUnique(SwipeComponent);
	}
	void RemoveDebugSwipe(USwipeComponent* SwipeComponent)
	{
		if (SwipeComponent)
		{
			if (SwipeComponentsDebug.Contains(SwipeComponent))
			{
				SwipeComponentsDebug.Remove(SwipeComponent);
			}
		}
	}
	float GetScaleUI()const;
};
