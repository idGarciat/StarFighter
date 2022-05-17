// Copyright Epic Games, Inc. All Rights Reserved.


#include "StarFighterGameModeBase.h"
#include "NaveTerrestreEnemiga01.h"
#include "NaveAereaEnemiga_01.h"

void AStarFighterGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	SpawnNaveEnemiga();
}

void AStarFighterGameModeBase::SpawnNaveEnemiga()
{

	UWorld* const World = GetWorld();
	World->SpawnActor<ANaveAereaEnemiga_01>(FVector(400.0f, -400.0f, 200), FRotator::ZeroRotator);
	

}

void AStarFighterGameModeBase::Tick(float DeltaSeconds)
{

	UE_LOG(LogTemp, Warning, TEXT("Creando nave"));
	float newX = rand() % 100 + 1;
	float newY = rand() % 100 + 1;
	UWorld* const World = GetWorld();
	World->SpawnActor<ANaveAereaEnemiga_01>(FVector(newX, newY, 200), FRotator::ZeroRotator);
}

AStarFighterGameModeBase::AStarFighterGameModeBase()
{
	/*UE_LOG(LogTemp, Warning, TEXT("Dentro de constructor en GameModeBase"));
	GetWorld()->SpawnActor<ANaveTerrestreEnemiga01>(FVector::ZeroVector, FRotator::ZeroRotator);*/

	//SpawnNave<ANaveTerrestreEnemiga01>();

}
