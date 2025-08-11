// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuSystem/InGameMenu.h"

bool UInGameMenu::Initialize()
{
	bool bSuccess = Super::Initialize();

	if (!bSuccess) return false;

	if (!ensure(Cancel_Button != nullptr)) return false;
	Cancel_Button->OnClicked.AddDynamic(this, &UInGameMenu::OnCancelPressed);

	if (!ensure(Quit_Button != nullptr)) return false;
	Quit_Button->OnClicked.AddDynamic(this, &UInGameMenu::OnQuitPressed);

	return true;
}


void UInGameMenu::OnCancelPressed()
{
	Terminate();
}

void UInGameMenu::OnQuitPressed()
{
	if (Menu_Interface != nullptr)
	{
		Terminate();
		Menu_Interface->LoadMainMenu();
	}
}