// ModuleAndPlugin.build.cs

using UnrealBuildTool;

public class ModuleAndPlugin : ModuleRules
{
	public ModuleAndPlugin(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput",
			
			//모듈 추가
			"ModuleTest",
			
			//플러그인 모듈 추가
			"PluginTestRuntime", "PluginTestEditor"
		});
	}
}
