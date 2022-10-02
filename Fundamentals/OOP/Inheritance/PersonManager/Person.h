/*
	@FileName: Person.h
	@Author: Hakan CERAN
	@Date: 02/10/22 18:25
	@Description: 
	@Notes: 
*/

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
	int id = 0;
	int age;
	string firstName;
	string lastName;
	string email;
public:
	Person();
    Person(int id, int age, string firstName, string lastName, string email);
	~Person();
		
	int getId();
	void setId(int id);
		
	int getAge();
	void setAge(int age);
		
	string getFirstName();
	void setFirstName(string firstName);
		
	string getLastName();
	void setLastName(string lastName);
		
	string getEmail();
	void setEmail(string email);
};

#endif

