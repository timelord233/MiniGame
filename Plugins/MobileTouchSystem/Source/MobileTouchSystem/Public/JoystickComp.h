/* Copyright (C) 2022 IQRA IQBAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/
#pragma once

#include "CoreMinimal.h"
#include "BaseTouchComp.h"
#include "JoystickComp.generated.h"


USTRUCT(BlueprintType)
struct FJoyStickWidgetInfo
{
	GENERATED_BODY()

	FJoyStickWidgetInfo():ThumbTexture(nullptr),BGTexture(nullptr)
	{
		ActiveOpacity = 1.f;
		InActiveOpacity = 0.4f;
		BackgroundSize = FVector2D(256.f,256.f);
		ThumbSize = FVector2D(64.f,64.f);
		Tint = FColor::White;
		bShouldRecenter = false;
		WidgetLocation = FVector2D(.15f,.8f);
	}
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="JoyStickWidgetInfo")
	class UTexture2D* ThumbTexture;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="JoyStickWidgetInfo")
	class UTexture2D* BGTexture;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="JoyStickWidgetInfo")
	float ActiveOpacity;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="JoyStickWidgetInfo")
	float InActiveOpacity;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="JoyStickWidgetInfo")
	bool bShouldRecenter;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="JoyStickWidgetInfo")
	FVector2D BackgroundSize;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="JoyStickWidgetInfo")
	FVector2D ThumbSize;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="JoyStickWidgetInfo")
	FLinearColor Tint;
	
	// Location should be from 0-1 range for X and Y
	// where (0,0) is top left corner and (1,1) is bottom right corner of screen
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="JoyStickWidgetInfo")
	FVector2D WidgetLocation;
	
	
};


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnValueChanged,float,Value);


UCLASS(ClassGroup=(MobileTouch),meta=(BlueprintSpawnableComponent))
class MOBILETOUCHSYSTEM_API UJoystickComp : public UBaseTouchComp
{
	GENERATED_BODY()
private:


	// If bool Should Recenter is true then this value be used for Joystick Center in HUD
	FVector2D JoyStickCenter;
	/**
	 *	Adjust the start location if needed
	 *  If we exceeded the drag limit then update
	 *  start location is needed to update to keep DragDistance 
	 */
	void AdjustStartLocation();
	FVector2D CurrentXYValue;
	float CalculateXYValueAndAngle(FVector2D& OutRefXY);
	
public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Joystick Component",meta=(ClampMin="0",ClampMax="1"))
	float JoystickDragLimit;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Joystick Component")
	bool bShouldInvertX = false;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Joystick Component")
	bool bShouldInvertY = false;
	
	UJoystickComp();
	 UPROPERTY(BlueprintAssignable,Category="Joystick Component")
	 FOnValueChanged XValueChanged;
	 UPROPERTY(BlueprintAssignable,Category="Joystick Component")
	 FOnValueChanged YValueChanged;


	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Joystick Component")
	FJoyStickWidgetInfo MyJoyStickWidgetInfo;
	
    UFUNCTION(BlueprintCallable,Category="Joystick Component")
    void AddJoystickWidget(const FJoyStickWidgetInfo& JoyStickWidgetInfo);

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// If Bool Should recenter for the joystick Widget is true
	// then Returns the joystick center location (Touch start location without adjustment)
	FORCEINLINE const FVector2D& GetJoystickCenter()const{return JoyStickCenter;}
	// Returns the current X,Y Value of the joystick
	FORCEINLINE FVector2D GetCurrentXYValue()const{return CurrentXYValue;}
	
	//FORCEINLINE bool GetIsTouched()const{return bIsTouched;}
	FORCEINLINE const FJoyStickWidgetInfo& GetWidgetInfo()const {return MyJoyStickWidgetInfo;}
protected:
	virtual void BeginPlay() override;
	virtual  void OnTouchBegin(FVector2D TouchLocation, int32 TouchCount) override;
	virtual  void OnTouchMoved(FVector2D TouchLocation, int32 TouchCount) override;
	virtual  void OnTouchReleased(FVector2D TouchLocation, int32 TouchCount) override;
	virtual void OnStart() override;
	//virtual void OnTouchPressed(const FVector& Location, ETouchIndex::Type TouchIndex) override;
};
