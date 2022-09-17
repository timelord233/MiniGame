/* Copyright (C) 2022 IQRA IQBAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/
#include "TouchButton.h"

#include "TouchScreenHud.h"
#include "Kismet/KismetMathLibrary.h"




void UTouchButton::OnTouchBegin(FVector2D TouchLocation, int32 TouchCount)
{
	if (!bCanBeTouched)
	{
		return;
	}
	TArray<int32>ButtonIndexes;

	
	
	if (CheckButtonsBounds(TouchLocation,ButtonIndexes))
	{
		if (ButtonIndexes.Num()>0)
		{
			for(int32 Index=0;Index < ButtonIndexes.Num();++Index)
			{
				int32 ButtonIndex  = ButtonIndexes[Index];
				FTouchButtonData& TouchData = TouchButtonDatas[ButtonIndex];
				if (TouchData.ButtonType == EButtonType::ETap && TouchData.bIsPressed)
				{
					TouchData.TouchIndex = -1;
					TouchData.bIsPressed = false;
					OnButtonReleased.Broadcast(TouchData.HitBoxName, Index);
					continue; // Continue next loop

				}
				TouchData.TouchIndex = TouchCount;
				
				//Call only if it was not already pressed
				if (!TouchData.bIsPressed)
				{
					TouchData.bIsPressed = true;
					OnButtonClicked.Broadcast(TouchData.HitBoxName,ButtonIndex);
				}
				
			}
		}
	}
}

void UTouchButton::OnTouchReleased(FVector2D TouchLocation, int32 TouchCount)
{
	if (TouchButtonDatas.Num()>0)
	{
		for(int32 Index=0;Index<TouchButtonDatas.Num();++Index)
		{
			FTouchButtonData& TouchData = TouchButtonDatas[Index];
			if (TouchData.ButtonType == EButtonType::ETap && TouchData.TouchIndex==TouchCount)
			{
				continue; // Continue next loop
			}
			if (TouchData.TouchIndex == TouchCount)
			{
				TouchData.bIsPressed = false;
				TouchData.TouchIndex = -1;
				OnButtonReleased.Broadcast(TouchData.HitBoxName,Index);
			}
		}
	}
	
}

void UTouchButton::AddToDebug()
{
	return;
}

void UTouchButton::BeginPlay()
{
	Super::BeginPlay();
	if (MyHud)
	{
		MyHud->AddTouchButton(this);
	}
}


void UTouchButton::HideAllButtons()
{
	if (TouchButtonDatas.Num()>0)
	{
		for (FTouchButtonData& TouchButtonData : TouchButtonDatas)
		{
			TouchButtonData.bIsVisible = false;
		}
	}
}

void UTouchButton::ShowAllButtons()
{
	if (TouchButtonDatas.Num()>0)
	{
		for (FTouchButtonData& TouchButtonData : TouchButtonDatas)
		{
			TouchButtonData.bIsVisible = true;
		}
	}
}


bool UTouchButton::ComparePriorties(UBaseTouchComp* OtherComp, const FVector2D& Location) const
{
	if (OtherComp)
	{
		if (this->bCanBeTouched && this->bShouldBlockLowerPriorty)
		{
			// If the TouchButton Has low touch priority then the other component
			if (OtherComp->GetPriority() >= this->TouchPriorty)
			{
				return false;
			}
			
			TArray<int32> Indexes;
			bool ShouldBlock{false};
			bool InButtonBounds = CheckButtonsBounds(Location, Indexes);

			if (InButtonBounds)
			{
				for (int32 Counter = 0; Counter < Indexes.Num(); ++Counter)
				{
					const int32 Index = Indexes[Counter];
					
					const FTouchButtonData& TouchData = TouchButtonDatas[Index];

					if (TouchData.bShouldBlockLowerPriorty == false)
					{
						continue;
					}
					if (TouchData.TouchPriorty > OtherComp->GetPriority())
					{
						ShouldBlock = true;
						break;
					}
					
				}
			} // If in button bounds 
			return ShouldBlock;
		} // if button canbe touched and should block low priority
		return false;
	}
	return false;
	//return false;
}
bool UTouchButton::CheckButtonsBounds(const FVector2D& Location,TArray<int32> &ButtonsIndexes)const 
{
	const FVector2D NormalizedLocation {NormalizeScreenSize(Location)};
	bool IsInBounds = false;

	if (TouchButtonDatas.Num()>0)
	{
		for (int32 Index=0;Index < TouchButtonDatas.Num();++Index)
		{
			const FTouchButtonData& TouchButtonData = TouchButtonDatas[Index];
			const FVector2D& LocalBoxOrigin = TouchButtonData.BoxOrigin;
			FVector2D LocalBoxSize {TouchButtonData.BoxSize};
			LocalBoxSize *= GetScale();
			LocalBoxSize = NormalizeScreenSize(LocalBoxSize);
	

			if (TouchButtonData.bIsVisible)
			{
				const bool bInBounds = (UKismetMathLibrary::InRange_FloatFloat(NormalizedLocation.X,
				                                                               LocalBoxOrigin.X-LocalBoxSize.X,
				                                                               LocalBoxOrigin.X+LocalBoxSize.X)
					&&
					UKismetMathLibrary::InRange_FloatFloat(NormalizedLocation.Y,
					                                       LocalBoxOrigin.Y-LocalBoxSize.Y,
					                                       LocalBoxOrigin.Y+LocalBoxSize.Y)
				);
				if (bInBounds)
				{
					if (!IsInBounds)
					{
						IsInBounds = true;
					}
					ButtonsIndexes.Add(Index);
				}
			}
		}
		
	}
	
	return IsInBounds;
}
