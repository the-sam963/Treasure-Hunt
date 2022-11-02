// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Door.h"
#include "Components/BoxComponent.h"
#include "TriggerComponent.generated.h"

/**
 *
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PUZZELSYSTEM_API UTriggerComponent : public UBoxComponent
{
	GENERATED_BODY()

public:
	UTriggerComponent();


protected:
	virtual void BeginPlay() override;

public:
	void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction);


private:
	AActor* GetAcceptableActor() const;


	UPROPERTY(EditAnywhere)
		FName AcceptableActorTag;

	UPROPERTY(EditAnywhere)
		ADoor* Door;
};
