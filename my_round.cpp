/*

Write a program to print round of numbers, don't use built in round function

Input:
10.7

Output:
My Round Result : 11
C++ Round Result: 11




Input:
10.3

Output:
My Round Result : 10
C++ Round Result: 10




Input:
-10.7

Output:
My Round Result : -11
C++ Round Result: -11


*/

#include <iostream>
#include <string>
#include <cmath>


float readNumber(const std::string message){

	float number = 0;

	std::cout << message << "\n";
	std::cin >> number;

	return number;
}


float getFractionPart(float number){

	return number - int(number);

}


int myRound(float number){

	int intPart = int(number);

	float fractionPart = getFractionPart(number);

	if(std::abs(fractionPart) >= 0.5f){

		if(number > 0){
		 	 ++intPart;
		}
		else{
			 --intPart;
		}
	}

	return intPart;
}



int main(){

	float userInput = readNumber("Enter a number, please?");

	std::cout << "\nMy round result: ";
	std::cout << myRound(userInput) << "\n";

	std::cout << "C++ round result: ";
	std::cout << std::round(userInput) << std::endl;

	return 0;
}


