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
#define LAMOEGREEN  Gruen 

#define MYDRAWSTARTY  ((GetMaxH() - MYLANEWIDTH * 6) / 2)
#define MYDRAWENDY    ((GetMaxH() + MYLANEWIDTH * 6) / 2) 
#define MYDRAWSTARTX  ((GetMaxW() - MYLANEWIDTH * 7) / 2)
#define MYDRAWENDX    ((GetMaxW() + MYLANEWIDTH * 7) / 2)

#define MYDRAWFLX  (STARTX - LEERwIDTH)
#define MYDRAWFRX  (ENDX + LEERwIDTH)
#define MYDRAWFOY  (STARTY - LEERwIDTH)
#define MYDRAWFUY  (ENDY + LEERwIDTH)

#define LAMPERADIO      20
#define LAMPELINEWIDTH  3
#define LAMPELINELENGTH (2 * LAMPERADIO - 10)
#define ABSTAND         50

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


#define RICHTUNGGERAD   0
#define RICHTUNGLEFT    1
#define RICHTUNGRIGHT   2

#define ROADRICHTUNG012     (2.0 * M_PI * 270 / 360)
#define ROADRICHTUNG3456    (0.0)
#define ROADRICHTUNG789     (2.0 * M_PI * 90 / 360)
#define ROADRICHTUNG0123    (2.0 * M_PI * 180 / 360)    

#define ABLENGHT        50
#define ABLEER          50
#define ABWIDTH         6 

#define ABFARBE         Weiss

#define HELPLINEWEISS        Weiss
#define HELPLINEGELB         Gelb
#define HELPLINEWIDTH   2
#define HELPLINELENGTH  10 
#define HELPLINESKIP    5

#define HELPLINE1OFROMX     (endX + LEERwIDTH)
#define HELPLINE1OFROMY     (startY + MYLANEWIDTH)
#define HELPLINE1OTOX       (startX - LEERwIDTH)
#define HELPLINE1OTOY       (startY + MYLANEWIDTH)

#define HELPLINE1UFROMX     (endX + LEERwIDTH)
#define HELPLINE1UFROMY     (startY + 2 * MYLANEWIDTH)
#define HELPLINE1UTOX       (startX - LEERwIDTH)
#define HELPLINE1UTOY       (startY + 2 * MYLANEWIDTH)

#define HELPLINE2UFROMX     (endX + LEERwIDTH)
#define HELPLINE2UFROMY     (startY + 3 * MYLANEWIDTH)
#define HELPLINE2UTOX       (endX - 2 * MYLANEWIDTH)
#define HELPLINE2UTOY       (startY + 3 * MYLANEWIDTH)
#define HELPLINE2PX         (endX - 2 * MYLANEWIDTH)
#define HELPLINE2PY         (endY)
#define HELPLINE2STARTGRAD  90
#define HELPLINE2ENDGRAD    180
#define RAD2IN                (3 * MYLANEWIDTH)
#define RAD2OUT               (4 * MYLANEWIDTH)



#define HELPLINE8OFROMX     (startX - LEERwIDTH)
#define HELPLINE8OFROMY     (endY - 2 * MYLANEWIDTH)
#define HELPLINE8OTOX       (endX + LEERwIDTH)
#define HELPLINE8OTOY       (endY - 2 * MYLANEWIDTH)

#define HELPLINE8UFROMX     (startX - LEERwIDTH)
#define HELPLINE8UFROMY     (endY - MYLANEWIDTH)
#define HELPLINE8UTOX       (endX + LEERwIDTH)
#define HELPLINE8UTOY       (endY - MYLANEWIDTH)

#define HELPLINE4RFROMX     (endX - MYLANEWIDTH)
#define HELPLINE4RFROMY     (endY + LEERwIDTH)
#define HELPLINE4RTOX       (endX - MYLANEWIDTH)
#define HELPLINE4RTOY       (startY - LEERwIDTH)

#define HELPLINE4LFROMX     (endX - 2 * MYLANEWIDTH)
#define HELPLINE4LFROMY     (endY + LEERwIDTH)
#define HELPLINE4LTOX       (endX - 2 * MYLANEWIDTH)
#define HELPLINE4LTOY       (startY - LEERwIDTH)

#define HELPLINE11RFROMX     (startX + MYLANEWIDTH)
#define HELPLINE11RFROMY     (startY - LEERwIDTH)
#define HELPLINE11RTOX       (startX + MYLANEWIDTH)
#define HELPLINE11RTOY       (endY + LEERwIDTH)

#define HELPLINE11LFROMX     (startX + 2 * MYLANEWIDTH)
#define HELPLINE11LFROMY     (startY - LEERwIDTH)
#define HELPLINE11LTOX       (startX + 2 * MYLANEWIDTH)
#define HELPLINE11LTOY       (endY + LEERwIDTH)

