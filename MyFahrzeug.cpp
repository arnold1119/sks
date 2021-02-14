#include "MyFahrzeug.h"
#include "Plan.h"
#include <list.h>


list<MyFahrzeug *> r0;
list<MyFahrzeug *> r1;
list<MyFahrzeug *> r2;
list<MyFahrzeug *> r3;
list<MyFahrzeug *> r4;
list<MyFahrzeug *> r5;
list<MyFahrzeug *> r6;
list<MyFahrzeug *> r7;
list<MyFahrzeug *> r8;
list<MyFahrzeug *> r9;
list<MyFahrzeug *> r10;
list<MyFahrzeug *> r11;
list<MyFahrzeug *> r12;
list<MyFahrzeug *> r13;


void MyFahrzeug::setAutoWidth(int width) {
    this->autoW = width;
}
int MyFahrzeug::getAutoWidth(void) {
    return this->autoW;
}
void MyFahrzeug::setAutoHeight(int height) {
    this->autoH = height;
}
int MyFahrzeug::getAutoHeight(void) {
    return this->autoH;
}
void MyFahrzeug::setSpeed(double speed) {
    double temp = (1.0 * (random(10) + 1) /10 + random(MAXSPEED));
    this->autoSpeed = temp > speed? speed : temp; 
}
void MyFahrzeug::setSpeed(MyFahrzeug* fs) {
    this->setSpeed(fs->getSpeed());
}
double MyFahrzeug::getSpeed(void) {
    return this->autoSpeed; 
}
int MyFahrzeug::setRoadNum(void) {
   return this->roadNum = random(ROADS);
}
int MyFahrzeug::getRoadNum(void) {
   return this->roadNum;
}
void MyFahrzeug::setPositon(void) {
    switch(this->roadNum) {
        case 0:
            this->autoPositionX = GetMaxW();
            this->autoPositionY = STARTY + 1.0 * MYLANEWIDTH / 2; 
            this->autoRichtung = 2.0 * M_PI * 270 / 360;
            r0.push_front(this);
            break;
        case 1:
            this->autoPositionX = GetMaxW();
            this->autoPositionY = STARTY + 3.0 * MYLANEWIDTH / 2; 
            this->autoRichtung = 2.0 * M_PI * 270 / 360;
            r1.push_front(this);
            break;
        case 2:
            this->autoPositionX = GetMaxW();
            this->autoPositionY = STARTY + 5.0 * MYLANEWIDTH / 2; 
            this->autoRichtung = 2.0 * M_PI * 270 / 360;
            r2.push_front(this);
            break;
        case 3:
            this->autoPositionY = GetMaxH();
            this->autoPositionX = ENDX - 1.0 * MYLANEWIDTH / 2;
            this->autoRichtung = 2.0 * 0.0;
            r3.push_front(this);
            break;
        case 4:
            this->autoPositionY = GetMaxH();
            this->autoPositionX = ENDX - 3.0 * MYLANEWIDTH / 2;
            this->autoRichtung = 2.0 * 0.0;
            r4.push_front(this);
            break;
        case 5:
            this->autoPositionY = GetMaxH();
            this->autoPositionX = ENDX - 5.0 * MYLANEWIDTH / 2;
            this->autoRichtung = 2.0 * 0.0;
            r5.push_front(this);
            break;
        case 6:
            this->autoPositionY = GetMaxH();
            this->autoPositionX = ENDX - 7.0 * MYLANEWIDTH / 2;
            this->autoRichtung = 2.0 * 0.0;
            r6.push_front(this);
            break;
        case 7:
            this->autoPositionX = 0.0; 
            this->autoPositionY = ENDY - 1.0 * MYLANEWIDTH / 2;
            this->autoRichtung = 2.0 * M_PI * 90 / 360;
            r7.push_front(this);
            break;
        case 8:
            this->autoPositionX = 0.0; 
            this->autoPositionY = ENDY - 3.0 * MYLANEWIDTH / 2;
            this->autoRichtung = 2.0 * M_PI * 90 / 360;
            r8.push_front(this);
            break;
        case 9:
            this->autoPositionX = 0.0; 
            this->autoPositionY = ENDY - 5.0 * MYLANEWIDTH / 2;
            this->autoRichtung = 2.0 * M_PI * 90 / 360;
            r9.push_front(this);
            break;
        case 10:
            this->autoPositionY = 0.0; 
            this->autoPositionX = STARTX + 1.0 * MYLANEWIDTH / 2;
            this->autoRichtung = 2.0 * M_PI * 180 / 360;
            r10.push_front(this);
            break;
        case 11:
            this->autoPositionY = 0.0; 
            this->autoPositionX = STARTX + 3.0 * MYLANEWIDTH / 2;
            this->autoRichtung = 2.0 * M_PI * 180 / 360;
            r11.push_front(this);
            break;
        case 12:
            this->autoPositionY = 0.0; 
            this->autoPositionX = STARTX + 5.0 * MYLANEWIDTH / 2;
            this->autoRichtung = 2.0 * M_PI * 180 / 360;
            r12.push_front(this);
            break;
        case 13:
            this->autoPositionY = 0.0; 
            this->autoPositionX = STARTX + 7.0 * MYLANEWIDTH / 2;
            this->autoRichtung = 2.0 * M_PI * 180 / 360;
            r13.push_front(this);
            break;
        default:
            break; 
    }
}
double MyFahrzeug::getPositionX(void) {
    return this->autoPositionX;
}
double MyFahrzeug::getPositionY(void) {
    return this->autoPositionY;
}

