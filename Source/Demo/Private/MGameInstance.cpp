// Fill out your copyright notice in the Description page of Project Settings.


#include "MGameInstance.h"
#include "Blueprint/UserWidget.h"

UMGameInstance::UMGameInstance(const FObjectInitializer& ObjectInitializer)
{

}

void UMGameInstance::OnStart()
{

}

void UMGameInstance::Shutdown()
{
	rtc_engine_->release(true);
	destroyNERtcEngine((void*&)rtc_engine_);
	rtc_engine_ = nullptr;
}

void UMGameInstance::InitNERTCSDK()
{
	rtc_engine_ = (nertc::IRtcEngineEx*)createNERtcEngine();
	nertc::NERtcEngineContext rtc_engine_context_ = {};
	rtc_engine_context_.app_key = "08af4db5196f9bb9e781c4a31ba82374";
	rtc_engine_context_.log_dir_path = TCHAR_TO_UTF8(*FPaths::ProjectSavedDir());
	auto ret = rtc_engine_->initialize(rtc_engine_context_);
	if (ret != nertc::kNERtcNoError)
	{
		UE_LOG(LogTemp, Log, TEXT("Init Failed"));
		return ;
	}
	rtc_engine_->joinChannel(nullptr, "Test", 0);
}

