#include "MyDraw.h"
#include "Plan.h"

void MyDraw::init() {
    SetPen(Klar);
    SetBrush(MYROADCOLOR);
    // SetBrush(Gelb);
    Rectangle(0, 0, GetMaxW(), GetMaxH());
}


void MyDraw::myDrawRoad(int iAllLanes, int (&iStore)[2], int iHorizontale = 1) {
        int iLans = iAllLanes + 1;
        SetPen(Klar);
        SetBrush(MYROADCOLOR);
        if(iHorizontale == 1) {
            iHLans = iLans;
            startY = iStore[0] = (GetMaxH() - MYLANEWIDTH * iLans) / 2;
            endY = iStore[1]   = (GetMaxH() + MYLANEWIDTH * iLans) / 2;
            Rectangle(0, iStore[0], GetMaxW(), iLans * MYLANEWIDTH);
            for(int i = 1; i < iLans; i++) {
                myDrawRoadLine(0, iStore[0] + MYLANEWIDTH * i, GetMaxW(), iStore[0] + MYLANEWIDTH * i, MYROADLINECOLOR);
                myDrawRoadCoverLine(0, iStore[0] + MYLANEWIDTH * i, GetMaxW(), iStore[0] + MYLANEWIDTH * i, MYROADCOVERCOLOR);
            }
        } else if(iHorizontale == 0) {
            iWLans = iLans;
            startX = iStore[0] = (GetMaxW() - MYLANEWIDTH * iLans) / 2;
            endX = iStore[1]   = (GetMaxW() + MYLANEWIDTH * iLans) / 2;
            Rectangle(iStore[0], 0, iLans * MYLANEWIDTH, GetMaxH());
            for(int i = 1; i < iLans; i++) {
                myDrawRoadLine(iStore[0] + MYLANEWIDTH * i, 0,
                               iStore[0] + MYLANEWIDTH * i, GetMaxH(), MYROADLINECOLOR);
                myDrawRoadCoverLine(iStore[0] + MYLANEWIDTH * i, 0,
                                    iStore[0] + MYLANEWIDTH * i, GetMaxH(), MYROADCOVERCOLOR);
            }
        }
}

void MyDraw::myDrawRoadLine(int startX, int startY, int endX, int endY, TColor color = MYROADLINECOLOR) {
    SetPen(color, MYROADLINEWIDTH);
    MoveTo(startX, startY);
    LineTo(endX, endY);
}

void MyDraw::myDrawRoadCoverLine(int startX, int startY, int endX, int endY, TColor color = MYROADCOVERCOLOR) {
    SetPen(color, MYROADLINEWIDTH);     
    if(startX == endX) { // 垂直
        int curY = startY;
        while (curY < endY) {
            MoveTo(startX, curY += 100);
            LineTo(startX,  curY += 50);
        }
        
    } else if(startY == endY) {//水平
        int curX = startX;
        while (curX < endX) {
            MoveTo(curX += 100, startY);
            LineTo(curX += 50, startY);
        }
        
    }
}

void MyDraw::myDrawKreuzungCover(int (&x)[2], int (&y)[2]) {
    SetBrush(MYROADCOLOR);
    Rectangle(x[0], y[0], x[1] - x[0], y[1] - y[0]);    
    SetBrush(GEBAUDE);
    SetPen(Klar);
    Circle(startX - LEERwIDTH, startY - LEERwIDTH, LEERwIDTH); //leftup
    Rectangle(0, 0, startX, startY - LEERwIDTH);
    Rectangle(0, 0, startX - LEERwIDTH, startY);
    Circle(endX + LEERwIDTH, endY + LEERwIDTH, LEERwIDTH); //rightdown
    Rectangle(endX, endY + LEERwIDTH, GetMaxW(), GetMaxH());
    Rectangle(endX + LEERwIDTH, endY, GetMaxW(), GetMaxH());
    Circle(startX - LEERwIDTH, endY + LEERwIDTH, LEERwIDTH); //leftdown
    Rectangle(0, endY, startX - LEERwIDTH, GetMaxH());
    Rectangle(0, endY + LEERwIDTH, startX, GetMaxH());
    Circle(endX + LEERwIDTH, startY- LEERwIDTH, LEERwIDTH); //rightup
    Rectangle(endX, 0, GetMaxW(), startY - LEERwIDTH);
    Rectangle(endX + LEERwIDTH, 0, GetMaxW(), startY);
}



void MyDraw::myDrawZwisch(int num, int iHorizontale = 1) {
    SetBrush(MYROADVERBOTE);
    if(iHorizontale == 1) {
        Rectangle(0, startY + num * MYLANEWIDTH, startX, MYLANEWIDTH + MYROADLINEWIDTH);
        Rectangle(endX, startY + (iHLans - num - 1) * MYLANEWIDTH, GetMaxW(), MYLANEWIDTH + MYROADLINEWIDTH);
    } else if(iHorizontale == 0) {
        Rectangle(startX + num * MYLANEWIDTH, 0, MYLANEWIDTH + MYROADLINEWIDTH, startY);
        Rectangle(startX + (iWLans - num - 1) * MYLANEWIDTH, endY, MYLANEWIDTH + MYROADLINEWIDTH, GetMaxH());
    }
}


void MyDraw::myDrawFP() {
    SetPen(Klar);
    SetBrush(PCOLOR);
    Rectangle(startX - LEERwIDTH - FWIDTH - PWIDTH, startY, FWIDTH + PWIDTH, iHLans * MYLANEWIDTH); //LeftP
    Rectangle(startX, startY - LEERwIDTH - FWIDTH - PWIDTH, iWLans * MYLANEWIDTH, PWIDTH + FWIDTH); //UpP
    Rectangle(endX + LEERwIDTH, startY, FWIDTH + PWIDTH, iHLans * MYLANEWIDTH); //rightP
    Rectangle(startX, endY + LEERwIDTH, iWLans * MYLANEWIDTH, PWIDTH + FWIDTH); //downP
    SetBrush(FCOLOR);
    Rectangle(startX - LEERwIDTH - FWIDTH, startY, FWIDTH, iHLans * MYLANEWIDTH); //leftF
    Rectangle(startX, startY - LEERwIDTH -FWIDTH, iWLans * MYLANEWIDTH, FWIDTH); //upF
    Rectangle(endX + LEERwIDTH, startY, FWIDTH, iHLans * MYLANEWIDTH); //rightF
    Rectangle(startX, endY + LEERwIDTH, iWLans * MYLANEWIDTH, FWIDTH); //downF
}


void MyDraw::myDrawAuto(int positonX, int positionY, int roadNum) {
    SetBrush(MYROADAUTOCOLOR);
    SetPen(Klar);
}