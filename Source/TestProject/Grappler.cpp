// Fill out your copyright notice in the Description page of Project Settings.
#include "Grappler.h"
#include "Crosshair.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Math/UnrealMathUtility.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include <stdlib.h>

// Sets default values
AGrappler::AGrappler()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm Component"));
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->TargetArmLength = 300;
	//SpringArmComp->bUsePawnControlRotation = true;
	SpringArmComp->bEnableCameraLag = true;
	SpringArmComp->bEnableCameraRotationLag = true;
	SpringArmComp->bInheritYaw = false;
	SpringArmComp->bInheritRoll = false;
	SpringArmComp->bInheritPitch = false;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);
}

// Called when the game starts or when spawned
void AGrappler::BeginPlay()
{
	Super::BeginPlay();
	Crosshair = GetWorld()->SpawnActor<ACrosshair>(CrosshairBP, GetTransform());
}

// Called every frame
void AGrappler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*float castDistance = 2500.f;

	FQuat castDirection = GetActorTransform().GetRotation();
	FVector castDirectionVector = castDirection.Vector();

	FVector start = GetActorLocation();
	start += GetCapsuleComponent()->GetScaledCapsuleRadius() * castDirectionVector.RotateAngleAxis(90, FVector(0, 0, 1));
	FVector end = start + castDistance * castDirectionVector;

	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());
	FHitResult hit;
	GetWorld()->LineTraceSingleByChannel(
		hit,
		start,
		end,
		ECollisionChannel::ECC_Visibility
	);

	Crosshair->SetFromHit(hit, castDirection);*/
}

// Called to bind functionality to input
void AGrappler::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	
}

void AGrappler::UpdateCrosshair(FHitResult hit) {
	auto lookDir = CameraComp->GetForwardVector();
	Crosshair->SetFromHit(hit, this);
}

void AGrappler::MoveForward(float value) {
	if(abs(value) > 0.5f)
		UE_LOG(LogTemp, Warning, TEXT("Move Forward"));
}

void AGrappler::MoveRight(float value) {
	if (abs(value) > 0.5f)
		UE_LOG(LogTemp, Warning, TEXT("Strafe"));
}

void AGrappler::Jump(float value) {
	if (abs(value) > 0.5f)
		UE_LOG(LogTemp, Warning, TEXT("Jump"));
}

void AGrappler::Fire() {

}

void AGrappler::AdjustViewport(FVector pct)
{
	if (abs(pct.X) > 0.6f) {
		SpringArmComp->AddRelativeRotation(FRotator(0.f, pct.X, 0.f), true);
	}
	if (abs(pct.Y) > 0.8f) {
		float currentPitch = SpringArmComp->GetRelativeRotation().GetNormalized().Pitch;
		pct.Y *= -1;
		
		float maxPitch = 60.f;
		if (abs(currentPitch + pct.Y) > maxPitch)
			pct.Y = (maxPitch * FMath::Sign(pct.Y)) - currentPitch;

		SpringArmComp->AddRelativeRotation(FRotator(pct.Y, 0.f, 0.f), true);
	}
}
