#ifndef MYFAHRZEUG_H
#define MYFAHRZEUG_H

#include "Plan.h"
#include "MyDraw.h"
#define AUTOCOLOR       Gelb
#define RADCOLOR        Schwarz
#define LANGECOLOR      Schwarz
#define LANGEKURZ       2
#define RADPEN          2
#define LANGEPEN        1
#define AUTOW           12 
#define AUTOH           30
#define RAD             6
#define LANGE           (AUTOW + 4) 
#define ROADS           14
#define MAXSPEED        5
#define SAFESPACE       5 
#define SPEEDSCHRITT    0.1

#define STARTY      ((GetMaxH() - MYLANEWIDTH * 6) / 2 )
#define ENDY        ((GetMaxH() + MYLANEWIDTH * 6) / 2 )
#define STARTX      ((GetMaxW() - MYLANEWIDTH * 7) / 2 )
#define ENDX        ((GetMaxW() + MYLANEWIDTH * 7) / 2 )

#define FLX         (STARTX - LEERwIDTH)
#define FRX         (ENDX + LEERwIDTH)
#define FOY         (STARTY - LEERwIDTH)
#define FUY         (ENDY + LEERwIDTH)

#define R2BSTART   (ENDX - 2 * MYLANEWIDTH)
#define R2BEND     (ENDY)

#define R5BSTART   (ENDY - MYLANEWIDTH)
#define R5BEND     (STARTX) 

#define R6BSTART   (ENDY - MYLANEWIDTH)
#define R6BEND     (STARTX) 

#define R9BSTART   (STARTX + 2 * MYLANEWIDTH)
#define R9BEND    (STARTY)

#define R12BSTART   (STARTY + MYLANEWIDTH)
#define R12BEND    (ENDX)

#define R13BSTART   (STARTY + MYLANEWIDTH)
#define R13BEND    (ENDX)

#define BIEGEN0     (1.0 * MYROADRADIO + MYLANEWIDTH / 2)
#define BIEGEN3     (1.0 * MYROADRADIO + MYLANEWIDTH / 2)
#define BIEGEN7     (1.0 * MYROADRADIO + MYLANEWIDTH / 2)
#define BIEGEN10    (1.0 * MYROADRADIO + MYLANEWIDTH / 2)
#define BIEGEN9     (1.0 * MYLANEWIDTH * 7 / 2)
#define BIEGEN2     (1.0 * MYLANEWIDTH * 7 / 2)
#define BIEGEN6     (1.0 * MYLANEWIDTH * 7 / 2)
#define BIEGEN5     (1.0 * MYLANEWIDTH * 9 / 2)
#define BIEGEN13    (1.0 * MYLANEWIDTH * 7 / 2)
#define BIEGEN12    (1.0 * MYLANEWIDTH * 9 / 2)


#define UP          (2.0 * 0.0)
#define DOWN        (2.0 * M_PI * 180 / 360)
#define LEFT        (2.0 * M_PI * 270 / 360)
#define RIGHT       (2.0 * M_PI * 90 / 360)


class MyFahrzeug : public TPlan{

public:
    void setAutoWidth(int);
    int  getAutoWidth(void);
    void setAutoHeight(int);
    int  getAutoHeight(void);
    int setRoadNum(void);
    int getRoadNum(void);
    void setSpeed(double speed);
    void setSpeed(MyFahrzeug* fs);
    double getSpeed(void);
    MyFahrzeug* createAuto(int width, int height, TColor color);
    void setPositon(void);
    double getPositionX(void);
    double getPositionY(void);
    double getAutoRichtung(void);
    void autoMove(void);
    void myDrawAuto(int positionX, int positionY, int autoW, int autoL,
                        double richtung, int radL, int lange, int kurz, int radPen, int langePen, 
                        TColor radColor, TColor autoColor);
 
private:
    int autoW, autoH;
    double autoPositionX, autoPositionY;
    int roadNum;
    //0 fur ^  90 fur > 180 fur unter 270 fur <
    double autoRichtung, autoSpeed;
    int calcRichtungPositionX(int PositionX, int PositionY, int centerX, int centerY, double richtung);
    int calcRichtungPositionY(int PositionX, int PositionY, int centerX, int centerY, double richtung);
    void richtungMove(void);
};

#endif