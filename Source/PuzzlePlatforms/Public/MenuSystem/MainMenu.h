// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuSystem/MenuWidget.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableTextBox.h"
#include "Components/ScrollBox.h"
#include "MainMenu.generated.h"

class UUServerRow;

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
	void SetServerList(TArray<FString> ServerNames);

	void SelectIndex(uint32 Index);

protected:
	virtual bool Initialize();

private:
	TSubclassOf<UUServerRow> ServerRowClass;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> Host_Button;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> Join_Button;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton>	Exit_Button;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> Cancel_JoinMenu_Button;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> Join_Session_Button;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UScrollBox> SB_ServerList;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UWidgetSwitcher> MenuSwitcher;

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
};