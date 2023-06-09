// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include <GameFramework/FloatingPawnMovement.h>
#include "MyAgent.generated.h"


UCLASS()
class FLOCKINGGAME_API AMyAgent : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyAgent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Init(UStaticMeshComponent* mesh, int id);

	UFloatingPawnMovement* PawnMovement;
	//UStaticMeshComponent* Mesh;

	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
