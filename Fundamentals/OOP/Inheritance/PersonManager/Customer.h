/*
	@FileName: Customer.h
	@Author: Hakan CERAN
	@Date: 02/10/22 18:25
	@Description: 
	@Notes: 
*/

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"

class Customer : public Person {
public:
	Customer();
	Customer(int id, int age, string firstName, string lastName, string email);
	~Customer();
};

#endif

