/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Level.h
 * Author: DooM
 *
 * Created on May 7, 2018, 2:01 PM
 */

#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTexture.hpp>


class Level : public sf::Drawable {
public:
    Level(sf::Texture& texture);
    virtual ~Level();
    
    void loadLevel(std::string name);
    
    inline std::size_t positionToIndex(sf::Vector2i position) const;
    inline sf::Vector2i indexToPosition(std::size_t index) const;
    
    sf::Vector2i mapPixelToCell(sf::Vector2f pixel) const;
    sf::Vector2f mapCellToPixel(sf::Vector2i cell) const;
    
    sf::Vector2i getSize() const;
    
    bool isBrick(sf::Vector2i position) const;
private:
    
    enum LevelData {
        BRICK,
        STEEL,
        EMPTY
    };
    
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::Vector2i m_levelSize;
    std::vector<LevelData> m_levelData;
    
    sf::RenderTexture m_renderLevel;
    sf::Texture& m_texture;
};

#endif /* LEVEL_H */

