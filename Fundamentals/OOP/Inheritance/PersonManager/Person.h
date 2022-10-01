#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>

using namespace std;

class Person {
	private:
			int id;
			int age;
			string firstName;
			string lastName;
			string email;

	public:
		Person(int id);
		
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

	protected:

};

#endif

