/*









Write a program to print Ceil of numbers, don't use built in Ceil function

Input:
10.7

Output:
My MyCeil Result: 11
C++ Ceil Result : 11

Input:
-10.7

Output:
My MyCeil Result : -10
C++ Ceil Result: -10


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


float getFractionPart(float userInput){

	return userInput - int(userInput);

}

int myCeil(float userInput){

	int intPart = int(userInput);
	float franctionPart = getFractionPart(userInput);

	if(std::abs(franctionPart) > 0){
		if(userInput > 0){
			return ++intPart;
		}
	}

	return intPart;

}


int main(){
	float userInput = readNumber("Enter a number, Please?");


	std::cout << "\nMy myCeil result: " << myCeil(userInput) << "\n";

	std::cout << "C++ Ceil result: " << ceil(userInput) << std::endl; 

	return 0;
}
