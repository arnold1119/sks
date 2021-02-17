//====================================================================
// Simulation dynamischer Systeme mit PLAN
//====================================================================
// Projektbeschreibung:
//
//====================================================================
#include <vcl.h>
#pragma hdrstop
#include <iostream>
#include <vector>
#include <list>
#include "Plan.h"
#include "MyDraw.h"
#include "MyFahrzeug.h"
 

#define CREATEAUTODOWN  (GetMaxH() - AUTOH / 2 - SAFESPACE - 20)
#define CREATEAUTORIGHT  (GetMaxW() - AUTOH / 2 - SAFESPACE - 20)

class TUser : public TPlan {
    public:
        
        void Init(void);
        void Run(void);
        void Reset(void);
        void createCall(void);
        void showVec(std::vector<MyFahrzeug>& lr);
        void showFs(int x, int y, double richtung);
        void myDrawAutoPublic(int x, int y, double richtung);
        void myDrawAutoPrivate(int positionX, int positionY, double richtung, int autoW, int autoL,
                               int radL, int lange, int kurz, int radPen, int langePen,
                               TColor radColor, TColor autoColor);
        int calcRichtungPositionX(int PositionX, int PositionY, int centerX, int centerY, double richtung);
        int calcRichtungPositionY(int PositionX, int PositionY, int centerX, int centerY, double richtung);
};
std::vector<MyFahrzeug> vfs0;
std::vector<MyFahrzeug> vfs1;
std::vector<MyFahrzeug> vfs2;
std::vector<MyFahrzeug> vfs3;
std::vector<MyFahrzeug> vfs4;
std::vector<MyFahrzeug> vfs5;
std::vector<MyFahrzeug> vfs6;
std::vector<MyFahrzeug> vfs7;
std::vector<MyFahrzeug> vfs8;
std::vector<MyFahrzeug> vfs9;
std::vector<MyFahrzeug> vfs10;
std::vector<MyFahrzeug> vfs11;
std::vector<MyFahrzeug> vfs12;
std::vector<MyFahrzeug> vfs13;


MyDraw myDraw;
MyFahrzeug ss;



int roadNum = 0;
int createNum = 3;
int W = 0, H = 0;

void TUser::Init(void) {
    vfs0.clear();
    vfs1.clear();
    vfs2.clear();
    vfs3.clear();
    vfs4.clear();
    vfs5.clear();
    vfs6.clear();
    vfs7.clear();
    vfs8.clear();
    vfs9.clear();
    vfs10.clear();
    vfs11.clear();
    vfs12.clear();
    vfs13.clear();

    createNum = 3;
    roadNum = 0;
    int retY[2], retX[2];
    myDraw.init(W, H);
    ss.init(W,H);
    myDraw.myDrawRoad(5, retY, 1);
    myDraw.myDrawRoad(6, retX, 0);
    myDraw.myDrawKreuzungCover(retX, retY);
    myDraw.myDrawZwisch(2, 1);
    myDraw.myDrawZwisch(4, 0);
    myDraw.myDrawFP();
    createCall();
    printf("x is %f, y ist %f, w ist %f, h ist %f, richtung ist %f\n",
           ss.getPositionX(), ss.getPositionY(), ss.getAutoWidth(), ss.getAutoHeight(),
        ss.getAutoRichtung() );
}

void TUser::Run(void) {
    int retY[2], retX[2];
    myDraw.init();
    myDraw.myDrawRoad(5, retY, 1);
    myDraw.myDrawRoad(6, retX, 0);
    myDraw.myDrawKreuzungCover(retX, retY);
    myDraw.myDrawZwisch(2, 1);
    myDraw.myDrawZwisch(4, 0);
    myDraw.myDrawFP();

    createCall();
    showVec(vfs0);
    showVec(vfs1);
    showVec(vfs2);
    showVec(vfs3);
    showVec(vfs4);
    showVec(vfs5);
    showVec(vfs6);
    showVec(vfs7);
    showVec(vfs8);
    showVec(vfs9);
    showVec(vfs10);
    showVec(vfs11);
    showVec(vfs12);
    showVec(vfs13);

    
    CallRun = true; 
}

void TUser::Reset(void) {
    TUser::Init(); 
}

void TUser::myDrawAutoPublic(int x, int y, double richtung) {
    this->myDrawAutoPrivate(x, y, richtung, AUTOW, AUTOH, RAD, 
                            LANGE, LANGEKURZ, RADPEN,
                            LANGEPEN, RADCOLOR, AUTOCOLOR);
}


