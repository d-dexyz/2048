#include "GamePainter.h" 
#include <string>

using namespace sf;
using namespace std;

GamePainter::GamePainter(RenderWindow& win) : BasePainter(win) {
}


void GamePainter::drawMenu() {
    window.draw(MenuMap);
    window.draw(PlayerButton);
    window.draw(PlayerButtonText);
    window.draw(MaxScoreButton);
    window.draw(MaxScoreButtonText);
    window.draw(Name);
    if (bgMusic.getStatus() == Music::Playing) bgMusic.stop();
}

void GamePainter::drawPlay(const Board& board) {
    window.draw(MenuMap);
    tile.draw(window, board);
    window.draw(SumScore);
    window.draw(Best);
    window.draw(Pic2);
    SumScoreText.setString("SCORE : " + to_string(board.Score()));
    BestText.setString("BEST : " + to_string(board.loadHighScore()));
    window.draw(SumScoreText);
    window.draw(BestText);
    if (bgMusic.getStatus() != Music::Playing) bgMusic.play();
}

void GamePainter::drawGameOver(const Board& board, bool showOver) {
    window.draw(MenuMap);
    tile.draw(window, board);
    window.draw(SumScore);
    window.draw(Best);
    window.draw(Pic2);
    SumScoreText.setString("SCORE : " + to_string(board.Score()));
    BestText.setString("HIGH : " + to_string(board.loadHighScore()));
    window.draw(SumScoreText);
    window.draw(BestText);
    if (showOver) {
        window.draw(overlay);
        window.draw(GameoverText);
    }
    if (bgMusic.getStatus() == Music::Playing) bgMusic.stop();
}

void GamePainter::drawMaxScore(const Board& board) {
    window.draw(MenuMap);
    window.draw(HightScore);
    int best = board.loadHighScore();
    HighScoreText.setString("HIGH SCORE: " + to_string(board.loadHighScore()));
    window.draw(HighScoreText);
}