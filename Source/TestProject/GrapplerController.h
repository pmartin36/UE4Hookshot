// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Grappler.h"
#include "GameFramework/PlayerController.h"
#include "GrapplerController.generated.h"

/**
 * 
 */
UCLASS()
class TESTPROJECT_API AGrapplerController : public APlayerController
{
	GENERATED_BODY()
public:
	AGrapplerController(const FObjectInitializer& ObjectInitializer);
	virtual void Tick(float DeltaTime) override;
	virtual void SetupInputComponent() override;

	void MoveForward(float value);
	void MoveRight(float value);
	void Jump(float value);
	void Fire();

	AGrappler* GetGrappler() { return GetPawn<AGrappler>(); }
};
