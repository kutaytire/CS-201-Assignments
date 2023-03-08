
/*

Kutay Tire
22001787
Sec03
21.11.2021


*/

#ifndef _LABORGANIZER_H
#define _LABORGANIZER_H
#include <string>
#include "Cabinet.h"
#include "Chemical.h"

class LabOrganizer{
public:

LabOrganizer();
~LabOrganizer();
void addCabinet(int const id, int rows, int columns);
void removeCabinet(int id);
void listCabinets();
void cabinetContents(int id);
void placeChemical(int cabinetId, string location, string chemType, int chemID);
void findChemical(int id);
void removeChemical(int id);
static Cabinet** increaseArraySize(Cabinet** arrayName, int sizeOf, Cabinet* lastElement);
static Cabinet** decreaseArraySize(Cabinet** arrayName, int sizeOf, int breakingPoint);
static int checkEmptySlots(Cabinet sample);


private :

    int sizeOfPointerArray;
    Cabinet** pointerArray;

};

#endif
