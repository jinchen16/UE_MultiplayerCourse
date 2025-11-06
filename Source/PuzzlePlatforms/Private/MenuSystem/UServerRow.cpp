// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuSystem/UServerRow.h"
#include "MenuSystem/MainMenu.h"

void UUServerRow::Setup(UMainMenu* IN_Parent, uint32 IN_Index)
{
	Parent = IN_Parent;
	Index = IN_Index;
	RowButton->OnClicked.AddDynamic(this, &UUServerRow::OnClicked);
}

void UUServerRow::OnClicked()
{
	Parent->SelectIndex(Index);
}