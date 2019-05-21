// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Runtime/Engine/Classes/Engine/TriggerVolume.h"

#include "EnemyCPP.generated.h"

UCLASS()
class BOXLEVELCASTLE_API AEnemyCPP : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyCPP();

UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* VisibleEnemy;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	    class  USphereComponent* CollisionSphereEnemy;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true")) // array of waypoints the enemy gonna go through
		TArray<AActor *> waypoints;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))// how close and presice the object hitbox is
		float accuracy;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true")) // changing the speed with this variable
		float speed;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true")) // the speed of rotation so it doesnt inta rotate, that would look wierd
		float rotSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")// liv
		float EnemyHealth = 100;
		float SphereRadiusEnemy;
	UPROPERTY(EditAnywhere, BlueprintReadWrite , Category = "CurrentWaypoint") // which waypoint it is going to
		int currentWP = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite , Category = "Trigger")// the trigger box that activate when the player overlaps
	ATriggerVolume* WaypointTrigger;

	AActor* Player;
};
