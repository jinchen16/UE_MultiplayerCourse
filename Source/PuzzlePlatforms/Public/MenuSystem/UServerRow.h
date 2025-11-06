// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "UServerRow.generated.h"

/**
 * 
 */
UCLASS()
class UUServerRow : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> ServerName;

	UPROPERTY()
	class UMainMenu* Parent;

	uint32 Index;

	void Setup(class UMainMenu* IN_Parent, uint32 IN_Index);

private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> RowButton;

	UFUNCTION()
	void OnClicked();
};
