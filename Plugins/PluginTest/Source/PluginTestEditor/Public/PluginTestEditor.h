// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

// 런타임모듈에서는 안쓴 IModuleInterface를 상속받은 헤더. 
// 모듈이 로드, 리로드, 셧다운되는 여러 시점에 호출되는 함수가 있는데, 아직 잘 모르겟음.
class FPluginTestEditorModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
