/*
Kutay Tire
22001787
07.12.2021
HW02
*/

#include <unordered_set>
#include <iostream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>
using namespace std;


bool firstAlgorithm(int* arr1, int* arr2, int size1, int size2) {

    int counter;
    for (int a = 0; a < size2; a++) {


        for (int b = 0; b < size1; b++) {

            if (arr1[b] == arr2[a]) {

                counter++;
                break;

            }
        }
    }

    if (counter == size2) {

        return true;
    }


    return false;

}

void sortingAlgorithm(int* arr, int sizeOf)
{
    int pivot, up;
    for (int low = 1; low < sizeOf; low++)
    {
        pivot = arr[low];
        up = low - 1;

        while (up >= 0 && arr[up] > pivot)
        {
            arr[up + 1] = arr[up];
            up = up - 1;
        }
        arr[up + 1] = pivot;
    }
}

bool BinarySearchAlgorithm(int* arr, int bottom, int top, int value){

    if(top >= bottom){
        int middleIndex = (top + bottom) / 2;

        if(arr[middleIndex] == value){

            return true;
        }

        if(arr[middleIndex] > value){

            return BinarySearchAlgorithm(arr, bottom, middleIndex - 1, value);
        }

        return BinarySearchAlgorithm(arr, middleIndex + 1, top, value);
    }
    return false;
}

bool secondAlgorithm(int* arr1, int size1, int* arr2, int size2){

    for(int i = 0; i < size2; i++){

        if(!BinarySearchAlgorithm(arr1, 0, size1 - 1, arr2[i])){

            return false;
        }
    }
    return true;
}


bool thirdAlgorithm (int* arr1, int* arr2, int size1, int size2) {


    int maximum = arr1[0];
    for ( int i = 1; i < size1; i++) {

        if (arr1[i] > maximum) {

            maximum = arr1[i];
        }
    }

    int * frequency = new int [maximum];

    for ( int k = 0; k < maximum; k++) {

        frequency [k] = 0;
    }

    for (int a = 0; a < size1; a++) {

            int value = arr1[a] - 1;
    }


    for (int k = 0; k < size2; k++) {

        if ( arr2[k] > maximum) {

            return false;
        }

        if (frequency[arr2[k] - 1] > 0 ) {


            frequency[arr2[k] - 1]--;
        }


        else {

            return false;
        }
    }

    return true;




}



int main() {


    int size1 = 4 * pow(10,6);
    int size2 = 1000;


    int* arr1 = new int[size1];
    int* arr2 = new int [size2];

    srand(time(NULL));

    // Creates the arr2

    for ( int i = 0; i < size1; i++) {


        arr1[i] = i + rand() % 100;
    }

    sort( arr1, arr1 + size1);


    // Creates arr2, but if an element is already found in arr2, randomly creates a new integer to make the array unique.


    for ( int i = 0; i < size2; i++) {


        bool exit = false;
        do {


            int counter = 0;
            int number  = i + rand() % 100;

            for ( int a = 0; a < i; a++) {

                if ( arr2[a] != number) {

                    counter++;
                }
            }

            if ( counter == i) {

                arr2[i] = number;

                exit = true;
                }


        } while (!exit);



    }




//Declare necessary variables
std::chrono::time_point< std::chrono::system_clock > startTime;
std::chrono::duration< double, milli > elapsedTime;
//Store the starting time
startTime = std::chrono::system_clock::now();


firstAlgorithm(arr1, arr2, size1, size2);

/*
for (int i = 0; i < 100000; i++) {

        secondAlgorithm(arr1, size1,arr2, size2);
    }


*/

// Below are the second and third algorithm calls commented to not cause any confusion.

/*
    for (int i = 0; i < 10; i++) {
    thirdAlgorithm(arr1, arr2, size1, size2);
    }


*/



elapsedTime = (std::chrono::system_clock::now() - startTime) ;
cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

delete [] arr1;
delete [] arr2;

return 0;


}
