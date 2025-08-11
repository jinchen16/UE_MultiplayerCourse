// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuSystem/MainMenu.h"
#include "Components/Button.h"
#include "GameFramework/PlayerController.h"

bool UMainMenu::Initialize()
{
    bool bSuccess = Super::Initialize();

    if (!bSuccess) return false;

    if (!ensure(Host_Button != nullptr)) return false;    
    Host_Button->OnClicked.AddDynamic(this, &UMainMenu::HostServer);

    if (!ensure(Join_Button != nullptr)) return false;
    Join_Button->OnClicked.AddDynamic(this, &UMainMenu::OpenJoinMenu);

    if (!ensure(Exit_Button != nullptr)) return false;
    Exit_Button->OnClicked.AddDynamic(this, &UMainMenu::QuitGame);

    if (!ensure(Cancel_JoinMenu_Button != nullptr)) return false;
    Cancel_JoinMenu_Button->OnClicked.AddDynamic(this, &UMainMenu::OpenMainMenu);

    return true;
}

void UMainMenu::HostServer()
{
    if (Menu_Interface != nullptr)
    {
        Menu_Interface->Host();
    }    
}

void UMainMenu::OpenJoinMenu()
{
    if (!ensure(MenuSwitcher != nullptr)) return;
    if (!ensure(JoinMenu != nullptr)) return;

    MenuSwitcher->SetActiveWidget(JoinMenu);
}

void UMainMenu::OpenMainMenu()
{
    if (!ensure(MenuSwitcher != nullptr)) return;
    if (!ensure(MainMenu != nullptr)) return;

    MenuSwitcher->SetActiveWidget(MainMenu);
}

void UMainMenu::JoinServer()
{
    if (Menu_Interface != nullptr)
    {
        if (!ensure(IPAddressField != nullptr)) return;

        const FString& Address = IPAddressField->GetText().ToString();
        Menu_Interface->Join(Address);
    }
}

void UMainMenu::QuitGame()
{
    UWorld* World = GetWorld();
    if (!ensure(World != nullptr)) return;

    APlayerController* PlayerController = World->GetFirstPlayerController();
    if (!ensure(PlayerController != nullptr)) return;

    PlayerController->ConsoleCommand("quit");
}
