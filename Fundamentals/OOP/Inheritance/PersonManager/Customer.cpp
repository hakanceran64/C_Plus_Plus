/*
	@FileName: Customer.cpp
	@Author: Hakan CERAN
	@Date: 02/10/22 18:25
	@Description: 
	@Notes: 
*/

#include "Customer.h"

Customer::Customer()
    : Person()
{
	cout << "Customer default constructor!" << endl;
}

Customer::Customer(int id, int age, string firstName, string lastName, string email)
    : Person(id, age, firstName, lastName, email)
{
	cout << "Customer " << id << " created!" << endl;
}

Customer::~Customer(){
	cout << "Customer " << id << " destructor!" << endl;
}
