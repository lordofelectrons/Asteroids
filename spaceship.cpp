#include "spaceship.h"
#include "functioncollection.h"

void SpaceShip::setDef(int x, int y, QPixmap* img, QPixmap* bul, unsigned short* step)
{
    this->x = x;
    this->y = y;
    this->img = img;
    this->step = step;
    this->bul = bul;
    curangle = 0;
}

SpaceShip& SpaceShip::getInstance()
{
    static SpaceShip theSingleInstance;
    return theSingleInstance;
}

void SpaceShip::moveside(bool direction)
{
    if(direction)
    {
        curangle += SHIPTURNSPEED;
    }
    else
    {
        curangle -= SHIPTURNSPEED;
    }
    if(curangle > MAXTURN)
    {
        curangle -= MAXTURN;
    }
    else if(curangle < 0)
    {
        curangle += MAXTURN;
    }
}

void SpaceShip::movestraight(bool direction)
{
    funcCol::movestraight(direction, curangle, &x, &y, SHIPSPEED);
    if(x < 0)
    {
        x += SHIPSPEED;
    }
    else if (x + SHIPSIZE > WINDOWWIDTH)
    {
        x -= SHIPSPEED;
    }
    if(y < 0)
    {
        y += SHIPSPEED;
    }
    else if (y + SHIPSIZE > WINDOWHEIGHT)
    {
        y -= SHIPSPEED;
    }
}

short SpaceShip::getAngle()
{
    return curangle;
}

int SpaceShip::getCoord(bool mode)
{
    if(mode)
    {
        return static_cast<int>(x);
    }
    else
    {
        return static_cast<int>(y);
    }
}

void SpaceShip::draw(QPainter* paint)
{
    if(*step % FIRESTEP == 0)
    {
        curimg = !curimg;
    }
    paint->drawPixmap(static_cast<int>(x), static_cast<int>(y), funcCol::turn(img->copy(curimg * SHIPSIZE, 0, SHIPSIZE, SHIPSIZE), curangle));
}
