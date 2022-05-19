// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveAereaEnemiga_01.h"
#include "NaveAereaJugador.h"
#include "Kismet/GameplayStatics.h"
#include "Proyectil.h"

ANaveAereaEnemiga_01::ANaveAereaEnemiga_01()
{
	GunOffset = FVector(90.f, 0.f, 0.f); //para la distancia de aparicion de la bala
	FireRate = 2.0f;
	bCanFire = true;
}

void ANaveAereaEnemiga_01::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &ANaveAereaEnemiga_01::FireEnemigo, 5.0f, true, 5.0f);

}

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

	// basic intel: move the monster towards the player
	ANaveAereaJugador* avatar = Cast<ANaveAereaJugador>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	if (!avatar)
	{
		return;

	}
	FVector toPlayer = avatar->GetActorLocation() - GetActorLocation();
	toPlayer.Normalize();

	// reduce to unit vector
	// Actually move the monster towards the player a bit

	//AddMovementInput(toPlayer, MoveSpeed * DeltaSeconds);


	// At least face the target
	// Gets you the rotator to turn something
	// that looks in the `toPlayer` direction

	FRotator toPlayerRotation = toPlayer.Rotation();
	toPlayerRotation.Pitch = 0; // 0 off the pitch
	RootComponent->SetWorldRotation(toPlayerRotation);
/*	    srand(time(nullptr));
		UE_LOG(LogTemp, Warning, TEXT("Creando nave"));
		float newX = rand() % 100 + 1;
		float newY = rand() % 100 + 1;
		UWorld* const World = GetWorld();
		World->SpawnActor<ANaveAereaEnemiga_01>(FVector(newX, newY, 200), FRotator::ZeroRotator);
		*/
}

void ANaveAereaEnemiga_01::FireEnemigo()
{
	//UE_LOG(LogTemp, Warning, TEXT("Presionaste una tecla Rayo"));//solo muestra en el registro de salida

	bCanFire = true;
	const FVector FireDirectionEnemigo = FVector(MovingTX, MovingTY, 0.0f).GetClampedToMaxSize(1.0f);

	FireShotEnemigo(FireDirectionEnemigo);
}

void ANaveAereaEnemiga_01::FireShotEnemigo(FVector FireDirectionEnemigo)
{
	
	if (bCanFire == true)
	{
		UE_LOG(LogTemp, Warning, TEXT("Presionaste una tecla Rayo"));

		if (FireDirectionEnemigo.SizeSquared() > 0.0f)
		{
			ANaveAereaJugador* avatar = Cast<ANaveAereaJugador>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
			if (!avatar)
			{
				return;

			}
			FVector toPlayer = avatar->GetActorLocation() - GetActorLocation();

			const FRotator FireRotation = toPlayer.Rotation();
			const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				World->SpawnActor<AProyectil>(SpawnLocation, FireRotation);
			}

			bCanFire = false;
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ANaveAereaEnemiga_01::ShotTimerExpired, FireRate);


		}
	}

}

void ANaveAereaEnemiga_01::ShotTimerExpired()
{
	bCanFire = true;
}

/**void ANaveAereaEnemiga_01::duplicate(AActor* original)
{

}*/
