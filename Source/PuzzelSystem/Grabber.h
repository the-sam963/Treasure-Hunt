// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"

#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PUZZELSYSTEM_API UGrabber : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
		void Grab();

	UFUNCTION(BlueprintCallable)
		void Release();

private:

	UPROPERTY(EditAnywhere)
		float MaxGrabDistance = 300.0f;

	UPROPERTY(EditAnywhere)
		float GrabberRadius = 50.0f;

	UPROPERTY(EditAnywhere)
		float HoldDistance = 200.0f;
	
	bool GetGrabbableInReach(FHitResult& outHitResult) const;
	UPhysicsHandleComponent* GetPhysicsHandle() const;
};
