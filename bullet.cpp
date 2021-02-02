#include "bullet.h"
#include "functioncollection.h"

Bullet::Bullet(double x, double y, QPixmap* img, short angle) : doubleEntity(x, y, img)
{
    this->angle = angle;
}

void Bullet::draw(QPainter* paint)
{
    move();
    paint->drawPixmap(static_cast<int>(x), static_cast<int>(y), funcCol::turn(*img, angle));
}

void Bullet::move()
{
    funcCol::movestraight(true, angle, &x, &y, BULLETSPEED);
}

Bullet::~Bullet()
{}