void TUser::myDrawAutoPrivate(int x, int y, double richtung, 
                        int autoW = AUTOW, int autoL = AUTOH, int radL = RAD, 
                        int lange = LANGE, int kurz = LANGEKURZ, int radPen = RADPEN,
                        int langePen = LANGEPEN, TColor radColor = RADCOLOR, TColor autoColor = AUTOCOLOR) {
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


int TUser::calcRichtungPositionX(int PositionX, int PositonY, int centerX, int centerY, double richtung) {
    return cos(richtung) * (PositionX - centerX) - sin(richtung) * (PositonY - centerY) + centerX;
}

int TUser::calcRichtungPositionY(int PositionX, int PositionY, int centerX, int centerY, double richtung) {
    return sin(richtung) * (PositionX - centerX) + cos(richtung) * (PositionY - centerY) + centerY;
}
void TUser::showFs(int x, int y, double richtung) {
    myDrawAutoPublic(x, y, richtung);
}

void TUser::showVec(std::vector<MyFahrzeug>& lr) {
    std::cout<<"----------------------vfs0 size ist "<<lr.size()<<std::endl;
    MyFahrzeug* vor;
    for (std::vector<MyFahrzeug>::iterator iter = lr.begin(), vor = lr.begin(); iter != lr.end(); iter++) {
            if(iter == vor) {
                iter->setSpeed(MAXSPEED);
            } else {
                iter->setMaxSpeed(*vor);
            }
            (iter)->autoMove();
            showFs(iter->getPositionX(), iter->getPositionY(), iter->getAutoRichtung());
            vor = iter;
        // std::cout<<"vfs0 x ist "<<(*iter).getPositionX()<<std::endl;
        // std::cout<<"vfs0 y ist "<<(*iter).getPositionY()<<std::endl;
        // std::cout<<"vfs0 speed ist "<<(*iter).getSpeed()<<std::endl;
    }
}

void TUser::createCall(void) {
    
    for(int startI = 0; startI < createNum; startI++) {
        ss.createAuto(roadNum, AUTOW, AUTOH, AUTOCOLOR);
        switch(roadNum) {
            case 0:
                if (0 != vfs0.size()) {
                    if(vfs0.back().getPositionX() >= CREATEAUTORIGHT) {
                        break;
                    }
                } 
                // ss.setSpeed(MAXSPEED);
                vfs0.push_back(ss);
                break;
            case 1:
                if (0 != vfs1.size()) {
                    if(vfs1.back().getPositionX() >= CREATEAUTORIGHT) {
                        break;
                    }
                }
                ss.setSpeed(MAXSPEED);
                vfs1.push_back(ss);
                break;
            case 2:
                if (0 != vfs2.size()) {
                    if(vfs2.back().getPositionX() >= CREATEAUTORIGHT) {
                        break;
                    }
                }
                ss.setSpeed(MAXSPEED);
                vfs2.push_back(ss);
                break;
            case 3:
                if (0 != vfs3.size()) {
                    if(vfs3.back().getPositionY() >= CREATEAUTODOWN) {
                        break;
                    }
                }
                ss.setSpeed(MAXSPEED);
                vfs3.push_back(ss);
                break;
            case 4:
                if (0 != vfs4.size()) {
                    if(vfs4.back().getPositionY() >= CREATEAUTODOWN) {
                        break;
                    }
                }
                ss.setSpeed(MAXSPEED);
                vfs4.push_back(ss);
                break;
            case 5:
                if (0 != vfs5.size()) {
                    if(vfs5.back().getPositionY() >= CREATEAUTODOWN) {
                        break;
                    }
                }
                ss.setSpeed(MAXSPEED);
                vfs5.push_back(ss);
                break;
            case 6:
                if (0 != vfs6.size()) {
                    if(vfs6.back().getPositionY() >= CREATEAUTODOWN) {
                        break;
                    }
                }
                ss.setSpeed(MAXSPEED);
                vfs6.push_back(ss);
                break;
            case 7:
                if (0 != vfs7.size()) {
                    if(vfs7.back().getPositionX() <= CREATEAUTOLEFT) {
                        break;
                    }
                }
                ss.setSpeed(MAXSPEED);
                vfs7.push_back(ss);
                break;
            case 8:
                if (0 != vfs8.size()) {
                    if(vfs8.back().getPositionX() <= CREATEAUTOLEFT) {
                        break;
                    }
                }
                ss.setSpeed(MAXSPEED);
                vfs8.push_back(ss);
                break;
            case 9:
                if (0 != vfs9.size()) {
                    if(vfs9.back().getPositionX() <= CREATEAUTOLEFT) {
                        break;
                    }
                }
                ss.setSpeed(MAXSPEED);
                vfs9.push_back(ss);
                break;
            case 10:
                if (0 != vfs10.size()) {
                    if(vfs10.back().getPositionY() <= CREATEAUTOUP) {
                        break;
                    }
                }
                ss.setSpeed(MAXSPEED);
                vfs10.push_back(ss);
                break;
            case 11:
                if (0 != vfs11.size()) {
                    if(vfs11.back().getPositionY() <= CREATEAUTOUP) {
                        break;
                    }
                }
                ss.setSpeed(MAXSPEED);
                vfs11.push_back(ss);
                break; 
            case 12:
                if (0 != vfs12.size()) {
                    if(vfs12.back().getPositionY() <= CREATEAUTOUP) {
                        break;
                    }
                }
                ss.setSpeed(MAXSPEED);
                vfs12.push_back(ss);
                break; 
            case 13:
                if (0 != vfs13.size()) {
                    if(vfs13.back().getPositionY() <= CREATEAUTOUP) {
                        break;
                    }
                }
                ss.setSpeed(MAXSPEED);
                vfs13.push_back(ss);
                break; 
            default:
                std::cout<<"you are snoopy"<<std::endl;
        }
    } 
}


//====================================================================
#pragma argsused
int main(int argc, char* argv[]){ TUser a; a.Execute(); return 0; }
//__________________________________________________________Ost08_____

