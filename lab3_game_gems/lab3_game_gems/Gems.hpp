#pragma once

#include <vector>
#include "SFML/Graphics.hpp"




class Board : public sf::RectangleShape {
public:
    Board(size_t block_size, size_t board_size);
    void setFillColor(const std::vector<sf::Color>& colors);
    void setFillColor(const sf::Color& color, size_t x_coord, size_t y_coord);
private:
    std::vector<std::vector<RectangleShape>> _board;
    
};
