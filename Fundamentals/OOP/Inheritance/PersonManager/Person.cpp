/*
	@FileName: Person.cpp
	@Author: Hakan CERAN
	@Date: 02/10/22 18:25
	@Description: 
	@Notes: 
*/

#include "Person.h"

Person::Person(){
	cout << "Person default constructor!" << endl;
}

Person::Person(int id, int age, string firstName, string lastName, string email){
	Person::id = id;
	Person::age = age;
	Person::firstName = firstName;
	Person::lastName = lastName;
	Person::email = email;

	cout << "Person " << id << " created!" << endl;
}

Person::~Person(){
	cout << "Person " << id << " destructor!" << endl;
}

int Person::getId(){ return Person::id; }
void Person::setId(int id){ Person::id = id; }

int Person::getAge(){ return Person::age; }
void Person::setAge(int age){ Person::age = age; }

string Person::getFirstName(){ return Person::firstName; }
void Person::setFirstName(string firstName){ Person::firstName = firstName; }

string Person::getLastName(){ return Person::lastName; }
void Person::setLastName(string lastName){ Person::lastName = lastName; }

string Person::getEmail(){ return Person::email; }
void Person::setEmail(string email){ Person::email = email; }

