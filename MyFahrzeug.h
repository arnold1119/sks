#ifndef MYFAHRZEUG_H
#define MYFAHRZEUG_H

#include "Plan.h"
#include "MyDraw.h"
#define AUTOCOLOR Gelb
#define RADCOLOR Schwarz
#define LANGECOLOR Schwarz
#define LANGEKURZ 2
#define RADPEN 2
#define LANGEPEN 1
#define AUTOW 12 
#define AUTOH 30
#define RAD 6
#define LANGE  (AUTOW + 4) 
#define ROADS 14
#define MAXSPEED 5
#define SAFESPACE 5 
#define SPEEDSCHRITT 0.1

#define STARTY   ((GetMaxH() - MYLANEWIDTH * 6) / 2 )
#define ENDY  ((GetMaxH() + MYLANEWIDTH * 6) / 2 )
#define STARTX ((GetMaxW() - MYLANEWIDTH * 7) / 2 )
#define ENDX  ((GetMaxW() + MYLANEWIDTH * 7) / 2 )



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
    int autoPositionX, autoPositionY;
    int roadNum;
    //0 fur ^  90 fur > 180 fur unter 270 fur <
    double autoRichtung, autoSpeed;
    int calcRichtungPositionX(int PositionX, int PositionY, int centerX, int centerY, double richtung);
    int calcRichtungPositionY(int PositionX, int PositionY, int centerX, int centerY, double richtung);
};

#endif