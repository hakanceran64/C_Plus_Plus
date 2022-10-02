/*
	@FileName: Employee.cpp
	@Author: Hakan CERAN
	@Date: 02/10/22 18:25
	@Description: 
	@Notes: 
*/

#include "Employee.h"

Employee::Employee()
    : Person()
{
	cout << "Employee default constructor!" << endl;
}

Employee::Employee(int id, int age, string firstName, string lastName, string email)
    : Person(id, age, firstName, lastName, email)
{
	cout << "Employee " << id << " created!" << endl;
}

Employee::~Employee(){
	cout << "Employee " << id << " destructor!" << endl;
}

double Employee::getSalary(){
	return Employee::salary;
}

void Employee::setSalary(double salary){
	Employee::salary = salary;
}

void Employee::showInfo(){
	
	cout << endl;
	cout << "Employee ID: " << id << endl;
	cout << "Employee Age:" << age << endl;
	cout << "Employee First Name: " << firstName << endl;
	cout << "Employee Last Name: " << lastName << endl;
	cout << "Employee Email: " << email << endl;
	cout << endl;
}


