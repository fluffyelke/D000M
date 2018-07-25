/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Constants.h
 * Author: DooM
 *
 * Created on May 6, 2018, 9:32 AM
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <SFML/Graphics/Color.hpp>


/**
 * Window constants.
 */
namespace MyWindow {
    static const int WINDOW_WIDTH = 1440;
    static const int WINDOW_HEIGHT = 880;
}   //End of Window Constants.

//Select State Consts
namespace SelectCnst {
    static const float STRETCH_X = 6;
    static const float STRETCH_Y = 3.7;
    
    static const int TANK_VISUAL_X = 410;
    static const int TANK_VISUAL_Y = 455;
} //End of Select State Consts

//Color Consts
namespace Colors {
    static sf::Color BLACK = sf::Color::Black;
    static sf::Color BLUE = sf::Color::Blue;
    static sf::Color CYAN = sf::Color::Cyan;
    static sf::Color GREEN = sf::Color::Green;
    static sf::Color MAGENTA = sf::Color::Magenta;
    static sf::Color RED = sf::Color::Red;
    static sf::Color WHITE = sf::Color::White;
    static sf::Color YELLOW = sf::Color::Yellow;
    static sf::Color BROWN = sf::Color{139,69,19};
    static sf::Color TRANSPERNT = sf::Color::Transparent;
}   //End colors

//Text Size Consts
namespace TextSize {
    static const int SMALL = 12;
    static const int MEDIUM = 18;
    static const int AVERAGE = 24;
    static const int BIG = 32;
    static const int GRAND = 40;
} //End TextSize namespace
#endif /* CONSTANTS_H */

