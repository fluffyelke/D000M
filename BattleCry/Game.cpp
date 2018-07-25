/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.cpp
 * Author: DooM
 * 
 * Created on May 6, 2018, 9:29 AM
 */

#include <SFML/Window/Event.hpp>

#include "Game.h"
#include "Constants.h"
#include "utils/Print.h"
#include "states/Select.h"
#include "states/Load.h"
#include "states/Play.h"
#include "states/Won.h"
#include "states/Lost.h"

Game::Game() 
    : m_window{sf::VideoMode{MyWindow::WINDOW_WIDTH, MyWindow::WINDOW_HEIGHT}, "BattleCry Game"}{
    createPrint("Game()");
    
    initResources();
    
    m_gameStates[GameState::SELECT] = new Select{this};
    m_gameStates[GameState::LOADING] = new Load{this};
    m_gameStates[GameState::PLAY] = new Play{this};
    m_gameStates[GameState::WON] = new Won{this};
    m_gameStates[GameState::LOST] = new Lost{this};
    
    changeGameState(GameState::SELECT);

}
Game::~Game() {
    for(GameState* state : m_gameStates) {
        delete state;
    }
    destroyPrint("~Game()");
}

void Game::run() {
    
    sf::Clock frameClock;
    
    ///MainGame Loop
    while(m_window.isOpen()) {
        sf::Event e;
        //Event Loop
        while(m_window.pollEvent(e)) {
            //Exit the game
            if(e.type == sf::Event::Closed) {
                m_window.close();
            }
            
            //Events.
            if(e.type == sf::Event::KeyPressed) {
                controlsOperations(e);
            }
        }   //End of Event Loop
        
        m_currentState->update(frameClock.restart());
        
        m_window.clear();
        
        //DrawHere
        m_currentState->draw(m_window);
        
        m_window.display();
    }   
}

void Game::changeGameState(GameState::State newState) {
    m_currentState = m_gameStates[newState];
}

void Game::controlsOperations(sf::Event& e) {
    switch(e.key.code) {
        //Load Screen Controls.
        case sf::Keyboard::Return:
            m_currentState->loadingScreen();
            break;
        case sf::Keyboard::Down:
            m_currentState->selectAction(true);
            break;
        case sf::Keyboard::Up:
            m_currentState->selectAction(false);
    }
}


void Game::initResources() throw(std::runtime_error) {
    try {
        m_hudTexture.loadFromFile("assets/resources/hud.png");
        m_gameTexture.loadFromFile("assets/resources/game.png");
        m_font.loadFromFile("assets/fonts/fallout.ttf");
    }
    catch(std::runtime_error& e) {
        std::cout << "Failed to load the resource: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}
sf::Font& Game::getFont(){
    return m_font;
}
sf::Texture& Game::getHud(){
    return m_hudTexture;
}
sf::Texture& Game::getTexture(){
    return m_gameTexture;
}




 