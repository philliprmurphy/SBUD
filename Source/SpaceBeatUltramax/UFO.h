// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UFO.generated.h"

UCLASS()
class SPACEBEATULTRAMAX_API AUFO : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUFO();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Rotation")
		float pitch;

	UPROPERTY(EditAnywhere, Category = "Rotation")
		float yaw;

	UPROPERTY(EditAnywhere, Category = "Rotation")
		float roll;

	UPROPERTY(EditAnywhere, Category = "Movement")
		float ySpeed;

	UPROPERTY(EditAnywhere, Category = "Movement")
		float yDistance;

	float accumulator;
	FVector originalLocation;

};
