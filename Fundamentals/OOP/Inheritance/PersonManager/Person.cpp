#include "Person.h"

Person::Person(int id){
	Person::id = id;

	cout << "Person " << id << " created!" << endl;
}

int Person::getId(){
	return Person::id;
}

void Person::setId(int id){
	Person::id = id;
}

int Person::getAge(){
	return Person::age;
}

void Person::setAge(int age){
	Person::age = age;
}

string Person::getFirstName(){
	return Person::firstName;
}

void Person::setFirstName(string firstName){
	Person::firstName = firstName;
}

string Person::getLastName(){
	return Person::lastName;
}

void Person::setLastName(string lastName){
	Person::lastName = lastName;
}

string Person::getEmail(){
	return Person::email;
}

void Person::setEmail(string email){
	Person::email = email;
}

