#ifndef FAHRZEUG_H
#define FAHRZEUG_H
#define FAHRZEUGCOLOR     Geld
#define FAHRZEUGRADCOLOR Schwarz
#include "Plan.h"

class Fahrzeug : public TPlan {
private:
    int autoW = 30;
    int autoH = 50;
    int autoX, autoY;
    int radLength = 10;
    TColor autoRadC = 
    TColor autoC = FAHRZEUGCOLOR;
}

#endif