// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PluginTestRuntime : ModuleRules
{
	public PluginTestRuntime(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"UMG"
		});
	}
}
