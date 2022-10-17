/*
	@FileName: functions.cpp
	@Author: Hakan CERAN
	@Date: 06/10/2022 09:13
	@Description: 
	@Notes: 
*/

#include <iostream>
#include <cstdlib> // for EXIT_SUCCESS and EXIT_FAILURE

using namespace std;

// Test Class
class Person{
	public:
		string name;
		string surname;
		int age;
};

// Definition of user-defined function doPrint()
void doPrint(){
	cout << "Function: doPrint" << endl;
}

// Nesned functions are not supported
// void foo(){
// 	void temp(){
// 		cout << endl;
// 	}
// }

// Function return types -> int, double, float, string, Class Object, Array
void returnVoid(){

}

int returnInt(){
	return 0;
	}

double returnDouble(){
	return 3.1415;
	}
float returnFloat(){
	return 3.1415;
	}

string returnString(){
	return "";
	}

Person returnObject(){
	Person personObject;
	
	return personObject;
	}

int* returnArray(){
	static int numbers[10];

	for (int i = 0; i < 10; i++){
		numbers[i] = i;
	}

	return numbers;
}

int main(){

	doPrint();

	int *test;
	test = returnArray();

	cout << test[5] << endl;

	// Best Practice: Your main function should return the value 0 if the program ran normally. (EXIT_SUCCESS = 0)
    return EXIT_SUCCESS;
}