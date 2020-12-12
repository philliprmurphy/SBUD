// Fill out your copyright notice in the Description page of Project Settings.


#include "UFO.h"

// Sets default values
AUFO::AUFO()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	pitch = 0.f;
	yaw = 1.f;
	roll = 0.f;

	ySpeed = 2.f;
	yDistance = 80.f;
	accumulator = 0.f;

	originalLocation = this->GetActorLocation();
}

// Called when the game starts or when spawned
void AUFO::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUFO::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Rotating it
	FRotator newRotation = FRotator(pitch, yaw, roll);
	FQuat quatRotation = FQuat(newRotation);
	AddActorLocalRotation(quatRotation, false, 0, ETeleportType::None);

	// Movement
	accumulator += GetWorld()->GetDeltaSeconds();
	float alpha = FMath::Sin(accumulator * ySpeed);
	float newDelta = FMath::Lerp(0.f, yDistance, alpha);
	FVector currLocation = this->GetActorLocation();
	currLocation.Y = originalLocation.Y + newDelta;
	this->SetActorLocation(currLocation);

}

