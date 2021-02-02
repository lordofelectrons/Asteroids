#ifndef ASTEROID_H
#define ASTEROID_H

#include "doubleentity.h"

class Asteroid : public doubleEntity
{
public:
    Asteroid(double x, double y, QPixmap* img, short anglefly, unsigned char type);
    virtual void draw(QPainter* paint);
    void move();
    void turn();
    bool checkBUM(int x, int y);
    bool isBig();
    unsigned char getType();
    virtual ~Asteroid();

private:
    short anglefly = 0, angle = 0;
    char angspeed = 0;
    bool checkcoords(double c1, int c2);
    unsigned char type = 0;
    unsigned char speed = 0;
};

#endif // ASTEROID_H
