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
 

#define CREATEAUTODOWN      (GetMaxH() - AUTOH / 2 - SAFESPACE - 20)
#define CREATEAUTORIGHT     (GetMaxW() - AUTOH / 2 - SAFESPACE - 20)
#define COUNTNUM        120
#define GELBCOUNTNUM    10
#define NOLAUF          35
#define REGELNUM        6

#define REGEL0  0
#define REGEL1  1
#define REGEL2  2
#define REGEL3  3
#define REGEL4  4
#define REGEL5  5
#define REGEL6  6

#define LAUFSTOP    1
#define LAUFRUN     2
#define LAUFSLOW    3
#define FWIDTH              25
#define PWIDTH              55
#define FCOLOR              Schwarz 
#define PCOLOR              Hellgrau

#define LAMPERED    Hellrot 
#define LAMPEGELB Gelb 
#define LAMPEGREEN  Gruen 

#define MYDRAWSTARTY  ((GetMaxH() - MYLANEWIDTH * 6) / 2)
#define MYDRAWENDY    ((GetMaxH() + MYLANEWIDTH * 6) / 2) 
#define MYDRAWSTARTX  ((GetMaxW() - MYLANEWIDTH * 7) / 2)
#define MYDRAWENDX    ((GetMaxW() + MYLANEWIDTH * 7) / 2)

#define MYDRAWFLX  (STARTX - LEERwIDTH)
#define MYDRAWFRX  (ENDX + LEERwIDTH)
#define MYDRAWFOY  (STARTY - LEERwIDTH)
#define MYDRAWFUY  (ENDY + LEERwIDTH)

#define STOPUP      (MYDRAWSTARTY - LEERwIDTH - FWIDTH - PWIDTH - AUTOH / 2)
#define STOPDOWN    (MYDRAWENDY + LEERwIDTH + FWIDTH + PWIDTH + AUTOH / 2)
#define STOPLEFT    (MYDRAWSTARTX - LEERwIDTH - FWIDTH - PWIDTH - AUTOH / 2)
#define STOPRIGHT   (MYDRAWENDX + LEERwIDTH + FWIDTH + PWIDTH + AUTOW / 2)

#define SPEEDSLOW   0.5


class TUser : public TPlan {
    public:
        
        void Init(void);
        void Run(void);
        void Reset(void);
        void createCall(void);
        void showVec(std::vector<MyFahrzeug>& lr, int roadNum, int laufStatus);
        void showFs(int x, int y, double richtung);
        void myDrawAutoPublic(int x, int y, double richtung);
        void myDrawAutoPrivate(int positionX, int positionY, double richtung, int autoW, int autoL,
                               int radL, int lange, int kurz, int radPen, int langePen,
                               TColor radColor, TColor autoColor);

        void lampeLauf();
        void regelLauf(int regelNum, int callRunNum, int status);
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
int createNum = 2;
int W = 0, H = 0;

int tempCallNum = 0;

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
    myDraw.myDrawABLine();
    myDraw.myDrawLampeStop();
    createCall();
}

void TUser::Run(void) {
    int retY[2], retX[2];
    myDraw.init();
    myDraw.myDrawRoad(5, retY, 1);
    myDraw.myDrawRoad(6, retX, 0);
    myDraw.myDrawABLine();
    myDraw.myDrawKreuzungCover(retX, retY);
    myDraw.myDrawZwisch(2, 1);
    myDraw.myDrawZwisch(4, 0);
    myDraw.myDrawFP();
    lampeLauf();
    createCall();

    
    
    CallRun = true; 
}

void TUser::Reset(void) {
    TUser::Init(); 
}


