/*
	@FileName: Main.cpp
	@Author: Hakan CERAN
	@Date: 02/10/22 18:25
	@Description: 
	@Notes: 
*/

#include "Employee.h"
#include "Customer.h"

int main(){
	cout << "Main.cpp working" << endl;
	cout << endl;
	
	Employee hakan(1, 26, "Hakan", "CERAN", "hakanceran64@gmail.com");
	hakan.showInfo();
	
	Customer ceran(2, 26, "Merve", "CERAN", "hakanceran64@gmail.com");
	
	return 0;
}

