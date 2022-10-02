/*
	@FileName: Employee.h
	@Author: Hakan CERAN
	@Date: 02/10/22 18:25
	@Description: 
	@Notes: 
*/

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

class Employee : public Person {
protected:
double salary;

public:
    Employee();
	Employee(int id, int age, string firstName, string lastName, string email);
	~Employee();
	double getSalary();
	void setSalary(double salary);
	void showInfo();
};

#endif

