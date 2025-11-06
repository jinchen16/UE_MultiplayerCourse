// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuSystem/MainMenu.h"
#include "Components/Button.h"
#include "MenuSystem/UServerRow.h"
#include "GameFramework/PlayerController.h"

UMainMenu::UMainMenu()
{
	ConstructorHelpers::FClassFinder<UUServerRow> ServerRowBPClass(TEXT("/Game/PuzzlePlatforms/MenuSystem/WBP_ServerName"));
	if (!ensure(ServerRowBPClass.Class != nullptr)) return;

	ServerRowClass = ServerRowBPClass.Class;
}

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

	if (Menu_Interface != nullptr)
	{
		Menu_Interface->RefreshServerList();
	}
}

void UMainMenu::OpenMainMenu()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(MainMenu != nullptr)) return;

	MenuSwitcher->SetActiveWidget(MainMenu);
}

void UMainMenu::JoinServer()
{
	if (Menu_Interface != nullptr && SelectedIndex.IsSet())
	{
		//if (!ensure(IPAddressField != nullptr)) return;
		//const FString& Address = IPAddressField->GetText().ToString();
		Menu_Interface->Join(SelectedIndex.GetValue());
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

void UMainMenu::SetServerList(TArray<FString> ServerNames)
{
	UWorld* World = this->GetWorld();

	if (!ensure(World != nullptr)) return;

	SB_ServerList->ClearChildren();

	uint32 index = 0;
	for (const FString& ServerName : ServerNames)
	{
		UUServerRow* Row = CreateWidget<UUServerRow>(World, ServerRowClass);
		if (!ensure(Row != nullptr)) return;

		Row->ServerName->SetText(FText::FromString(ServerName));
		Row->Setup(this, index);
		++index;
		SB_ServerList->AddChild(Row);
	}
}

void UMainMenu::SelectIndex(uint32 Index)
{
	SelectedIndex = Index;
}
