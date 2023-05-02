// Fill out your copyright notice in the Description page of Project Settings.


#include "FlockingManager.h"
#define AGENT_COUNT 10
#include "Agent.h"

void UFlockingManager::Init(UWorld* world, UStaticMeshComponent* mesh) 
{
	UE_LOG(LogTemp, Warning, TEXT("MANAGER INIT"));

    World = world;
    float incr = (PI * 2.f) / AGENT_COUNT;
    for (int i = 0; i < AGENT_COUNT; i++) 
    {
        if (World != nullptr) 
        {
            FRotator rotation = FRotator();

            FVector location = FVector();
            location.X = FMath::Sin(incr * i) * 150.f;
            location.Z = FMath::Cos(incr * i) * 150.f;

            AAgent* agent = World->SpawnActor<AAgent>(location, rotation);
            agent->Init(mesh, i);
            Agents.Add(agent);
        }
    }

    initialized = true;
}

void UFlockingManager::Flock() 
{
    FVector v1, v2, v3;
    for (int b = 0; b < Agents.Num(); b++)
    {
        v1 = rule1(b);
        v2 = rule2(b);
        v3 = rule3(b);

        Agents[b]->Velocity = Agents[b]->Velocity + v1 + v2 +v3;
        //Agents[b]->SetActorLocation(Agents[b]->GetActorLocation() + Agents[b]->Velocity);
        limiting_velocity(b);
        //tend_to_place(b);
      
    }

}

// To calculate the center of mass of all the boids and move the all the boids to that location
FVector UFlockingManager::rule1(int I)
{
    FVector pc;
    for (int j = 0; j < AGENT_COUNT; j++)
    {
       if (j != I)
         {
             pc = pc + Agents[j]->GetActorLocation(); // GetActorLocation is used in unreal game engine to fetch the position of an object
         }
    }

 
    pc = pc / (Agents.Num() - 1);

    return (pc - Agents[I]->GetActorLocation() )/ 100;

}
// To check the collision between two boids say if distance between two boids is less than 100 then move it as far away again as it already is
FVector UFlockingManager::rule2(int I)
{
    FVector c = FVector(0.0f);
    for (int b = 0; b < Agents.Num(); b++)
    {
        if (b != I)
        {
            if (FVector::Dist(Agents[b]->GetActorLocation(), Agents[I]->GetActorLocation()) < 100) // unreal has inbuilt function to calculate magnitude between two boids called as FVector::Dist
            {
                c = c - (Agents[b]->GetActorLocation() - Agents[I]->GetActorLocation());
            }
        }

    }
    return c;

}

FVector UFlockingManager::rule3(int I)
{
    FVector pv;
    for (int b = 0; b < Agents.Num(); b++)
    {
        if (b != I)
        {
            pv = pv + Agents[b]->Velocity;
        }

    }
    pv = pv / (Agents.Num() - 1);
    return (pv - Agents[I]->Velocity) / 8;

}
// to limit the velocity of the boids considering animals cannot go that fast
void UFlockingManager::limiting_velocity(int I)
{
    int v = 5;
    FVector lv;

    if (Agents[I]->Velocity.Size() > v)
    {
        Agents[I]->Velocity = (Agents[I]->Velocity / Agents[I]->Velocity.Size()) * v;
    }
    return;
}

FVector UFlockingManager::tend_to_place(int I)
{
    FVector place = FVector(0 , 0 , 0);
    return ((place - Agents[I]->GetActorLocation()) / 100);

}