#ifndef MYDRAW_H
#define MYDRAW_H
#define MYLANEWIDTH         35 
#define MYROADCOLOR         Grau
#define GEBAUDE             Hellgrau
#define MYROADLINECOLOR     Weiss
#define MYROADCOVERCOLOR    Grau
#define MYROADLINEWIDTH     2  
#define CONTROLWIDTH        200
#define MYROADRADIO         50
#define MYROADVERBOTE       Hellrot

#define MYROADAUTOCOLOR     Gelb
#define MYROADAUTOBREIT     20
#define MYROADAUTOLANGE     40
#define MYROADSICHER        100

#define LEERwIDTH           50
#define FWIDTH              25
#define PWIDTH              55
#define FCOLOR              Schwarz 
#define PCOLOR              Hellgrau



#include "Plan.h"
/*
    @Function: Draw Road
    @Parameter:
        iAllLanes       :   Number of lanes
        iLeft           :   left or up Number of lanes
        iStore          :   return for height or width
        iHorizontale    :   Road horizontale
    @return: void
*/
class MyDraw : public TPlan{
public:
    void init();
    void myDrawRoad(int iAllLanes, int (&iStore)[2], int iHorizontale);
    void myDrawRoadLine(int startX, int startY, int endX, int endY, TColor color);
    void myDrawRoadCoverLine(int startX, int startY, int endX, int endY, TColor color);
    void myDrawKreuzungCover(int (&x)[2], int (&y)[2]);
    void myDrawZwisch(int num, int iHorizontale);
    void myDrawFP();
    
private:
    int iHLans, iWLans;
    int startX, endX, startY, endY;

};

#endif