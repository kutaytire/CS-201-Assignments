
/*

Kutay Tire
22001787
Sec03
21.11.2021


*/

#include <iostream>
using namespace std;
#include "LabOrganizer.h"
#include "Cabinet.h"
#include "Chemical.h"
#include <string>
#include <sstream>
LabOrganizer :: LabOrganizer() {

    sizeOfPointerArray = 0;
    pointerArray = new Cabinet*[sizeOfPointerArray];

}


LabOrganizer :: ~LabOrganizer() {

    for (int k = 0; k < sizeOfPointerArray; k ++) {


        for (int i = 0; i < pointerArray[k] -> getChemicalArraySize(); i++) {

                delete pointerArray[k] -> getChemicalPointer() [i];

        }
        delete [] pointerArray[k] -> getChemicalPointer();


        for (int i = 0; i < pointerArray[k] -> getRowNumber(); i++){

            delete [] pointerArray[k] -> getCabinetSystem() [i];

        }
        delete [] pointerArray[k] -> getCabinetSystem();
        delete pointerArray[k];
    }

    delete [] pointerArray;
    sizeOfPointerArray = 0;



}

int LabOrganizer :: checkEmptySlots( Cabinet sample) {

    int emptySlots = 0;
    for (int a = 0; a < sample.getRowNumber(); a++){

        for (int b = 0; b < sample.getColumnNumber(); b++) {


            if ( (sample.getCabinetSystem())[a][b] == '+' ) {

                emptySlots++;
            }


        }
    }

    return emptySlots;
}

Cabinet** LabOrganizer :: increaseArraySize(Cabinet** arrayName, int sizeOf, Cabinet* lastElement) {

int newSize = sizeOf + 1;
Cabinet** newArray = new Cabinet*[newSize];

for (int k = 0; k < sizeOf; k++){

    newArray[k] = arrayName[k];
}
newArray[sizeOf] = lastElement;
delete [] arrayName;
return newArray;


}

Cabinet** LabOrganizer :: decreaseArraySize(Cabinet** arrayName, int sizeOf, int breakingPoint) {

        int newSize = sizeOf -1;
        Cabinet** newArray = new Cabinet*[newSize];

        for ( int k = 0; k < breakingPoint; k++) {

            newArray[k] = arrayName[k];
        }

        delete arrayName[breakingPoint];

        for ( int k = breakingPoint; k < newSize; k++ ) {

            newArray[k] = arrayName[k + 1];
        }

        delete [] arrayName;
        return newArray;

}

void LabOrganizer :: addCabinet(int const id, int rows, int columns){

    if ( rows > 9 || columns > 9) {
        // Rows or columns out of bounds
        cout << "Cannot add the cabinet: dimensions are out of bounds." << endl;
        cout << " " << endl;
    }
    else {

            bool canBeAdded = true;
            // Check for id exists
            for( int k = 0; k < sizeOfPointerArray; k++) {
                if ( (*(pointerArray[k])).getID()== id) {
                    cout << "Cannot add the cabinet: ID " << id << " is already on the system." << endl;
                    cout << " " << endl;
                    canBeAdded = false;
                    break; // Already in the list so break the loop and make canBeAdded boolean false
                }
            } // end of for

            if  (canBeAdded) {
                // Add cabinet at the end and increase size

                Cabinet* cabPointer = new Cabinet(id,rows,columns);
                pointerArray = increaseArraySize(pointerArray, sizeOfPointerArray, cabPointer);
                sizeOfPointerArray++;
                cout << "Added a cabinet: ID " << id << " and dimensions " << rows << " to " << columns << endl;
                cout<< "Total cabinet:" << sizeOfPointerArray << endl;
                cout << " " << endl;

            }


    }

}

void LabOrganizer :: removeCabinet(int id) {

     bool found = false;

     for( int k = 0; k < sizeOfPointerArray; k++) {

        if ( (*(pointerArray[k])).getID()== id) {


            for (int i = 0; i < pointerArray[k] -> getChemicalArraySize(); i++) {

                delete pointerArray[k] -> getChemicalPointer() [i];

        }
        delete [] pointerArray[k] -> getChemicalPointer();


        for (int i = 0; i < pointerArray[k] -> getRowNumber(); i++){

            delete [] pointerArray[k] -> getCabinetSystem() [i];

        }


        delete [] pointerArray[k] -> getCabinetSystem();


            pointerArray = decreaseArraySize(pointerArray, sizeOfPointerArray, k);
            sizeOfPointerArray--;


            cout << "Cabinet " << id << " has been removed." << endl;
            found = true;
        }
     }

    if (!found) {

        cout << "Cabinet " << id << " does not exist in the system." << endl;
    }


}




void LabOrganizer :: listCabinets(){



 for( int k = 0; k < sizeOfPointerArray; k++) {

      cout << "Cabinet ID:" << (*(pointerArray[k])).getID() << ",";
      cout << " Dimensions: ";
      cout << (*(pointerArray[k])).getRowNumber();
      cout << "x" << (*(pointerArray[k])).getColumnNumber();
      cout << ", Number of empty slots: " << checkEmptySlots((*(pointerArray[k]))) << endl;
 }

}


