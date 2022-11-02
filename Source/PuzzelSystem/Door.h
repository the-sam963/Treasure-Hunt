// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class PUZZELSYSTEM_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetShouldMove(bool _ShouldMobe);

private:
	FVector OriginalLocation;
	void OpenDoor(float _DeltaTime);


	UPROPERTY(EditAnywhere)
	bool ShouldMove = false;

	UPROPERTY(EditAnywhere)
		FVector MoveOfset;

	UPROPERTY(EditAnywhere)
		float MoveTime = 4.0f;


};
