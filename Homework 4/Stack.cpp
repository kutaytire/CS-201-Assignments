

/*

Kutay Tire
22001787
Sec03
04.01.2022

*/

#include <iostream>
using namespace std;
#include "Stack.h"
#include <string>


Stack :: Stack() {

    topPtr = NULL;

}

Stack :: Stack( const Stack& aStack) {

    if (aStack.topPtr == NULL) {

        topPtr = NULL;
    }

    else {

        topPtr = new StackNode;
        topPtr -> item = aStack.topPtr -> item;
        StackNode* newPtr = topPtr;

        for ( StackNode* origPtr = aStack.topPtr->next; origPtr != NULL; origPtr = origPtr -> next) {

            newPtr -> next = new StackNode;
            newPtr = newPtr -> next;
            newPtr -> item = origPtr -> item;

        }

        newPtr -> next = NULL;


    }


}

Stack :: ~Stack() {

    while ( !isEmpty()) {


        pop();
    }

}

bool Stack :: isEmpty() const {

    return topPtr == NULL;

}

bool Stack :: push( string newItem) {

    StackNode * newPtr = new StackNode;
    newPtr -> item = newItem;
    newPtr -> next = topPtr;
    topPtr = newPtr;

    return true;


}

bool Stack :: pop () {

    if (isEmpty()) {

        return false;
    }

    else {

    StackNode* temp = topPtr;

    topPtr = topPtr -> next;
    temp -> next = NULL;

    delete temp;

    return true;


    }

}

bool Stack :: getTop ( string& topItem) {

    if( isEmpty()) {

        return false;
    }

    else {

        topItem = topPtr -> item;
        return true;
    }

}
