// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FirstLessonDemo : ModuleRules
{
	public FirstLessonDemo(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
			"SlateCore",
			"DeveloperSettings",
			"GameplayTags"

		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"FirstLessonDemo",
			"FirstLessonDemo/Variant_Horror",
			"FirstLessonDemo/Variant_Horror/UI",
			"FirstLessonDemo/Variant_Shooter",
			"FirstLessonDemo/Variant_Shooter/AI",
			"FirstLessonDemo/Variant_Shooter/UI",
			"FirstLessonDemo/Variant_Shooter/Weapons"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
