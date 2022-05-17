// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System;
using System.IO;

public classDojoChainForUnreal : ModuleRules
{
    public DojoChainForUnreal(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

        PrivateDependencyModuleNames.AddRange(new string[] { });

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
        LoadDojoChain(Target);
    }

    public bool LoadDojoChain(ReadOnlyTargetRules Target)
    {
        Console.WriteLine("ModulePath: " + ModulePath);
        Console.WriteLine("ThirdPartyPath: " + ThirdPartyPath);

        bool isLibrarySupported = false;
        if ((Target.Platform == UnrealTargetPlatform.Win64) || (Target.Platform == UnrealTargetPlatform.Win32))
        {
            isLibrarySupported = true;
            string PlatformString = (Target.Platform == UnrealTargetPlatform.Win64) ? "x64" : "x86";
            string LibrariesPath = Path.Combine(ThirdPartyPath, "DojoChain", "Library");

            Console.WriteLine("LibrariesPath: " + LibrariesPath);

            string addtiveLib = Path.Combine(LibrariesPath, "DojoChain-sdk." + PlatformString + ".lib");
            Console.WriteLine("AddtiveLibary: " + addtiveLib);
            PublicAdditionalLibraries.Add(addtiveLib);
        }
        if (isLibrarySupported)
        {
            // Include path
            string strIncPath = Path.Combine(ThirdPartyPath, "DojoChain", "Include");
            Console.WriteLine("Include Path: " + strIncPath);
            PublicIncludePaths.Add(strIncPath);
        }
        Definitions.Add(string.Format("WITH_Dojo_CHAIN_BINDING=£û0£ý", isLibrarySupported ? 1 : 0));
        return isLibrarySupported;
    }

    private string ModulePath
    {
        get
        {
            return ModuleDirectory;
        }
    }

    private string ThirdPartyPath
    {
        get
        {
            return Path.GetFullPath(Path.Combine(ModulePath, "../../ThirdParty"));
        }
    }
}
