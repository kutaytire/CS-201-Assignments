
/*

Kutay Tire
22001787
Sec03
21.11.2021


*/

#include <iostream>
using namespace std;
#include "Cabinet.h"
#include <sstream>

Cabinet:: Cabinet(int idNumber, int rowNumber, int columnNumber){

    sizeOfChemArray = 0;
    id = idNumber;
    rows = rowNumber;
    columns = columnNumber;
    chemArray = new Chemical*[sizeOfChemArray];
    cabinetSystem = new char*[rows];
    for (int k = 0; k < rowNumber; k++) {

        cabinetSystem[k] = new char[columns];
    }

    for (int a = 0; a < rows; a++){

        for (int b = 0; b < columns; b++) {

            cabinetSystem [a][b] = '+';

        }

    }


}

Cabinet :: Cabinet () {

    id = 0;
    rows = 0;
    columns = 0;
    chemArray = NULL;
    cabinetSystem = NULL;


}

int Cabinet :: getID() {

    return id;
}

Chemical** Cabinet :: increaseArraySize(Chemical** arrayName, int sizeOf, Chemical* lastElement) {

    int newSize = sizeOf + 1;
    Chemical** newArray = new Chemical*[newSize];

    for (int k = 0; k < sizeOf; k++){

        newArray[k] = arrayName[k];
    }
    newArray[sizeOf] = lastElement;
    delete [] arrayName;
    return newArray;
}

