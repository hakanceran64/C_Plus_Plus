/*
	@FileName: arrays.h
	@Author: Hakan CERAN
	@Date: 04/10/22 23:03
	@Description: 
	@Notes: 
*/

#include <iostream>
#include <string>

using namespace std;

int main(){

    // ## Array Declaration and Allocation
    int myNumbers[4]; // integer array with 4 elements
    string cars[4] = {"Volvo", "BMW", "Ford", "Audi"};
    int myArray[] = {1, 2, 3};

    // ### Access the Element of an Array
    cout << "Access the Element of an Array cars[3]: " << cars[3] << endl;

    // ### Change an Array Element
    cars[1] = "Renault";
    cout << "Change an Array Element cars[1]: " << cars[1] << endl;

    // ## Multi-dimensional Arrays
    int myMultiArray[2][2] = {
        {0, 1},
        {2, 3}
    };

    // ## Dynamics Arrays
    int* p = new int[3]; // dynamically allocated array
    *(p+0) = 10;
    cout << "Dynamics Arrays p[0]: " << p[0] << endl;

    // Determining Array Size
    int length = sizeof(myArray) / sizeof(int); // 3
    cout << "myArray Size: " << length << endl;

    // When you are done using dynamic array you must remember to delete it.
    int size = 3;
    int* pArray = new int[size];
    delete[] pArray; // Release Allocated Array

    return 0;
}