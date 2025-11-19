#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib> 
#include <ctime>
#include "Board.h"
#include "Tile.h"
#include "BasePainter.h" 
#include "GameState.h"
using namespace std;
using namespace sf;
class GameManager{
private:
    RenderWindow window;
    GameState state;
    Board board;
    BasePainter* painter;
    Clock gameOverClock;
    bool showGameOver;
    int highScore;
    void handlevent();
    void update();
    void render();
public:
    GameManager();
    ~GameManager();
    void run();
};