#define HELPLINE12RFROMX     HELPLINE11LFROMX
#define HELPLINE12RFROMY     HELPLINE11LFROMY
#define HELPLINE12RTOX       HELPLINE11LFROMX
#define HELPLINE12RTOY       (startY + MYLANEWIDTH)

#define HELPLINE12LFROMX     (startX + 3 * MYLANEWIDTH)
#define HELPLINE12LFROMY     HELPLINE11LFROMY
#define HELPLINE12LTOX       (startX + 3 * MYLANEWIDTH)
#define HELPLINE12LTOY       (startY + MYLANEWIDTH)

#define HELPLINE13LFROMX     (startX + 4 * MYLANEWIDTH)
#define HELPLINE13LFROMY     HELPLINE11LFROMY
#define HELPLINE13LTOX       (startX + 4 * MYLANEWIDTH)
#define HELPLINE13LTOY       (startY + MYLANEWIDTH)

#define HELPLINE1213PX         (endX)
#define HELPLINE1213PY         (startY + MYLANEWIDTH)
#define HELPLINE1213STARTGRAD  180
#define HELPLINE1213ENDGRAD    270
#define RAD12IN                (3 * MYLANEWIDTH)
#define RAD13IN                (4 * MYLANEWIDTH)
#define RAD13OUT               (5 * MYLANEWIDTH)

#define HELPLINE0PX         (endX + LEERwIDTH)
#define HELPLINE0PY         (startY - LEERwIDTH)
#define HELPLINE0STARTGRAD  180
#define HELPLINE0ENDGRAD    270

#define HELPLINE10PX         (startX - LEERwIDTH)
#define HELPLINE10PY         (startY - LEERwIDTH)
#define HELPLINE10STARTGRAD  270
#define HELPLINE10ENDGRAD    360

#define HELPLINE7PX         (startX - LEERwIDTH)
#define HELPLINE7PY         (endY + LEERwIDTH)
#define HELPLINE7STARTGRAD  0
#define HELPLINE7ENDGRAD    90

#define HELPLINE3PX         (endX + LEERwIDTH)
#define HELPLINE3PY         (endY + LEERwIDTH)
#define HELPLINE3STARTGRAD  90
#define HELPLINE3ENDGRAD    180

#define HELPLINE9OFROMX     (startX - LEERwIDTH)
#define HELPLINE9OFROMY     (endY - 3 * MYLANEWIDTH)
#define HELPLINE9OTOX       (startX + 2 * MYLANEWIDTH)
#define HELPLINE9OTOY       (endY - 3 * MYLANEWIDTH)
#define HELPLINE9PX         (startX + 2 * MYLANEWIDTH)
#define HELPLINE9PY         (startY)
#define HELPLINE9STARTGRAD  270
#define HELPLINE9ENDGRAD    360
#define RAD9IN                (3 * MYLANEWIDTH)
#define RAD9OUT               (4 * MYLANEWIDTH)

#define HELPLINE5LFROMX     (endX - 3 * MYLANEWIDTH)
#define HELPLINE5LFROMY     (endY + LEERwIDTH)
#define HELPLINE5LTOX       (endX - 3 * MYLANEWIDTH)
#define HELPLINE5LTOY       (endY - MYLANEWIDTH)
#define HELPLINE6LFROMX     (endX - 4 * MYLANEWIDTH)
#define HELPLINE6LFROMY     (endY + LEERwIDTH)
#define HELPLINE6LTOX       (endX - 4 * MYLANEWIDTH)
#define HELPLINE6LTOY       (endY - MYLANEWIDTH)
#define HELPLINE56PX         (startX)
#define HELPLINE56PY         (endY - MYLANEWIDTH)
#define HELPLINE56STARTGRAD  0
#define HELPLINE56ENDGRAD    90
#define RAD5IN                (4 * MYLANEWIDTH)
#define RAD6IN                (3 * MYLANEWIDTH)
#define RAD5OUT               (5 * MYLANEWIDTH)


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
    void myDrawABLine(void);
    void myDrawABLine(int x, int y, double roadRichtung, int biegRichtung, int length, int width, TColor color);
    void myDrawHelpLine(void);
    void myDrawHelpLine18(TColor color);
    void myDrawHelpLine2(TColor color);
    void myDrawHelpLine341011(TColor color);
    void myDrawHelpLine567(TColor color);
    void myDrawHelpLine9(TColor color);
    void myDrawHelpLine01213(TColor color);
    
private:
    int iHLans, iWLans;
    int startX, endX, startY, endY;
    int calcRichtungPositionX(int PositionX, int PositonY, int centerX, int centerY, double richtung);
    int calcRichtungPositionY(int PositionX, int PositionY, int centerX, int centerY, double richtung);
};

#endif