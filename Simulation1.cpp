//====================================================================
// Simulation dynamischer Systeme mit PLAN
//====================================================================
// Projektbeschreibung:
//
//====================================================================
//#include <vcl.h>
#pragma hdrstop
#include "Plan.h"
#include <stdio>
#include "MyDraw.h"
#include "MyFahrzeug.h"
#include <vector>
#include <list> 

#define ARRAYNUM 400
#define AUTONUMIN1ROAD  30 

class TUser : public TPlan {
    public:
        
        void Init(void);
        void Run(void);
        void Reset(void);
        void createCall(void);
        void showVec(const std::vector<int>& lr);
};
// std::vector<MyFahrzeug> vfs;
// std::list<MyFahrzeug> lfs;
// std::list<MyFahrzeug>::iterator itrs = lfs.begin();
// std::list<MyFahrzeug>::iterator itre = lfs.end();

MyDraw myDraw;
MyFahrzeug ss[ARRAYNUM];
std::vector<int> lr0;
std::vector<int> lr1;
std::vector<int> lr2;
std::vector<int> lr3;
std::vector<int> lr4;
std::vector<int> lr5;
std::vector<int> lr6;
std::vector<int> lr7;
std::vector<int> lr8;
std::vector<int> lr9;
std::vector<int> lr10;
std::vector<int> lr11;
std::vector<int> lr12;
std::vector<int> lr13;


int roadNum = 0;
int startI = 0;
int createNum = 1;

void TUser::Init(void) {
    printf("=========================================\n");
    lr0.clear();
    lr1.clear();
    lr2.clear();
    lr3.clear();
    lr4.clear();
    lr5.clear();
    lr6.clear();
    lr7.clear();
    lr8.clear();
    lr9.clear();
    lr10.clear();
    lr11.clear();
    lr12.clear(); 
    lr13.clear(); 
    startI = 0;
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

    // for(int i = 0; i < ARRAYNUM; i++) {
    //     ss[i].autoMove();
    // }

    createCall();
    showVec(lr0);
    showVec(lr1);
    showVec(lr2);
    showVec(lr3);
    showVec(lr4);
    showVec(lr5);
    showVec(lr6);
    showVec(lr7);
    showVec(lr8);
    showVec(lr9);
    showVec(lr10);
    showVec(lr11);
    showVec(lr12);
    showVec(lr13);
   
    CallRun = true; 
}

void TUser::Reset(void) {
    TUser::Init(); 
    
}

void TUser::createCall(void) {
    int temp = startI + createNum;
    for(; startI < temp; startI++) {
        ss[startI].createAuto(roadNum, AUTOW, AUTOH, AUTOCOLOR);
        
       
        switch(roadNum) {
            case 0:
                if (0 != lr0.size())
                {
                    int index = lr0.back();
                    if (ss[index].getPositionX() >= CREATEAUTORIGHT)
                    {
                        ss[startI];
                        break;
                    }
                }
                ss[startI].autoDraw();
                lr0.push_back(startI);
                break;
            case 1:
                if (0 != lr1.size())
                {
                    int index = lr1.back();
                    if (ss[index].getPositionX() >= CREATEAUTORIGHT)
                    {
                        ss[startI];
                        continue;
                    }
                }
                ss[startI].autoDraw();
                lr1.push_back(startI);
                break;
            case 2:
                if (0 != lr2.size())
                {
                    int index = lr2.back();
                    if (ss[index].getPositionX() >= CREATEAUTORIGHT)
                    {
                        ss[startI];
                        continue;
                    }
                }
                lr2.push_back(startI);
                break;
            case 3:
                if (0 != lr3.size())
                {
                    int index = lr3.back();
                    if (ss[index].getPositionY() >= CREATEAUTODOWN)
                    {
                        ss[startI];
                        continue;
                    }
                }
                lr3.push_back(startI);
                break;
            case 4:
                if (0 != lr4.size())
                {
                    int index = lr4.back();
                    if (ss[index].getPositionY() >= CREATEAUTODOWN)
                    {
                        ss[startI];
                        continue;
                    }
                }
                lr4.push_back(startI);
                break;
            case 5:
                if (0 != lr5.size())
                {
                    int index = lr5.back();
                    if (ss[index].getPositionY() >= CREATEAUTODOWN)
                    {
                        ss[startI];
                        continue;
                    }
                }
                lr5.push_back(startI);
                break;
            case 6:
                if (0 != lr6.size())
                {
                    int index = lr6.back();
                    if (ss[index].getPositionY() >= CREATEAUTODOWN)
                    {
                        ss[startI];
                        continue;
                    }
                }
                lr6.push_back(startI);
                break;
            case 7:
                if (0 != lr7.size())
                {
                    int index = lr7.back();
                    if (ss[index].getPositionX() <= CREATEAUTOLEFT)
                    {
                        ss[startI];
                        continue;
                    }
                }
                lr7.push_back(startI);
                break;
            case 8:
                if (0 != lr8.size())
                {
                    int index = lr8.back();
                    if (ss[index].getPositionX() <= CREATEAUTOLEFT)
                    {
                        ss[startI];
                        continue;
                    }
                }
                lr8.push_back(startI);
                break;
            case 9:
                if (0 != lr9.size())
                {
                    int index = lr9.back();
                    if (ss[index].getPositionX() <= CREATEAUTOLEFT)
                    {
                        ss[startI];
                        continue;
                    }
                }
                lr9.push_back(startI);
                break;
            case 10:
                if (0 != lr10.size())
                {
                    int index = lr10.back();
                    if (ss[index].getPositionY() <= CREATEAUTOUP)
                    {
                        ss[startI];
                        continue;
                    }
                }

                lr10.push_back(startI);
                break;
            case 11:
                if (0 != lr11.size())
                {
                    int index = lr11.back();
                    if (ss[index].getPositionY() <= CREATEAUTOUP)
                    {
                        ss[startI];
                        continue;
                    }
                }
                lr11.push_back(startI);
                break;
            case 12:
                if (0 != lr12.size())
                {
                    int index = lr12.back();
                    if (ss[index].getPositionY() <= CREATEAUTOUP)
                    {
                        ss[startI];
                        continue;
                    }
                }
                lr12.push_back(startI);
                break;
            case 13:
                if (0 != lr13.size())
                {
                    int index = lr13.back();
                    if (ss[index].getPositionY() <= CREATEAUTOUP)
                    {
                        ss[startI];
                        continue;
                    }
                }
                lr13.push_back(startI);
                break;
        }
    } 
}

void TUser::showVec(const std::vector<int>& lr) {
    for (std::vector<int>::const_iterator iter = lr.begin(); iter != lr.end(); iter++) {
        ss[*iter].autoMove();
    }
}
//====================================================================
#pragma argsused
int main(int argc, char* argv[]){ TUser a; a.Execute(); return 0; }
//__________________________________________________________Ost08_____

