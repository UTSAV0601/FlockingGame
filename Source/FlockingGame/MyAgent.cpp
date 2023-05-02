// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAgent.h"

// Sets default values
AMyAgent::AMyAgent()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>("PawnMovement");
}

// Called when the game starts or when spawned
void AMyAgent::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyAgent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
//void AMyAgent::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
	//Super::SetupPlayerInputComponent(PlayerInputComponent);


//}

void AMyAgent::Init(UStaticMeshComponent* mesh, int id)
{
	UE_LOG(LogTemp, Warning, TEXT("Agent initialized."));
	//Mesh->SetStaticMesh(mesh->GetStaticMesh());
}