double MyFahrzeug::getAutoRichtung(void) {
    return this->autoRichtung;
}
MyFahrzeug* MyFahrzeug::createAuto(int width = AUTOW, int height = AUTOH, TColor color = AUTOCOLOR) {
    this->setRoadNum();
    this->setPositon();
    printf("Road ist %d,\tX ist %f,\tY ist %f,\tRichtung ist %f\n", 
        this->getRoadNum(), this->getPositionX(), this->getPositionY(), this->getAutoRichtung());
    this->setSpeed(MAXSPEED);
  
    myDrawAuto(this->getPositionX(), this->getPositionY(), AUTOW, AUTOH,
                        this->getAutoRichtung(), RAD, LANGE, LANGEKURZ, RADPEN, LANGEPEN, 
                        RADCOLOR, AUTOCOLOR);
    return this;
}

void MyFahrzeug::autoMove(void) {
    this->autoPositionX += this->getSpeed();
     this->autoPositionY += this->getSpeed();
    myDrawAuto(this->getPositionX(), this->getPositionY(), AUTOW, AUTOH,
                        this->getAutoRichtung(), RAD, LANGE, LANGEKURZ, RADPEN, LANGEPEN, 
                        RADCOLOR, AUTOCOLOR);
}
void MyFahrzeug::myDrawAuto(int x, int y, int autoW, int autoL,
                        double richtung, int radL, int lange, int kurz, int radPen,
                        int langePen, TColor radColor, TColor autoColor) {
    ClearPoints(); 
    
    
    //Auto Position
    int autoLeftPX   = x -autoW / 2;
    int autoRightPX  = x + autoW / 2;
    int autoFrontPY  = y - autoL / 2;
    int autoHintenPY = y + autoL / 2;

    int calAutoLeftPX   = this->calcRichtungPositionX(autoLeftPX, autoFrontPY, x, y, richtung);
    int calAutoFrontPY  = this->calcRichtungPositionY(autoLeftPX, autoFrontPY, x, y, richtung);
    int calAutoFRPX   = this->calcRichtungPositionX(autoRightPX, autoFrontPY, x, y, richtung);
    int calAutoFRPY  = this->calcRichtungPositionY(autoRightPX, autoFrontPY, x, y, richtung);
    int calAutoRightPX  = this->calcRichtungPositionX(autoRightPX, autoHintenPY, x, y, richtung);
    int calAutoHintenPY = this->calcRichtungPositionY(autoRightPX, autoHintenPY, x, y, richtung);
    int calAutoHLPX  = this->calcRichtungPositionX(autoLeftPX, autoHintenPY, x, y, richtung);
    int calAutoHLPY = this->calcRichtungPositionY(autoLeftPX, autoHintenPY, x, y, richtung);
    
    //Lange Position
    int leftLangePX  = x - lange / 2;
    int rightLangePX = x + lange / 2;
    int frontLangPY = y - autoL / 2 + kurz + radL / 2;
    int hintenLangPY = y + autoL / 2 - kurz - radL / 2;

    int calLeftlangePX   = this->calcRichtungPositionX(leftLangePX, frontLangPY, x, y, richtung);
    int calFrontLangPY   = this->calcRichtungPositionY(leftLangePX, frontLangPY, x, y, richtung);
    int calLangFRPX      = this->calcRichtungPositionX(rightLangePX, frontLangPY, x, y, richtung);
    int calLangFRPY      = this->calcRichtungPositionY(rightLangePX, frontLangPY, x, y, richtung);
    int calLangHLPX      = this->calcRichtungPositionX(leftLangePX, hintenLangPY, x, y, richtung);
    int calLangHLPY      = this->calcRichtungPositionY(leftLangePX, hintenLangPY, x, y, richtung);
    int calRightLangePX  = this->calcRichtungPositionX(rightLangePX, hintenLangPY, x, y, richtung);
    int calHintenLangePY = this->calcRichtungPositionY(rightLangePX, hintenLangPY, x, y, richtung);

    //Rad Position
    int frontRadP0Y = y - autoL / 2 + kurz;
    int frontRadP1Y = y - autoL / 2 + kurz + radL;
    int hintenP0Y = y + autoL / 2 - kurz;
    int hintenP1Y = y + autoL / 2 - kurz - radL;

    int calRadFLP0X = this->calcRichtungPositionX(leftLangePX, frontRadP0Y, x, y, richtung);
    int calRadFLP0Y = this->calcRichtungPositionY(leftLangePX, frontRadP0Y, x, y, richtung);

    int calRadFLP1X = this->calcRichtungPositionX(leftLangePX, frontRadP1Y, x, y, richtung);
    int calRadFLP1Y = this->calcRichtungPositionY(leftLangePX, frontRadP1Y, x, y, richtung);
    
    int calRadFRP0X = this->calcRichtungPositionX(rightLangePX, frontRadP0Y, x, y, richtung);
    int calRadFRP0Y = this->calcRichtungPositionY(rightLangePX, frontRadP0Y, x, y, richtung);
    
    int calRadFRP1X = this->calcRichtungPositionX(rightLangePX, frontRadP1Y, x, y, richtung);
    int calRadFRP1Y = this->calcRichtungPositionY(rightLangePX, frontRadP1Y, x, y, richtung);

    int calRadHLP0X = this->calcRichtungPositionX(leftLangePX, hintenP0Y, x, y, richtung);
    int calRadHLP0Y = this->calcRichtungPositionY(leftLangePX, hintenP0Y, x, y, richtung);

    int calRadHLP1X = this->calcRichtungPositionX(leftLangePX, hintenP1Y, x, y, richtung);
    int calRadHLP1Y = this->calcRichtungPositionY(leftLangePX, hintenP1Y, x, y, richtung);

    int calRadHRP0X = this->calcRichtungPositionX(rightLangePX, hintenP0Y, x, y, richtung);
    int calRadHRP0Y = this->calcRichtungPositionY(rightLangePX, hintenP0Y, x, y, richtung);

    int calRadHRP1X = this->calcRichtungPositionX(rightLangePX, hintenP1Y, x, y, richtung);
    int calRadHRP1Y = this->calcRichtungPositionY(rightLangePX, hintenP1Y, x, y, richtung);
 
    
    //RAD
    SetPen(radColor, radPen);
    MoveTo(calRadFLP0X, calRadFLP0Y); //front left rad 
    LineTo(calRadFLP1X, calRadFLP1Y); //front left rad 
    MoveTo(calRadFRP0X, calRadFRP0Y); //front right rad 
    LineTo(calRadFRP1X, calRadFRP1Y); //front right rad 
    MoveTo(calRadHLP0X, calRadHLP0Y); //hinten left rad 
    LineTo(calRadHLP1X, calRadHLP1Y); //hinten left rad 
    MoveTo(calRadHRP0X, calRadHRP0Y); //hinten right rad 
    LineTo(calRadHRP1X, calRadHRP1Y); //hinten right rad 

    //Lange
    SetPen(radColor, langePen);
    MoveTo(calLeftlangePX, calFrontLangPY); //front lange 
    LineTo(calLangFRPX, calLangFRPY);  //front lange
    MoveTo(calLangHLPX, calLangHLPY); //hinten lange
    LineTo(calRightLangePX, calHintenLangePY); //hinten lange 
  
    //Auto
    SetPoint(calAutoLeftPX, calAutoFrontPY);
    SetPoint(calAutoFRPX, calAutoFRPY);
    SetPoint(calAutoRightPX, calAutoHintenPY);
    SetPoint(calAutoHLPX, calAutoHLPY);
    SetPoint(calAutoLeftPX, calAutoFrontPY);
    SetPenColor(Klar);
    SetBrushColor(autoColor);
    Poly();
}

int MyFahrzeug::calcRichtungPositionX(int PositionX, int PositonY, int centerX, int centerY, double richtung) {
    return cos(richtung) * (PositionX - centerX) - sin(richtung) * (PositonY - centerY) + centerX;
}

int MyFahrzeug::calcRichtungPositionY(int PositionX, int PositionY, int centerX, int centerY, double richtung) {
    return sin(richtung) * (PositionX - centerX) + cos(richtung) * (PositionY - centerY) + centerY;
}