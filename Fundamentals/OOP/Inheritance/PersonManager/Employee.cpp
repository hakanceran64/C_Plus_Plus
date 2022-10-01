#include "Employee.h"

Employee::Employee(int id) : Person(id){
	cout << "Employee created!" << endl;
}

double Employee::getSalary(){
	return Employee::salary;
}

void Employee::setSalary(double salary){
	Employee::salary = salary;
}

