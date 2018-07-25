/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Select.h
 * Author: DooM
 *
 * Created on May 6, 2018, 9:58 AM
 */

#ifndef SELECT_H
#define SELECT_H

#include "../GameState.h"

class Select : public GameState{
public:
    Select(Game* game);
    virtual ~Select();
    
    void                selectAction(bool direction) override;
    void                loadingScreen() override;
    void                move(sf::Vector2i direction) override;
    void                update(sf::Time dt) override;
    void                draw(sf::RenderWindow& window) override;
    
private:
    
    sf::Sprite m_backGround;
    sf::Sprite m_tankVisual;
    sf::Text m_text;
    
    sf::Sprite m_blackRect;
    
    int m_currAction;
    
    bool m_blinkText;
};

#endif /* SELECT_H */

