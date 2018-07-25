/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lost.cpp
 * Author: DooM
 * 
 * Created on May 6, 2018, 10:20 AM
 */

#include "Lost.h"

Lost::Lost(Game* game)
    :GameState{game}  {
    createPrint("Lost()");
}

Lost::~Lost() {
    destroyPrint("~Lost()");
}
void Lost::selectAction(bool direction) {

}
void Lost::loadingScreen() {

}
void Lost::move(sf::Vector2i direction) {

}
void Lost::update(sf::Time dt) {

}
void Lost::draw(sf::RenderWindow& window) {

}


