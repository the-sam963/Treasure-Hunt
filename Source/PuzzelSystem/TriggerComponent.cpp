// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"

UTriggerComponent::UTriggerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();


}


void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* AcceptableActor = GetAcceptableActor();

	if (!Door) return;
	
	if (AcceptableActor)
	{
		Door->SetShouldMove(true);
	}
	else
	{
		Door->SetShouldMove(false);
	}
}


AActor* UTriggerComponent::GetAcceptableActor() const
{
	TArray<AActor*> Actors;
	GetOverlappingActors(Actors);
	for (AActor* Actor : Actors)
	{
		bool hasAcceptableTag = Actor->ActorHasTag(AcceptableActorTag);
		bool hasGrabbed = Actor->ActorHasTag("Grabbed");
		if (hasAcceptableTag && !hasGrabbed)
		{
			return Actor;
		}
	}
	return nullptr;
}