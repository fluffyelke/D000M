/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.h
 * Author: DooM
 *
 * Created on May 6, 2018, 9:29 AM
 */

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "GameState.h"
#include <array>
#include <SFML/Window/Event.hpp>

class Game {
public:
    
    /**
     * Default Constructor for the Game object.
     */
    Game();
    virtual ~Game();
    
    /**
     * Method to run the Game.
     */
    void                            run();
    
    /**
     * Method to change the current state
     * @param newState - set the new state.
     */
    void                            changeGameState(GameState::State newState);
    
    /**
     * Method for input operations.
     * @param e - the event
     */
    void                            controlsOperations(sf::Event& e);
    
    /**
     * Load in game resources.
     */
    void initResources() throw(std::runtime_error);
    
    //Accessors to the resources.
    sf::Font& getFont();
    sf::Texture& getHud();
    sf::Texture& getTexture();
private:
    /**
     * The window for drawing the game.
     */
    sf::RenderWindow               m_window;
    
    /**
     * Current State of the game.
     */
    GameState*                     m_currentState;
    
    /**
     * Array to hold all the states.
     */
    std::array<GameState*, GameState::STATES_COUNT> m_gameStates;
    
    sf::Texture                    m_hudTexture;    //The hud Texture
    sf::Texture                    m_gameTexture;   //The game Texture
    sf::Font                       m_font;  //the Game Font
};

#endif /* GAME_H */

