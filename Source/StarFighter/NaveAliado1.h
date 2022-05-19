// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveAerea.h"
#include "NaveAliado1.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API ANaveAliado1 : public ANaveAerea
{
	GENERATED_BODY()

public:

	ANaveAliado1();

	virtual void BeginPlay() override;
	void Tick(float DeltaSeconds);

	UPROPERTY(Editanywhere)
		float SpeedScale;

	float RunningTime;
};
