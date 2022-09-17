/* Copyright (C) 2022 IQRA IQBAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/
#pragma once

#include "CoreMinimal.h"
#include "BaseTouchComp.h"
#include "DragComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnXYChanged,float,XValue,float,YValue);
UCLASS(ClassGroup=(MobileTouch),meta=(BlueprintSpawnableComponent))
class MOBILETOUCHSYSTEM_API UDragComponent : public UBaseTouchComp
{
	GENERATED_BODY()
public:
	UDragComponent();
protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="DragComponent")
	bool bShouldInvertX = false;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="DragComponent")
	bool bShouldInvertY = false;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="DragComponent")
	float SmoothnessMultiplier;
	
	virtual void OnTouchBegin(FVector2D TouchLocation, int32 TouchCount) override;
	virtual void OnTouchMoved(FVector2D TouchLocation, int32 TouchCount) override;
	virtual void OnTouchReleased(FVector2D TouchLocation, int32 TouchCount) override;

	UPROPERTY(BlueprintAssignable,Category="DragComponent")
	FOnXYChanged OnXYValueChanged;
};
