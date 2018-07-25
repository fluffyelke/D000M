/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameState.h
 * Author: DooM
 *
 * Created on May 6, 2018, 9:46 AM
 */

#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "utils/Print.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Game;

class GameState {
public:
    
    enum State {
        SELECT,
        LOADING,
        PLAY,
        WON,
        LOST,
        STATES_COUNT
    };
    
    /**
     * Constructor 
     * @param game pointer to the Game instance.
     */
    GameState(Game* game);
    virtual ~GameState();
    
    /**
     * Method to access Game Instance.
     * @return this Game
     */
    Game*                   getGame() const;
    
    
    //Virtual Methods for the game states.
    /**
     * Select Screen(Menu) method.
     */
    virtual void            selectAction(bool direction) = 0;
    
    /**
     * Method for the loading screen state.
     */
    virtual void                    loadingScreen() = 0;
    
    /**
     * Method to move the objects on the screen.
     * @param direction
     */
    virtual void            move(sf::Vector2i direction) = 0;
    
    /**
     * Method to update the screen objects.
     * @param dt - update the screen every time dt is changed.
     */
    virtual void            update(sf::Time dt) = 0;
    
    /**
     * Method to draw objects on the screen.
     * @param window - drawing window. 
     */
    virtual void            draw(sf::RenderWindow& window) = 0;
    
private:
    /**
     * Pointer to the game instance.
     */
    Game*                   m_game;
};

#endif /* GAMESTATE_H */

