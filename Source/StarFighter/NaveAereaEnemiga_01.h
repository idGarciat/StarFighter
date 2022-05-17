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
public:
	float MovingTX;
	float MovingTY;
	void Tick(float DeltaSeconds);
	void duplicate(AActor* original);
};
