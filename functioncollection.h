#ifndef FUNCTIONCOLLECTION_H
#define FUNCTIONCOLLECTION_H

#include "constants.h"

class funcCol
{
public:
    static QPixmap turn(QPixmap img, short angle);
    static void movestraight(bool direction, short curangle, double* x, double* y, unsigned char speed);
};

#endif // FUNCTIONCOLLECTION_H
