/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Select.cpp
 * Author: DooM
 * 
 * Created on May 6, 2018, 9:58 AM
 */

#include "Select.h"
#include "../Game.h"
#include "../Constants.h"
#include "../utils/Print.h"

Select::Select(Game* game)
    : GameState(game),
      m_blinkText{true},
      m_currAction{0} {
    createPrint("Select()");
    
    // Select Game Background
    m_backGround.setTexture(getGame()->getHud());
    m_backGround.setTextureRect(sf::IntRect{0, 0, 255, 224});
    m_backGround.setScale(SelectCnst::STRETCH_X, SelectCnst::STRETCH_Y);
    m_backGround.setPosition(0, 0);
    
    //Movable Tank position.
    m_tankVisual.setTexture(getGame()->getHud());
    m_tankVisual.setTextureRect(sf::IntRect{64, 124, 15, 15});
    m_tankVisual.setScale(SelectCnst::STRETCH_X, SelectCnst::STRETCH_Y);
    m_tankVisual.setPosition(SelectCnst::TANK_VISUAL_X, SelectCnst::TANK_VISUAL_Y);
    
    //The Green Text On the screen.
    m_text.setFont(getGame()->getFont());
    m_text.setFillColor(Colors::GREEN);
    m_text.setString("SELECT OPTION AND PRESS ENTER");
    m_text.setCharacterSize(TextSize::BIG);
    centerOrigin(m_text);
    m_text.setPosition(MyWindow::WINDOW_WIDTH / 2, MyWindow::WINDOW_HEIGHT / 2 - 30);
    
    //To Clear the tank from background.
    m_blackRect.setTexture(getGame()->getHud());
    m_blackRect.setTextureRect(sf::IntRect{0, 80, 20, 20});
    m_blackRect.setScale(4, 4);
    m_blackRect.setPosition(388, 463);
}
Select::~Select() {
    destroyPrint("~Select()");
}
void Select::selectAction(bool direction) {
    if(direction) {
        m_currAction++;
        if(m_currAction >= 3) {
            m_currAction = 0;
        }
    }
    else {
        m_currAction--;
        if(m_currAction < 0) {
            m_currAction = 2;
        }
    }
    std::cout << m_currAction << std::endl;
}
void Select::loadingScreen() {
    switch(m_currAction) {
        case 0: 
            getGame()->changeGameState(GameState::LOADING);
            break;
    }
}
void Select::move(sf::Vector2i direction) {

}
void Select::update(sf::Time dt) {
    static sf::Time timeBuffer = sf::Time::Zero;
    
    timeBuffer += dt;
    
    while(timeBuffer >= sf::seconds(0.5)) {
        m_blinkText = !m_blinkText;
        timeBuffer -= sf::seconds(1);
    }
    switch(m_currAction) {
        case 0:
            m_tankVisual.setPosition(SelectCnst::TANK_VISUAL_X, SelectCnst::TANK_VISUAL_Y);
            break;
        case 1:
            m_tankVisual.setPosition(SelectCnst::TANK_VISUAL_X, SelectCnst::TANK_VISUAL_Y + 60);
            break;
        case 2:
            m_tankVisual.setPosition(SelectCnst::TANK_VISUAL_X, SelectCnst::TANK_VISUAL_Y + 120);
            break;
        default:
            std::cout << "Should not enter here.\n";
            break;
    }
}
void Select::draw(sf::RenderWindow& window) {
    
    window.draw(m_backGround);
    window.draw(m_blackRect);
    window.draw(m_tankVisual);
    
    if(m_blinkText) {
        window.draw(m_text);
    }
}


