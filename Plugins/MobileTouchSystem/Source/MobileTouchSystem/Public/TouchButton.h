/* Copyright (C) 2022 IQRA IQBAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/
#pragma once

#include "CoreMinimal.h"
#include "BaseTouchComp.h"
#include "TouchButton.generated.h"


UENUM(BlueprintType)
enum class EButtonType :uint8 {
	EHold UMETA(DisplayName = "Hold"),
	ETap UMETA(DisplayName = "Tap")
};

USTRUCT(BlueprintType)
struct FTouchButtonData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="TouchButtonData",meta=(ToolTip="Value should be in Percentage (0-1) range"))
	FVector2D BoxOrigin;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="TouchButtonData",meta=(ToolTip="Value should be in Pixels"))
	FVector2D BoxSize;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="TouchButtonData",meta=(ToolTip="This Name will be very useful Button pressed and released events will use this name , Try to give unique name"))
	FName HitBoxName;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="TouchButtonData",meta=(ToolTip="If not visible then It will be not drawn and donot get any Press or Released Events"))
	bool bIsVisible;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "TouchButtonData")
	EButtonType ButtonType;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="TouchButtonData")
	TEnumAsByte<EBlendMode> BlendMode;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="TouchButtonData")
	UTexture2D* NormalIcon;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="TouchButtonData",meta=(ToolTip="If left empty then NormalIcon will be used"))
	UTexture2D* PressedIcon;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="TouchButtonData")
	FColor NormalTint;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="TouchButtonData")
	FColor PressedTint;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="TouchButtonData")
	float IconRotation;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BaseTouchComponent|Configs",meta=(ToolTip="Blocks the lower priorty component when this hitbox get touched -- Priorty needs to be set "))
	bool bShouldBlockLowerPriorty;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BaseTouchComponent|Configs",meta=(EditCondition="bShouldBlockLowerPriorty",ToolTip="Higher value means high priority"))
	int32 TouchPriorty{0};
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="TouchButtonData")
	int32 TouchIndex;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="TouchButtonData")
	bool bIsPressed;

	
	FTouchButtonData()
	{
		BoxOrigin = FVector2D(0.f);
		BoxSize = FVector2D(128.f);
		HitBoxName = FName("Button");
		bIsVisible = true;
		BlendMode = EBlendMode::BLEND_Translucent;
		bShouldBlockLowerPriorty = false;
		NormalIcon= nullptr;
		PressedIcon = nullptr;
		NormalTint = FColor::White;
		PressedTint = FColor::White;
		TouchIndex = -1;
		bIsPressed = false;
		ButtonType = EButtonType::EHold;
		IconRotation = 0.f;
		
	}
		
};



DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnButtonStatusChanged,FName,ButtonName,int32,Index);
//=============================================================================
/**
 * Only Use it for the In Game Action Buttons, For which You want to Hold And Drag Functionality
 * Like the fire button , where you hold to continue the fire and drag to move the camera
 * For all other buttons use UMG
 */

UCLASS(ClassGroup=(MobileTouch),meta=(BlueprintSpawnableComponent))
class MOBILETOUCHSYSTEM_API UTouchButton : public UBaseTouchComp
{
	GENERATED_BODY()
protected:
	virtual void OnTouchBegin(FVector2D TouchLocation, int32 TouchCount) override;
	virtual void OnTouchReleased(FVector2D TouchLocation, int32 TouchCount) override;
	
	virtual void AddToDebug() override;
	virtual void BeginPlay() override;
	
	/** Returns true If the provided location lies in Hitboxes areas and that button is currently visible
	*@param ButtonsIndexes is the array of index values for all button under the Current hit location
	*/
	bool CheckButtonsBounds(const FVector2D& Location,TArray<int32> &ButtonsIndexes)const  ;
	
	UPROPERTY(BlueprintAssignable,Category="TouchButton")
	FOnButtonStatusChanged OnButtonClicked;
	UPROPERTY(BlueprintAssignable,Category="TouchButton")
	FOnButtonStatusChanged OnButtonReleased;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="TouchButton")
	TArray<FTouchButtonData>TouchButtonDatas;

	



	UFUNCTION(BlueprintCallable,Category="TouchButton")
	void HideAllButtons();
	UFUNCTION(BlueprintCallable,Category="TouchButton")
	void ShowAllButtons();
	
public:
	
	virtual bool ComparePriorties(UBaseTouchComp* OtherComp, const FVector2D& Location) const override;
	FORCEINLINE const TArray<FTouchButtonData>& GetButtonsData()const{return TouchButtonDatas;}
};

