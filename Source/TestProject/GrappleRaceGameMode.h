// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GrappleRaceGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TESTPROJECT_API AGrappleRaceGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

	UPROPERTY(EditAnywhere, Category="Generation")
	TSubclassOf<class ABlock> block;
	UPROPERTY(EditAnywhere, Category = "Generation", meta = (ClampMin = "10", ClampMax = "50", UIMin = "10", UIMax = "50"))
	int width;
	UPROPERTY(EditAnywhere, Category = "Generation", meta = (ClampMin = "10", ClampMax = "50", UIMin = "10", UIMax = "50"))
	int height;
	UPROPERTY(EditAnywhere, Category = "Generation", meta = (ClampMin = "10", ClampMax = "50", UIMin = "10", UIMax = "50"))
	int depth;
	UPROPERTY(EditAnywhere, Category = "Generation", meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float density;
};
