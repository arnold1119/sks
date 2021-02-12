#include "MyFahrzeug.h"
#include "Plan.h"


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
    double temp = (1.0 * (random(100) + 1) /10 + random(MAXSPEED));
    this->autoSpeed = temp > speed? speed : temp; 
}
double MyFahrzeug::getSpeed(void) {
    return this->autoSpeed; 
}
void MyFahrzeug::setRoadNum(void) {
   this->roadNum = random(ROADS);
}
int MyFahrzeug::getRoadNum(void) {
   return this->roadNum;
}
void MyFahrzeug::setPositon(void) {
    switch(this->roadNum) {
        case 0:
            this->autoPositionX = GetMaxW();
            this->autoPositionY = STARTY + MYLANEWIDTH / 2; 
            this->autoRichtung = 270 / 360 * M_PI;
            break;
        case 1:
            this->autoPositionX = GetMaxW();
            this->autoPositionY = STARTY + 3 * MYLANEWIDTH / 2; 
            this->autoRichtung = 270 / 360 * M_PI;
            break;
        case 2:
            this->autoPositionX = GetMaxW();
            this->autoPositionY = STARTY + 5 * MYLANEWIDTH / 2; 
            this->autoRichtung = 270 / 360 * M_PI;
            break;
        case 3:
            this->autoPositionY = GetMaxH();
            this->autoPositionX = ENDX - MYLANEWIDTH / 2;
            this->autoRichtung = 0.0;
            break;
        case 4:
            this->autoPositionY = GetMaxH();
            this->autoPositionX = ENDX - 3 * MYLANEWIDTH / 2;
            this->autoRichtung = 0.0;
            break;
        case 5:
            this->autoPositionY = GetMaxH();
            this->autoPositionX = ENDX - 5 * MYLANEWIDTH / 2;
            this->autoRichtung = 0.0;
            break;
        case 6:
            this->autoPositionY = GetMaxH();
            this->autoPositionX = STARTX + MYLANEWIDTH / 2;
            this->autoRichtung = 0.0;
            break;
        case 7:
            this->autoPositionX = 0.0; 
            this->autoPositionY = ENDY - MYLANEWIDTH / 2;
            this->autoRichtung = 90 / 360 * M_PI;
            break;
        case 8:
            this->autoPositionX = 0.0; 
            this->autoPositionY = STARTY + 3 * MYLANEWIDTH / 2;
            this->autoRichtung = 90 / 360 * M_PI;
            break;
        case 9:
            this->autoPositionX = 0.0; 
            this->autoPositionY = STARTY + MYLANEWIDTH / 2;
            this->autoRichtung = 90 / 360 * M_PI;
            break;
        case 10:
            this->autoPositionY = 0.0; 
            this->autoPositionX = STARTX + MYLANEWIDTH / 2;
            this->autoRichtung = 180 / 360 * M_PI;
            break;
        case 11:
            this->autoPositionY = 0.0; 
            this->autoPositionX = STARTX + 3 * MYLANEWIDTH / 2;
            this->autoRichtung = 180 / 360 * M_PI;
            break;
        case 12:
            this->autoPositionY = 0.0; 
            this->autoPositionX = STARTX + 5 * MYLANEWIDTH / 2;
            this->autoRichtung = 180 / 360 * M_PI;
            break;
        case 13:
            this->autoPositionY = 0.0; 
            this->autoPositionX = STARTX + 7 * MYLANEWIDTH / 2;
            this->autoRichtung = 180 / 360 * M_PI;
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
MyFahrzeug* MyFahrzeug::createAuto(int width = AUTOW, int height = AUTOH, TColor color = AUTOCOLOR) {
    this->setRoadNum();
    this->setSpeed(0);
    return this;
}