/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Load.h
 * Author: DooM
 *
 * Created on May 6, 2018, 10:15 AM
 */

#ifndef LOAD_H
#define LOAD_H
#include "../GameState.h"

class Load : public GameState {
public:
    Load(Game* game);
    virtual ~Load();
    
    void                selectAction(bool direction) override;
    void                loadingScreen() override;
    void                move(sf::Vector2i direction) override;
    void                update(sf::Time dt) override;
    void                draw(sf::RenderWindow& window) override;
    
//    void                setNextLevel();
//    int                 getCurrentLevel();
private:
    
    int m_currLevel;
    sf::Sprite m_stage;
    sf::Sprite m_number;
    sf::Sprite m_backGround;
};

#endif /* LOAD_H */

