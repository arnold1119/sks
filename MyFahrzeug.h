#ifndef MYFAHRZEUG_H
#define MYFAHRZEUG_H

#include "Plan.h"
#include "MyDraw.h"
#define AUTOCOLOR Gelb
#define AUTOW 34
#define AUTOH 50
#define ROADS 14
#define MAXSPEED 5
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
    void setRoadNum(void);
    int getRoadNum(void);
    void setSpeed(double speed);
    double getSpeed(void);
    MyFahrzeug* createAuto(int width, int height, TColor color);
    void setPositon(void);
    double getPositionX(void);
    double getPositionY(void);

 
private:
    int autoW, autoH;
    int autoPositionX, autoPositionY;
    int roadNum;
    //0 fur ^  90 fur > 180 fur unter 270 fur <
    double autoRichtung, autoSpeed;
};

#endif