#ifndef BULLET_H
#define BULLET_H

#include "doubleentity.h"

class Bullet : public doubleEntity
{
public:
    Bullet(double x, double y, QPixmap* img, short angle);
    virtual void draw(QPainter* paint);
    void move();
    virtual ~Bullet();

private:
    short angle;
};

#endif // BULLET_H
