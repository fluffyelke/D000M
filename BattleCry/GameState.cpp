/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameState.cpp
 * Author: DooM
 * 
 * Created on May 6, 2018, 9:46 AM
 */

#include "GameState.h"

GameState::GameState(Game* game)
    : m_game{game}   {
    createPrint("GameState()");
}

GameState::~GameState() {
    destroyPrint("~GameState()");
}

Game* GameState::getGame() const {
    return m_game;
}



