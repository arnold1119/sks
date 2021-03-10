#include "MyDraw.h"
#include "MyFahrzeug.h"
#include "Plan.h"

void MyDraw::init(int& w, int& h) {
    SetPen(Klar);
    SetBrush(MYROADCOLOR);
    w = GetMaxW();
    h = GetMaxH();
    Rectangle(0, 0, GetMaxW(), GetMaxH());
}
void MyDraw::init() {
    SetPen(Klar);
    SetBrush(MYROADCOLOR);
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
    Rectangle(x[0] - LEERwIDTH, y[0] - LEERwIDTH, x[1] - x[0] + 2 * LEERwIDTH, y[1] - y[0] + 2 * LEERwIDTH);    
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
    
    
void MyDraw::myDrawLampeStop() {
    SetPen(Schwarz, 1);
    SetBrush(LAMPERED);
    Circle(LAMPELX, LAMPELLY, LAMPERADIO); //9
    Circle(LAMPELX, LAMPELGY, LAMPERADIO); //8
    Circle(LAMPELX, LAMPELRY, LAMPERADIO); //7

    Circle(LAMPERX, LAMPERRY, LAMPERADIO); //0
    Circle(LAMPERX, LAMPERGY, LAMPERADIO); //1
    Circle(LAMPERX, LAMPERLY, LAMPERADIO); //2

    Circle(LAMPEORX, LAMPEOY, LAMPERADIO); //10
    Circle(LAMPEOGX, LAMPEOY, LAMPERADIO); //11
    Circle(LAMPEOLX, LAMPEOY, LAMPERADIO); //12 13
    
    Circle(LAMPEULX, LAMPEUY, LAMPERADIO); //5 6
    Circle(LAMPEUGX, LAMPEUY, LAMPERADIO); //4
    Circle(LAMPEURX, LAMPEUY, LAMPERADIO); //3

    SetPen(Klar);
    SetBrush(ABFARBE);
    myDrawABLine(LAMPELX, LAMPELLY, ROADRICHTUNG3456, RICHTUNGGERAD, LAMPELINELENGTH, LAMPELINEWIDTH, ABFARBE); //9
    myDrawABLine(LAMPELX, LAMPELGY, ROADRICHTUNG789, RICHTUNGGERAD, LAMPELINELENGTH, LAMPELINEWIDTH, ABFARBE); //8
    myDrawABLine(LAMPELX, LAMPELRY, ROADRICHTUNG0123, RICHTUNGGERAD, LAMPELINELENGTH, LAMPELINEWIDTH, ABFARBE); //7


    myDrawABLine(LAMPERX, LAMPERRY, ROADRICHTUNG3456, RICHTUNGGERAD, LAMPELINELENGTH, LAMPELINEWIDTH, ABFARBE); //0
    myDrawABLine(LAMPERX, LAMPERGY, ROADRICHTUNG012, RICHTUNGGERAD, LAMPELINELENGTH, LAMPELINEWIDTH, ABFARBE); //1
    myDrawABLine(LAMPERX, LAMPERLY, ROADRICHTUNG0123, RICHTUNGGERAD, LAMPELINELENGTH, LAMPELINEWIDTH, ABFARBE); //2


    myDrawABLine(LAMPEORX, LAMPEOY, ROADRICHTUNG012, RICHTUNGGERAD, LAMPELINELENGTH, LAMPELINEWIDTH, ABFARBE); //10
    myDrawABLine(LAMPEOGX, LAMPEOY, ROADRICHTUNG0123, RICHTUNGGERAD, LAMPELINELENGTH, LAMPELINEWIDTH, ABFARBE); //11
    myDrawABLine(LAMPEOLX, LAMPEOY, ROADRICHTUNG789, RICHTUNGGERAD, LAMPELINELENGTH, LAMPELINEWIDTH, ABFARBE); //12 13

    myDrawABLine(LAMPEULX, LAMPEUY, ROADRICHTUNG012, RICHTUNGGERAD, LAMPELINELENGTH, LAMPELINEWIDTH, ABFARBE); //5 6
    myDrawABLine(LAMPEUGX, LAMPEUY, ROADRICHTUNG3456, RICHTUNGGERAD, LAMPELINELENGTH, LAMPELINEWIDTH, ABFARBE); //4
    myDrawABLine(LAMPEURX, LAMPEUY, ROADRICHTUNG789, RICHTUNGGERAD, LAMPELINELENGTH, LAMPELINEWIDTH, ABFARBE); //3
}
void MyDraw::myDrawABLine(void) {
    myDrawABLine(endX + LEERwIDTH + FWIDTH + PWIDTH + ABLEER, startY + MYLANEWIDTH / 2, ROADRICHTUNG012, RICHTUNGRIGHT, ABLENGHT, ABWIDTH, ABFARBE);
    myDrawABLine(endX + LEERwIDTH + FWIDTH + PWIDTH + ABLEER, startY + 3 * MYLANEWIDTH / 2, ROADRICHTUNG012, RICHTUNGGERAD, ABLENGHT, ABWIDTH, ABFARBE);
    myDrawABLine(endX + LEERwIDTH + FWIDTH + PWIDTH + ABLEER, startY + 5 * MYLANEWIDTH / 2, ROADRICHTUNG012, RICHTUNGLEFT, ABLENGHT, ABWIDTH, ABFARBE);
    
    
    myDrawABLine(startX - LEERwIDTH - FWIDTH - PWIDTH - ABLEER, startY + 7 * MYLANEWIDTH / 2, ROADRICHTUNG789, RICHTUNGLEFT, ABLENGHT, ABWIDTH, ABFARBE);
    myDrawABLine(startX - LEERwIDTH - FWIDTH - PWIDTH - ABLEER, startY + 9 * MYLANEWIDTH / 2, ROADRICHTUNG789, RICHTUNGGERAD, ABLENGHT, ABWIDTH, ABFARBE);
    myDrawABLine(startX - LEERwIDTH - FWIDTH - PWIDTH - ABLEER, startY + 11 * MYLANEWIDTH / 2, ROADRICHTUNG789, RICHTUNGRIGHT, ABLENGHT, ABWIDTH, ABFARBE);

    myDrawABLine(endX - MYLANEWIDTH / 2, endY + LEERwIDTH + FWIDTH + PWIDTH + ABLEER, ROADRICHTUNG3456, RICHTUNGRIGHT, ABLENGHT, ABWIDTH, ABFARBE);
    myDrawABLine(endX - 3 * MYLANEWIDTH / 2, endY + LEERwIDTH + FWIDTH + PWIDTH + ABLEER, ROADRICHTUNG3456, RICHTUNGGERAD, ABLENGHT, ABWIDTH, ABFARBE);
    myDrawABLine(endX - 5 * MYLANEWIDTH / 2, endY + LEERwIDTH + FWIDTH + PWIDTH + ABLEER, ROADRICHTUNG3456, RICHTUNGLEFT, ABLENGHT, ABWIDTH, ABFARBE);
    myDrawABLine(endX - 7 * MYLANEWIDTH / 2, endY + LEERwIDTH + FWIDTH + PWIDTH + ABLEER, ROADRICHTUNG3456, RICHTUNGLEFT, ABLENGHT, ABWIDTH, ABFARBE);

    myDrawABLine(startX + MYLANEWIDTH / 2, startY - LEERwIDTH - FWIDTH - PWIDTH - ABLEER, ROADRICHTUNG0123, RICHTUNGRIGHT, ABLENGHT, ABWIDTH, ABFARBE);
    myDrawABLine(startX + 3 * MYLANEWIDTH / 2, startY - LEERwIDTH - FWIDTH - PWIDTH - ABLEER, ROADRICHTUNG0123, RICHTUNGGERAD, ABLENGHT, ABWIDTH, ABFARBE);
    myDrawABLine(startX + 5 * MYLANEWIDTH / 2, startY - LEERwIDTH - FWIDTH - PWIDTH - ABLEER, ROADRICHTUNG0123, RICHTUNGLEFT, ABLENGHT, ABWIDTH, ABFARBE);
    myDrawABLine(startX + 7 * MYLANEWIDTH / 2, startY - LEERwIDTH - FWIDTH - PWIDTH - ABLEER, ROADRICHTUNG0123, RICHTUNGLEFT, ABLENGHT, ABWIDTH, ABFARBE);
}

void MyDraw::myDrawABLine(int x, int y, double roadRichtung, int biegRichtung, 
int h = ABLENGHT, int w = ABWIDTH, TColor color = ABFARBE) {
    ClearPoints(); 
    int eckmx = 0;
    int eckmy = 0;

    int eckox = 0;
    int eckoy = 0;

    int eckux = 0;
    int eckuy = 0;

    int eckolx = 0;
    int eckoly = 0;

    int eckulx = 0;
    int eckuly = 0;

    int lox = x - w / 2;
    int loy = y - h / 2;

    int lux = x - w / 2;
    int luy = y + h / 2;

    int rox = x + w / 2;
    int roy = y - h / 2;

    int rux = x + w / 2; 
    int ruy = y + h / 2;
    
    int guailx = x - w / 2;
    int guaily = y - h / 2 + w; 
    
    int guairx = x + w / 2;
    int guairy = y - h / 2 + w; 
    if(biegRichtung == RICHTUNGGERAD) {
        eckolx = lox;
        eckoly = loy;
        eckulx = rox;
        eckuly = roy;
        eckox = x + w;
        eckoy = y - h / 2;
        eckux = x - w;
        eckuy = y - h / 2;
        eckmx = x;
        eckmy = y - h / 2 - w;
    }

    if(biegRichtung == RICHTUNGLEFT) {
        eckolx = x - w;
        eckoly = y - h / 2;
        eckulx = x - w;
        eckuly = y - h / 2 + w;
        eckox = x - w;
        eckoy = y - h / 2 - w / 2;
        eckux = x - w;
        eckuy = y - h / 2 + 3 * w / 2;
        eckmx = x - 2 * w;
        eckmy = y - h / 2 + w / 2;
    }

    if(biegRichtung == RICHTUNGRIGHT) {
        eckolx = x + w;
        eckoly = y - h / 2;
        eckulx = x + w;
        eckuly = y - h / 2 + w;
        eckox = x + w;
        eckoy = y - h / 2 - w / 2;
        eckux = x + w;
        eckuy = y - h / 2 + 3 * w / 2;
        eckmx = x + 2 * w;
        eckmy = y - h / 2 + w / 2;
    }

    int calEckmx = this->calcRichtungPositionX(eckmx, eckmy, x, y, roadRichtung);
    int calEckmy = this->calcRichtungPositionY(eckmx, eckmy, x, y, roadRichtung);

    int calEckox = this->calcRichtungPositionX(eckox, eckoy, x, y, roadRichtung);
    int calEckoy = this->calcRichtungPositionY(eckox, eckoy, x, y, roadRichtung);

    int calEckux = this->calcRichtungPositionX(eckux, eckuy, x, y, roadRichtung);
    int calEckuy = this->calcRichtungPositionY(eckux, eckuy, x, y, roadRichtung);

    int calEckolx = this->calcRichtungPositionX(eckolx, eckoly, x, y, roadRichtung);
    int calEckoly = this->calcRichtungPositionY(eckolx, eckoly, x, y, roadRichtung);

    int calEckulx = this->calcRichtungPositionX(eckulx, eckuly, x, y, roadRichtung);
    int calEckuly = this->calcRichtungPositionY(eckulx, eckuly, x, y, roadRichtung);
    
    int calLox = this->calcRichtungPositionX(lox, loy, x, y, roadRichtung);
    int calLoy = this->calcRichtungPositionY(lox, loy, x, y, roadRichtung);

    int calLux =this->calcRichtungPositionX(lux, luy, x, y, roadRichtung);
    int calLuy =this->calcRichtungPositionY(lux, luy, x, y, roadRichtung);

    int calRox =this->calcRichtungPositionX(rox, roy, x, y, roadRichtung);
    int calRoy =this->calcRichtungPositionY(rox, roy, x, y, roadRichtung);

    int calRux =  this->calcRichtungPositionX(rux, ruy, x, y, roadRichtung);
    int calRuy =  this->calcRichtungPositionY(rux, ruy, x, y, roadRichtung);


    int calGuailx = this->calcRichtungPositionX(guailx, guaily, x, y, roadRichtung);
    int calGuaily = this->calcRichtungPositionY(guailx, guaily, x, y, roadRichtung);
    
    int calGuairx = this->calcRichtungPositionX(guairx, guairy, x, y, roadRichtung);
    int calGuairy = this->calcRichtungPositionY(guairx, guairy, x, y, roadRichtung);
    if(biegRichtung == RICHTUNGGERAD) {
        SetPoint(calLux, calLuy); //left unten
        SetPoint(calLox, calLoy);   //left oben
        SetPoint(calEckux, calEckuy);   //left eck unten
        SetPoint(calEckmx, calEckmy);   // eck point
        SetPoint(calEckox, calEckoy);   //eck right oben 
        SetPoint(calRox, calRoy); //right oben
        SetPoint(calRux, calRuy); //right abbiegen
        SetPoint(calLux, calLuy); //left unten
    }
    if(biegRichtung == RICHTUNGLEFT) {
        SetPoint(calLux, calLuy); //left unten
        SetPoint(calGuailx, calGuaily); //left abbiegen
        SetPoint(calEckulx, calEckuly); //left eck unten abbiegen link
        SetPoint(calEckux, calEckuy);   //left eck unten
        SetPoint(calEckmx, calEckmy);   // eck point
        SetPoint(calEckox, calEckoy);   //eck right oben 
        SetPoint(calEckolx, calEckoly); //eck right oben link
        SetPoint(calLox, calLoy);   //left oben
        SetPoint(calRox, calRoy); //right oben
        SetPoint(calGuairx, calGuairy); //right abbiegen
        SetPoint(calRux, calRuy); //right abbiegen
        SetPoint(calLux, calLuy); //left unten
    }
    if(biegRichtung == RICHTUNGRIGHT)  {
        SetPoint(calLux, calLuy); //left unten
        SetPoint(calGuailx, calGuaily); //left abbiegen
        SetPoint(calLox, calLoy);   //left oben
        SetPoint(calRox, calRoy); //right oben
        SetPoint(calEckolx, calEckoly); //eck right oben link
        SetPoint(calEckox, calEckoy);   //eck right oben 
        SetPoint(calEckmx, calEckmy);   // eck point
        SetPoint(calEckux, calEckuy);   //left eck unten
        SetPoint(calEckulx, calEckuly); //left eck unten abbiegen link
        SetPoint(calGuairx, calGuairy); //right abbiegen
        SetPoint(calRux, calRuy); //right abbiegen
        SetPoint(calLux, calLuy); //left unten
    }
    SetPenColor(Klar);
    SetBrushColor(color);
    Poly();

}
int MyDraw::calcRichtungPositionX(int PositionX, int PositonY, int centerX, int centerY, double richtung) {
    return cos(richtung) * (PositionX - centerX) - sin(richtung) * (PositonY - centerY) + centerX;
}

int MyDraw::calcRichtungPositionY(int PositionX, int PositionY, int centerX, int centerY, double richtung) {
    return sin(richtung) * (PositionX - centerX) + cos(richtung) * (PositionY - centerY) + centerY;
}

void MyDraw::myDrawHelpLine(void) {
    // 1 8
    myDrawHelpLine18(HELPLINEWEISS);
    // 2
    myDrawHelpLine2(HELPLINEWEISS);
    // 3 4 10 11
    myDrawHelpLine341011(HELPLINEWEISS);
    // 5 6 7
    myDrawHelpLine567(HELPLINEWEISS);
    // 9
    myDrawHelpLine9(HELPLINEWEISS);
    // 0 12 13
    myDrawHelpLine01213(HELPLINEWEISS);
    return;
}

void MyDraw::myDrawHelpLine18(TColor color = HELPLINEWEISS) {
    int  end;
    SetPen(color, HELPLINEWIDTH);
    MoveTo(HELPLINE1OFROMX, HELPLINE1OFROMY);
    for(end = HELPLINE1OFROMX; end > HELPLINE1OTOX;) {
        end -= HELPLINELENGTH;
        LineTo(end, HELPLINE1OFROMY);
        end -= HELPLINESKIP;
        MoveTo(end, HELPLINE1OFROMY);
    }
    MoveTo(HELPLINE1UFROMX, HELPLINE1UFROMY);
    for(end = HELPLINE1UFROMX; end > HELPLINE1UTOX;) {
        end -= HELPLINELENGTH;
        LineTo(end, HELPLINE1UFROMY);
        end -= HELPLINESKIP;
        MoveTo(end, HELPLINE1UFROMY);
    }

    MoveTo(HELPLINE8OFROMX, HELPLINE8OFROMY);
    for(end = HELPLINE8OFROMX; end < HELPLINE8OTOX;) {
        end += HELPLINELENGTH;
        LineTo(end, HELPLINE8OFROMY);
        end += HELPLINESKIP;
        MoveTo(end, HELPLINE8OFROMY);
    }
    MoveTo(HELPLINE8UFROMX, HELPLINE8UFROMY);
    for( end = HELPLINE8UFROMX; end < HELPLINE8UTOX;) {
        end += HELPLINELENGTH;
        LineTo(end, HELPLINE8UFROMY);
        end += HELPLINESKIP;
        MoveTo(end, HELPLINE8UFROMY);
    }
    return;
}
void MyDraw::myDrawHelpLine2(TColor color = HELPLINEWEISS) {
    int end;
    SetPen(color, HELPLINEWIDTH);
    MoveTo(HELPLINE2UFROMX, HELPLINE2UFROMY);
    for(end = HELPLINE2UFROMX; end > HELPLINE2UTOX; ) {
        end -= HELPLINELENGTH;
        LineTo(end, HELPLINE2UFROMY);
        end -= HELPLINESKIP;
        MoveTo(end, HELPLINE2UFROMY);
    }
    for(end = HELPLINE2STARTGRAD; end < HELPLINE2ENDGRAD; ) {
        Arc(HELPLINE2PX, HELPLINE2PY, end, end + HELPLINELENGTH, RAD2IN);
        Arc(HELPLINE2PX, HELPLINE2PY, end, end + HELPLINELENGTH, RAD2OUT);
        end = end + HELPLINELENGTH + HELPLINESKIP;
    }

}
void MyDraw::myDrawHelpLine341011(TColor color = HELPLINEWEISS) {
    int end;
    SetPen(color, HELPLINEWIDTH);
    MoveTo(HELPLINE4RFROMX, HELPLINE4RFROMY);
    for(end = HELPLINE4RFROMY; end > HELPLINE4RTOY;) {
        end -= HELPLINELENGTH;
        LineTo(HELPLINE4RFROMX, end);
        end -= HELPLINESKIP;
        MoveTo(HELPLINE4RFROMX, end);
    }
    MoveTo(HELPLINE4LFROMX, HELPLINE4LFROMY);
    for( end = HELPLINE4LFROMY; end > HELPLINE4LTOY;) {
        end -= HELPLINELENGTH;
        LineTo(HELPLINE4LFROMX, end);
        end -= HELPLINESKIP;
        MoveTo(HELPLINE4LFROMX, end);
    }
    
    MoveTo(HELPLINE11RFROMX, HELPLINE11RFROMY);
    for(end = HELPLINE11RFROMY; end < HELPLINE11RTOY;) {
        end += HELPLINELENGTH;
        LineTo(HELPLINE11RFROMX, end);
        end += HELPLINESKIP;
        MoveTo(HELPLINE11RFROMX, end);
    }
    MoveTo(HELPLINE11LFROMX, HELPLINE11LFROMY);
    for(end = HELPLINE11LFROMY; end < HELPLINE11LTOY;) {
        end += HELPLINELENGTH;
        LineTo(HELPLINE11LFROMX, end);
        end += HELPLINESKIP;
        MoveTo(HELPLINE11LFROMX, end);
    }

    for(end = HELPLINE3STARTGRAD; end < HELPLINE3ENDGRAD;) {
        Arc(HELPLINE3PX, HELPLINE3PY, end, end + HELPLINELENGTH, LEERwIDTH + MYLANEWIDTH);
        end = end + HELPLINELENGTH + HELPLINESKIP;
    }
    for( end = HELPLINE10STARTGRAD; end < HELPLINE10ENDGRAD;) {
        Arc(HELPLINE10PX, HELPLINE10PY, end, end + HELPLINELENGTH, LEERwIDTH + MYLANEWIDTH);
        end = end + HELPLINELENGTH + HELPLINESKIP;
    }
}
void MyDraw::myDrawHelpLine567(TColor color = HELPLINEWEISS) {
    int  end;
    SetPen(color, HELPLINEWIDTH);
    MoveTo(HELPLINE5LFROMX, HELPLINE5LFROMY);
    for(end = HELPLINE5LFROMY; end > HELPLINE5LTOY;) {
        end -= HELPLINELENGTH;
        LineTo(HELPLINE5LFROMX, end);
        end -= HELPLINESKIP;
        MoveTo(HELPLINE5LFROMX, end);
    }
      MoveTo(HELPLINE6LFROMX, HELPLINE6LFROMY);
    for(end = HELPLINE6LFROMY; end > HELPLINE6LTOY;) {
        end -= HELPLINELENGTH;
        LineTo(HELPLINE6LFROMX, end);
        end -= HELPLINESKIP;
        MoveTo(HELPLINE6LFROMX, end);

    }
    for(end = HELPLINE56STARTGRAD; end < HELPLINE56ENDGRAD; ) {
        Arc(HELPLINE56PX, HELPLINE56PY, end, end + HELPLINELENGTH, RAD6IN);
        Arc(HELPLINE56PX, HELPLINE56PY, end, end + HELPLINELENGTH, RAD5IN);
        Arc(HELPLINE56PX, HELPLINE56PY, end, end + HELPLINELENGTH, RAD5OUT);
        end = end + HELPLINELENGTH + HELPLINESKIP;
    }
    for( end = HELPLINE7STARTGRAD; end < HELPLINE7ENDGRAD;) {
        Arc(HELPLINE7PX, HELPLINE7PY, end, end + HELPLINELENGTH, LEERwIDTH + MYLANEWIDTH);
        end = end + HELPLINELENGTH + HELPLINESKIP;
    }
}
void MyDraw::myDrawHelpLine9(TColor color = HELPLINEWEISS) {
    int end;
    SetPen(color, HELPLINEWIDTH);
    MoveTo(HELPLINE9OFROMX, HELPLINE9OFROMY);
    for(end = HELPLINE9OFROMX; end < HELPLINE9OTOX; ) {
        end += HELPLINELENGTH;
        LineTo(end, HELPLINE9OFROMY);
        end += HELPLINESKIP;
        MoveTo(end, HELPLINE9OFROMY);
    }
     for(end = HELPLINE9STARTGRAD; end < HELPLINE9ENDGRAD; ) {
        Arc(HELPLINE9PX, HELPLINE9PY, end, end + HELPLINELENGTH, RAD9IN);
        Arc(HELPLINE9PX, HELPLINE9PY, end, end + HELPLINELENGTH, RAD9OUT);
        end = end + HELPLINELENGTH + HELPLINESKIP;
    } 
}
void MyDraw::myDrawHelpLine01213(TColor color = HELPLINEWEISS) {
    int end;
    SetPen(color, HELPLINEWIDTH);
    MoveTo(HELPLINE12LFROMX, HELPLINE12LFROMY);
    for(end = HELPLINE12LFROMY; end < HELPLINE12LTOY;) {
        end += HELPLINELENGTH;
        LineTo(HELPLINE12LFROMX, end);
        end += HELPLINESKIP;
        MoveTo(HELPLINE12LFROMX, end);
    }
      MoveTo(HELPLINE13LFROMX, HELPLINE13LFROMY);
    for(end = HELPLINE13LFROMY; end < HELPLINE13LTOY;) {
        end += HELPLINELENGTH;
        LineTo(HELPLINE13LFROMX, end);
        end += HELPLINESKIP;
        MoveTo(HELPLINE13LFROMX, end);
    }
    for(end = HELPLINE1213STARTGRAD; end < HELPLINE1213ENDGRAD; ) {
        Arc(HELPLINE1213PX, HELPLINE1213PY, end, end + HELPLINELENGTH, RAD12IN);
        Arc(HELPLINE1213PX, HELPLINE1213PY, end, end + HELPLINELENGTH, RAD13IN);
        Arc(HELPLINE1213PX, HELPLINE1213PY, end, end + HELPLINELENGTH, RAD13OUT);
        end = end + HELPLINELENGTH + HELPLINESKIP;
    }  
   
    for(end = HELPLINE0STARTGRAD; end < HELPLINE0ENDGRAD; ) {
        Arc(HELPLINE0PX, HELPLINE0PY, end, end + HELPLINELENGTH, LEERwIDTH + MYLANEWIDTH);
        end = end + HELPLINELENGTH + HELPLINESKIP;
    }  
 
}