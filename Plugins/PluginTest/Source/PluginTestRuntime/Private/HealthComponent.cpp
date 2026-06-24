// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = MaxHealth;
	bDead = false;

	OnCurrentHealthChanged.Broadcast(CurrentHealth);
	OnMaxHealthChanged.Broadcast(CurrentHealth);
}

void UHealthComponent::SetMaxHealth(float newHealth)
{
	MaxHealth = newHealth;
	CurrentHealth = MaxHealth;
	bDead = false;
	OnCurrentHealthChanged.Broadcast(CurrentHealth);
	OnMaxHealthChanged.Broadcast(MaxHealth);
}

void UHealthComponent::TakeDamageValue(float Damage)
{
	//단순한 회복 테스트를 위해 음수 비활성 조건을 일부러 제거함,
	/*if (bDead || Damage <= 0.0f)
	{
		return;
	}*/

	//CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0.0f, MaxHealth);
	
	CurrentHealth = FMath::Clamp(CurrentHealth - Damage, -100.f, MaxHealth);
	UE_LOG(LogTemp, Warning, TEXT("TakeDamageValue: %f, CurrentHealth : %f"), Damage, CurrentHealth);
	OnCurrentHealthChanged.Broadcast(CurrentHealth);
	if (CurrentHealth <= 0.0f)
	{
		bDead = true;
		OnDeath.Broadcast();
	}
}

void UHealthComponent::Heal(float Amount)
{
	if (Amount <= 0 || bDead)
		return;
	CurrentHealth = FMath::Clamp(CurrentHealth + Amount, 0.f, MaxHealth);
	OnCurrentHealthChanged.Broadcast(CurrentHealth);
}

float UHealthComponent::GetHealthRatio() const
{
	if (MaxHealth <= 0.f)
		return 0.f;
	return CurrentHealth / MaxHealth;
}

float UHealthComponent::GetCurrentHealth() const
{
	return CurrentHealth;
}

float UHealthComponent::GetMaxHealth() const
{
	return MaxHealth;
}


