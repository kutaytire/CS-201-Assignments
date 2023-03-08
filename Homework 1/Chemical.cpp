
/*

Kutay Tire
22001787
Sec03
21.11.2021


*/

#include <iostream>
using namespace std;
#include "Chemical.h"
#include <string>

Chemical :: Chemical(string const locationString, string const chemTypeString, int const id){

    location = locationString;
    chemType = chemTypeString;
    chemId = id;
}

Chemical :: Chemical () {

    location = "";
    chemType = "";
    chemId = 0;

}

int Chemical :: getID() {

    return chemId;
}
string Chemical :: getLocation() {

    return location;
}

string Chemical :: getChemType() {

    return chemType;
}
