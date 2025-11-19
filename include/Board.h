#pragma once
#include <map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <iterator>

class Board{
private:
    int grid[4][4];
    int score;
public:
    Board();
    void reset();
    void spawnTile();
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    bool isGameOver();
    int Score()const;
    int loadHighScore()const;
    void saveHighScore(int newScore);
    int get(int i, int j) const;
};