#ifndef DOUBLEENTITY_H
#define DOUBLEENTITY_H

#include "constants.h"

class doubleEntity
{
public:
    doubleEntity(double x, double y, QPixmap* img);
    virtual void draw(QPainter* paint) = 0;
    int getCoord(bool mode);
    virtual ~doubleEntity();

protected:
    double x = 0, y = 0;
    QPixmap* img;
};

#endif // DOUBLEENTITY_H
