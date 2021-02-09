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
class TUser : public TPlan {
    public:
        void Init(void);
        void Run(void);
        void Reset(void);

};

MyDraw myDraw;

void TUser::Init(void) {
    int retY[2], retX[2];
    myDraw.init();
    myDraw.myDrawRoad(5, retY, 1);
    myDraw.myDrawRoad(6, retX, 0);
    myDraw.myDrawKreuzungCover(retX, retY);
    myDraw.myDrawZwisch(2, MYROADVERBOTE, 1);
    myDraw.myDrawZwisch(4, MYROADVERBOTE, 0);
    myDraw.myDrawFP();

}

void TUser::Run(void) {

}

void TUser::Reset(void) {

}


//====================================================================
#pragma argsused
int main(int argc, char* argv[]){ TUser a; a.Execute(); return 0; }
//__________________________________________________________Ost08_____

