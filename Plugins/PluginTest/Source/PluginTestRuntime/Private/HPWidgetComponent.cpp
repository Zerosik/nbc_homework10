// Fill out your copyright notice in the Description page of Project Settings.


#include "HPWidgetComponent.h"

#include "HealthComponent.h"
#include "UW_HPText.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

void UHPWidgetComponent::InitWidget()
{
	Super::InitWidget();
	
	// 일부러 위젝 추가와 초기화코드등을 여기로 옮겨서 플러그인내에서 컴포넌트와 UI다 추가해보도록 시도함
	// 결과적으로 캐릭터에 HealthComponent, HPWidgetComponent추가하는것만으로 구현이 되는듯함.
	
	// build.cs에서 플러그인의 런타임모듈에서만 "UMG"추가헀으나 정삭적용함.
	// 모듈 로드도 기능을 사용하는 특정 모듈에서만 로드하면됨
	
	UHealthComponent* HealthComponent = GetOwner()->GetComponentByClass<UHealthComponent>();
	UUW_HPText* HPTextWidget = Cast<UUW_HPText>(GetWidget());
	if (IsValid(HPTextWidget))
	{
		HPTextWidget->SetOwningActor(GetOwner());
		HPTextWidget->InitializeHPTextWidget(HealthComponent);
	}
}

void UHPWidgetComponent::TickComponent(float DeltaTime, enum ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if (IsValid(GetWidget()) == true)
	{
		FVector WidgetComponentLocation = GetComponentLocation();
		FVector LocalPlayerCameraLocation = UGameplayStatics::GetPlayerCameraManager(this, 0)->GetCameraLocation();
		SetWorldRotation(UKismetMathLibrary::FindLookAtRotation(WidgetComponentLocation, LocalPlayerCameraLocation));
	}
}
