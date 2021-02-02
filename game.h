#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QApplication>
#include <QTimer>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QDebug>
#include "button.h"
#include "spaceship.h"
#include "reloadbar.h"
#include "asteroid.h"
#include "QList"
#include "iostream"
#include "fstream"
#include <QLineEdit>
#include <QMessageBox>

class Game
{
public:
    static Game& getInstance();
    void setDef(QPixmap* aster, QPixmap* backgrounds,
                 QPixmap* buts, QPixmap* backbut,
                QPixmap* spaceship, unsigned short* step,
                unsigned char* curback, bool* directions,
                QPixmap* bul, QPixmap* rel, QPixmap* smallaster,
                QLineEdit* line);
    void startGame();
    void backToMain();
    void draw(QPainter* paint);
    void checkCoord(int x, int y, bool press = false);
    void action();
    void shoot();
    void setSounds(QSound* crack, QSound* list);
    bool isInGame();
    reloadBar* relBar;

private:
    Game() = default;
    Game(const Game& root) = delete;
    Game& operator=(const Game&) = delete;
    void* operator new(std::size_t) = delete;
    void* operator new[](std::size_t) = delete;
    void operator delete(void*) = delete;
    void operator delete[](void*) = delete;

    SpaceShip& ship = SpaceShip::getInstance();
    QPixmap* aster = nullptr;
    QPixmap* smallaster = nullptr;
    QPixmap* backgrounds = nullptr;
    QPixmap* buts = nullptr;
    QPixmap* backbut = nullptr;
    QPixmap* spaceship = nullptr;
    QPixmap* bul = nullptr;
    QPixmap* rel = nullptr;
    unsigned short* step = nullptr;
    const QString texts[BUTAMOUNT] = {"Start Game", "Leaderboards", "Help", "Exit"};
    bool inGame = false;
    Button* buttons[BUTAMOUNT];
    Button* back;
    unsigned int score = 0;
    bool* directions = nullptr;
    unsigned char* curback = nullptr;
    QList<Bullet*> bullets;
    QList<Asteroid*> asteroids;
    QList<std::string> names;
    QList<unsigned int> records;
    void checkControls();
    Asteroid* genNewAster();
    void clearMem();
    void checkCollisions();
    void createPieces(Asteroid* potsient);
    template<class T>
    void checkScreenBounds(T* smth, int size);
    QSound* crack;
    QSound* list;
    void readRecords();
    void writeRecords();
    void addRecord();
    void showRecords();
    QLineEdit* line;
    QMessageBox mes;
};

#endif // GAME_H
