/*

Kutay Tire
22001787
Sec03
12.12.2021

*/

#include <iostream>
using namespace std;
#include "Flower.h"
#include <string>
#include<bits/stdc++.h>

Flower :: Flower() {

    size = 0;
    flowerName = "";
    head = NULL;

}

Flower :: Flower(string flowerName) {

    size = 0;
    this -> flowerName = flowerName;
    head = NULL;
}

Flower :: Flower(const Flower& aFlower) {

    size = aFlower.size;
    if( aFlower.head == NULL) {

        head = NULL;
    }

    else {


        head = new FeatureNode;
        head -> feature = aFlower.head -> feature;
        FeatureNode * newPtr = head;

        for (FeatureNode* originalPtr = aFlower.head -> next; originalPtr != NULL; originalPtr = originalPtr -> next) {


            newPtr -> next = new FeatureNode;
            newPtr = newPtr -> next;
            newPtr -> feature = originalPtr -> feature;
        }

        newPtr -> next = NULL;
    }

}

Flower :: ~Flower () {


    while (!isEmpty()) {

      FeatureNode* temp = head;
      head = head->next;
      temp->next = NULL;


      delete temp;

      size --;

    }


}


bool Flower :: isEmpty() const {


    return size == 0;

}

int Flower :: getLength() const {

    return size;
}


bool Flower :: add(string feature) {

    transform(feature.begin(), feature.end(), feature.begin(), ::tolower);
    FeatureNode * cur;
    FeatureNode * prev;

    int newSize = getLength() + 1;

    FeatureNode * newPtr = new FeatureNode;
    newPtr -> feature = feature;
    size = newSize;


    if ( head == NULL || head -> feature > feature) {


        newPtr -> next = head;
        head = newPtr;
    }

    else {

        for(prev = NULL, cur = head; (cur != NULL)&& (feature > cur->feature); prev = cur, cur = cur->next);


        newPtr -> next = cur;
        prev -> next = newPtr;

    }

    return true;

}

bool Flower :: remove(string feature) {

    FeatureNode * cur;
    FeatureNode * tmp;
    FeatureNode * prev;

    --size;

    if ( head -> feature == feature) {

        cur = head;
        head = head -> next;
    }

    else {

        for( prev = NULL, tmp = head; (tmp != NULL); prev = tmp, tmp = tmp-> next ) {

            if (feature == (tmp->feature)) {

                    break;

            }
        }

        cur = prev -> next;
        prev -> next = cur -> next;


    }

       cur->next = NULL;
       delete cur;
       cur = NULL;

       return true;


}


string Flower :: printFlower() const {


    FeatureNode * cur;
    string result = "";


    if ( head == NULL ) {


        cout << "No feature";
        return "";
    }

    else {

        for ( cur = head; cur != NULL; cur = cur->next) {

            result = result.append(cur -> feature);
            result.append( ",");

        }

        result.erase(result.length() - 1);
        return result;
    }


}

string Flower :: getFlowerName() const {

    return flowerName;
}

bool Flower :: checkForSameFeatures( string feature) {


     FeatureNode * cur;

    if (head == NULL) {

        return false;
    }

    for ( cur = head; cur != NULL; cur = cur -> next) {


        if ( cur -> feature == feature) {


            return true;
        }

    }

    return false;



}


