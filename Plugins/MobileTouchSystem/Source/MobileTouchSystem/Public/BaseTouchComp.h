/* Copyright (C) 2022 IQRA IQBAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/
#pragma once

#include "CoreMinimal.h"

#include "Components/ActorComponent.h"
#include "BaseTouchComp.generated.h"



class ATouchScreenHud;
UCLASS( ClassGroup=(MobileTouch), meta=(BlueprintSpawnableComponent) ,Abstract)
class MOBILETOUCHSYSTEM_API UBaseTouchComp : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBaseTouchComp();
	
	 bool bAlreadyHaveAWidget;
	 // UPROPERTY()
	 // APawn* MyPawn;
	 // UPROPERTY()
	 // APlayerController* MyController;

	
	virtual void OnRegister() override;
	virtual void OnUnregister() override;
	/**
	 *Setup the hit box for this touch component
	 *All the touches that will lie in this hit box will be registered
	 * @param InBoxOrigin is the value of box Origin and clamped 0-1 for each X and Y  
	 * @param InBoxSize is the value of box Size and clamped 0-1 for each X and Y  
	 */
	UFUNCTION(BlueprintCallable,Category="BaseTouchComponent|Configs")
	void SetupHitBox(const FVector2D& InBoxOrigin,const FVector2D& InBoxSize);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	//UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BaseTouchComponent|Configs",meta=(ToolTip="Very small number to adjust YHitbox Correction"))
	//float YHitBoxCorrection = {0.04f};
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BaseTouchComponent|Configs",meta=(ToolTip="Blocks the lower priorty component when this hitbox get touched -- Priorty needs to be set "))
	bool bShouldBlockLowerPriorty;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BaseTouchComponent|Configs")
	bool bShouldDrawDebug;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BaseTouchComponent|Configs",meta=(EditCondition="bShouldBlockLowerPriorty",ToolTip="Higher value means high priority"))
	int32 TouchPriorty{0};
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BaseTouchComponent|Configs",meta=(EditCondition="bShouldDrawDebug"))
	FColor DebugBoxColor =FColor::Green;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BaseTouchComponent|Configs",meta=(EditCondition="bShouldDrawDebug"))
	FString DebugName = TEXT("TouchComponent");
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BaseTouchComponent|Configs",meta=(EditCondition="bShouldDrawDebug"))
	float DebugFingerTipRadius =90.f;
	
	TArray<FVector>Locations;

	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly,Category="BaseTouchComponent|Configs",meta=(ToolTip="Size of the Hitbox for this component , Give values in range of 0-1"))
	FVector2D BoxSize;
	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly,Category="BaseTouchComponent|Configs",meta=(ToolTip="Origin of the Hitbox for this component , Give values in range of 0-1"))
	FVector2D BoxOrigin;

	// true if this hit box is already touched -- false if not currently touched
	bool bIsTouched;
	
	// Remembers the finger index which has touched this comp
	int32 MyCurrentTouchIndex;


	FVector2D TouchStartLocation;
	FVector2D CurrentTouchLocation;
	//UFUNCTION(BlueprintCallable,Category="BaseTouchComponent")
	//virtual void OnTouchPressed(const FVector& Location,ETouchIndex::Type TouchIndex);


	
	float DeltaSeconds;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="BaseTouchComponent")
	bool bCanBeTouched;
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Returns the current angle value between touch start and current touch location
	FORCEINLINE float GetCurrentAngle()const{return CurrentAngle;}
	FORCEINLINE bool GetShouldDrawDebug()const{return bShouldDrawDebug;}
	FORCEINLINE bool GetIsTouched()const{return bIsTouched;}
	FORCEINLINE const FVector2D& GetBoxSize()const{return BoxSize;}
	FORCEINLINE const FVector2D& GetBoxOrigin()const{return BoxOrigin;}
	FORCEINLINE const FColor& GetDebugColor()const{return DebugBoxColor;}
	FORCEINLINE const FString& GetDebugName()const{return DebugName;}
	FORCEINLINE int32 GetPriority()const{return TouchPriorty;}
	FORCEINLINE const FVector2D& GetStartTouchLocation()const{return TouchStartLocation;}
	FORCEINLINE const FVector2D& GetCurrentTouchLocation()const{return CurrentTouchLocation;}
	FORCEINLINE float GetDebugFingerRadius()const{return DebugFingerTipRadius;}



	FVector2D GetSizeXY();
		
	// returns bool value indicate whether to block this input or not
	virtual bool ComparePriorties(UBaseTouchComp* OtherComp,const FVector2D& Location)const;

	UFUNCTION(BlueprintCallable,Category="BaseTouchComponent")
	void ToggleDebug(bool bShouldTurnOn);
	UFUNCTION(BlueprintCallable,Category="BaseTouchComponent")
	void ToggleCanBeTouched(bool bInCanBeTouched);
	
protected:

	// end the current touch
	UFUNCTION(BlueprintCallable,Category="BaseTouchComponent")
	void ForceEndTouch();

	virtual void OnStart();
	// handle the moving functionality when this component is already consuming input
	virtual void OnMoved();
	// handle the End functionality when this component is already consuming input
	virtual void OnEnd();
	
	virtual void OnTouchBegin(FVector2D TouchLocation,int32 TouchCount);
	
	virtual void OnTouchMoved(FVector2D TouchLocation,int32 TouchCount);
	
	virtual void OnTouchReleased(FVector2D TouchLocation,int32 TouchCount);

	virtual void AddToDebug();
	// If sizeY of the game window is 1080 but you are playing at resoution 720
	//then change hit boxes according to resolution
	FVector2D ConvertResToScreen(FVector2D InLoc) ;

	UPROPERTY()
	ATouchScreenHud* MyHud;

	float GetScale()const;
	
	// Angle between touch Start and CurrentTouch location
	float CurrentAngle;

	
	// Set owner Controller and Pawn Pointer
	//void SetupOwners();
	FVector2D NormalizeScreenSize(const FVector2D& InScreenLocation) const;

	virtual bool CheckIsInBounds(const FVector2D& Location)const;
	
	//Calculate the angle between start and current touch locations
	float CalculateAngle(float Offset = 90.f)const;
	float CalculateAngle(const FVector2D& StartLocation,const FVector2D& CurrentLocationfloat ,float Offset = 90.f)const;
	bool CheckForPeriorty(const FVector2D& Location);
private:
	
	
};
