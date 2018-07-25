/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Load.cpp
 * Author: DooM
 * 
 * Created on May 6, 2018, 10:15 AM
 */

#include "Load.h"
#include "../Game.h"
#include "../Constants.h"

Load::Load(Game* game)
    : GameState{game},
      m_currLevel{0} {
    createPrint("Load()");
    
    m_backGround.setTexture(getGame()->getTexture());
    m_backGround.setTextureRect(sf::IntRect{368, 210, 25, 25});
    m_backGround.setScale(30, 30);
    centerOrigin(m_backGround);
    m_backGround.setPosition(MyWindow::WINDOW_WIDTH / 2, MyWindow::WINDOW_HEIGHT / 2);
    
    m_stage.setTexture(getGame()->getTexture());
    m_stage.setTextureRect(sf::IntRect{328, 176, 40, 7});
    m_stage.setScale(5, 5);
    centerOrigin(m_stage);
    m_stage.setPosition(MyWindow::WINDOW_WIDTH / 2 - 65, MyWindow::WINDOW_HEIGHT / 2);
    
    m_number.setTexture(getGame()->getTexture());

}

Load::~Load() {
    destroyPrint("~Load()");
}
void Load::selectAction(bool direction) {

}
void Load::loadingScreen() {

}
void Load::move(sf::Vector2i direction) {

}
void Load::update(sf::Time dt) {
    static sf::Time timeBuffer = sf::Time::Zero;
    
    timeBuffer += dt;
    
    if(timeBuffer.asSeconds() >= 5) {
//        m_playingState->loadNextLevel();
        getGame()->changeGameState(GameState::PLAY);
    }
}
void Load::draw(sf::RenderWindow& window) {
    window.draw(m_backGround);
    window.draw(m_stage);
}
//int Load::getCurrentLevel() {
//    return m_currLevel;
//}
//void Load::setNextLevel() {
//    m_currLevel++;
//}



