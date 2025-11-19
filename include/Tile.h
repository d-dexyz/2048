#pragma once
#include <string>
#include <SFML/Graphics.hpp>
using namespace sf;

class Board;

class Tile{
private:
    RectangleShape tile;
    Font font;
public:
    Tile(); 
    void draw(RenderWindow &window, const Board &board);
};