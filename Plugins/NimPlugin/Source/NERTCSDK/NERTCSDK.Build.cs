using System;
using System.Collections.Generic;
using System.IO;
using UnrealBuildTool;

public class NERTCSDK : ModuleRules
{

    public NERTCSDK(ReadOnlyTargetRules Target) : base(Target)
    {
        // ModuleType.External tells the engine not to look for (or compile) any source code.
        Type = ModuleType.External;
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        // add the header files for reference
        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Include"));

        // AWS SDK relies on certain identifiers being undefined, so this produces warnings
        // Unreal engine treats certain warnings as errors and fails the build
        // this line will disable those warnings:
        bEnableUndefinedIdentifierWarnings = false;

        // Dynamically linking to the SDK requires us to define the
        // USE_IMPORT_EXPORT symbol for all build targets using the
        // SDK. Source: https://github.com/aws/aws-sdk-cpp/blob/main/Docs/SDK_usage_guide.md#build-defines
        PublicDefinitions.Add("USE_IMPORT_EXPORT");


        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            PublicDefinitions.Add("USE_WINDOWS_DLL_SEMANTICS");
        }

        // do this for each lib and dll
        string LibraryPath = Path.Combine(ModuleDirectory, "Binaries", Target.Platform.ToString());

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            PublicAdditionalLibraries.Add(Path.Combine(LibraryPath, "nertc_sdk.lib"));
            string[] dllNames = new string[] {
                "nertc_sdk.dll",
                "NERtcnn.dll",
                "protoopp.dll",
                "SDL2.dll",
                "SDL2_image.dll",
                "SDL2_ttf.dll",
                "zlib1.dll",
                "NERtcPersonSegment.dll",
                "NERtcFaceDetect.dll",
                "libwebp-7.dll",
                "libtiff-5.dll",
                "libpng16-16.dll",
                "libjpeg-9.dll",
                "libfreetype-6.dll"
            };
            foreach (string dllName in dllNames)
            {
                RuntimeDependencies.Add("$(BinaryOutputDir)/" + dllName, Path.Combine(LibraryPath, dllName));
            }
        }

        PrivateDependencyModuleNames.AddRange(
        new string[] {
                    "CoreUObject",
                    "Engine",
                    "Slate",
                    "SlateCore",   
        });
    }
}