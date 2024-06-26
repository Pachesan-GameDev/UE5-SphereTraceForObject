#include "MyCPPDocument/SphereTraceForObject.h"
#include "Kismet/KismetSystemLibrary.h"

ASphereTraceForObject::ASphereTraceForObject()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ASphereTraceForObject::BeginPlay()
{
	Super::BeginPlay();
	
	FVector Start = GetActorLocation();
	FVector End = (GetActorForwardVector() * 500) + Start;
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes = {UEngineTypes::ConvertToObjectType(ECC_WorldStatic)};
	TArray<AActor*> ActorsToIgnore;
	FHitResult HitResult;

	bool bHit = UKismetSystemLibrary::SphereTraceSingleForObjects
	(
		GetWorld(),
		Start,
		End,
		20.0f,
		ObjectTypes,
		false,
		ActorsToIgnore,
		EDrawDebugTrace::ForDuration,
		HitResult,
		true,
		FLinearColor::Red,
		FLinearColor::Green,
		60.0f
	);
}

void ASphereTraceForObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
