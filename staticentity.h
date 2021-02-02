#ifndef STATICENTITY_H
#define STATICENTITY_H

#include "constants.h"

class staticEntity
{
public:
    staticEntity(int x, int y, QPixmap* img);
    virtual void draw(QPainter* paint) = 0;
    virtual ~staticEntity();

protected:
    int x = 0, y = 0;
    QPixmap* img;
};

#endif // STATICENTITY_H
