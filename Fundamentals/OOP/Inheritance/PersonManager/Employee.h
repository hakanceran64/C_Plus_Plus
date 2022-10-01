#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include "Person.h"

class Employee : public Person {
	private:
		double salary;

	public:
		Employee(int id);
		double getSalary();
		void setSalary(double salary);

	protected:
};

#endif

