/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Level.cpp
 * Author: DooM
 * 
 * Created on May 7, 2018, 2:01 PM
 */

#include <stdexcept>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "Level.h"
#include "Constants.h"

Level::Level(sf::Texture& texture) 
    : m_texture{texture},
      m_levelSize{0, 0} {
}

void Level::loadLevel(std::string name) {
    
    sf::Image imageData;
    if(!imageData.loadFromFile("assets/levels/" + name + ".png")) {
        throw std::runtime_error("Unable to load level: " + name);
    }
    m_levelSize = sf::Vector2i(imageData.getSize());
    
    //Read image Pixels
    for(unsigned int y = 0; y < m_levelSize.y; ++y) {
        for(unsigned int x = 0; x < m_levelSize.x; ++x) {
            sf::Color cellData = imageData.getPixel(x, y);
            if(cellData == Colors::BLACK) {
                m_levelData.push_back(EMPTY);
            }
            else if(cellData == sf::Color{165, 42, 42}) {
                m_levelData.push_back(BRICK);
            }
            else if(cellData == Colors::WHITE) {
                m_levelData.push_back(STEEL);
            }
        }
    }
    
    m_renderLevel.create(32 * m_levelSize.x, 32 * m_levelSize.y);
    m_renderLevel.clear(Colors::BLACK);
    
    sf::Sprite brick{m_texture};
    brick.setTextureRect(sf::IntRect{280, 0, 8, 8});
    brick.setOrigin(0, 8);
    
    sf::Sprite steel{m_texture};
    steel.setTextureRect(sf::IntRect{256, 72, 8, 8});
    steel.setOrigin(0, 8);
    m_renderLevel.display();
    
    for(unsigned int i = 0; i < m_levelData.size(); ++i) {
        sf::Vector2i position = indexToPosition(i);
        if(m_levelData[i] == BRICK) {
//            sf::RectangleShape bricks;
//            bricks.setSize(sf::Vector2f{30, 30});
//            bricks.setFillColor(Colors::BROWN);
            brick.setPosition(32 * position.x, 32 * position.y);
            brick.setScale(4, 4);
            m_renderLevel.draw(brick);
        }
        else if(m_levelData[i] == STEEL) {
            steel.setPosition(32 * position.x, 32 * position.y);
            steel.setScale(4, 4);
            m_renderLevel.draw(steel);
        }
    }
}
Level::~Level() {
}

void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sf::Sprite{m_renderLevel.getTexture()}, states);
}

std::size_t Level::positionToIndex(sf::Vector2i position) const {
    return position.y * m_levelSize.x + position.x;
}

sf::Vector2i Level::indexToPosition(std::size_t index) const {
    sf::Vector2i position;
    
    position.x = index % m_levelSize.x;
    position.y = index / m_levelSize.y;
    
    return position;
}

sf::Vector2f Level::mapCellToPixel(sf::Vector2i cell) const {
    sf::Vector2f pixel;
    pixel.x = cell.x * 32 + 8;
    pixel.y = cell.y * 32 + 8;
    return pixel;
}

sf::Vector2i Level::mapPixelToCell(sf::Vector2f pixel) const {
    sf::Vector2i cell;
    cell.x = std::floor(pixel.x / 32.f);
    cell.y = std::floor(pixel.y / 32.f);
    
    return cell;
}

bool Level::isBrick(sf::Vector2i position) const {
    if(position.x < 0 || position.x >= m_levelSize.x || position.y < 0 || position.y >= m_levelSize.y ) {
        return false;
    }
    return m_levelData[positionToIndex(position)] == BRICK;
}
