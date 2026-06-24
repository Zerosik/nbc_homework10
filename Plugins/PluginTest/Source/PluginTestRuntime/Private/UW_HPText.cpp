// Fill out your copyright notice in the Description page of Project Settings.


#include "UW_HPText.h"

#include "Components/TextBlock.h"
#include "HealthComponent.h"

UUW_HPText::UUW_HPText(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

void UUW_HPText::NativeConstruct()
{
	Super::NativeConstruct();
	APawn* Pawn = Cast<APawn>(OwningActor);
	if (IsValid(Pawn) == true)
	{
		UHealthComponent* HealthComponent = Pawn->GetComponentByClass<UHealthComponent>();
		if (HealthComponent)
		{
			HealthComponent->OnCurrentHealthChanged.AddDynamic(this, &UUW_HPText::OnCurrentHPChange);
			HealthComponent->OnMaxHealthChanged.AddDynamic(this, &UUW_HPText::OnMaxHPChange);
			
		}
	}
}

void UUW_HPText::InitializeHPTextWidget(UHealthComponent* HealthComponent)
{
	OnMaxHPChange(HealthComponent->GetMaxHealth());
	OnCurrentHPChange(HealthComponent->GetCurrentHealth());
}

void UUW_HPText::OnMaxHPChange(float InMaxHP)
{
	MaxHPText->SetText(FText::FromString(FString::SanitizeFloat(InMaxHP)));
	
}

void UUW_HPText::OnCurrentHPChange(float InCurrentHP)
{
	CurrentHPText->SetText(FText::FromString(FString::SanitizeFloat(InCurrentHP)));
	
}
