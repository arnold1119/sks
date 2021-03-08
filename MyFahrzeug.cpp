#include "MyFahrzeug.h"
#include "Plan.h"


MyFahrzeug:: MyFahrzeug(){}
MyFahrzeug:: init(double x, double y){
    this->w = x;
    this->h = y;
    CREATEAUTODOWN = (h - AUTOH / 2 - SAFESPACE - 20);
    CREATEAUTORIGHT = (w - AUTOH / 2 - SAFESPACE - 20);
    STARTY = ((h - MYLANEWIDTH * 6) / 2);
    ENDY = ((h + MYLANEWIDTH * 6) / 2);
    STARTX = ((w - MYLANEWIDTH * 7) / 2);
    ENDX = ((w + MYLANEWIDTH * 7) / 2);
    FLX = (STARTX - LEERwIDTH);
    FRX = (ENDX + LEERwIDTH);
    FOY = (STARTY - LEERwIDTH);
    FUY = (ENDY + LEERwIDTH);
    R2BSTART = (ENDX - 2 * MYLANEWIDTH);
    R2BEND = (ENDY);
    R5BSTART = (ENDY - MYLANEWIDTH);
    R5BEND = (STARTX);
    R6BSTART = (ENDY - MYLANEWIDTH);
    R6BEND = (STARTX);
    R9BSTART = (STARTX + 2 * MYLANEWIDTH);
    R9BEND = (STARTY);
    R12BSTART = (STARTY + MYLANEWIDTH);
    R12BEND = (ENDX);
    R13BSTART = (STARTY + MYLANEWIDTH);
    R13BEND = (ENDX);
}

double MyFahrzeug::getW(void) {
    return this->w;
}
double MyFahrzeug::getH(void) {
    return this->h;
}
MyFahrzeug:: MyFahrzeug(const MyFahrzeug& fs){
    this->w = fs.w;
    this->h = fs.h;
    this->autoW = fs.autoW;
    this->autoH = fs.autoH;
    this->autoPositionX = fs.autoPositionX;
    this->autoPositionY = fs.autoPositionY;
    this->roadNum = fs.roadNum;
    this->autoRichtung = fs.autoRichtung;
    this->autoSpeed = fs.autoSpeed;
    this->CREATEAUTODOWN = fs.CREATEAUTODOWN;
    this->CREATEAUTORIGHT = fs.CREATEAUTORIGHT;
    this->STARTY = fs.STARTY;
    this->ENDY   = fs.ENDY;
    this->STARTX = fs.STARTX;
    this->ENDX   = fs.ENDX;
    this->FLX  = fs.FLX;
    this->FRX = fs.FRX;
    this->FOY  = fs.FOY;
    this->FUY = fs.FUY;
    this->R2BSTART = fs.R2BSTART;
    this->R2BEND   = fs.R2BEND;
    this->R5BSTART  = fs.R5BSTART;
    this->R5BEND   = fs.R5BEND;
    this->R6BSTART  = fs.R6BSTART;
    this->R6BEND   = fs.R6BEND;
    this->R9BSTART  = fs.R9BSTART;
    this->R9BEND   = fs.R9BEND;
    this->R12BSTART = fs.R12BSTART;
    this->R12BEND  = fs.R12BEND;
    this->R13BSTART = fs.R13BSTART;
    this->R13BEND  = fs.R13BEND;
}
MyFahrzeug& MyFahrzeug::operator=(const MyFahrzeug& fs) {
    if(this == &fs)
        return *this;
    this->w = fs.w;
    this->h = fs.h;
    this->autoW = fs.autoW;
    this->autoH = fs.autoH;
    this->autoPositionX = fs.autoPositionX;
    this->autoPositionY = fs.autoPositionY;
    this->roadNum = fs.roadNum;
    this->autoRichtung = fs.autoRichtung;
    this->autoSpeed = fs.autoSpeed;
        this->CREATEAUTODOWN = fs.CREATEAUTODOWN;
    this->CREATEAUTORIGHT = fs.CREATEAUTORIGHT;
    this->STARTY = fs.STARTY;
    this->ENDY   = fs.ENDY;
    this->STARTX = fs.STARTX;
    this->ENDX   = fs.ENDX;
    this->FLX  = fs.FLX;
    this->FRX = fs.FRX;
    this->FOY  = fs.FOY;
    this->FUY = fs.FUY;
    this->R2BSTART = fs.R2BSTART;
    this->R2BEND   = fs.R2BEND;
    this->R5BSTART  = fs.R5BSTART;
    this->R5BEND   = fs.R5BEND;
    this->R6BSTART  = fs.R6BSTART;
    this->R6BEND   = fs.R6BEND;
    this->R9BSTART  = fs.R9BSTART;
    this->R9BEND   = fs.R9BEND;
    this->R12BSTART = fs.R12BSTART;
    this->R12BEND  = fs.R12BEND;
    this->R13BSTART = fs.R13BSTART;
    this->R13BEND  = fs.R13BEND;
    return *this;
}

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
    
    if(speed >= MAXSPEED) {
        this->autoSpeed = MAXSPEED;
    } else {
        this->autoSpeed = speed;
    }
    if(speed == MAXSPEED + 2.5) {
        this->autoSpeed = speed;
    }
}


