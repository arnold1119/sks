#ifndef MYFAHRZEUG_H
#define MYFAHRZEUG_H

#include "Plan.h"
#include "MyDraw.h"
#include <list>
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
#define MAXSPEED        4.5
#define SAFESPACE       5 
#define SPEEDSCHRITT    0.1


#define CREATEAUTOUP    (AUTOH / 2 + SAFESPACE + 20)
#define CREATEAUTOLEFT  (AUTOH / 2 + SAFESPACE + 20)


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

class MyFahrzeug{

public:
    MyFahrzeug(void);
    init(double x, double y);
    MyFahrzeug(const MyFahrzeug& fs);
    MyFahrzeug& operator=(const MyFahrzeug& other);
    ~MyFahrzeug(void);
    void setAutoWidth(int);
    int  getAutoWidth(void);
    void setAutoHeight(int);
    int  getAutoHeight(void);
    int setRoadNum(void);
    int getRoadNum(void);
    void setSpeed(double speed);
    void setMaxSpeed(MyFahrzeug& fs);
    double getSpeed(void);
    MyFahrzeug& createAuto(int& roadNum, int width, int height, TColor color);
    void setPositon(void);
    double getPositionX(void);
    double getPositionY(void);
    double getAutoRichtung(void);
    MyFahrzeug& autoMove(void);
    void autoDraw(void);
    double getW(void);
    double getH(void);
 
private:
    double w, h;
    int autoW, autoH;
    double autoPositionX, autoPositionY;
    int roadNum;
    //0 fur ^  90 fur > 180 fur unter 270 fur <
    double autoRichtung, autoSpeed;
    void richtungMove(void);

    int CREATEAUTODOWN; 
    int CREATEAUTORIGHT;
    int STARTY;
    int ENDY  ;
    int STARTX;
    int ENDX  ;
    int FLX ;
    int FRX;
    int FOY ;
    int FUY;
    int R2BSTART; 
    int R2BEND  ;
    int R5BSTART ;
    int R5BEND  ;
    int R6BSTART ;
    int R6BEND  ;
    int R9BSTART ;
    int R9BEND  ;
    int R12BSTART;
    int R12BEND ;
    int R13BSTART;
    int R13BEND ;
};

#endif