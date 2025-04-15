// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuSystem/MainMenu.h"
#include "Components/Button.h"
#include "MenuSystem/MenuInterface.h"

void UMainMenu::SetMenuInterface(IMenuInterface* MenuInterface)
{
    this->Menu_Interface = MenuInterface;
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