void TUser::regelLauf(int regelNum, int callRunNum, int status) {
    TColor color = (status == LAUFRUN)? LAMPEGREEN : LAMPEGELB;
    myDraw.myDrawLampeStop();
    
    switch(regelNum) {
        case REGEL0:
// std::cout<<"status\t"<<status<<std::endl;
            showVec(vfs1, 1, status);
            showVec(vfs8, 8, status);
    showVec(vfs0, 0, LAUFSTOP);
    showVec(vfs2, 2, LAUFSTOP);
    showVec(vfs3, 3, LAUFSTOP);
    showVec(vfs4, 4, LAUFSTOP);
    showVec(vfs5, 5, LAUFSTOP);
    showVec(vfs6, 6, LAUFSTOP);
    showVec(vfs7, 7, LAUFSTOP);
    showVec(vfs9, 9, LAUFSTOP);
    showVec(vfs10, 10, LAUFSTOP);
    showVec(vfs11, 11, LAUFSTOP);
    showVec(vfs12, 12, LAUFSTOP);
    showVec(vfs13, 13, LAUFSTOP);
    SetBrush(color);
        Circle(LAMPERX, LAMPERGY, LAMPERADIO); //1
        Circle(LAMPELX, LAMPELGY, LAMPERADIO); //8
    SetBrush(ABFARBE);
        myDraw.myDrawABLine(LAMPERX, LAMPERGY, ROADRICHTUNG012, RICHTUNGGERAD, LAMPELINELENGTH, LAMPELINEWIDTH, ABFARBE); //1
        myDraw.myDrawABLine(LAMPELX, LAMPELGY, ROADRICHTUNG789, RICHTUNGGERAD, LAMPELINELENGTH, LAMPELINEWIDTH, ABFARBE); //8
        break;
        case REGEL1:
    
            showVec(vfs2, 2, status);
    showVec(vfs0, 0, LAUFSTOP);
    showVec(vfs1, 1, LAUFSTOP);
    showVec(vfs3, 3, LAUFSTOP);
    showVec(vfs4, 4, LAUFSTOP);
    showVec(vfs5, 5, LAUFSTOP);
    showVec(vfs6, 6, LAUFSTOP);
    showVec(vfs7, 7, LAUFSTOP);
    showVec(vfs8, 8, LAUFSTOP);
    showVec(vfs9, 9, LAUFSTOP);
    showVec(vfs10, 10, LAUFSTOP);
    showVec(vfs11, 11, LAUFSTOP);
    showVec(vfs12, 12, LAUFSTOP);
    showVec(vfs13, 13, LAUFSTOP);
    SetBrush(color);
        Circle(LAMPERX, LAMPERLY, LAMPERADIO); //2
    SetBrush(ABFARBE);
        myDraw.myDrawABLine(LAMPERX, LAMPERLY, ROADRICHTUNG0123, RICHTUNGGERAD, LAMPELINELENGTH, LAMPELINEWIDTH, ABFARBE); //2
        break;
        case REGEL2:
            showVec(vfs3, 3, status);
            showVec(vfs4, 4, status);
            showVec(vfs10, 10, status);
            showVec(vfs11, 11, status);
    showVec(vfs0, 0, LAUFSTOP);
    showVec(vfs1, 1, LAUFSTOP);
    showVec(vfs2, 2, LAUFSTOP);
    showVec(vfs5, 5, LAUFSTOP);
    showVec(vfs6, 6, LAUFSTOP);
    showVec(vfs7, 7, LAUFSTOP);
    showVec(vfs8, 8, LAUFSTOP);
    showVec(vfs9, 9, LAUFSTOP);
    showVec(vfs12, 12, LAUFSTOP);
    showVec(vfs13, 13, LAUFSTOP);
    SetBrush(color);
            Circle(LAMPEURX, LAMPEUY, LAMPERADIO); //3
            Circle(LAMPEUGX, LAMPEUY, LAMPERADIO); //4
            Circle(LAMPEORX, LAMPEOY, LAMPERADIO); //10
            Circle(LAMPEOGX, LAMPEOY, LAMPERADIO); //11
        SetBrush(ABFARBE);
            myDraw.myDrawABLine(LAMPEUGX, LAMPEUY, ROADRICHTUNG3456, RICHTUNGGERAD, LAMPELINELENGTH, LAMPELINEWIDTH, ABFARBE); //4
            myDraw.myDrawABLine(LAMPEURX, LAMPEUY, ROADRICHTUNG789, RICHTUNGGERAD, LAMPELINELENGTH, LAMPELINEWIDTH, ABFARBE); //3
            myDraw.myDrawABLine(LAMPEORX, LAMPEOY, ROADRICHTUNG012, RICHTUNGGERAD, LAMPELINELENGTH, LAMPELINEWIDTH, ABFARBE); //10
            myDraw.myDrawABLine(LAMPEOGX, LAMPEOY, ROADRICHTUNG0123, RICHTUNGGERAD, LAMPELINELENGTH, LAMPELINEWIDTH, ABFARBE); //11
        break;
        case REGEL3:
            showVec(vfs5, 5, status);
            showVec(vfs6, 6, status);
            showVec(vfs7, 7, status);
    showVec(vfs0, 0, LAUFSTOP);
    showVec(vfs1, 1, LAUFSTOP);
    showVec(vfs2, 2, LAUFSTOP);
    showVec(vfs3, 3, LAUFSTOP);
    showVec(vfs4, 4, LAUFSTOP);
    showVec(vfs8, 8, LAUFSTOP);
    showVec(vfs9, 9, LAUFSTOP);
    showVec(vfs10, 10, LAUFSTOP);
    showVec(vfs11, 11, LAUFSTOP);
    showVec(vfs12, 12, LAUFSTOP);
    showVec(vfs13, 13, LAUFSTOP);
    SetBrush(color);
            Circle(LAMPEULX, LAMPEUY, LAMPERADIO); //5 6
            Circle(LAMPELX, LAMPELRY, LAMPERADIO); //7 
    SetBrush(ABFARBE);
    myDraw.myDrawABLine(LAMPEULX, LAMPEUY, ROADRICHTUNG012, RICHTUNGGERAD, LAMPELINELENGTH, LAMPELINEWIDTH, ABFARBE); //5 6
    myDraw.myDrawABLine(LAMPELX, LAMPELRY, ROADRICHTUNG0123, RICHTUNGGERAD, LAMPELINELENGTH, LAMPELINEWIDTH, ABFARBE); //7
        break;
        case REGEL4:
            showVec(vfs9, 9, status);
    showVec(vfs0, 0, LAUFSTOP);
    showVec(vfs1, 1, LAUFSTOP);
    showVec(vfs2, 2, LAUFSTOP);
    showVec(vfs3, 3, LAUFSTOP);
    showVec(vfs4, 4, LAUFSTOP);
    showVec(vfs5, 5, LAUFSTOP);
    showVec(vfs6, 6, LAUFSTOP);
    showVec(vfs7, 7, LAUFSTOP);
    showVec(vfs8, 8, LAUFSTOP);
    showVec(vfs10, 10, LAUFSTOP);
    showVec(vfs11, 11, LAUFSTOP);
    showVec(vfs12, 12, LAUFSTOP);
    showVec(vfs13, 13, LAUFSTOP);
    SetBrush(color);
            Circle(LAMPELX, LAMPELLY, LAMPERADIO); //9
    SetBrush(ABFARBE);
     myDraw.myDrawABLine(LAMPELX, LAMPELLY, ROADRICHTUNG3456, RICHTUNGGERAD, LAMPELINELENGTH, LAMPELINEWIDTH, ABFARBE); //9
        break;
        case REGEL5:
    showVec(vfs1, 1, LAUFSTOP);
            showVec(vfs0, 0, status);
            showVec(vfs12, 12, status);
            showVec(vfs13, 13, status);
    showVec(vfs1, 1, LAUFSTOP);
    showVec(vfs2, 2, LAUFSTOP);
    showVec(vfs3, 3, LAUFSTOP);
    showVec(vfs4, 4, LAUFSTOP);
    showVec(vfs5, 5, LAUFSTOP);
    showVec(vfs6, 6, LAUFSTOP);
    showVec(vfs7, 7, LAUFSTOP);
    showVec(vfs8, 8, LAUFSTOP);
    showVec(vfs9, 9, LAUFSTOP);
    showVec(vfs10, 10, LAUFSTOP);
    showVec(vfs11, 11, LAUFSTOP);
    SetBrush(color);
            Circle(LAMPERX, LAMPERRY, LAMPERADIO); //0
            Circle(LAMPEOLX, LAMPEOY, LAMPERADIO); //12 13
    SetBrush(ABFARBE);
    myDraw.myDrawABLine(LAMPERX, LAMPERRY, ROADRICHTUNG3456, RICHTUNGGERAD, LAMPELINELENGTH, LAMPELINEWIDTH, ABFARBE); //0
    myDraw.myDrawABLine(LAMPEOLX, LAMPEOY, ROADRICHTUNG789, RICHTUNGGERAD, LAMPELINELENGTH, LAMPELINEWIDTH, ABFARBE); //12 1
        break;
    default:
    showVec(vfs0, 0, LAUFSTOP);
    showVec(vfs1, 1, LAUFSTOP);
    showVec(vfs2, 2, LAUFSTOP);
    showVec(vfs3, 3, LAUFSTOP);
    showVec(vfs4, 4, LAUFSTOP);
    showVec(vfs5, 5, LAUFSTOP);
    showVec(vfs6, 6, LAUFSTOP);
    showVec(vfs7, 7, LAUFSTOP);
    showVec(vfs8, 8, LAUFSTOP);
    showVec(vfs9, 9, LAUFSTOP);
    showVec(vfs10, 10, LAUFSTOP);
    showVec(vfs11, 11, LAUFSTOP);
    showVec(vfs12, 12, LAUFSTOP);
    showVec(vfs13, 13, LAUFSTOP);
        break;
    }
}