Chemical** Cabinet :: decreaseArraySize(Chemical** arrayName, int sizeOf, int breakingPoint){

        int newSize = sizeOf -1;
        Chemical** newArray = new Chemical*[newSize];

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

int Cabinet :: getRowNumber() {

    return rows;
}

int Cabinet :: getColumnNumber() {

    return columns;
}

char** Cabinet :: getCabinetSystem() {

    return cabinetSystem;
}

Chemical** Cabinet :: getChemicalPointer() {

    return chemArray;
}
int Cabinet :: getChemicalArraySize() {

    return sizeOfChemArray;
}


string Cabinet :: checkChemicalConditions(int row, int column) {

    string result = "";

    if (row > 0 && row < (*this).getRowNumber() && column >= 0 && (*this).getColumnNumber() > column ) {

        if ( (*this).getCabinetSystem() [row-1][column] == 'c') {

            return "";

        }

    }

    if (column > 0 && (*this).getColumnNumber() > column && row >= 0 && row < (*this).getRowNumber()) {

        if ((*this).getCabinetSystem() [row][column-1] == 'c') {

            return "";

        }

    }

    if (row > 0 && column > 0 && row < (*this).getRowNumber() && (*this).getColumnNumber() > column ) {

        if  ((*this).getCabinetSystem() [row-1][column-1] == 'c') {

            return "";

        }

    }

    if (row > 0 && column + 1 < (*this).getColumnNumber() && row < (*this).getRowNumber() && column >= 0) {

        if  ((*this).getCabinetSystem() [row-1][column+1] == 'c') {

            return "";

        }

    }




    if (row + 1 < (*this).getRowNumber() && row >= 0 && column >= 0 && (*this).getColumnNumber() > column  ) {

        if  ((*this).getCabinetSystem() [row+1][column] == 'c') {

            return "";

        }

    }

    if (column + 1 < (*this).getColumnNumber() && column >= 0 && row >= 0 && row < (*this).getRowNumber() ) {

        if ( (*this).getCabinetSystem() [row][column+1] == 'c') {

            return "";

        }

    }

    if (row + 1 < (*this).getRowNumber() && column + 1 < (*this).getColumnNumber() && row >= 0 && column >= 0) {

        if ( (*this).getCabinetSystem() [row+1][column+1] == 'c') {

            return "";

        }

    }

    if (row + 1 < (*this).getRowNumber() && column > 0 && (*this).getColumnNumber() > column && row >= 0) {

        if ( (*this).getCabinetSystem() [row+1][column-1] == 'c') {

            return "";

        }

    }


    if (row == 0) {

        result = "A";
    }

    else if (row == 1) {

        result = "B";
    }
    else if (row == 2) {

        result = "C";
    }

    else if (row == 3) {

        result = "D";
    }

    else if (row == 4) {

        result = "E";
    }

    else if (row == 5) {

        result = "F";
    }

    else if (row == 6) {

        result = "G";
    }

    else if (row == 7) {

        result = "H";
    }

    else if (row == 8) {

        result = "I";
    }



    if (row >= 0 && column >= 0 && row < (*this).getRowNumber() && column < (*this).getColumnNumber()) {

        if(((*this).getCabinetSystem() [row][column] == '+' )) {


            int a = column + 1;
            stringstream ss;
            ss << a;
            string str = ss.str();
            return result.append(str);

        }
    }

    return "";
}

string Cabinet :: checkChemicalConditionsRetardant(int row, int column) {


    string result = "";


    if (row == 0) {

        result = "A";
    }

    else if (row == 1) {

        result = "B";
    }
    else if (row == 2) {

        result = "C";
    }

    else if (row == 3) {

        result = "D";
    }

    else if (row == 4) {

        result = "E";
    }

    else if (row == 5) {

        result = "F";
    }

    else if (row == 6) {

        result = "G";
    }

    else if (row == 7) {

        result = "H";
    }

    else if (row == 8) {

        result = "I";
    }


    if (row >= 0 && column >= 0 && row < (*this).getRowNumber() && column < (*this).getColumnNumber()) {

        if(((*this).getCabinetSystem() [row][column] == '+' )) {


            int a = column + 1;
            stringstream ss;
            ss << a;
            string str = ss.str();
            return result.append(str);


        }
    }


    return "";


}


bool Cabinet :: checkOtherChemId(int id) {

    for (int k = 0; k < sizeOfChemArray; k++) {

        if ((*(chemArray[k])).getID() == id) {
            return true;
        }
    }

    return false;
}

void Cabinet :: removeInChemArray(int id) {

    for (int k = 0; k < sizeOfChemArray; k++) {

        if ( (*(chemArray[k])).getID() == id) {

            chemArray = decreaseArraySize (chemArray, sizeOfChemArray, k);
            //delete (chemArray[k]);
            sizeOfChemArray--;
        }

    }

}

void Cabinet :: checkChemicalPlacement(string locationString, string chemTypeString, int id) {

    int rowNumber;

    stringstream intValue(locationString.substr(1,1));
    int number = 0;
    intValue >> number;
    int columnNumber = number -1;
    char chemTypeChar;
    string outputString = "";


    if (chemTypeString == "combustive") {
        chemTypeChar = 'c';
    }

    else if (chemTypeString == "retardant") {
        chemTypeChar = 'r';
    }

    chemTypeString[0] = toupper(chemTypeString[0]);

    if (locationString[0] == 'A') {

        rowNumber = 0;
    }

    else if (locationString[0] == 'B') {

        rowNumber = 1;
    }

    else if (locationString[0] == 'C') {

        rowNumber = 2;
    }

    else if (locationString[0] == 'D') {

        rowNumber = 3;
    }

    else if (locationString[0] == 'E') {

        rowNumber = 4;
    }

    else if (locationString[0] == 'F') {

        rowNumber = 5;
    }

    else if (locationString[0] == 'G') {

        rowNumber = 6;
    }

     else if (locationString[0] == 'H') {

        rowNumber = 7;
    }

     else if (locationString[0] == 'I') {

        rowNumber = 8;
    }

    else {

        return;
    }


    if ((*this).getCabinetSystem()[rowNumber][columnNumber] != '+') {

        bool found = false;
        if (chemTypeChar == 'r') {

            int bigger = (*this).getRowNumber();
            if ( (*this).getColumnNumber() > (*this).getRowNumber()) {

                bigger = (*this).getColumnNumber();
            }

            for ( int k = 1; k < bigger; k++) {

                for ( int a = k; a >= -k; a--) {

                    string result1 = (*this).checkChemicalConditionsRetardant( rowNumber + k , (columnNumber + a));
                    string result2 = (*this).checkChemicalConditionsRetardant( rowNumber - k, (columnNumber + a));

                    if (result1 != "") {

                        outputString.append(result1);
                        outputString.append(",");

                    }

                    if (result2 != "") {

                        outputString.append(result2);
                        outputString.append(",");

                    }
                }

                for ( int a = k-1; a >= -(k-1); a--) {

                    string result3 = (*this).checkChemicalConditionsRetardant( rowNumber + a , (columnNumber + k));
                    string result4 = (*this).checkChemicalConditionsRetardant( rowNumber + a , (columnNumber - k));

                    if (result3 != "") {

                        outputString.append(result3);
                        outputString.append(",");

                    }

                    if (result4 != "") {

                        outputString.append(result4);
                        outputString.append(",");

                    }
                }

                if (outputString != "") {

                found = true;
                outputString.erase(outputString.length() -1 );
                cout << "Location " << locationString << " in cabinet " << (*this).getID() << " is already occupied. ";
                cout << "Nearest possible locations for this chemical: " << outputString << endl;
                break;

                }
            }

        }


        else if (chemTypeChar == 'c') {


             int bigger = (*this).getRowNumber();
                    if ( (*this).getColumnNumber() > (*this).getRowNumber()) {

                        bigger = (*this).getColumnNumber();
                    }

                    for ( int k = 1; k < bigger; k++) {

                        for ( int a = k; a >= -k; a--) {

                            string result1 = (*this).checkChemicalConditions( rowNumber + k , (columnNumber + a));
                            string result2 = (*this).checkChemicalConditions( rowNumber - k, (columnNumber + a));

                            if (result1 != "") {

                                outputString.append(result1);
                                outputString.append(",");

                            }

                            if (result2 != "") {

                                outputString.append(result2);
                                outputString.append(",");

                            }
                        }

                        for ( int a = k-1; a >= -(k-1); a--) {

                            string result3 = (*this).checkChemicalConditions( rowNumber + a , (columnNumber + k));
                            string result4 = (*this).checkChemicalConditions( rowNumber + a , (columnNumber - k));

                            if (result3 != "") {

                                outputString.append(result3);
                                outputString.append(",");

                            }

                            if (result4 != "") {

                                outputString.append(result4);
                                outputString.append(",");

                            }
                        }

                        if (outputString != "") {

                            outputString.erase(outputString.length() -1 );
                            cout << "Location " << locationString << " in cabinet " << (*this).getID() << " is not suitable for a combustive chemical. ";
                            cout << "Nearest possible locations for this chemical: " << outputString << endl;
                            found = true;
                            break;
                        }
                    }



        }
        if (!found) {

            cout << "Sorry, no suitable location" << endl;
        }

    }
    else {

            if (chemTypeChar == 'r') {

                    Chemical* chemPointer = new Chemical( locationString, chemTypeString , id);
                    (*this).getCabinetSystem()[rowNumber][columnNumber] = chemTypeChar;


                    chemArray = increaseArraySize (chemArray, sizeOfChemArray, chemPointer);

                    sizeOfChemArray++;
                    cout << chemTypeString << " chemical with ID " << id << " has been placed at the location " << locationString << " in cabinet " <<( *this).getID() << endl;

            }
            else {
;
                string str = (*this).checkChemicalConditions(rowNumber, columnNumber);

                if (str != "") {

                    Chemical* chemPointer = new Chemical( locationString, chemTypeString , id);
                    (*this).getCabinetSystem()[rowNumber][columnNumber] = chemTypeChar;
                    chemArray = increaseArraySize (chemArray, sizeOfChemArray, chemPointer);


                    sizeOfChemArray++;

                    cout << chemTypeString << " chemical with ID " << id << " has been placed at the location " << locationString << " in cabinet " <<( *this).getID() << endl;
                }

                else {

                    int bigger = (*this).getRowNumber();
                    if ( (*this).getColumnNumber() > (*this).getRowNumber()) {

                        bigger = (*this).getColumnNumber();
                    }
                    bool found = false;

                    for ( int k = 1; k < bigger; k++) {

                        for ( int a = k; a >= -k; a--) {

                            string result1 = (*this).checkChemicalConditions( rowNumber + k , (columnNumber + a));
                            string result2 = (*this).checkChemicalConditions( rowNumber - k, (columnNumber + a));

                            if (result1 != "") {

                                outputString.append(result1);
                                outputString.append(",");

                            }

                            if (result2 != "") {

                                outputString.append(result2);
                                outputString.append(",");

                            }
                        }

                        for ( int a = k-1; a >= -(k-1); a--) {

                            string result3 = (*this).checkChemicalConditions( rowNumber + a , (columnNumber + k));
                            string result4 = (*this).checkChemicalConditions( rowNumber + a , (columnNumber - k));

                            if (result3 != "") {

                                outputString.append(result3);
                                outputString.append(",");

                            }

                            if (result4 != "") {

                                outputString.append(result4);
                                outputString.append(",");

                            }
                        }

                        if (outputString != "") {

                            outputString.erase(outputString.length() -1 );
                            cout << "Location " << locationString << " in cabinet " << (*this).getID() << " is not suitable for a combustive chemical. ";
                            cout << "Nearest possible locations for this chemical: " << outputString << endl;
                            found = true;
                            break;
                        }

                    }



                    if (!found) {
                        cout << "No suitable location found" << endl;
                    }
                }
            }


        }

}







