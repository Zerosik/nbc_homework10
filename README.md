# nbc_homework10
모듈과 플러그인 만들어보기


# 개인 블로그 정리 #
### https://zerosik00.tistory.com/94 ###

# 개인 블로그 모듈 추가 과정 정리 #
### https://zerosik00.tistory.com/95 ###

# 과제에서 시도한것: #
플러그인을 알아보는중 모듈은 에디터 모듈과 런타임 모듈을 설정하여,
특정시점에서만 로드되는 모듈을 분리하여 만들 수 있음을 알았음.

이를 이용해 체력기능을 런타임 모듈에 구현하여 분리하는걸 시도하였고,
간단한 출력함수를 에디터 모듈에 구현하여 배포시 코드가 제외되는걸 의도했으나
컴퓨터의 한계로 배포버전으로 테스트하진 못하였음.

캐릭터의 체력과 관련된것 (체력 관리 컴포넌트, HP출력을 위한 위젯 컴포넌트)를 플러그인의 모듈에 분리하여
플러그인의 모듈내부에서 최대한 구현하고 주 게임 모듈에서는 API사용하듯 처리하도록 하는 구조를 의도함.

3인칭 템플릿 캐릭터에 컴포넌트를 추가하고 컴포넌트의 기능은 전부 모듈에서 처리함


# 추가 과정 #

플러그인 추가는 에디터에서 제공하는 기능을 통해 추가하였고,
모듈 추가는 언리얼 공식문서를 따라 추가 및 설정하였음.

하나의 플러그인 내부에 에디터/런타임 모듈을 따로 두기 위해 모듈을 추가하고,
uplugin내 Modules 부분을 수정함

  	"Modules": [
		{
			"Name": "PluginTestRuntime",
			"Type": "Runtime",
			"LoadingPhase": "PreDefault"
		},
		{
			"Name": "PluginTestEditor",
			"Type": "Editor",
			"LoadingPhase": "PreDefault"
		}
	]




기존에 프로젝트, 강의 등에서 사용한 HealthComponent, HPWidgetComponent, HPTextWidget등을 플러그인의 런타임 모듈에 추가함

<img width="284" height="481" alt="image" src="https://github.com/user-attachments/assets/54fadff1-5bea-401e-9810-fea00413e86a" />

3인칭 템플릿 캐릭터에 Include 추가하고

```
#include "HealthComponent.h"
#include "HPWidgetComponent.h"
#include "ModuleAndPluginCharacter.generated.h"
....


public:
UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
TObjectPtr<UHealthComponent> HealthComponent;

UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
TObjectPtr<UHPWidgetComponent> HealthWidgetComponent;
```
구현부에 초기화 추가


```
AModuleAndPluginCharacter::AModuleAndPluginCharacter()
{
  ....
  // 런타임모듈에 추가한 컴포넌트들을 캐릭터에 추가함.
  // 출력되는 UI용 WBP도 플러그인의 Content폴더에 추가하여 사용하였음.
  HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
  HealthWidgetComponent = CreateDefaultSubobject<UHPWidgetComponent>(TEXT("HPWidgetComponent"));
  HealthWidgetComponent->SetupAttachment(GetRootComponent());
  HealthWidgetComponent->SetRelativeLocation(FVector(0.f, 0.f, 100.f));
  HealthWidgetComponent->SetWidgetSpace(EWidgetSpace::World);
  HealthWidgetComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
  //에디터플러그인의 스태틱합수를 호출해 출력해보기
  UMyUtility::PrintHelloWorld();
}
```


