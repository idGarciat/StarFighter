// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveAerea.h"
#include "NaveAereaEnemiga_01.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API ANaveAereaEnemiga_01 : public ANaveAerea
{
	GENERATED_BODY()

private:
	uint32 bCanFire : 1;
	FTimerHandle TimerHandle_ShotTimerExpired;

public:

	ANaveAereaEnemiga_01();

	FTimerHandle MemberTimerHandle;

	virtual void BeginPlay() override;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		FVector GunOffset;//es como la distancia que aparecera la bala
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		float FireRate; //propiedad que hara cuanto tardara en despareccere a bala
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
		float Speed;

	void Tick(float DeltaSeconds);

	float MovingTX;
	float MovingTY;

	void FireEnemigo();
	void FireShotEnemigo(FVector FireDirectionEnemigo);
    void ShotTimerExpired();
	
	//void duplicate(AActor* original);
};
