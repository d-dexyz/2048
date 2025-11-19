#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib> 
#include <ctime>
#include "Board.h"
#include "Tile.h"
#include "GameManager.h"
#include "GameState.h"
#include "GamePainter.h"
using namespace sf;
using namespace std;

GameManager::GameManager() : 
    window(VideoMode(700, 700), "Game 2048"), 
    state(MENU),
    showGameOver(false)
    {
        srand(static_cast<unsigned int>(time(0)));
        try {
            painter = new GamePainter(window);
        }
        catch (const runtime_error& e) {
            cerr << e.what() <<endl; 
            window.close(); 
        }
    }
GameManager::~GameManager() {
    delete painter; 
}

void GameManager::handlevent() {
    Event e;
    while (window.pollEvent(e)) {
        if (e.type == Event::Closed) {
            window.close();
        }
        if (state == MENU) {
            showGameOver = false;
            if (e.type == Event::MouseButtonPressed) {
                Vector2i mousePos = Mouse::getPosition(window);
                FloatRect playButtonBounds(150.f, 300.f, 400.f, 120.f);
                FloatRect maxScoreButtonBounds(150.f, 500.f, 400.f, 120.f);
                if (playButtonBounds.contains((float)mousePos.x, (float)mousePos.y)) {
                    board.reset();
                    state = PLAY;
                }
                if (maxScoreButtonBounds.contains((float)mousePos.x, (float)mousePos.y)) {
                    state = MAXSCORE;
                }
            }
        }
        if(state == PLAY){
            window.clear();
            if(e.type == Event::KeyPressed){
                if (e.key.code == Keyboard::Left)  board.moveLeft();
                if (e.key.code == Keyboard::Right) board.moveRight();
                if (e.key.code == Keyboard::Up)    board.moveUp();
                if (e.key.code == Keyboard::Down)  board.moveDown();
            }
        }
        if((state == PLAY || state == MAXSCORE || state == GAMEOVER) && Keyboard::isKeyPressed(Keyboard::Escape)){
            state = MENU;
        }
    }
}

void GameManager::update(){
    if (board.isGameOver() && state == PLAY) {
        state = GAMEOVER;
        showGameOver = false;
        gameOverClock.restart();
    }
    if (board.Score() > board.loadHighScore()) {
            board.saveHighScore(board.Score());
    }
    if (state == GAMEOVER && !showGameOver) {
        if (gameOverClock.getElapsedTime().asSeconds() > 2.0f) {
            showGameOver = true; 
        }
    }
}

void GameManager::render() {
    painter->displayFrame(state, board, showGameOver);
}

void GameManager::run() {
    while (window.isOpen()) {
        handlevent();
        update();
        render();
    }
}