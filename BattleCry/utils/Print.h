/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Print.h
 * Author: DooM
 *
 * Created on May 6, 2018, 9:39 AM
 */

#ifndef PRINT_H
#define PRINT_H

#include <string>
#include <iostream>
#include <SFML/Graphics/Rect.hpp>

void createPrint(const std::string& printInfo); 
void destroyPrint(const std::string& printInfo);

template<typename T>
void centerOrigin(T& drawable) {
    sf::FloatRect bound = drawable.getLocalBounds();
    drawable.setOrigin(bound.width / 2, bound.height / 2);
}

#endif /* PRINT_H */

