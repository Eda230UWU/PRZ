// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTrain.h"

// Sets default values
AMyTrain::AMyTrain()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CMC = GetCharacterMovement();
	if (CMC) {
		CMC->RotationRate = FRotator(0.f, 1000.f, 0.f);
		CMC->bOrientRotationToMovement = true;
		CMC->MaxWalkSpeed = 2000.f;

	}
	//TODO
	//Ucharactermovementcontroler - zrychleni atd silly veci xd
}

// Called when the game starts or when spawned
void AMyTrain::BeginPlay()
{
	Super::BeginPlay();

	check(GEngine != nullptr);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("character"));

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
			Subsystem->AddMappingContext(UVehicleMappingContext, 0);

	/*GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, UVehicleMappingContext->ContextDescription.ToString());
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, UControlVehicle->ActionDescription.ToString());*/



	//GetCharacterMovement()->MaxFlySpeed = 54321.f;

}

// Called every frame
void AMyTrain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	moveRotation = FRotator(0.0f, Controller->GetControlRotation().Yaw, 0.0f);
	directionVectorF = moveRotation.RotateVector(FVector::ForwardVector);
	directionVectorR = moveRotation.RotateVector(FVector::RightVector);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, ForwardVelocity.ToString());
	
	AddMovementInput(directionVectorF, ForwardVelocity.X);

}

// Called to bind functionality to input
void AMyTrain::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	Input->BindAction(UControlVehicle, ETriggerEvent::Triggered, this, &AMyTrain::moveVehicle);
	//bool BindingOne = Input->GetActionBinding(0).IsValid();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Setup input"));

}

void AMyTrain::moveVehicle(const FInputActionValue& Value) {
	moveVector = Value.Get<FVector2D>();
	moveVector.X = 0.f;

	changeVelocityFront((FVector)moveVector.Y);
	AddMovementInput(directionVectorR, moveVector.X);
}

void AMyTrain::changeVelocityFront(FVector Velocity) {

	Velocity = FVector(Velocity.X);
	ForwardVelocity += Velocity;

}


