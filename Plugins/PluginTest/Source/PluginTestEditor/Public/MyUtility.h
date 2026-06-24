// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyUtility.generated.h"

/**
 * 에디터 모듈(플러그인)은 말그대로 에디터=개발시점만 로드되고 사용하는 모듈임
 * 개발중에 테스트용 기능들을 에디터모듈에 넣고(아이템,지형편집이나 출력등)사용하면
 * 차후에 배포시 해당기능들이 빠지도록 할 수 있다고하나, 정확하게 어떻게 사용하는지는 더 알아보아야함.
 */
UCLASS()
class PLUGINTESTEDITOR_API UMyUtility : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	static void PrintHelloWorld();
};
