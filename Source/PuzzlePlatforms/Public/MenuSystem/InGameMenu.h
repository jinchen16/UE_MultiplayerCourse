// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuSystem/MenuWidget.h"
#include "Components/Button.h"
#include "InGameMenu.generated.h"

/**
 *
 */
UCLASS()
class PUZZLEPLATFORMS_API UInGameMenu : public UMenuWidget
{
	GENERATED_BODY()

protected:
	virtual bool Initialize();

private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> Cancel_Button;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> Quit_Button;

	UFUNCTION()
	void OnCancelPressed();

	UFUNCTION()
	void OnQuitPressed();
};
