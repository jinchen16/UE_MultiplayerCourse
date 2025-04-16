// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuSystem/MainMenu.h"
#include "Components/Button.h"
#include "MenuSystem/MenuInterface.h"

void UMainMenu::SetMenuInterface(IMenuInterface* MenuInterface)
{
    this->Menu_Interface = MenuInterface;
}

void UMainMenu::Setup()
{
    this->AddToViewport();

    UWorld* World = GetWorld();
    if (!ensure(World != nullptr)) return;

    APlayerController* PlayerController = World->GetFirstPlayerController();
    if (!ensure(PlayerController != nullptr)) return;

    FInputModeUIOnly InputMode;
    InputMode.SetWidgetToFocus(this->TakeWidget());
    InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);;
    PlayerController->SetInputMode(InputMode);

    PlayerController->bShowMouseCursor = true;
}

void UMainMenu::Terminate()
{
    this->RemoveFromViewport();

    UWorld* World = GetWorld();
    if (!ensure(World != nullptr)) return;

    APlayerController* PlayerController = World->GetFirstPlayerController();
    if (!ensure(PlayerController != nullptr)) return;

    // This set back to the normal gameplay input exiting only UI mode
    FInputModeGameOnly InputMode;    
    PlayerController->SetInputMode(InputMode);

    PlayerController->bShowMouseCursor = false;
}

bool UMainMenu::Initialize()
{
    bool bSuccess = Super::Initialize();

    if (!bSuccess) return false;

    if (!ensure(Host != nullptr)) return false;    
    Host->OnClicked.AddDynamic(this, &UMainMenu::HostServer);

    return true;
}

void UMainMenu::HostServer()
{
    if (Menu_Interface != nullptr)
    {
        Menu_Interface->Host();
    }    
}
