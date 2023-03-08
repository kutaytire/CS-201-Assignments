/*

Kutay Tire
22001787
Sec03
12.12.2021

*/

#include <string>
#include "FlowerList.h"
class FlowerLibrary{
public:
    FlowerLibrary();
    ~FlowerLibrary();
    void addFlower(string name);
    void removeFlower(string name);
    void listFlowers() const;
    void listFeatures(string name) const;
    void addFeature(string name,string feature);
    void removeFeature(string name, string feature);
    void findFlowers(string feature) const;
private:

    FlowerList flowers;
// ...
//you may define additional member functions and data members, if necessary
};
