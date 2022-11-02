// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	OriginalLocation = GetActorLocation();
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	OpenDoor(DeltaTime);
}

void ADoor::OpenDoor(float _DeltaTime)
{
	FVector CurrentLocation = GetActorLocation();
	FVector TargetLocation = OriginalLocation + MoveOfset;
	float Speed = FVector::Distance(OriginalLocation, TargetLocation) / MoveTime;

	if (ShouldMove)
	{
		FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, _DeltaTime, Speed);
		SetActorLocation(NewLocation);
	}	
	else
	{
		FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, OriginalLocation, _DeltaTime, Speed);
		SetActorLocation(NewLocation);
	}
}

void ADoor::SetShouldMove(bool _ShouldMobe)
{
	ShouldMove = _ShouldMobe;
}