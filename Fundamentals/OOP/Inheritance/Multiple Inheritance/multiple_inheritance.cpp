///	@filename: multiple_inheritance.cpp
///	@author: Hakan CERAN
///	@date: 12/10/22 21:41
///	@description: 
///	@notes:

#include <iostream>

class A{
    public:
        int a;

        void getA(){
            std::cout << "Enter an Integer value: " << std::endl;
            std::cin >> a;
        }
};

class B{
    public:
        int b;

        void getB(){
            std::cout << "Enter an Integer value: " << std::endl;
            std::cin >> b;
        }
};

class C : public A, public B{
    public:
        int c;

        void add(){
            c = a + b;

            std::cout << a << " + " << b << " = " << c << std::endl;
        }
};

int main(int argc, char **argv){

    C obj;

    obj.getA();
    obj.getB();
    obj.add();

    return EXIT_SUCCESS;
}

