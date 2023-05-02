// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FlockingManager.generated.h"

/**
 * 
 */
UCLASS()
class FLOCKINGGAME_API UFlockingManager : public UObject
{
public:
	GENERATED_BODY()

	void Init(UWorld* world, UStaticMeshComponent* mesh);
	void Flock();

private:

	UWorld* World;
	bool initialized;
	TArray<class AAgent*> Agents;
	FVector rule1(int I);
	FVector rule2(int I);
	FVector rule3(int I);
	void limiting_velocity(int I);
	FVector tend_to_place(int I);

};
