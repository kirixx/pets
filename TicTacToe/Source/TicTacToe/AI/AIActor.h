// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CAIHandler.h"
#include "Game/CGameManager.h"
#include "AIActor.generated.h"

UCLASS()
class TICTACTOE_API AAIActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAIActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool IsPlayerVSAi;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool IsAIVSAI;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	CAIHandler	 mAIHandler;
};
