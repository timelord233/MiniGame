/* Copyright (C) 2022 IQRA IQBAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/

#include "TouchSystemStatics.h"
#include "BaseTouchComp.h"

void UTouchSystemStatics::ToggleDebugOnAllTouchComps(AActor* Owner, bool bTurnOn)
{
	if (Owner)
	{
		TInlineComponentArray<UBaseTouchComp*> Touchcomps;
		Owner->GetComponents<UBaseTouchComp>(Touchcomps);
		for (UBaseTouchComp* TouchComp : Touchcomps)
		{
			
			if (TouchComp!=nullptr)
			{
				TouchComp->ToggleDebug(bTurnOn);
			}
		}
	}
}

void UTouchSystemStatics::ToggleCanbeTouched(AActor* Owner, bool bTurnOn)
{
	if (Owner)
	{
		TInlineComponentArray<UBaseTouchComp*> Touchcomps;
		Owner->GetComponents<UBaseTouchComp>(Touchcomps);
		for (UBaseTouchComp* TouchComp : Touchcomps)
		{
			
			if (TouchComp!=nullptr)
			{
				TouchComp->ToggleCanBeTouched(bTurnOn);
			}
		}
	}
}
