// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuSystem/MenuWidget.h"
#include "MainMenu.generated.h"

class UUServerRow;

USTRUCT()
struct FServerData
{
	GENERATED_BODY()

	FString Name;
	uint16 CurrentPlayers;
	uint16 MaxPlayers;
	FString HostUsername;
};

/**
 *
 */
UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UMenuWidget
{
	GENERATED_BODY()

	UMainMenu();

public:
	UFUNCTION()
	void SetServerList(TArray<FServerData> ServerNames);

	void SelectIndex(uint32 Index);

protected:
	virtual bool Initialize();

private:
	TSubclassOf<UUServerRow> ServerRowClass;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UButton> Host_Button;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UButton> Join_Button;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UButton>	Exit_Button;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UButton> Cancel_JoinMenu_Button;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UButton> Join_Session_Button;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UScrollBox> SB_ServerList;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UWidgetSwitcher> MenuSwitcher;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UWidget> JoinMenu;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UWidget> MainMenu;

	UFUNCTION()
	void HostServer();

	UFUNCTION()
	void OpenJoinMenu();

	UFUNCTION()
	void OpenMainMenu();

	UFUNCTION()
	void JoinServer();

	UFUNCTION()
	void QuitGame();

	TOptional<uint32> SelectedIndex;

	void UpdateChildren();
};