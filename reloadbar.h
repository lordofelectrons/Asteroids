#ifndef RELOADBAR_H
#define RELOADBAR_H

#include "staticentity.h"

class reloadBar : staticEntity
{
public:
    reloadBar(int x, int y, QPixmap* img);
    virtual void draw(QPainter* paint);
    void action();
    bool shoot();
    virtual ~reloadBar();

private:
    unsigned char curstate = MAXLENGTH;
};

#endif // RELOADBAR_H
