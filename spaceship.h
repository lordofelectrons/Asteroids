#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "constants.h"
#include "bullet.h"

class SpaceShip
{
public:
    static SpaceShip& getInstance();
    void setDef(int x, int y, QPixmap* img, QPixmap* bul, unsigned short* step);
    void draw(QPainter* paint);
    void moveside(bool direction);
    void movestraight(bool direction);
    short getAngle();
    int getCoord(bool mode);

private:
    SpaceShip() = default;
    SpaceShip(const SpaceShip& root) = delete;
    SpaceShip& operator=(const SpaceShip&) = delete;
    void* operator new(std::size_t) = delete;
    void* operator new[](std::size_t) = delete;
    void operator delete(void*) = delete;
    void operator delete[](void*) = delete;

    double x = 0, y = 0;
    QPixmap* img;
    QPixmap* bul;
    QSound* shootsound;
    bool curimg = false;
    short curangle = 0;
    unsigned short* step = nullptr;
};

#endif // SPACESHIP_H
