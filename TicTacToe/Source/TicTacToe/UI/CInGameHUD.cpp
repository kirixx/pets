// Fill out your copyright notice in the Description page of Project Settings.


#include "CInGameHUD.h"

ACInGameHUD::ACInGameHUD()
{

}


void ACInGameHUD::DrawHUD()
{
    Super::DrawHUD();
}

void ACInGameHUD::BeginPlay()
{
    Super::BeginPlay();
    if (PlayerTurnWidget)
    {
        mPlayerTurnWidget = CreateWidget<UCPlayerTurnWidget>(GetWorld(), PlayerTurnWidget);
        if (mPlayerTurnWidget)
        {
            mPlayerTurnWidget->AddToViewport();
        }
    }
}

void ACInGameHUD::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
}


void ACInGameHUD::UpdateWinner(const GameTypes::Player& player)
{
    if (WinnerWidgetClass)
    {
        mWinnerWidget = CreateWidget<UCWinnerWidget>(GetWorld(), WinnerWidgetClass);
        if (mWinnerWidget)
        {
            mWinnerWidget->AddToViewport();
        }
        mWinnerWidget->ShowWinner(player);
    }
}

void ACInGameHUD::ChangeTurn(const GameTypes::Player& player)
{
    if (mPlayerTurnWidget)
    {
        mPlayerTurnWidget->ChangeTurn(player);
    }
}