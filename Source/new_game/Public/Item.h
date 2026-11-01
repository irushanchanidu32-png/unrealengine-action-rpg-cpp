// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

class USphereComponent;

enum class EItemState :uint8 {
	EIS_Hovering,
	EIS_Equipped
};

UCLASS()
class NEW_GAME_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	float TransformedSin(float Value);
	float TransformedCos(float Value);

	UPROPERTY(EditAnywhere , BlueprintReadOnly)
	float RunningTime;

	template<typename T>
	T AVG(T First, T Second);

	UFUNCTION()
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(VisibleAnywhere ,BlueprintReadOnly);
	UStaticMeshComponent* ItemMesh;

	EItemState ItemState = EItemState::EIS_Hovering;



	UPROPERTY(VisibleAnywhere);
	USphereComponent* Sphere;

private:
	
	float Amplitude = 0.25f;
	float TimeConstant = 0.5f;

	

	
};

template<typename T>
inline T AItem::AVG(T First, T Second)
{
	return (First + Second) / 2;
}
