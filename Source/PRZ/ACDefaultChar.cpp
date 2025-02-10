// Fill out your copyright notice in the Description page of Project Settings.


#include "ACDefaultChar.h"



// Sets default values
AACDefaultChar::AACDefaultChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AACDefaultChar::BeginPlay()
{
	Super::BeginPlay();
	
	check(GEngine != nullptr);

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
			Subsystem->AddMappingContext(UCharMappingContext, 0);

}

// Called every frame
void AACDefaultChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AACDefaultChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	
	Input->BindAction(UControlChar, ETriggerEvent::Triggered, this, &AACDefaultChar::moveChar);
}

void AACDefaultChar::moveChar(const FInputActionValue& Value) {
	moveVector = Value.Get<FVector2D>();

	moveRotation = FRotator(0.f, Controller->GetControlRotation().Yaw, 0.f);
	directionVectorF = moveRotation.RotateVector(FVector::ForwardVector);
	directionVectorR = moveRotation.RotateVector(FVector::RightVector);

	AddMovementInput(directionVectorF, moveVector.Y);
	AddMovementInput(directionVectorR, moveVector.X);

}
