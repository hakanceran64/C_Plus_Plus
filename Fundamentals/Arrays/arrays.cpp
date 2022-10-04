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

    // An Array
    int myNumbers[4];
    string cars[4] = {"Volvo", "BMW", "Ford", "Audi"};

    // Access the Element of an Array
    cout << cars[3] << endl;

    // Change an Array Element
    cars[1] = "Renault";
    cout << cars[1] << endl;

    return 0;
}