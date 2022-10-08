///	@filename: structure.cpp
///	@author: Hakan CERAN
///	@date: 08/10/22 21:41
///	@description: 
///	@notes:

#include <iostream>
#include <stdio.h>

using namespace std;

/// @brief Create Structure
struct {
    string brand;
    string model;
    int year;
} myCar1, myCar2;

/// @brief Create Named Structure
struct Employee
{
    int id;
    int age;
    double wage;
    string name;
    string surname;
};

int main(){

    Employee hakan = {1, 26, 1000, "Hakan", "CERAN"};

    cout << "Hakan age: " << hakan.age << endl;

    Employee ceran;
    ceran = {ceran.id = 1, ceran.age=12};

    cout << "Ceran ID: " << ceran.id << endl;

    return EXIT_SUCCESS;
}

