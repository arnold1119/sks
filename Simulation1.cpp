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

list<MyFahrzeug *> lsss;

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
// lsss.push_front(fs);
fs.setSpeed(4.4);
    // printf("fs  = %d, \n",lsss.size());
}

void TUser::Run(void) {
    printf("fs  = %f, y = %f \n",
        fs.getPositionX(), fs.getPositionY());

}

void TUser::Reset(void) {

}


//====================================================================
#pragma argsused
int main(int argc, char* argv[]){ TUser a; a.Execute(); return 0; }
//__________________________________________________________Ost08_____

