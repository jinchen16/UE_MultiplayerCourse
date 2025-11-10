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
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> HostUsername;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> PlayerQuantity;

	UPROPERTY()
	class UMainMenu* Parent;

	uint32 Index;

	void Setup(class UMainMenu* IN_Parent, uint32 IN_Index);

	UPROPERTY(BlueprintReadOnly)
	bool Selected = false;

private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> RowButton;

	UFUNCTION()
	void OnClicked();
};