void LabOrganizer :: placeChemical(int cabinetId, string location, string chemType, int chemID){

    bool exists = false;
    bool otherChemicalExists = false;
    int cabinetPlace = 0;

    for( int k = 0; k < sizeOfPointerArray; k++) {

            if((*(pointerArray[k])).checkOtherChemId(chemID)) {

                otherChemicalExists = true;
            }

            if ( (*(pointerArray[k])).getID()== cabinetId) {

                    cabinetPlace = k;
                    exists = true;
            }
        }

    if (!exists) {

        cout << "Cabinet " << cabinetId << " does not exist in the system." << endl;
    }


    if ( otherChemicalExists) {

        cout << "Chemical ID " << chemID << " already exists in the system." << endl;

    }
    if (exists && !otherChemicalExists ) {

            (*(pointerArray[cabinetPlace])).checkChemicalPlacement(location, chemType, chemID);


    }

}

void LabOrganizer :: findChemical(int id) {

    bool foundChemical = false;

    for( int k = 0; k < sizeOfPointerArray; k++) {

            for(int a = 0; a < (*(pointerArray[k])).getChemicalArraySize(); a++) {

                    if ( (*((*(pointerArray[k])). getChemicalPointer()[a])).getID() == id ) {

                        foundChemical = true;
                        cout << "Chemical " << id << " is at location " << (*((*(pointerArray[k])). getChemicalPointer()[a])).getLocation() << " in cabinet " << (*(pointerArray[k])).getID() << endl;
                        break;
                    }
            }
    }

    if (!foundChemical) {

        cout << "Chemical " << id << " is not in the system" << endl;
    }


}

void LabOrganizer :: cabinetContents(int id) {


    bool exists = false;
    int target = 0;

    for( int k = 0; k < sizeOfPointerArray; k++) {

            if ( (*(pointerArray[k])).getID()== id) {


                string outputString = "";
                exists = true;
                target = k;
                cout << "ID: " << id << ", " << (*(pointerArray[k])).getRowNumber() << "x" << (*(pointerArray[k])).getColumnNumber();
                cout << " Empty slots: " << checkEmptySlots((*(pointerArray[k]))) << " Chemical: ";

                for (int a = 0; a < (*(pointerArray[k])).getChemicalArraySize(); a++) {

                    outputString.append((*((*(pointerArray[k])). getChemicalPointer()[a])).getLocation());
                    outputString.append(": ");

                    int idNumber =(*((*(pointerArray[k])). getChemicalPointer()[a])).getID();
                    stringstream ss;
                    ss << idNumber;
                    string str = ss.str();
                    outputString.append(str);
                    outputString.append(", ");
                }
                outputString.erase(outputString.length() - 2 );
                cout << outputString << endl;


            }




    }
            if (exists) {

                cout << " ";
                for (int k = 1; k <= (*(pointerArray[target])).getColumnNumber(); k++) {

                    cout <<" " <<  k;
                }
                cout << endl;
                for (int a = 0; a < (*(pointerArray[target])).getRowNumber(); a++){


                        if (a == 0) {

                            cout << "A ";
                        }
                        else if (a == 1) {

                            cout << "B ";
                        }
                        else if (a == 2) {

                            cout << "C ";
                        }
                        else if (a == 3) {

                            cout << "D ";
                        }
                        else if (a == 4) {

                            cout << "E ";
                        }
                        else if (a == 5) {

                            cout << "F ";
                        }
                        else if (a == 6) {

                            cout << "G ";
                        }
                        else if (a == 7) {

                            cout << "H ";
                        }
                        else if (a == 8) {

                            cout << "I ";
                        }




                        for (int b = 0; b < (*(pointerArray[target])).getColumnNumber(); b++) {


                            cout <<  (*(pointerArray[target])).getCabinetSystem()[a][b]  << " ";

                        }
                        cout << endl;
                }

            }

            else {


                cout << "Cabinet " << id << " is not in the system" << endl;
            }


}

void LabOrganizer :: removeChemical(int id) {

    bool foundChemical = false;

    for( int k = 0; k < sizeOfPointerArray; k++) {

            for(int a = 0; a < (*(pointerArray[k])).getChemicalArraySize(); a++) {

                    if ( (*((*(pointerArray[k])). getChemicalPointer()[a])).getID() == id ) {

                            foundChemical = true;
                            string loc = (*((*(pointerArray[k])). getChemicalPointer()[a])).getLocation();

                            int rowNumber;
                            stringstream intValue(loc.substr(1,1));
                            int number = 0;
                            intValue >> number;
                            int columnNumber = number -1;


                            if (loc[0] == 'A') {

                                rowNumber = 0;
                            }

                            else if (loc[0] == 'B') {

                                rowNumber = 1;
                            }

                            else if (loc[0] == 'C') {

                                rowNumber = 2;
                            }

                            else if (loc[0] == 'D') {

                                rowNumber = 3;
                            }

                            else if (loc[0] == 'E') {

                                rowNumber = 4;
                            }

                            else if (loc[0] == 'F') {

                                rowNumber = 5;
                            }

                            else if (loc[0] == 'G') {

                                rowNumber = 6;
                            }

                             else if (loc[0] == 'H') {

                                rowNumber = 7;
                            }

                             else if (loc[0] == 'I') {

                                rowNumber = 8;
                            }

                            (*(pointerArray[k])).getCabinetSystem() [rowNumber][columnNumber] = '+';

                            (*(pointerArray[k])).removeInChemArray(id);
                            cout << "Chemical " << id << " has been removed from cabinet " << (*(pointerArray[k])).getID() << endl;

                    }


            }
    }

    if (!foundChemical) {

        cout << "Chemical " << id << " is not in the system" << endl;
    }


}









