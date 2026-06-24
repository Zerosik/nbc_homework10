// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeath);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCurrentHealthChanged, float, CurrentHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChanged, float, MaxHealth);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PLUGINTESTRUNTIME_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
public:
	UFUNCTION(BlueprintCallable)
	void SetMaxHealth(float newHealth);

	UFUNCTION(BlueprintCallable)
	void TakeDamageValue(float Damage);

	UFUNCTION(BlueprintCallable)
	void Heal(float Amount);

	UFUNCTION(BlueprintCallable)
	float GetHealthRatio() const;
	
	float GetCurrentHealth() const;
	float GetMaxHealth() const;
	
	FOnDeath OnDeath;
	FOnCurrentHealthChanged OnCurrentHealthChanged;
	FOnMaxHealthChanged OnMaxHealthChanged;
private:
	float CurrentHealth = 100.f;
	float MaxHealth = 100.f;
	bool bDead = false;

public:	
		
};
