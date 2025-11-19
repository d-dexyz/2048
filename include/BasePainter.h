#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Board.h"
#include "Tile.h"
#include "GameState.h"
using namespace sf;
class BasePainter {
protected:
    RenderWindow& window;
    Tile tile;
    Font font;
    Music bgMusic;
    
    RectangleShape PlayerButton, MaxScoreButton, MenuMap, SumScore, Pic2, HightScore, Best, overlay;
    Texture MenuMapTexture, Pic2Texture, GameOverTexture;
    Text PlayerButtonText, MaxScoreButtonText, SumScoreText, HighScoreText, Name, BestText, GameoverText;

    void load();
    void setup();

    virtual void drawMenu() = 0;
    virtual void drawPlay(const Board& board) = 0;
    virtual void drawGameOver(const Board& board, bool showOver) = 0;
    virtual void drawMaxScore(const Board& board) = 0;

public:
    BasePainter(RenderWindow& win);
    virtual ~BasePainter() {}

    void displayFrame(GameState state, const Board& board, bool showOver);
};