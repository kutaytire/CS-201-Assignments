
/*

Kutay Tire
22001787
Sec03
12.12.2021

*/

#include <string>
using namespace std;
#include "Flower.h"
class FlowerList{
public:
    FlowerList();
    FlowerList(const FlowerList& aList);
    ~FlowerList();
    bool isEmpty() const;
    int getLength() const;
    bool retrieve(string flowerName, Flower& flower) const;
    bool add(string flowerName);
    bool remove(string flowerName);
    bool checkForSameNames( string name) const;
    void showList() const;
    void showFeatureOfFlower( string name) const;
    bool addFeatureOfFlower( string flowerName, string feature);
    bool removeFeatureOfFlower ( string flowerName, string feature);
    void findFeatureInFlowers ( string feature) const;

private:
    struct FlowerNode{
        Flower f;
        FlowerNode* next;
    };
    int size;
    FlowerNode* head;

                    //the flowers are stored in a sorted singly linear linked list
// ...
//you may define additional member functions and data members, if necessary
};