void TUser::lampeLauf() {
    int temp = CallRunCount % (COUNTNUM * REGELNUM);
 
    if(0 <= temp && temp < COUNTNUM - GELBCOUNTNUM - NOLAUF) {
        regelLauf(REGEL0, CallRunCount, LAUFRUN);
    }
    else if(COUNTNUM - GELBCOUNTNUM - NOLAUF <= temp && temp < COUNTNUM - NOLAUF) {
        regelLauf(REGEL0, CallRunCount, LAUFSLOW);
    } 
    
    else if(1 * COUNTNUM <= temp && temp < 2 * COUNTNUM - GELBCOUNTNUM - NOLAUF) {
        regelLauf(REGEL1, CallRunCount, LAUFRUN);
    }
    else if(2 * COUNTNUM - GELBCOUNTNUM - NOLAUF <= temp && temp < 2 * COUNTNUM - NOLAUF) {
        regelLauf(REGEL1, CallRunCount, LAUFSLOW);
    } 

    else if(2 * COUNTNUM <= temp && temp < 3 * COUNTNUM - GELBCOUNTNUM - NOLAUF) {
        regelLauf(REGEL2, CallRunCount, LAUFRUN);
    }
    else if(3 * COUNTNUM - GELBCOUNTNUM - NOLAUF <= temp && temp < 3 * COUNTNUM - NOLAUF) {
        regelLauf(REGEL2, CallRunCount, LAUFSLOW);
    } 

    else if(3 * COUNTNUM <= temp && temp < 4 * COUNTNUM - GELBCOUNTNUM - NOLAUF) {
        regelLauf(REGEL3, CallRunCount, LAUFRUN);
    }
    else if(4 * COUNTNUM - GELBCOUNTNUM - NOLAUF <= temp && temp < 4 * COUNTNUM - NOLAUF) {
        regelLauf(REGEL3, CallRunCount, LAUFSLOW);
    } 

    else if(4 * COUNTNUM <= temp && temp < 5 * COUNTNUM - GELBCOUNTNUM - NOLAUF) {
        regelLauf(REGEL4, CallRunCount, LAUFRUN);
    }
    else if(5 * COUNTNUM - GELBCOUNTNUM - NOLAUF <= temp && temp < 5 * COUNTNUM - NOLAUF) {
        regelLauf(REGEL4, CallRunCount, LAUFSLOW);
    } else if(5 * COUNTNUM <= temp && temp < 6 * COUNTNUM - GELBCOUNTNUM - NOLAUF) {
        regelLauf(REGEL5, CallRunCount, LAUFRUN);
    }
    else if(6 * COUNTNUM - GELBCOUNTNUM - NOLAUF <= temp && temp < 6 * COUNTNUM - NOLAUF) {
        regelLauf(REGEL5, CallRunCount, LAUFSLOW);
    } 
    else {regelLauf(REGEL6, CallRunCount, LAUFSTOP);}
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

void TUser::showVec(std::vector<MyFahrzeug>& lr, int roadNum, int laufStatus) {
    // std::cout<<"----------------------vfs0 size ist "<<lr.size()<<std::endl;
    MyFahrzeug* vor;
    if(lr.size()> 20) {
        lr.erase(lr.begin());
    }
    int flag = 0;
    if(LAUFSTOP == laufStatus) {
        switch (roadNum)
        {
        case 0:
        case 1:
        case 2: 
            for (std::vector<MyFahrzeug>::iterator iter = lr.begin(), vor = lr.begin(); iter != lr.end(); iter++) {
                if (iter->getPositionX() > STOPRIGHT)
                {
                    if(!flag) {
                        iter->setMaxSpeed(*iter, roadNum, STOPRIGHT);
                        if(iter->getSpeed() == 0) {
                            flag = 1;
                        }
                    } else {
                        iter->setMaxSpeed(*vor);
                    }
                }
                else
                {
                    if (iter == vor)
                    {
                        iter->setSpeed(MAXSPEED);
                    }
                    else
                    {
                        iter->setMaxSpeed(*vor);
                    }
                }

                (iter)->autoMove();
                showFs(iter->getPositionX(), iter->getPositionY(), iter->getAutoRichtung());
                vor = iter;

            }
            break;
        case 3:
        case 4:
        case 5:
        case 6:
            for (std::vector<MyFahrzeug>::iterator iter = lr.begin(), vor = lr.begin(); iter != lr.end(); iter++) {
                if (iter->getPositionY() > STOPDOWN)
                {
                    if(!flag) {
                        iter->setMaxSpeed(*iter, roadNum, STOPDOWN);
                        if(iter->getSpeed() == 0) {
                            flag = 1;
                        }
                    } else {
                        iter->setMaxSpeed(*vor);
                    }
                }
                else
                {
                    if (iter == vor)
                    {
                        iter->setSpeed(MAXSPEED);
                    }
                    else
                    {
                        iter->setMaxSpeed(*vor);
                    }
                }

                (iter)->autoMove();
                showFs(iter->getPositionX(), iter->getPositionY(), iter->getAutoRichtung());
                vor = iter;

            }
            break;
        case 7:
        case 8:
        case 9:
            for (std::vector<MyFahrzeug>::iterator iter = lr.begin(), vor = lr.begin(); iter != lr.end(); iter++) {
                if (iter->getPositionX() < STOPLEFT)
                {
                    if(!flag) {
                        iter->setMaxSpeed(*iter, roadNum, STOPLEFT);
                        if(iter->getSpeed() == 0) {
                            flag = 1;
                        }
                    } else {
                        iter->setMaxSpeed(*vor);
                    }
                }
                else
                {
                    if (iter == vor)
                    {
                        iter->setSpeed(MAXSPEED);
                    }
                    else
                    {
                        iter->setMaxSpeed(*vor);
                    }
                }

                (iter)->autoMove();
                showFs(iter->getPositionX(), iter->getPositionY(), iter->getAutoRichtung());
                vor = iter;

            }
            break;
        case 10:
        case 11:
        case 12:
        case 13:
            for (std::vector<MyFahrzeug>::iterator iter = lr.begin(), vor = lr.begin(); iter != lr.end(); iter++) {
                if (iter->getPositionY() < STOPUP)
                {
                    if(!flag) {
                        iter->setMaxSpeed(*iter, roadNum, STOPUP);
                        if(iter->getSpeed() == 0) {
                            flag = 1;
                        }
                    } else {
                        iter->setMaxSpeed(*vor);
                    }
                }
                else
                {
                    if (iter == vor)
                    {
                        iter->setSpeed(MAXSPEED);
                    }
                    else
                    {
                        iter->setMaxSpeed(*vor);
                    }
                }

                (iter)->autoMove();
                showFs(iter->getPositionX(), iter->getPositionY(), iter->getAutoRichtung());
                vor = iter;

            }
            break;
        default:
            break;
        } 
    } else {
        for (std::vector<MyFahrzeug>::iterator iter = lr.begin(), vor = lr.begin(); iter != lr.end(); iter++) {
            if(iter == vor) {
                iter->setSpeed(MAXSPEED + ((laufStatus == LAUFRUN)? 0 :SPEEDSLOW));
            } else {
                iter->setMaxSpeed(*vor);
            }
            (iter)->autoMove();
            showFs(iter->getPositionX(), iter->getPositionY(), iter->getAutoRichtung());
            vor = iter;
        }
    }
}

void TUser::createCall(void) {
    if(random(50) > 2) return;
    for(int startI = 0; startI < createNum; startI++) {
        ss.createAuto(roadNum, AUTOW, AUTOH, AUTOCOLOR);
        switch(roadNum) {
            case 0:
                if (0 != vfs0.size()) {
                    if(vfs0.back().getPositionX() >= CREATEAUTORIGHT) {
                        break;
                    }
                } 
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

