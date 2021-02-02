#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QPainter>
#include <QPixmap>
#include <QSound>

enum consts
{
    //windowopt
    WINDOWWIDTH = 800,
    WINDOWHEIGHT = 600,
    FRAMESAMOUNT = 10,
    //steps
    UPDSTEP = 2,
    CHECKCOLSTEP = 10,
    //butopts
    BUTWIDTH = 300,
    BUTHEIGHT = 70,
    BUTJURYHEIGHT = 80,
    BUTAMOUNT = 4,
    BUTSTARTX = 250,
    BUTSTARTY = 100,
    NAMEHEIGHT = 50,
    //staff
    MAXSHORT = 65535,
    MAXTURN = 360,
    DIRAMOUNT = 4,
    HALFCIRCLE =  180,
    //spaceship
    SHIPSIZE = 100,
    SHIPSPEED = 5,
    SHIPTURNSPEED = 3,
    FIRESTEP = 15,
    //bullet
    BULLETSPEED = 20,
    BULLETSIZE = 50,
    //reloadbar
    MAXLENGTH = 240,
    HEIGHT = 20,
    MINLENGTH = 20,
    BARSTEP = 2,
    SHOOTDIF = 100,
    BARX = 20,
    BARY = 560,
    //asteroid
    MAXTURNSPEED = 10,
    GENCHANCE = 2,
    MAXCHANCE = 100,
    ASTERSIZE = 100,
    SMALLASTERSIZE = 50,
    ASTERTYPES = 3,
    MAXASTSPEED = 5,
    SMALLMIN = 2,
    SMALLMAX = 3,
    SCOREBIG = 100,
    SCORESMALL = 50
};

#define PI 3.14
#define recordPath "records.txt"
#define helptext "Космічний корабель контролюється за допомогою стрілок.\nГоловна ціль гри - набрати якомога більше очок.\nЗа розбиття великого астероїда надається 100 очок, уламку - 50.\nГра закінчується після попадання астероїду або уламку у корабель."

#endif // CONSTANTS_H
