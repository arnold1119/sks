//====================================================================
// Simulation dynamischer Systeme mit PLAN
//====================================================================
// Projektbeschreibung:
//
//====================================================================
#include <vcl.h>
#pragma hdrstop
#include "Plan.h"
#include "MyDraw.h"
#include "MyFahrzeug.h"
#include <list.h>
class TUser : public TPlan {
    public:
        void Init(void);
        void Run(void);
        void Reset(void);

};

MyDraw myDraw;

extern list<MyFahrzeug *> r0;
extern list<MyFahrzeug *> r1;
extern list<MyFahrzeug *> r2;
extern list<MyFahrzeug *> r3;
extern list<MyFahrzeug *> r4;
extern list<MyFahrzeug *> r5;
extern list<MyFahrzeug *> r5;
extern list<MyFahrzeug *> r7;
extern list<MyFahrzeug *> r8;
extern list<MyFahrzeug *> r9;
extern list<MyFahrzeug *> r10;
extern list<MyFahrzeug *> r11;
extern list<MyFahrzeug *> r12;
extern list<MyFahrzeug *> r13;

list<MyFahrzeug *>::iterator iter;

    MyFahrzeug fs;

void TUser::Init(void) {
    int retY[2], retX[2];
    myDraw.init();
    myDraw.myDrawRoad(5, retY, 1);
    myDraw.myDrawRoad(6, retX, 0);
    myDraw.myDrawKreuzungCover(retX, retY);
    myDraw.myDrawZwisch(2, 1);
    myDraw.myDrawZwisch(4, 0);
    myDraw.myDrawFP();
    // for(int i = 0; i < 1; i++) {
    //    MyFahrzeug fs;
    //    fs.createAuto(AUTOW, AUTOH, AUTOCOLOR);
    // }

    fs.createAuto(AUTOW, AUTOH, AUTOCOLOR);
    
    // printf("fs %d \n", lsss.front()->getRoadNum());
    // printf("fs  = %d, \n",lsss.size());
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
    // printf("fs  = %f, y = %f \n",
    //     fs.getPositionX(), fs.getPositionY());
    fs.autoMove();
    CallRun = true; 
}

void TUser::Reset(void) {
    TUser::Init();
}


//====================================================================
#pragma argsused
int main(int argc, char* argv[]){ TUser a; a.Execute(); return 0; }
//__________________________________________________________Ost08_____

