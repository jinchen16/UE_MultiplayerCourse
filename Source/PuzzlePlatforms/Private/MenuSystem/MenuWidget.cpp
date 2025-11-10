// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuSystem/MenuWidget.h"
#include "MenuSystem/MenuInterface.h"
#include "GameFramework/PlayerController.h"

void UMenuWidget::SetMenuInterface(IMenuInterface* MenuInterface)
{
    this->Menu_Interface = MenuInterface;
}

void UMenuWidget::Setup()
{
    this->AddToViewport();

    UWorld* World = this->GetWorld();
    if (!ensure(World != nullptr)) return;

    APlayerController* PlayerController = World->GetFirstPlayerController();
    if (!ensure(PlayerController != nullptr)) return;

    FInputModeUIOnly InputMode;
    InputMode.SetWidgetToFocus(this->TakeWidget());
    InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);;
    PlayerController->SetInputMode(InputMode);

    PlayerController->bShowMouseCursor = true;
}

void UMenuWidget::Terminate()
{
    this->RemoveFromParent();

    UWorld* World = this->GetWorld();
    if (!ensure(World != nullptr)) return;

    APlayerController* PlayerController = World->GetFirstPlayerController();
    if (!ensure(PlayerController != nullptr)) return;

    // This set back to the normal gameplay input exiting only UI mode
    FInputModeGameOnly InputMode;
    PlayerController->SetInputMode(InputMode);

    PlayerController->bShowMouseCursor = false;
}