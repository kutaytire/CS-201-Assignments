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
#include "FlowerList.h"


FlowerList :: FlowerList () {

    size = 0;
    head = NULL;

}

FlowerList :: FlowerList(const FlowerList& aList) {

    size = aList.size;
    if( aList.head == NULL) {

        head = NULL;
    }

    else {


        head = new FlowerNode;
        head -> f = aList.head -> f;
        FlowerNode * newPtr = head;

        for (FlowerNode* originalPtr = aList.head -> next; originalPtr != NULL; originalPtr = originalPtr -> next) {


            newPtr -> next = new FlowerNode;
            newPtr = newPtr -> next;
            newPtr -> f = originalPtr -> f;
        }

        newPtr -> next = NULL;
    }


}



FlowerList :: ~FlowerList() {

    while (!isEmpty()) {


      FlowerNode* temp = head;
      head = head->next;
      temp->next = NULL;


      delete temp;

      size --;

    }

}


bool FlowerList :: isEmpty() const {

    return size == 0;

}

int FlowerList :: getLength() const {

    return size;
}

bool FlowerList :: retrieve(string flowerName, Flower& flower) const {



    for ( FlowerNode * cur = head; cur != NULL; cur = cur -> next ) {


        if ( (cur -> f).getFlowerName() == flowerName) {

            flower = cur -> f;
            return true;

        }

    }

    return false;

}

bool FlowerList :: add(string flowerName) {

    FlowerNode * cur;
    FlowerNode * prev;

    FlowerNode * newPtr = new FlowerNode;

    (newPtr->f) = Flower(flowerName);

    size++;



    if ( head == NULL || (head ->f).getFlowerName() > flowerName) {

        newPtr->next = head;
        head = newPtr;


    }

    else {

        for(prev = NULL, cur = head; (cur != NULL)&& (flowerName > (cur->f).getFlowerName()); prev = cur, cur = cur->next);

        newPtr -> next = cur;
        prev -> next = newPtr;

    }


    return true;



}


bool FlowerList :: remove(string flowerName) {

    FlowerNode * cur;
    FlowerNode * tmp;
    FlowerNode * prev;

    --size;

    if ( (head -> f).getFlowerName() == flowerName) {

        cur = head;
        head = head -> next;
    }

    else {

        for( prev = NULL, tmp = head; (tmp != NULL); prev = tmp, tmp = tmp-> next ) {


            if (flowerName == (tmp->f).getFlowerName()) {

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



bool FlowerList :: checkForSameNames( string name) const {

    FlowerNode * cur;

    if (head == NULL) {

        return false;
    }

    for ( cur = head; cur != NULL; cur = cur -> next) {


        if ( ((cur -> f)).getFlowerName() == name) {


            return true;
        }

    }

    return false;


}

void FlowerList :: showList () const {


    FlowerNode* cur;

    if (head == NULL) {


        cout << "Library is empty"<< endl;
    }

    else {
        for ( cur = head ; cur != NULL; cur = cur -> next) {


            cout  << (cur->f).getFlowerName() << ": ";
            cout << (cur->f).printFlower();
            cout << endl;
        }

    }

}


void FlowerList :: showFeatureOfFlower ( string name) const{


    FlowerNode* cur;

    if (head == NULL) {


        cout << "No feature "<< endl;
    }

    else {

        for ( cur = head ; cur != NULL; cur = cur -> next){

            if ( name == (cur->f).getFlowerName()) {

                cout << (cur->f).printFlower();

                break;


            }


        }

    }

}

bool FlowerList :: addFeatureOfFlower( string flowerName, string feature) {

    FlowerNode* cur;


     for(cur = head; (cur != NULL); cur = cur-> next ) {


            if (flowerName == (cur->f).getFlowerName()) {

                if ( (cur->f).checkForSameFeatures(feature)) {

                    cout << feature << " already exists in " << flowerName << endl;
                    return false;
                }

                else {

                    (cur->f).add(feature);
                    return true;
                }
            }

     }


}

bool FlowerList :: removeFeatureOfFlower ( string flowerName, string feature){

    FlowerNode* cur;


     for(cur = head; (cur != NULL); cur = cur-> next ) {


            if (flowerName == (cur->f).getFlowerName()) {

                if ( (cur->f).checkForSameFeatures(feature)) {

                    (cur->f).remove(feature);
                    return true;
                }

                else {

                    cout << feature << " does not exist in " << flowerName << endl;
                    return false;
                }
            }

     }




}

void FlowerList :: findFeatureInFlowers ( string feature) const {


     FlowerNode* cur;
     string result = "";


     for(cur = head; (cur != NULL); cur = cur-> next ) {



            if ( (cur->f).checkForSameFeatures(feature)) {


                result = result.append( (cur->f).getFlowerName());
                result = result.append(",");


            }


        }

        if ( result == "") {

                cout << feature << " flowers: there is no such flower" << endl;

        }

            else {

                result.erase(result.length() - 1);
                cout << feature << " flowers: " <<  result << endl;
            }


}





