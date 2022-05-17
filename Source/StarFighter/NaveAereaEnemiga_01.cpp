// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveAereaEnemiga_01.h"

void ANaveAereaEnemiga_01::Tick(float DeltaSeconds)
{
	srand(time(NULL));

	MovingTX = rand() % 20 - 10;
	MovingTY = rand() % 20 - 10;

	MoveSpeed = 20;


	const FVector MoveDirection = FVector(MovingTX, MovingTY, 0.0f);
	const FVector Movement = MoveDirection * MoveSpeed * DeltaSeconds;

	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();

		FHitResult Hit(1.0f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
	}


/*	    srand(time(nullptr));
		UE_LOG(LogTemp, Warning, TEXT("Creando nave"));
		float newX = rand() % 100 + 1;
		float newY = rand() % 100 + 1;
		UWorld* const World = GetWorld();
		World->SpawnActor<ANaveAereaEnemiga_01>(FVector(newX, newY, 200), FRotator::ZeroRotator);
		*/
}

void ANaveAereaEnemiga_01::duplicate(AActor* original)
{

}
