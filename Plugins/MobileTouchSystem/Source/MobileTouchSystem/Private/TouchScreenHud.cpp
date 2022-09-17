/* Copyright (C) 2022 IQRA IQBAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/
#include "TouchScreenHud.h"
#include "Engine/Font.h"
#include "TouchButton.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"


ATouchScreenHud::ATouchScreenHud(const FObjectInitializer& ObjectInitializer):Super(ObjectInitializer)
{
	ScaleUI = 0.f;
	//conststatic ConstructorHelpers::FObjectFinder<UFont>
	if (UKismetSystemLibrary::IsDedicatedServer(this))
	{
		Font = nullptr;
	}
	else
	{
		static ConstructorHelpers::FObjectFinder<UFont>
			MyFont(TEXT("/MobileTouchSystem/MobileTouchFont"));
		//mMyTexture = SomeTexture.Object;
		Font = MyFont.Object;
		//myCanvasIcon = UCanvas::MakeIcon(mMyTexture,128.,128.f,128.f,256.f);
	}
}

void ATouchScreenHud::DrawHUD()
{
	Super::DrawHUD();
	if (Canvas != nullptr)
	{
		//ScaleUI = Canvas->ClipY/1080.f;
		ScreenXY.X = Canvas->ClipX; 
		ScreenXY.Y = Canvas->ClipY;
		ScaleUI = FMath::Min(ScreenXY.X,ScreenXY.Y)/1080.f;
		LoopJoysticks();
		LoopTouchButtons();
		
		DrawDebugLoop();
		
		
	
		
	}
}
void ATouchScreenHud::DrawDebugLoop()
{
	for (UBaseTouchComp* TouchComp:DebugsToDrawFor)
	{
		const FVector2D& BoxSize = TouchComp->GetBoxSize();
		const FVector2D& BoxOrigin = TouchComp->GetBoxOrigin();
		const FColor& Color = TouchComp->GetDebugColor();
		DrawDebugBox(BoxSize,BoxOrigin,Color);
		float TextX;
		float TextY;
		const FString& ActualText = TouchComp->GetDebugName();

		GetTextSize(ActualText,TextX,TextY,Font);
		TextX = Canvas->ClipX * BoxOrigin.X - (ScaleUI*TextX/2.f);
		TextY = Canvas->ClipY * BoxOrigin.Y - (ScaleUI*TextY/2.f);
			
		DrawText(ActualText,Color,TextX,
			TextY,Font,ScaleUI);

		// If Touched draw current finger location
		if (TouchComp->GetIsTouched())
		{
			const FVector2D& TouchLocation = TouchComp->GetCurrentTouchLocation();
			const FVector2D& StartTouchLocation = TouchComp->GetStartTouchLocation();
			DrawDebugCircle(24,TouchComp->GetDebugFingerRadius(),TouchLocation);
			DrawDebugCircle(24,TouchComp->GetDebugFingerRadius(),StartTouchLocation);

			//Draw line from start to touch location
			DrawLine(StartTouchLocation.X,
				StartTouchLocation.Y,
				TouchLocation.X,
				TouchLocation.Y,
				FColor::Green,2.f);
		}
		
	}

	for (USwipeComponent* SwipeComponent : SwipeComponentsDebug)
	{
		if (SwipeComponent)
		{
			if (SwipeComponent->GetIsTouched() && SwipeComponent->GetShouldDrawDebug())
			{
				const float MinDim{FMath::Min(ScreenXY.X,ScreenXY.Y)};
				const float Radius {SwipeComponent->GetSwipeRadius()*MinDim*2.f};
				const float TargetAngle {SwipeComponent->GetSwipeTargetAngle()};
				const float ToleranceAngle {SwipeComponent->GetSwipeTolerance()};
				const FVector2D& TouchStart{SwipeComponent->GetStartTouchLocation()};
				DrawDebugCircle(360,Radius,TouchStart
					,TargetAngle,
					SwipeComponent->GetSwipeTolerance(),false);

				FVector2D MinAnlgeLocation {GetLocationBasedOnAngle(TargetAngle-ToleranceAngle,
					Radius,TouchStart,-90.f,true,false)};
				FVector2D MaxAnlgeLocation {GetLocationBasedOnAngle(TargetAngle+ToleranceAngle,
					Radius,TouchStart,-90.f,true,false)};

				DrawLine(TouchStart.X,
					TouchStart.Y,
					MinAnlgeLocation.X,
					MinAnlgeLocation.Y,
					FLinearColor::Green,
					1.5f);
				DrawLine(TouchStart.X,
					TouchStart.Y,
					MaxAnlgeLocation.X,
					MaxAnlgeLocation.Y,
					FLinearColor::Green,
					1.5f);
				
			}
		}
	}
		
}


void ATouchScreenHud::LoopJoysticks()
{
	for (UJoystickComp* JoystickComp : JoystickComps)
	{
		DrawJoystick(JoystickComp);
	}
}

void ATouchScreenHud::LoopTouchButtons()
{
	for (UTouchButton* TouchButton : TouchButtons)
	{
		DrawTouchButton(TouchButton);
	}
}

void ATouchScreenHud::DrawTouchButton(UTouchButton* TouchButton)
{
	if (TouchButton == nullptr) {
		return;
	}
	const TArray<FTouchButtonData>& TouchButtonDatas = TouchButton->GetButtonsData();
	if (TouchButtonDatas.Num()>0)
	{
		for (const FTouchButtonData& TouchData:TouchButtonDatas)
		{
			if (!TouchData.bIsVisible)
			{
				continue;
			}
			
			UTexture2D* ButtonIcon{TouchData.NormalIcon};
			FColor ButtonTint {TouchData.NormalTint};

			if (TouchData.bIsPressed)
			{
				if (TouchData.PressedIcon != nullptr)
				{
					ButtonIcon = TouchData.PressedIcon;
				}
				ButtonTint = TouchData.PressedTint;
				
			}
			
			const EBlendMode& BlendMode = TouchData.BlendMode;
			FVector2D WidgetLocation =TouchData.BoxOrigin;
			// Making sure that location is in 0-1 range 
			WidgetLocation.X = FMath::Clamp(WidgetLocation.X,0.f,1.f);
			WidgetLocation.Y = FMath::Clamp(WidgetLocation.Y,0.f,1.f);
	
			WidgetLocation = WidgetLocation * ScreenXY;
			
			FVector2D WidgetSize = TouchData.BoxSize  *2.f;
			WidgetSize *= ScaleUI;
			const FVector2D Center = WidgetLocation - WidgetSize/2.f;
			// drawing the texture 
			if (ButtonIcon != nullptr)
			{
				
				DrawTexture(ButtonIcon,
				            Center.X,
				            Center.Y,
				            WidgetSize.X,WidgetSize.Y,
				            0.f,0.f,1.f,1.f
				            ,ButtonTint,BlendMode,1,false,TouchData.IconRotation,FVector2D(0.5f,0.5f));
				
			}

			if(TouchButton->GetShouldDrawDebug())
				DrawDebugBox((WidgetSize/ScreenXY)/2.f,TouchData.BoxOrigin,ButtonTint);
		}
	}
}

void ATouchScreenHud::DrawJoystick(UJoystickComp* JoystickCompToDraw)
{
	if (JoystickCompToDraw)
	{
		const FJoyStickWidgetInfo& WidgetInfo = JoystickCompToDraw->GetWidgetInfo();
		if (WidgetInfo.ThumbTexture && WidgetInfo.BGTexture)
		{
			
			FVector2D WidgetLocation;
			
			FLinearColor Color = WidgetInfo.Tint;

			//Setting color Alpha
			Color.A = (JoystickCompToDraw->GetIsTouched()) ?
				WidgetInfo.ActiveOpacity:WidgetInfo.InActiveOpacity;

			
			if (WidgetInfo.bShouldRecenter)
			{
				WidgetLocation = JoystickCompToDraw->GetJoystickCenter();
			}
			else
			{
				WidgetLocation = WidgetInfo.WidgetLocation;
				
			}
			// Making sure that location is in 0-1 range 
			WidgetLocation.X = FMath::Clamp(WidgetLocation.X,0.f,1.f);
			WidgetLocation.Y = FMath::Clamp(WidgetLocation.Y,0.f,1.f);
			//Location of the main bg Texture
			WidgetLocation = WidgetLocation * ScreenXY;
			
			const FVector2D WidgetSize = WidgetInfo.BackgroundSize * ScaleUI;
			const FVector2D BgWidgetLUCorner = WidgetLocation - WidgetSize/2.f;
			// drawing the bg texture 
			DrawTexture(WidgetInfo.BGTexture,
				BgWidgetLUCorner.X,
				BgWidgetLUCorner.Y,
				WidgetSize.X,WidgetSize.Y,
				0.f,0.f,1.f,1.f
				,Color);


			const float Angle = JoystickCompToDraw->GetCurrentAngle();
			FVector2D ThumbLocation = FVector2D(UKismetMathLibrary::DegSin(Angle),(-1.f)*UKismetMathLibrary::DegCos(Angle));
			
			ThumbLocation *= WidgetSize.X/2.f;

			ThumbLocation *= UKismetMathLibrary::GetAbs2D(JoystickCompToDraw->GetCurrentXYValue());
		
			const FVector2D ThumbSize = WidgetInfo.ThumbSize * ScaleUI;
			//const FVector2D ThumbSize = FVector2D(64.f) * ScaleUI;
			//ThumbLocation += BgWidgetLUCorner + (WidgetSize/2.f);
			ThumbLocation += WidgetLocation;
			ThumbLocation -= ThumbSize/2.f;

			
			//draw thumb texture
			DrawTexture(WidgetInfo.ThumbTexture,
				ThumbLocation.X,
				ThumbLocation.Y,
				ThumbSize.X,
				ThumbSize.Y,
				0.f,
				0.f,
				1.f,1.f,
				Color
				);
			
			
		} // End drawing joystick

		// if (JoystickCompToDraw->GetShouldDrawDebug())
		// {
		// 	const FVector2D& BoxSize=JoystickCompToDraw->GetBoxSize();
		// 	const FVector2D& BoxOrigin=JoystickCompToDraw->GetBoxOrigin();
		//
		// 	const FColor& Color = JoystickCompToDraw->GetDebugColor();
		// 	DrawDebugBox(BoxSize,BoxOrigin,Color);
		// 	
		// }
	}
}


void ATouchScreenHud::DrawDebugBox(const FVector2D& BoxSize, const FVector2D& BoxOrigin,const FColor& Color)
{
	//Top line
	DrawLine((BoxOrigin.X - BoxSize.X)*Canvas->ClipX,
		(BoxOrigin.Y-BoxSize.Y)*Canvas->ClipY,
		(BoxOrigin.X + BoxSize.X)*Canvas->ClipX,
		(BoxOrigin.Y-BoxSize.Y)*Canvas->ClipY,
		Color,2.f);
	// Bottom line
	DrawLine((BoxOrigin.X - BoxSize.X)*Canvas->ClipX,
		(BoxOrigin.Y+BoxSize.Y)*Canvas->ClipY,
		(BoxOrigin.X + BoxSize.X)*Canvas->ClipX,
		(BoxOrigin.Y+BoxSize.Y)*Canvas->ClipY,
		Color,2.f);
	// Left Line
	DrawLine((BoxOrigin.X - BoxSize.X)*Canvas->ClipX,
		(BoxOrigin.Y-BoxSize.Y)*Canvas->ClipY,
		(BoxOrigin.X - BoxSize.X)*Canvas->ClipX,
		(BoxOrigin.Y+BoxSize.Y)*Canvas->ClipY,
		Color,2.f);
	// Right Line
	DrawLine((BoxOrigin.X + BoxSize.X)*Canvas->ClipX,
		(BoxOrigin.Y-BoxSize.Y)*Canvas->ClipY,
		(BoxOrigin.X + BoxSize.X)*Canvas->ClipX,
		(BoxOrigin.Y+BoxSize.Y)*Canvas->ClipY,
		Color,2.f);

		
}

void ATouchScreenHud::DrawDebugCircle(int32 Sections, float Radius, const FVector2D& Center)
{
	Sections = FMath::Clamp(Sections,3,360);
	Radius *= ScaleUI;
	const float AnglePerSection = 360.f/(static_cast<float>(Sections));
	for (int32 Counter = 0;Counter<Sections;++Counter)
	{
		float Multiplier = static_cast<float> (Counter);
		
		const FVector2D Start = GetLocationBasedOnAngle(AnglePerSection*Multiplier,Radius,Center);
		Multiplier +=1.f;
		const FVector2D End = GetLocationBasedOnAngle(AnglePerSection*Multiplier,Radius,Center);
		DrawLine(Start.X,Start.Y,End.X,End.Y,FColor::Green,2.f);
	}
	
}

void ATouchScreenHud::DrawDebugCircle(int32 Sections, float Radius, const FVector2D& Center,float Target,float AngleTolerance,bool bAutoScaleRadius)
{
	Sections = FMath::Clamp(Sections,3,360);
	if(bAutoScaleRadius)
		Radius *= ScaleUI;

	// This offset will Rotate the Circle  
	//const float AngleOffset = 90.f+(360.f/8.f)/2.f;
	const float AnglePerSection = 360.f/(static_cast<float>(Sections));
	for (int32 Counter = 0;Counter<Sections;++Counter)
	{
		float Multiplier = static_cast<float> (Counter);
		float Angle = AnglePerSection * Multiplier;
		FColor CircleColor = (CheckAngleInRange(AngleTolerance,Angle,Target))?
			FColor::Green : FColor::Red;
		//Angle += AngleOffset;
		const FVector2D Start = GetLocationBasedOnAngle(AnglePerSection*Multiplier,Radius
			,Center,270.f,true,bAutoScaleRadius);
		Multiplier +=1.f;
		const FVector2D End = GetLocationBasedOnAngle(AnglePerSection*Multiplier
			,Radius,Center,270.f,true,bAutoScaleRadius);
		DrawLine(Start.X,Start.Y,End.X,End.Y,CircleColor,2.f);
	}
	
}

FVector2D ATouchScreenHud::GetLocationBasedOnAngle(float Angle, float Radius, const FVector2D& Center,float Rotation,bool Clockwise,bool bAutoScaleRadius)
{
	FVector2D Location;
	if(!Clockwise)
	{
		Location= FVector2D(UKismetMathLibrary::DegSin(Angle + Rotation),
			UKismetMathLibrary::DegCos(Angle + Rotation));
	}
	else
	{
		Location= FVector2D(UKismetMathLibrary::DegCos(Angle + Rotation),
			UKismetMathLibrary::DegSin(Angle + Rotation));
	}
	if (bAutoScaleRadius)
	{
		Location *= Radius*ScaleUI;
	}
	else
		Location *= Radius;
	Location = (Location + Center) - (Location/2.f);
	return Location;
}

bool ATouchScreenHud::CheckAngleInRange(float Tolerance, float CurrentAngle, float TargetAngle) const
{
	float Delta = CurrentAngle -TargetAngle;
	float TempValue{Delta+180.f};
	TempValue /=360.f;
	int32 Floored = UKismetMathLibrary::FFloor(TempValue);
	float AbsDelta = UKismetMathLibrary::Abs((Floored*360.f)-Delta);
	return AbsDelta<=Tolerance;
}


bool ATouchScreenHud::AddJoyStickWidget(UJoystickComp* JoystickComp)
{
	
	return (JoystickComps.AddUnique(JoystickComp)!=-1);
}

bool ATouchScreenHud::RemoveJoyStickWidget(UJoystickComp* JoystickComp)
{
	if (JoystickComp==nullptr)
	{
		return false;
	}
	if (JoystickComps.Contains(JoystickComp))
	{
		JoystickComps.Remove(JoystickComp);
		return true;
	}
	
	return false;
}

float ATouchScreenHud::GetScaleUI() const
{
	return ScaleUI;
}
