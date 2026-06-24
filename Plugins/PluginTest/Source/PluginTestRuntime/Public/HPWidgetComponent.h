// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "HPWidgetComponent.generated.h"

class UUW_HPText;
/**
 * 
 */
UCLASS()
class PLUGINTESTRUNTIME_API UHPWidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()
	
public:
	virtual void InitWidget() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bHPWidgetEnabled = true;
};
