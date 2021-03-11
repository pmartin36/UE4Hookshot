// Fill out your copyright notice in the Description page of Project Settings.


#include "GrappleRaceGameMode.h"
#include "Block.h"
#include "Components/StaticMeshComponent.h"
#include <math.h>

void AGrappleRaceGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) {
	Super::InitGame(MapName, Options, ErrorMessage);

	FQuat quat(0.f, 0.f, 0.f, 1.f);
	FVector pos(0.f, 0.f, 0.f);

	float dim = 500;

	int halfWidth = ceil(width / 2.f);
	int halfHeight = ceil(height / 2.f);
	int halfDepth = ceil(depth / 2.f);

	// diagonal 
	/*int z = 0;
	for (int yz = 0; yz < height; yz++) {
		for (int x = -halfWidth; x < halfWidth; x++) {
			pos = FVector(x * dim, yz * dim, yz * dim);
			GetWorld()->SpawnActor<ABlock>(block, FTransform(quat, pos));
		}
	}*/

	// top + bottom
	float z_base = halfHeight;
	for (int x = -halfWidth; x < halfWidth; x++) {
		for (int y = -halfDepth; y < halfDepth; y++) {
			int z = z_base;
			if ((x + y) % 2 == 0) {
				z++;
			}

			pos = FVector(x * dim, y * dim, z * dim);
			GetWorld()->SpawnActor<ABlock>(block, FTransform(quat, pos));

			pos.Z *= -1;
			GetWorld()->SpawnActor<ABlock>(block, FTransform(quat, pos));
		}
	}

	// front + back
	float y_base = halfDepth;
	for (int x = -halfWidth; x < halfWidth; x++) {
		for (int z = -halfHeight; z < halfHeight+1; z++) {
			int y = y_base;
			if ((x + z) % 2 == 0) {
				y++;
			}

			pos = FVector(x * dim, y * dim, z * dim);
			GetWorld()->SpawnActor<ABlock>(block, FTransform(quat, pos));

			pos.Y *= -1;
			GetWorld()->SpawnActor<ABlock>(block, FTransform(quat, pos));
		}
	}

	// sides
	float x_base = halfWidth;
	for (int y = -halfDepth; y < halfDepth+1; y++) {
		for (int z = -halfHeight; z < halfHeight+1; z++) {
			int x = x_base;
			if ((y + z) % 2 == 0) {
				x++;
			}

			pos = FVector(x * dim, y * dim, z * dim);
			GetWorld()->SpawnActor<ABlock>(block, FTransform(quat, pos));

			pos.X *= -1;
			GetWorld()->SpawnActor<ABlock>(block, FTransform(quat, pos));
		}
	}

	/*for (int x = 0; x < width; x++) {
		for (int y = 0; y < depth; y++) {
			for (int z = 0; z < height; z++) {

			}
		}
	}*/
}