void MyFahrzeug::setMaxSpeed(MyFahrzeug& fs) {
    double dis = (fs.getPositionX() - this->autoPositionX) * (fs.getPositionX() - this->autoPositionX)
                  + (fs.getPositionY() - this->autoPositionY) * (fs.getPositionY() - this->autoPositionY);
    // printf("dis -------------------speed ist %f\n", dis);
    dis = sqrt(dis) - SAFESPACE - AUTOH;
    if(dis < 0) {
        setSpeed(0);
        return;
    }
    // printf("sqrt  dis -------------------speed ist %f\n", dis);
    setSpeed(dis);
}
void MyFahrzeug::setMaxSpeed(MyFahrzeug& fs, int roadNum, int stopPosition) {
    double dis = 0.0;
    switch (roadNum)
    {
    case 0:
    case 1:
    case 2:
        dis = fs.getPositionX() - stopPosition - 2 * SAFESPACE;
        if (dis < 0)
        {
            setSpeed(0);
            return;
        }
        setSpeed(dis);
        break;
    case 3:
    case 4:
    case 5:
    case 6:
        dis = fs.getPositionY() - stopPosition - 2 * SAFESPACE;
        if (dis < 0)
        {
            setSpeed(0);
            return;
        }
        setSpeed(dis);
        break;
    case 7:
    case 8:
    case 9:
        dis = stopPosition - fs.getPositionX() - 2 * SAFESPACE;
        if (dis < 0)
        {
            setSpeed(0);
            return;
        }
        setSpeed(dis);
        break;
    case 10:
    case 11:
    case 12:
    case 13:
        dis = stopPosition - fs.getPositionY() - 2 * SAFESPACE;
        if (dis < 0)
        {
            setSpeed(0);
            return;
        }
        setSpeed(dis);
        break;
    default:
        break;
    }
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
            this->autoPositionX = w;
            this->autoPositionY = STARTY + 1.0 * MYLANEWIDTH / 2; 
            this->autoRichtung = 2.0 * M_PI * 270 / 360;
            break;
        case 1:
            this->autoPositionX = w;
            this->autoPositionY = STARTY + 3.0 * MYLANEWIDTH / 2; 
            this->autoRichtung = 2.0 * M_PI * 270 / 360;
            break;
        case 2:
            this->autoPositionX = w;
            this->autoPositionY = STARTY + 5.0 * MYLANEWIDTH / 2; 
            this->autoRichtung = 2.0 * M_PI * 270 / 360;
            break;
        case 3:
            this->autoPositionY = h;
            this->autoPositionX = ENDX - 1.0 * MYLANEWIDTH / 2;
            this->autoRichtung = 2.0 * 0.0;
            break;
        case 4:
            this->autoPositionY = h;
            this->autoPositionX = ENDX - 3.0 * MYLANEWIDTH / 2;
            this->autoRichtung = 2.0 * 0.0;
            break;
        case 5:
            this->autoPositionY = h;
            this->autoPositionX = ENDX - 5.0 * MYLANEWIDTH / 2;
            this->autoRichtung = 2.0 * 0.0;
            break;
        case 6:
            this->autoPositionY = h;
            this->autoPositionX = ENDX - 7.0 * MYLANEWIDTH / 2;
            this->autoRichtung = 2.0 * 0.0;
            break;
        case 7:
            this->autoPositionX = 0.0; 
            this->autoPositionY = ENDY - 1.0 * MYLANEWIDTH / 2;
            this->autoRichtung = 2.0 * M_PI * 90 / 360;
            break;
        case 8:
            this->autoPositionX = 0.0; 
            this->autoPositionY = ENDY - 3.0 * MYLANEWIDTH / 2;
            this->autoRichtung = 2.0 * M_PI * 90 / 360;
            break;
        case 9:
            this->autoPositionX = 0.0; 
            this->autoPositionY = ENDY - 5.0 * MYLANEWIDTH / 2;
            this->autoRichtung = 2.0 * M_PI * 90 / 360;
            break;
        case 10:
            this->autoPositionY = 0.0; 
            this->autoPositionX = STARTX + 1.0 * MYLANEWIDTH / 2;
            this->autoRichtung = 2.0 * M_PI * 180 / 360;
            break;
        case 11:
            this->autoPositionY = 0.0; 
            this->autoPositionX = STARTX + 3.0 * MYLANEWIDTH / 2;
            this->autoRichtung = 2.0 * M_PI * 180 / 360;
            break;
        case 12:
            this->autoPositionY = 0.0; 
            this->autoPositionX = STARTX + 5.0 * MYLANEWIDTH / 2;
            this->autoRichtung = 2.0 * M_PI * 180 / 360;
            break;
        case 13:
            this->autoPositionY = 0.0; 
            this->autoPositionX = STARTX + 7.0 * MYLANEWIDTH / 2;
            this->autoRichtung = 2.0 * M_PI * 180 / 360;
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
MyFahrzeug& MyFahrzeug::createAuto(int& roadNum, int width = AUTOW, int height = AUTOH, 
                                TColor color = AUTOCOLOR) {
    this->setRoadNum();
    this->setPositon();
    roadNum = this->getRoadNum(); 
   return *this; 
}


MyFahrzeug& MyFahrzeug::autoMove(void) {
    double richtungTMP = 0.0;
    switch (this->getRoadNum())
    {
        case 0:
        
            if(this->autoPositionY < FOY) {
                this->autoRichtung = UP;
            } else if(this->autoPositionX < FRX ) {
                richtungTMP = this->getSpeed() / BIEGEN0;
            } 
            this->richtungMove();
            this->autoRichtung += richtungTMP;
            break;
        case 2:
            if(this->autoPositionY > R2BEND) {
                this->autoRichtung = DOWN;
            } else if(this->autoPositionX < R2BSTART)  {
                richtungTMP = this->getSpeed() / BIEGEN2;
            }
            this->richtungMove();
            this->autoRichtung -= richtungTMP;
            break; 
        case 5:
            if(this->autoPositionX < R5BEND) {
                this->autoRichtung = LEFT;
            } else if(this->autoPositionY < R5BSTART)  {
                richtungTMP = this->getSpeed() / BIEGEN5;
            }
            this->richtungMove();
            this->autoRichtung -= richtungTMP;
            break;
        case 6:
            if(this->autoPositionX < R6BEND) {
                this->autoRichtung = LEFT;
            } else if(this->autoPositionY < R6BSTART)  {
                richtungTMP = this->getSpeed() / BIEGEN6;
            }
            this->richtungMove();
            this->autoRichtung -= richtungTMP;
            break;
        case 3:
            if(this->autoPositionX > FRX) {
                this->autoRichtung = RIGHT;
            } else if(this->autoPositionY < FUY) {
                richtungTMP = this->getSpeed() / BIEGEN3;
            }
            this->richtungMove();
            this->autoRichtung += richtungTMP;
            break;
        case 7:
            if(this->autoPositionY > FUY) {
                this->autoRichtung = DOWN;
            } else if(this->autoPositionX > FLX) {
                richtungTMP = this->getSpeed() / BIEGEN7; 
            }
            this->richtungMove();
            this->autoRichtung += richtungTMP;
            break;
        case 9:
            if(this->autoPositionY < R9BEND) {
                this->autoRichtung = UP;
            } else if(this->autoPositionX > R9BSTART)  {
                richtungTMP = this->getSpeed() / BIEGEN9;
            }
            this->richtungMove();
            this->autoRichtung -= richtungTMP;
            break;
        case 10:
            if(this->autoPositionX < FLX) {
                this->autoRichtung = LEFT;
            } else if(this->autoPositionY > FOY) {
                richtungTMP = this->getSpeed() / BIEGEN10;
            }
            this->richtungMove();
            this->autoRichtung += richtungTMP;
            break;
        case 12:
            if(this->autoPositionX > R12BEND) {
                this->autoRichtung = RIGHT;
            } else if(this->autoPositionY > R12BSTART)  {
                richtungTMP = this->getSpeed() / BIEGEN12;
            }
            this->richtungMove();
            this->autoRichtung -= richtungTMP;
            break;
        case 13:
            if(this->autoPositionX > R13BEND) {
                this->autoRichtung = RIGHT;
            } else if(this->autoPositionY > R13BSTART)  {
                richtungTMP = this->getSpeed() / BIEGEN13;
            }
            this->richtungMove();
            this->autoRichtung -= richtungTMP;
            break;
        case 1:
        case 4:
        case 8:
        case 11:
        default: 
            this->richtungMove();
            break;
    }

    return *this;
}
void MyFahrzeug::richtungMove(void) {
    this->autoPositionX += (sin(this->getAutoRichtung()) * this->getSpeed());
    this->autoPositionY -= (cos(this->getAutoRichtung()) * this->getSpeed());
}


MyFahrzeug::~MyFahrzeug() {
    // printf("auto delete\n");
}