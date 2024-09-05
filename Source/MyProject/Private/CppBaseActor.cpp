// Fill out your copyright notice in the Description page of Project Settings.


#include "CppBaseActor.h"

#include "Engine/Engine.h"

// Sets default values
ACppBaseActor::ACppBaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//Данное определение существует для оптимизации, исходя из чего можно сделать вывод, 
	// что там где нет необходимости использовать актора каждый tick его структура инициализируется, как false.
	PrimaryActorTick.bCanEverTick = true;

	//инициализация Mesh - Данная функция шаблонная, в качестве параметра шаблона они принимает тип создаваемого подобъекта и возвращает указатель на 
	// созданный подобъект. 
	//Также функция принимает два аргумента – это имя компонента (FName) и булевая – назначается ли компонент наследникам или он будет только у данного класса
	//истина – то компонент будет только у данного класса
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh"); 


	//SetRootComponent - Данная функция установит объявленный нами UStaticMeshComponent в качестве корневого компонента класса. 
	// Корневой компонент определяет трансформацию (местоположение, вращение, масштаб) этого Актора в мире, 
	// все остальные компоненты должны быть как-то привязаны к нему.
	SetRootComponent(Mesh);
}

// Called when the game starts or when spawned
void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();
	//ShowInformation();
	ShowActorInformation();
		
}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACppBaseActor::ShowInformation()
{
	UE_LOG(LogTemp, Display, TEXT("CppBase is here"));
	UE_LOG(LogTemp, Warning, TEXT("CppBase класс ошибся"));
	UE_LOG(LogTemp, Error, TEXT("CppBase тут иероглифыe"));	

	UE_LOG(LogTemp, Display, TEXT("EnemyNum: %d"), EnemyNum);
	UE_LOG(LogTemp, Display, TEXT("CurrentHealth: %f"), CurrentHealth);
	UE_LOG(LogTemp, Display, TEXT("IsAlive: %i"), IsAlive);
	UE_LOG(LogTemp, Display, TEXT("PlayerName: %s"), *PlayerName);

	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Black, PlayerName, true, FVector2D(2.0f, 2.0f));
}

void ACppBaseActor::ShowActorInformation()
{
	FString Name = !PlayerName.IsEmpty() ? PlayerName : GetName();	
	UE_LOG(LogTemp, Display, TEXT("PlayerName: %s"), *Name);
	//UE_LOG(LogTemp, Display, TEXT("PlayerName: %s"), *PlayerName);

	UE_LOG(LogTemp, Display, TEXT("EnemyNum: %d"), EnemyNum);
	UE_LOG(LogTemp, Display, TEXT("IsAlive: %i"), IsAlive);
}

