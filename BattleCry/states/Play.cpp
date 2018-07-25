/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Play.cpp
 * Author: DooM
 * 
 * Created on May 6, 2018, 10:17 AM
 */

#include "Play.h"
#include "../Game.h"

Play::Play(Game* game)
    : GameState{game},
      m_level{game->getTexture()}{
    createPrint("Play()");
    
    m_level.loadLevel("level1");
}

Play::~Play() {
    destroyPrint("~Play()");
}
void Play::selectAction(bool direction) {

}
void Play::loadingScreen() {

}
void Play::move(sf::Vector2i direction) {

}
void Play::update(sf::Time dt) {

}
void Play::draw(sf::RenderWindow& window) {
    window.draw(m_level);
}

