#include "Gems.hpp"
#include <iostream>
#include <exception>
using namespace sf;

//class Board : public RectangleShape {
//public:
//    Board(size_t block_size,size_t board_size) {
//        for (int i = 0; i < board_size; i++) {
//            std::vector<RectangleShape> tmp;
//            for (int j = 0; j < board_size; j++) {
//                tmp.push_back(RectangleShape(Vector2f(block_size,block_size)));
//            }
//            _board.push_back(tmp);
//        }
//    }
//    void setColor(const std::vector<Color> colors) {
//        const size_t num_colors = colors.size();
//        for (auto& line : _board) {
//            for (auto& block : line) {
//                block.setFillColor(colors[rand() % num_colors]);
//            }
//        }
//    }
//
//
//private:
//    std::vector<std::vector<RectangleShape>> _board;
//};





int main() {
    
    RenderWindow window(VideoMode(500, 500), "Gems");
    const std::vector<Color> colors = { Color::Blue,Color::Green,Color::Red,Color::Yellow };




    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color::White);
        //Board b(100, 5);
        //b.setFillColor({ Color::Black });
 
    // define a 100x100 square, red, with a 10x10 texture mapped on it
        sf::Vertex vertices[] =
        {
            sf::Vertex(sf::Vector2f(0,   0), sf::Color::Red, sf::Vector2f(0,  0)),
            sf::Vertex(sf::Vector2f(0, 100), sf::Color::Red, sf::Vector2f(0, 10)),
            sf::Vertex(sf::Vector2f(100, 100), sf::Color::Red, sf::Vector2f(10, 10)),
            sf::Vertex(sf::Vector2f(100,   0), sf::Color::Red, sf::Vector2f(10,  0))
        };
        // draw it
        //window.draw(vertices, 4, sf::Quads);
        auto t = RectangleShape({ 50,100 });
        t.setFillColor(Color::Blue);
        window.draw(t);
        window.display();
    }

	return 0;
}