
/*

Kutay Tire
22001787
Sec03
21.11.2021


*/

#include <iostream>
#include <string>
using namespace std;

#ifndef _CHEMICAL_H
#define _CHEMICAL_H
class Chemical {
public:

    Chemical();
    Chemical(string const locationString, string const chemTypeString, int const id);
    int getID();
    string getLocation();
    string getChemType();

private:

    int chemId;
    string location;
    string chemType;

};

#endif
