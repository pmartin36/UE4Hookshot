// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Grappler.generated.h"

UCLASS()
class TESTPROJECT_API AGrappler : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Camera")
	class USpringArmComponent* SpringArmComp;
	UPROPERTY(EditAnywhere, Category = "Camera")
	class UCameraComponent* CameraComp;
	UPROPERTY(EditAnywhere, Category = "Crosshair")
	TSubclassOf<class ACrosshair> CrosshairBP;

	// Sets default values for this character's properties
	AGrappler();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void UpdateCrosshair(FHitResult hit);

	void MoveForward(float value);
	void MoveRight(float value);
	void Jump(float value);
	void Fire();

	void AdjustViewport(FVector pct);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	class ACrosshair* Crosshair;
};
