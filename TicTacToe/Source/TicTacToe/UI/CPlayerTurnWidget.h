// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Game/Types.h"
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/UMG.h"
#include "CPlayerTurnWidget.generated.h"

/**
 * 
 */
UCLASS()
class TICTACTOE_API UCPlayerTurnWidget : public UUserWidget
{
	GENERATED_BODY()
public:
    UCPlayerTurnWidget(const FObjectInitializer& ObjectInitializer);

    virtual void NativeConstruct() override;

    void ChangeTurn(const GameTypes::ePlayer player);

    void SetPlayerSide(const GameTypes::ePlayer side);
    void SetAISide(const GameTypes::ePlayer side);

private:
    UPROPERTY(Transient, meta = (BindWidgetAnim))
    UWidgetAnimation* PlayerXTurn;

    UPROPERTY(Transient, meta = (BindWidgetAnim))
    UWidgetAnimation* PlayerOTurn;

    UPROPERTY(Transient, meta = (BindWidget))
    UTextBlock* PlayerSideTxt;
    UPROPERTY(Transient, meta = (BindWidget))
    UTextBlock* AISideTxt;

};
