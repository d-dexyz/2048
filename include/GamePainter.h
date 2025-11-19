#pragma once
#include "BasePainter.h" 

using namespace sf;

class GamePainter : public BasePainter {
protected:
    virtual void drawMenu() override;
    virtual void drawPlay(const Board& board) override;
    virtual void drawGameOver(const Board& board, bool showOver) override;
    virtual void drawMaxScore(const Board& board) override;

public:
    GamePainter(RenderWindow& window);
};