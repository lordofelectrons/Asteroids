#include "asteroid.h"
#include "functioncollection.h"

Asteroid::Asteroid(double x, double y, QPixmap* img, short anglefly, unsigned char type) : doubleEntity(x, y, img)
{
    this->anglefly = anglefly;
    this->type = type;
    angspeed = qrand() % MAXTURNSPEED + 1;
    speed = qrand() % MAXASTSPEED + 2;
    if(qrand() % 2)
    {
        angspeed = -angspeed;
    }
}

unsigned char Asteroid::getType()
{
    return type;
}

void Asteroid::draw(QPainter* paint)
{
    move();
    paint->drawPixmap(static_cast<int>(x), static_cast<int>(y), funcCol::turn(img->copy(img->size().height() * type, 0, img->size().height(), img->size().height()), angle));
}

bool Asteroid::checkBUM(int x, int y)
{
    if(checkcoords(this->x, x) && checkcoords(this->y, y))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Asteroid::isBig()
{
    if(img->size().height() == ASTERSIZE)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Asteroid::checkcoords(double c1, int c2)
{
    int cursize = img->size().height();
    return (c1 < c2 && c2 < c1 + cursize);
}

void Asteroid::turn()
{
    angle += angspeed;
    if(angle > MAXTURN)
    {
        angle -= MAXTURN;
    }
    else if(angle < 0)
    {
        angle += MAXTURN;
    }
}

void Asteroid::move()
{
    funcCol::movestraight(true, anglefly, &x, &y, speed);
    turn();
}

Asteroid::~Asteroid()
{}
