/*

Kutay Tire
22001787
Sec03
12.12.2021

*/

#include<bits/stdc++.h>
#include <string>
#include "FlowerLibrary.h"
#include <iostream>
using namespace std;


FlowerLibrary :: FlowerLibrary() {



}

FlowerLibrary :: ~FlowerLibrary() {



}


void FlowerLibrary :: addFlower(string name) {

    transform(name.begin(), name.end(), name.begin(), ::tolower);
    if ( flowers.checkForSameNames(name)) {
        cout << name << " cannot be added into the library because it already exists." << endl;
    } else {
        flowers.add(name);
        cout << name << " has been added into the library." << endl;
    }
}

void FlowerLibrary :: removeFlower (string name) {

    transform(name.begin(), name.end(), name.begin(), ::tolower);
    if ( !flowers. checkForSameNames(name)) {
        cout << name << " cannot be removed because it's not in the library." << endl;
    } else {
        flowers.remove(name);
        cout << name <<  " has been removed from the library" << endl;
    }
}


void FlowerLibrary :: listFlowers () const {

    flowers.showList();
}


void FlowerLibrary :: listFeatures( string name) const {

     transform(name.begin(), name.end(), name.begin(), ::tolower);
     if ( !flowers. checkForSameNames(name)) {

        cout << name << " isn't found in library" << endl;
     } else {

        cout << name << ": ";
        flowers.showFeatureOfFlower( name);

    }

}



void FlowerLibrary :: addFeature(string name,string feature) {

    transform(name.begin(), name.end(), name.begin(), ::tolower);
    transform(feature.begin(), feature.end(), feature.begin(), ::tolower);

    if ( !(flowers. checkForSameNames(name))) {
        cout << name << " isn't found in the library." << endl;
    } else {

        if ( flowers.addFeatureOfFlower(name, feature)) {

            cout << feature << " is added into " << name << endl;
        }
    }

}

void FlowerLibrary :: removeFeature(string name, string feature) {

    transform(name.begin(), name.end(), name.begin(), ::tolower);

     if ( !(flowers. checkForSameNames(name))) {
        cout << name << " is not found in the library." << endl;
    } else {

        if ( flowers.removeFeatureOfFlower(name, feature)) {

            cout << feature << " is removed from " << name << endl;
        }
    }



}


void FlowerLibrary :: findFlowers(string feature) const {


    flowers.findFeatureInFlowers(feature);


}






















