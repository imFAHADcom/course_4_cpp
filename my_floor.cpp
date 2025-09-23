/*
floor function Write a program to print floor of numbers, don't use built in floor function.

Input:
10.7

Output:
My MyFloor Result: 10
C++ floor Result : 10




Input:
10.3

Output:
My MyFloor Result: 10
C++ floor Result : 10




Input:
-10.3
Output:

My MyFloor Result : -11
C++ floor Result : -11


*/

#include <iostream>
#include <string>
#include <cmath>



float readNumber(const std::string& message){

	float number = 0;

	std::cout << message << "\n";
	std::cin >> number;

	return number;
}

int myFloor(float userInput){

	int intPart = int(userInput);

	if(userInput < 0){
		--intPart;
	}

	return intPart;

}




int main(){
	float userInput = readNumber("Enter a number, Please?");

	std::cout << "\nMy floor result: ";
	std::cout << myFloor(userInput) << "\n";

	std::cout << "C++ floor result: ";
	std::cout << floor(userInput) << std::endl;


	return 0;
}
