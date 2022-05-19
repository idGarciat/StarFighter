
// Fill out your copyright notice in the Description page of Project Settings.

#include "Timer.h"
#include "NaveAereaEnemiga_01.h"
#include "TimerManager.h"

// Sets default values
ATimer::ATimer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATimer::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &ATimer::repetir, 10.0f, true, 5.0f);
	
}

// Called every frame
void ATimer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATimer::repetir()
{
	//srand(time(nullptr));
	UE_LOG(LogTemp, Warning, TEXT("Creando nave"));
	float newX = rand() % 100 + 1;
	float newY = rand() % 100 + 1;
	UWorld* const World = GetWorld();
	World->SpawnActor<ANaveAereaEnemiga_01>(FVector(newX, newY, 200), FRotator::ZeroRotator);

}

