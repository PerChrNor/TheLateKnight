// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyCPP.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Kismet/KismetMaterialLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Components/SphereComponent.h"
#include "Classes/Kismet/KismetMathLibrary.h"
#include "Engine.h"

#include "Runtime/Engine/Classes/Engine/EngineTypes.h"
// Sets default values
AEnemyCPP::AEnemyCPP()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

		SphereRadiusEnemy = 50.f;// radius of sphere

	CollisionSphereEnemy = CreateDefaultSubobject<USphereComponent>(TEXT("MyEnemySphereComponent")); //naming 
	CollisionSphereEnemy->InitSphereRadius(SphereRadiusEnemy);
	CollisionSphereEnemy->SetCollisionProfileName("Trigger");
	RootComponent = CollisionSphereEnemy; // making this the root component for the enemy

	VisibleEnemy = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EnemyComponent"));
	
	VisibleEnemy->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AEnemyCPP::BeginPlay()
{
	Super::BeginPlay();

		currentWP = 0;// reset the waypoint
	
}

// Called every frame
void AEnemyCPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

		if(WaypointTrigger )

	if(EnemyHealth <= 0) //deletes the enemy when dead
	{
		Destroy();
	}

	FVector targetPosition = FVector(
	waypoints[currentWP]->GetActorLocation().X,
	waypoints[currentWP]->GetActorLocation().Y,
	GetActorLocation().Z
	);// gets the location for waypoint

	FVector direction = targetPosition - GetActorLocation();

	FRotator enemy_lookAt = UKismetMathLibrary::FindLookAtRotation(
		GetActorLocation(), targetPosition// unreal function that allows the object to look and rotate were its going
	);

	FRotator enemy_rotation = FQuat::Slerp(
		GetActorRotation().Quaternion(), enemy_lookAt.Quaternion(),
		DeltaTime * rotSpeed// so it doesnt insta rotate
	).Rotator();

	SetActorRotation(enemy_rotation);
if(direction.Size() < accuracy)
{
	currentWP++;
}
	//if(currentWP >= waypoints.Num())
	
	if(GetWorld())
	
	Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);	
	
	if(currentWP >= 4)// loops until further call
	{
		currentWP = 0;
	}


	if(WaypointTrigger->IsOverlappingActor(Player))// when character is overlapping the waypoint is 4, which is set to be the player
	{
		currentWP = 4;
	}

	SetActorLocation(
	GetActorLocation() + 
	direction.GetUnsafeNormal() * speed * DeltaTime
	); // sets up speed 
if(EnemyHealth <= 0)
{
	this->Destroy();
}

}

