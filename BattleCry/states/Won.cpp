/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Won.cpp
 * Author: DooM
 * 
 * Created on May 6, 2018, 10:20 AM
 */

#include "Won.h"

Won::Won(Game* game)
    :GameState{game}  {
    createPrint("Won()");
}

Won::~Won() {
    destroyPrint("~Won()");
}
void Won::selectAction(bool direction) {

}
void Won::loadingScreen() {

}
void Won::move(sf::Vector2i direction) {

}
void Won::update(sf::Time dt) {

}
void Won::draw(sf::RenderWindow& window) {

}

