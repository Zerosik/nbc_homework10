// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PluginTestEditor : ModuleRules
{
	public PluginTestEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core"
		});

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"CoreUObject",
			"Engine",
			"PluginTestRuntime",
			"Slate",
			"SlateCore",
			"UnrealEd"
		});
	}
}
