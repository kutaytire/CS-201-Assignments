
/*

Kutay Tire
22001787
Sec03
21.11.2021


*/

#include <iostream>
#include "Chemical.h"
using namespace std;

#ifndef _CABINET_H
#define _CABINET_H

class Cabinet {
public:

    Cabinet();
    Cabinet(int idNumber, int rowNumber, int columnNumber);
    int getID();
    int getRowNumber();
    int getColumnNumber();
    char** getCabinetSystem();
    void checkChemicalPlacement(string locationString, string chemTypeString, int id);
    bool checkOtherChemId(int id);
    string checkChemicalConditions(int row, int column);

    string checkChemicalConditionsRetardant(int row, int column);

    Chemical** increaseArraySize(Chemical** arrayName, int sizeOf, Chemical* lastElement);
    Chemical** decreaseArraySize(Chemical** arrayName, int sizeOf, int breakingPoint);
    Chemical** getChemicalPointer();


    int getChemicalArraySize();
    void removeInChemArray(int id);


private:

    int id;
    int rows;
    int columns;
    char** cabinetSystem;
    int sizeOfChemArray;
    Chemical** chemArray;
};

#endif

