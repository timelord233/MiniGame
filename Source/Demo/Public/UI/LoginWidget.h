// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LoginWidget.generated.h"

/**
 * 
 */
UCLASS()
class DEMO_API ULoginWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly)
	FName LoginButton;

	UPROPERTY(EditDefaultsOnly)
	FName IPAddressEditableText;

	UPROPERTY(EditDefaultsOnly)
	FName SingleMatchButton;
	
	UFUNCTION()
	void Login();

	UFUNCTION()
	void SingleMatch();

	virtual void NativeOnInitialized() override;
};
