/*

Kutay Tire
22001787
Sec03
12.12.2021

*/

using namespace std;
#include <string>
#ifndef __STACK_H
#define __STACK_H
class Stack{
public:
    Stack();
    Stack(const Stack& aStack);
    ~Stack();
    bool isEmpty() const;
    bool push( string newItem);
    bool pop();
    bool getTop( string& topItem);



private:
    struct StackNode{
        string item;
        StackNode* next;
    };

    StackNode *topPtr;


     //the features are stored in a sorted singly linear linked list

};

#endif

