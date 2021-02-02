#include "reloadbar.h"

reloadBar::reloadBar(int x, int y, QPixmap* img) : staticEntity(x, y, img)
{}

void reloadBar::draw(QPainter* paint)
{
    paint->drawPixmap(x, y, img->copy(0, 0, curstate, HEIGHT));
}

void reloadBar::action()
{
    if(curstate + BARSTEP <= MAXLENGTH)
    {
        curstate += BARSTEP;
    }
}

bool reloadBar::shoot()
{
    if(curstate - SHOOTDIF >= MINLENGTH)
    {
        curstate -= SHOOTDIF;
        return true;
    }
    else
    {
        return false;
    }
}

reloadBar::~reloadBar()
{}
