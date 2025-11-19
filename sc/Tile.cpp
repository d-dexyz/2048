#include "Tile.h"
#include "Board.h"
#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

Tile::Tile(){
    font.loadFromFile("resources/font/ClearSans-Bold.ttf");
    tile.setSize(Vector2f(100, 100));
    tile.setOutlineColor(Color(187, 173, 160));
    tile.setOutlineThickness(10);
}

void Tile::draw(RenderWindow &window, const Board &board) {
    float offsetX = window.getSize().x - (4 * 110) - 123;
    float offsetY = window.getSize().y - (4 * 110) - 60;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int val = board.get(i, j);

            if (val == 0) tile.setFillColor(Color(205, 193, 180));
            else if (val == 2) tile.setFillColor(Color(238, 228, 218));
            else if (val == 4) tile.setFillColor(Color(237, 224, 200));
            else if (val == 8) tile.setFillColor(Color(241, 170, 111));
            else if (val == 16) tile.setFillColor(Color(245, 149, 99));
            else if (val == 32) tile.setFillColor(Color(232, 103, 64));
            else if (val == 64) tile.setFillColor(Color(219, 75, 42));
            else if (val == 128) tile.setFillColor(Color(237, 206, 114));
            else if (val == 256) tile.setFillColor(Color(234, 198, 91));
            else if (val == 512) tile.setFillColor(Color(231, 193, 69));
            else if (val == 1024) tile.setFillColor(Color(228, 183, 46));
            else if (val == 2048) tile.setFillColor(Color(220,172,28));
            else if (val == 4096) tile.setFillColor(Color(128, 43, 122));
            else tile.setFillColor(Color(60, 58, 50));

            tile.setPosition(offsetX + j * 110, offsetY + i * 110);
            window.draw(tile);

            if (val != 0) {
                Text text(to_string(val), font, 32);
                text.setFillColor(Color::White);
                if (val == 2 || val == 4) text.setFillColor(Color::Black);
                if (val < 10) text.setPosition(offsetX + j * 110 + 40, offsetY + i * 110 + 30);
                else if (val >10 && val < 100) text.setPosition(offsetX + j * 110 + 30, offsetY + i * 110 + 30);
                else if (val >100&&val < 1000) text.setPosition(offsetX + j * 110 + 20, offsetY + i * 110 + 30);
                else text.setPosition(offsetX + j * 110 + 10, offsetY + i * 110 + 30);
            
                window.draw(text);
            }
        }
    }
}