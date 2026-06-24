// Copyright Epic Games, Inc. All Rights Reserved.

#include "PluginTestEditor.h"

#define LOCTEXT_NAMESPACE "FPluginTestEditorModule"

void FPluginTestEditorModule::StartupModule()
{
	UE_LOG(LogTemp, Warning, TEXT("FPluginTestEditorModule::StartupModule()"));
}

void FPluginTestEditorModule::ShutdownModule()
{
	UE_LOG(LogTemp, Warning, TEXT("FPluginTestEditorModule::ShutdownModule()"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FPluginTestEditorModule, PluginTestEditor)
