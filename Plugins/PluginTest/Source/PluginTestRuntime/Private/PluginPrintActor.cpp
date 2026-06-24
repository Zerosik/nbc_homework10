// Fill out your copyright notice in the Description page of Project Settings.

#include "PluginPrintActor.h"

APluginPrintActor::APluginPrintActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APluginPrintActor::BeginPlay()
{
	Super::BeginPlay();
}

void APluginPrintActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
