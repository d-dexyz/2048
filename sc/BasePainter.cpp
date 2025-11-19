#include "BasePainter.h"
#include <string>

using namespace sf;
using namespace std;

BasePainter::BasePainter(RenderWindow& win) : window(win) {
    window.setFramerateLimit(60);
    load();
    setup();
}

void BasePainter::displayFrame(GameState state, const Board& board, bool showOver) {
    window.clear(Color::White);
    if (state == MENU) drawMenu(); 
    else if (state == PLAY) drawPlay(board); 
    else if (state == GAMEOVER) drawGameOver(board, showOver); 
    else if (state == MAXSCORE) drawMaxScore(board); 
    window.display();
}

void BasePainter::load() {
    if (!font.loadFromFile("resources/font/ClearSans-Bold.ttf")) throw runtime_error("Lỗi: Không thể tải font ClearSans-Bold.ttf");
    if (!MenuMapTexture.loadFromFile("resources/picture/menu.png")) throw runtime_error("Lỗi: Không thể tải hình ảnh menu.png");
    if (!Pic2Texture.loadFromFile("resources/picture/trangtri.png")) throw runtime_error("Lỗi: Không thể tải hình ảnh trangtri.png");
    if (!bgMusic.openFromFile("resources/sound/shop3.ogg")) throw runtime_error("Lỗi: Không thể tải nhạc shop3.ogg"); 
}

void BasePainter::setup() {
    MenuMap.setSize(Vector2f(window.getSize().x, window.getSize().y));
    MenuMap.setTexture(&MenuMapTexture);

    Name.setFont(font);
    Name.setCharacterSize(100);
    Name.setPosition(Vector2f(230.f, 90.f));
    Name.setString("2048");

    PlayerButton.setSize(Vector2f(400.f, 120.f));
    PlayerButton.setPosition(Vector2f(150.f, 300.f));
    PlayerButton.setFillColor(Color(((141, 110, 99))));
    PlayerButton.setOutlineThickness(10.f);
    PlayerButton.setOutlineColor(Color((255, 183, 77)));
    PlayerButtonText.setFont(font);
    PlayerButtonText.setCharacterSize(50);
    PlayerButtonText.setString("PLAY");
    PlayerButtonText.setPosition(Vector2f(295.f, 330.f));

    MaxScoreButton.setSize(Vector2f(400.f, 120.f));
    MaxScoreButton.setPosition(Vector2f(150.f, 500.f));
    MaxScoreButton.setFillColor(Color(((141, 110, 99))));
    MaxScoreButton.setOutlineThickness(10.f);
    MaxScoreButton.setOutlineColor(Color((255, 183, 77)));
    MaxScoreButtonText.setFont(font);
    MaxScoreButtonText.setCharacterSize(50);
    MaxScoreButtonText.setString("MAX SCORE");
    MaxScoreButtonText.setPosition(Vector2f(215.f, 525.f));

    Best.setSize(Vector2f(290.f, 70.f));
    Best.setPosition(Vector2f(360.f, 30.f));
    Best.setFillColor(Color(112, 88, 79));
    BestText.setCharacterSize(35);
    BestText.setPosition(380.f, 45.f);
    BestText.setFont(font);

    SumScore.setSize(Vector2f(290.f, 70.f));
    SumScore.setPosition(Vector2f(50.f, 30.f));
    SumScore.setFillColor(Color(112, 88, 79));
    SumScoreText.setCharacterSize(35);
    SumScoreText.setPosition(65.f, 45.f);
    SumScoreText.setFont(font);

    Pic2.setSize(Vector2f(100.f, 100.f));
    Pic2.setTexture(&Pic2Texture);

    HighScoreText.setFont(font);
    HighScoreText.setCharacterSize(35);
    HighScoreText.setFillColor(Color::White);
    HighScoreText.setPosition(185.f, 330.f);
    HightScore.setSize(Vector2f(400.f, 120.f));
    HightScore.setFillColor(Color(((141, 110, 99))));
    HightScore.setOutlineThickness(10.f);
    HightScore.setOutlineColor(Color((255, 183, 77)));
    HightScore.setOrigin(400 / 2.0f, 120 / 2.0f);
    HightScore.setPosition(700 / 2.0f, 700 / 2.0f);

    overlay.setSize(Vector2f(window.getSize().x, window.getSize().y));
    overlay.setFillColor(Color(0, 0, 0, 150));
    GameoverText.setFont(font);
    GameoverText.setString("GAME OVER");
    GameoverText.setCharacterSize(70);
    GameoverText.setFillColor(Color::Yellow);
    FloatRect OverBounds = GameoverText.getLocalBounds();
    GameoverText.setOrigin(OverBounds.left + OverBounds.width / 2.0f, OverBounds.top + OverBounds.height / 2.0f);
    GameoverText.setPosition(700 / 2.0f, 700 / 2.0f);

    bgMusic.setLoop(true);
    bgMusic.setVolume(40);
}