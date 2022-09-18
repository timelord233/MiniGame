// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/LoginWidget.h"
#include "Components/Button.h"
#include "Components/EditableText.h"
#include "Kismet/GameplayStatics.h"
#include "NimSDK/Include/nim_chatroom.h"
#include "NimSDK/Include/nim_chatroom_def.h"

void ULoginWidget::Login()
{
	UEditableText* EditableTextIpAddress = Cast<UEditableText>(GetWidgetFromName(IPAddressEditableText));
	FString IpAddress = EditableTextIpAddress->GetText().ToString();

	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GWorld, 0);
	PlayerController->ClientTravel(IpAddress, TRAVEL_Absolute);
}

void ULoginWidget::SingleMatch()
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GWorld, 0);
	PlayerController->ClientTravel("/Game/Maps/P_TestMap_AI", TRAVEL_Absolute);
}

void ULoginWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	UButton* ButtonLogin = Cast<UButton>(GetWidgetFromName(LoginButton));
	if (ButtonLogin) 
	{
		ButtonLogin->OnClicked.AddDynamic(this, &ULoginWidget::Login);
	}
	UButton* ButtonSingleMatch = Cast<UButton>(GetWidgetFromName(SingleMatchButton));
	if (ButtonSingleMatch)
	{
		ButtonSingleMatch->OnClicked.AddDynamic(this, &ULoginWidget::SingleMatch);
	}
}
