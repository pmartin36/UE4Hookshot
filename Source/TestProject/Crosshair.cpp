#include "Crosshair.h"
#include "Components/DecalComponent.h"
#include "DrawDebugHelpers.h"

// Sets default values
ACrosshair::ACrosshair()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ACrosshair::BeginPlay()
{
	Super::BeginPlay();
	DecalComponent = FindComponentByClass<UDecalComponent>();
}

void ACrosshair::SetFromHit(FHitResult hit, AActor* caster) {
	AActor* actorHit = hit.GetActor();
	if (actorHit && hit.Distance < 2500.f) {
		DrawDebugLine(GetWorld(), GetActorLocation(), hit.Location, FColor(0, 0, 255, 255), false, 0.f, 0, 10.f);

		FVector cameraPlane(1, 1, 0);

		FRotator castDir = ((hit.Location - caster->GetActorLocation()) * cameraPlane).Rotation();

		SetActorHiddenInGame(false);
		SetActorLocation(hit.Location);
		SetActorRelativeRotation(castDir);

		DecalComponent->DecalSize = FVector(128, 128, 128) * (hit.Distance / 1000.f);
	}
	else {
		DrawDebugLine(GetWorld(), GetActorLocation(), hit.TraceEnd, FColor(255, 0, 0, 255), false, 0.f, 0, 10.f);

		SetActorHiddenInGame(true);
	}
}