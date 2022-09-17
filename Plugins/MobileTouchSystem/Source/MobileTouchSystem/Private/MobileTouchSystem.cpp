/* Copyright (C) 2022 IQRA IQBAL - All Rights Reserved
* This plugin is downloadable from the UE4 Marketplace
*/
#include "MobileTouchSystem.h"


#define LOCTEXT_NAMESPACE "FMobileTouchSystemModule"

void FMobileTouchSystemModule::StartupModule()
{
	
	
}

void FMobileTouchSystemModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMobileTouchSystemModule, MobileTouchSystem)