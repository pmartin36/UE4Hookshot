// Fill out your copyright notice in the Description page of Project Settings.


#include "GrapplerController.h"
#include "Grappler.h"

AGrapplerController::AGrapplerController(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	
};

void AGrapplerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FHitResult hit;
	GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECC_Visibility), true, hit);
	GetGrappler()->UpdateCrosshair(hit);

	int vpx = 0, vpy = 0;
	GetViewportSize(vpx, vpy);
	float x = 0, y = 0;
	GetMousePosition(x, y);
	FVector pct(x / (float)vpx, y / (float)vpy, 0);
	GetGrappler()->AdjustViewport(pct * 2 - 1);
}

void AGrapplerController::SetupInputComponent() {
	Super::SetupInputComponent();
	InputComponent->BindAxis("MoveForward", this, &AGrapplerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AGrapplerController::MoveRight);
	InputComponent->BindAxis("Jump", this, &AGrapplerController::Jump);
	InputComponent->BindAction("Fire", EInputEvent::IE_Pressed, this,  &AGrapplerController::Fire);
}

void AGrapplerController::MoveForward(float value) {
	GetGrappler()->MoveForward(value);
}
void AGrapplerController::MoveRight(float value) {
	GetGrappler()->MoveRight(value);
}
void AGrapplerController::Jump(float value) {
	GetGrappler()->Jump(value);
}

void AGrapplerController::Fire() {
	GetGrappler->Fire();
}



