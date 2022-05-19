// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveAliado1.h"
#include "Kismet/GameplayStatics.h"
#include "NaveAereaJugador.h"

ANaveAliado1::ANaveAliado1()
{
	SpeedScale = 0.0f;
}

void ANaveAliado1::BeginPlay()
{
	Super::BeginPlay();

}

void ANaveAliado1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Y += DeltaHeight * SpeedScale;
	RunningTime += DeltaTime;
	SetActorLocation(NewLocation);

	FVector NewLocation2 = GetActorLocation();
	float DeltaForward = (FMath::Cos(RunningTime + DeltaTime) - FMath::Cos(RunningTime));
	NewLocation2.X += DeltaForward * SpeedScale;
	RunningTime += DeltaTime;
	SetActorLocation(NewLocation2);

	const FVector MoveDirection = FVector(DeltaForward, DeltaHeight, 0.0f).GetClampedToMaxSize(1.0f);
	const FVector MoveMent = MoveDirection * SpeedScale * DeltaTime;

	if (MoveMent.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = MoveMent.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(MoveMent,NewRotation, true, &Hit);

		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
			const FVector Deflection = FVector::VectorPlaneProject(MoveMent, Normal2D) * (1.f - Hit.Time);
			RootComponent->MoveComponent(Deflection, NewRotation, true);
		}
	}

	// basic intel: move the monster towards the player
	/**ANaveAereaJugador* avatar = Cast<ANaveAereaJugador>(
		UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	if (!avatar) return;
	FVector toPlayer = avatar->GetActorLocation() -
		GetActorLocation();
	toPlayer.Normalize(); // reduce to unit vector
	// Actually move the monster towards the player a bit
	AddMovementInput(toPlayer, MoveSpeed * DeltaTime);
	// At least face the target
	// Gets you the rotator to turn something
	// that looks in the `toPlayer` direction
	FRotator toPlayerRotation = toPlayer.Rotation();
	toPlayerRotation.Pitch = 0; // 0 off the pitch
	RootComponent->SetWorldRotation(toPlayerRotation);*/

}
