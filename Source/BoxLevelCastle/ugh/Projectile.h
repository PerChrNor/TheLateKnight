// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TESTSTOROPPG_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

		void movement(float DeltaTime);

	UPROPERTY(EditAnywhere)
	float speed{-2500.f}; // speed of projectile

	UPROPERTY(EditAnywhere)
	float timeBeforeDestroy{5.f}; // setting up so it can be destroyed after a certain time
	
	UPROPERTY(EditAnywhere)
	class USphereComponent* CollisionSphere; // collision box
		UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* MyMesh; // mesh

	float SphereRadius; radius of sphere

	float hitScore{0};

	float TimeLived = 0.f; // how long it has lived
			
			UFUNCTION() //unreals overlap function with all its parameters
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult); 

};
