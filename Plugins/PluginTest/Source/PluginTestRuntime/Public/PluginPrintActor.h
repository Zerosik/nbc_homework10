// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PluginPrintActor.generated.h"

UCLASS()
class PLUGINTESTRUNTIME_API APluginPrintActor : public AActor
{
	GENERATED_BODY()

public:
	APluginPrintActor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
