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
#define MYROADVERBOTE       Hellgruen

#define MYROADAUTOCOLOR     Gelb
#define MYROADAUTOBREIT     20
#define MYROADAUTOLANGE     40
#define MYROADSICHER        100

#define LEERwIDTH           50
#define FWIDTH              25
#define PWIDTH              55
#define FCOLOR              Schwarz 
#define PCOLOR              Hellgrau

#define LAMPERED    Hellrot 
#define LAMPEYELLOW Gelb 
#define LAMOEGREEN  Green 

#define MYDRAWSTARTY  ((GetMaxH() - MYLANEWIDTH * 6) / 2)
#define MYDRAWENDY    ((GetMaxH() + MYLANEWIDTH * 6) / 2) 
#define MYDRAWSTARTX  ((GetMaxW() - MYLANEWIDTH * 7) / 2)
#define MYDRAWENDX    ((GetMaxW() + MYLANEWIDTH * 7) / 2)

#define MYDRAWFLX  (STARTX - LEERwIDTH)
#define MYDRAWFRX  (ENDX + LEERwIDTH)
#define MYDRAWFOY  (STARTY - LEERwIDTH)
#define MYDRAWFUY  (ENDY + LEERwIDTH)

#define LAMPERADIO  20
#define ABSTAND     50

#define LAMPEOLX     (MYDRAWSTARTX - ABSTAND)
#define LAMPEOGX     (MYDRAWSTARTX - 2 * ABSTAND)
#define LAMPEORX     (MYDRAWSTARTX - 3 * ABSTAND)
#define LAMPEOY      (MYDRAWSTARTY - ABSTAND)   

#define LAMPEULX    (MYDRAWENDX + ABSTAND)
#define LAMPEUGX    (MYDRAWENDX + 2 * ABSTAND)
#define LAMPEURX    (MYDRAWENDX + 3 * ABSTAND)
#define LAMPEUY     (MYDRAWENDY + ABSTAND)   

#define LAMPELLY    (MYDRAWENDY + ABSTAND)
#define LAMPELGY    (MYDRAWENDY + 2 * ABSTAND)
#define LAMPELRY    (MYDRAWENDY + 3 * ABSTAND)
#define LAMPELX     (MYDRAWSTARTX - ABSTAND)



#define LAMPERLY    (MYDRAWSTARTY- ABSTAND)
#define LAMPERGY    (MYDRAWSTARTY - 2 * ABSTAND)
#define LAMPERRY    (MYDRAWSTARTY - 3 * ABSTAND)
#define LAMPERX     (MYDRAWENDX+ ABSTAND)

#include "Plan.h"
#include "MyFahrzeug.h"
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
    void init(int&, int&);
    void myDrawRoad(int iAllLanes, int (&iStore)[2], int iHorizontale);
    void myDrawRoadLine(int startX, int startY, int endX, int endY, TColor color);
    void myDrawRoadCoverLine(int startX, int startY, int endX, int endY, TColor color);
    void myDrawKreuzungCover(int (&x)[2], int (&y)[2]);
    void myDrawFP();
    void myDrawZwisch(int num, int iHorizontale);
    void myDrawLampeStop(); 

   
private:
    int iHLans, iWLans;
    int startX, endX, startY, endY;

};

#endif