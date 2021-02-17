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
#include "Test.h"
 

#define ARRAYNUM 400
#define AUTONUMIN1ROAD  30 

class TUser : public TPlan {
    public:
        
        void Init(void);
        void Run(void);
        void Reset(void);
        void createCall(void);
        void showVec(std::vector<MyFahrzeug>& lr);
};
Test t;
std::vector<MyFahrzeug> vfs0;
std::list<MyFahrzeug> ls1;
// std::vector<MyFahrzeug> vfs2;
// std::vector<MyFahrzeug> vfs3;
// std::vector<MyFahrzeug> vfs4;
// std::vector<MyFahrzeug> vfs5;
// std::vector<MyFahrzeug> vfs6;
// std::vector<MyFahrzeug> vfs7;
// std::vector<MyFahrzeug> vfs8;
// std::vector<MyFahrzeug> vfs9;
// std::vector<MyFahrzeug> vfs10;
// std::vector<MyFahrzeug> vfs11;
// std::vector<MyFahrzeug> vfs12;
// std::vector<MyFahrzeug> vfs13;


MyDraw myDraw;
MyFahrzeug ss;



int roadNum = 0;
int createNum = 25;

void TUser::Init(void) {
    printf("test ist lauf a = %d\n", t.a);
    printf("=========================================\n");
   
    vfs0.clear();
    createNum = 25;
    roadNum = 0;
    int retY[2], retX[2];
    myDraw.init();
    myDraw.myDrawRoad(5, retY, 1);
    myDraw.myDrawRoad(6, retX, 0);
    myDraw.myDrawKreuzungCover(retX, retY);
    myDraw.myDrawZwisch(2, 1);
    myDraw.myDrawZwisch(4, 0);
    myDraw.myDrawFP();
    createCall();
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

    // createCall();
    
    std::cout<<"ls1 size ist "<<ls1.size()<<std::endl;
    ls1.front().autoMove();
    CallRun = true; 
}

void TUser::Reset(void) {
    TUser::Init(); 
    
}

void TUser::showVec(std::vector<MyFahrzeug>& lr) {
    std::cout<<"vfs0 size ist "<<lr.size()<<std::endl;
   
   ss.autoMove();
    for (std::vector<MyFahrzeug>::iterator iter = lr.begin(); iter != lr.end(); iter++) {
            // (iter)->autoMove();
        std::cout<<"vfs0 x ist "<<(*iter).getPositionX()<<std::endl;
        std::cout<<"vfs0 y ist "<<(*iter).getPositionY()<<std::endl;
        std::cout<<"vfs0 speed ist "<<(*iter).getSpeed()<<std::endl;
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
                vfs0.push_back(ss);
                break;
            case 1:
                if (0 != ls1.size()) {
                    if(ls1.back().getPositionX() >= CREATEAUTORIGHT) {
                        break;
                    }
                }
                ls1.push_back(ss);
                break;
            // case 1:
            //     if (0 != vfs1.size()) {
            //         if(vfs1.back().getPositionX() >= CREATEAUTORIGHT) {
            //             break;
            //         }
            //     }
            //     vfs1.push_back(ss);
            //     break;
            // case 2:
            //     if (0 != vfs2.size()) {
            //         if(vfs2.back().getPositionX() >= CREATEAUTORIGHT) {
            //             break;
            //         }
            //     }
            //     vfs2.push_back(ss);
            //     break;
            // case 3:
            //     if (0 != vfs3.size()) {
            //         if(vfs3.back().getPositionX() >= CREATEAUTORIGHT) {
            //             break;
            //         }
            //     }
            //     vfs3.push_back(ss);
            //     break;
            // case 4:
            //     if (0 != vfs4.size()) {
            //         if(vfs4.back().getPositionX() >= CREATEAUTORIGHT) {
            //             break;
            //         }
            //     }
            //     vfs4.push_back(ss);
            //     break;
            // case 5:
            //     if (0 != vfs5.size()) {
            //         if(vfs5.back().getPositionX() >= CREATEAUTORIGHT) {
            //             break;
            //         }
            //     }
            //     vfs5.push_back(ss);
            //     break;
            // case 6:
            //     if (0 != vfs6.size()) {
            //         if(vfs6.back().getPositionX() >= CREATEAUTORIGHT) {
            //             break;
            //         }
            //     }
            //     vfs6.push_back(ss);
            //     break;
            // case 7:
            //     if (0 != vfs7.size()) {
            //         if(vfs7.back().getPositionX() >= CREATEAUTORIGHT) {
            //             break;
            //         }
            //     }
            //     vfs7.push_back(ss);
            //     break;
            // case 8:
            //     if (0 != vfs8.size()) {
            //         if(vfs8.back().getPositionX() >= CREATEAUTORIGHT) {
            //             break;
            //         }
            //     }
            //     vfs8.push_back(ss);
            //     break;
            // case 9:
            //     if (0 != vfs9.size()) {
            //         if(vfs9.back().getPositionX() >= CREATEAUTORIGHT) {
            //             break;
            //         }
            //     }
            //     vfs9.push_back(ss);
            //     break;
            // case 10:
            //     if (0 != vfs10.size()) {
            //         if(vfs10.back().getPositionX() >= CREATEAUTORIGHT) {
            //             break;
            //         }
            //     }
            //     vfs10.push_back(ss);
            //     break;
            // case 11:
            //     if (0 != vfs11.size()) {
            //         if(vfs11.back().getPositionX() >= CREATEAUTORIGHT) {
            //             break;
            //         }
            //     }
            //     vfs11.push_back(ss);
            //     break; 
            // case 12:
            //     if (0 != vfs12.size()) {
            //         if(vfs12.back().getPositionX() >= CREATEAUTORIGHT) {
            //             break;
            //         }
            //     }
            //     vfs12.push_back(ss);
            //     break; 
            // case 13:
            //     if (0 != vfs13.size()) {
            //         if(vfs13.back().getPositionX() >= CREATEAUTORIGHT) {
            //             break;
            //         }
            //     }
            //     vfs13.push_back(ss);
            //     break; 
            default:
                std::cout<<"you are snoopy"<<std::endl;
        }
    } 
}


//====================================================================
#pragma argsused
int main(int argc, char* argv[]){ TUser a; a.Execute(); return 0; }
//__________________________________________________________Ost08_____

