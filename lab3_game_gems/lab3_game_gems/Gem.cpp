#include "Gems.hpp"


using namespace sf;

Gem::Gem() {

}



Board::Board(size_t block_size, size_t board_size) {
    for (int i = 0; i < board_size; i++) {
        std::vector<RectangleShape> tmp;
        for (int j = 0; j < board_size; j++) {
            tmp.push_back(RectangleShape(Vector2f(block_size, block_size)));
            tmp[j].setOutlineThickness(1);
        }
        _board.push_back(tmp);
    }     
}


void Board::setFillColor(const std::vector<sf::Color>& colors) { 
    const size_t num_colors = colors.size();
    for (auto& line : _board) {
        for (auto& block : line) {
            block.setFillColor(colors[rand() % num_colors]);
        }
    }
}

// 3x3
// 0,1,2
void Board::setFillColor(const sf::Color& color, size_t x_coord, size_t y_coord) {
    if (_board.size() > x_coord && _board[x_coord].size() > y_coord) {
        _board[x_coord][y_coord].setFillColor(color);
    }
}