/*
	@FileName: AnimalSound.cpp
	@Author: Hakan CERAN
	@Date: 07/10/2022 23:31
	@Description: Polymorphism example.
	@Notes:
*/

#include <iostream>
#include <string>

using namespace std;

// Base class
class Animal{
    public:
        void animalSound(){
            cout << "The animal makes a sound!" << endl;
        }
};

// Derived class
class Cat : public Animal {
    public:
        void animalSound(){
            cout << "The cat says: meow meow" << endl;
        }
};

// Derived class
class Dog : public Animal {
    public:
        void animalSound(){
            cout << "The dog says: bow wow" << endl;
        }
};

int main(){
    Animal myAnimal;
    Cat myCat;
    Dog myDog;

    myAnimal.animalSound();
    myCat.animalSound();
    myDog.animalSound();

    return 0;
}
