/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Play.h
 * Author: DooM
 *
 * Created on May 6, 2018, 10:17 AM
 */

#ifndef PLAY_H
#define PLAY_H

#include "../GameState.h"
#include "../Level.h"

class Play : public GameState {
public:
    Play(Game* game);
    virtual ~Play();
    
    void                selectAction(bool direction) override;
    void                loadingScreen() override;
    void                move(sf::Vector2i direction) override;
    void                update(sf::Time dt) override;
    void                draw(sf::RenderWindow& window) override;

private:
    
    Level m_level;
    
};

#endif /* PLAY_H */

