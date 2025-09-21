/*

Write a program to prfloat abs of numbers, don't use built in abs function

Input:
-10

Output:
My abs Result : 10
C++ abs Result: 10

*/

#include <iostream>
#include <string>
#include <cmath>


float readPositiveNumber(const std::string& message){

	float number = 0;

	std::cout << message << std::endl;
	std::cin >> number;

	return number;
}


float myabs(float number){

	if(number < 0){
		number = number * -1;
	}

	return number;

}


int main(){

	float userInput = readPositiveNumber("Enter a number, Please?");

	std::cout << "\nMy abs result: ";
	std::cout << myabs(userInput);

	std::cout << "\nC++ abs result: ";
	std::cout << abs(userInput) << std::endl;

	return 0;
}

