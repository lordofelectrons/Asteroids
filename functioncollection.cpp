#include "functioncollection.h"

QPixmap funcCol::turn(QPixmap img, short angle)
{
    QPixmap rot(img.size());
    rot.fill(Qt::transparent);
    QPainter p(&rot);
    p.translate(rot.size().width() / 2, rot.size().height() / 2);
    p.rotate(angle);
    p.translate(-rot.size().width() / 2, -rot.size().height() / 2);
    p.drawPixmap(0,0,img);
    p.end();
    return rot;
}

void funcCol::movestraight(bool direction, short curangle, double* x, double* y, unsigned char speed)
{
    double fDiffX = speed * sin(curangle * PI / HALFCIRCLE);
    double fDiffY = -(speed * cos(curangle * PI / HALFCIRCLE));
    if(!direction)
    {
        fDiffX = -fDiffX;
        fDiffY = -fDiffY;
    }
    *x += fDiffX;
    *y += fDiffY;
}
