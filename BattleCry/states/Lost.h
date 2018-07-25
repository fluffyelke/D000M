/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lost.h
 * Author: DooM
 *
 * Created on May 6, 2018, 10:20 AM
 */

#ifndef LOST_H
#define LOST_H

#include "../GameState.h"

class Lost : public GameState{
public:
    Lost(Game* game);
    virtual ~Lost();
    
    void                selectAction(bool direction) override;
    void                loadingScreen() override;
    void                move(sf::Vector2i direction) override;
    void                update(sf::Time dt) override;
    void                draw(sf::RenderWindow& window) override;

private:

};

#endif /* LOST_H */

