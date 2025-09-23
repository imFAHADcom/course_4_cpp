/*

Write a program to print Sart of numbers, don't use built in sqrt function

Input:
25

Output:
My MySqrt Result : 5
C++ sqrt Result: 5


*/


#include <iostream>
#include <cmath>


float readNumber(){

	float number = 0;

	std::cout << "Enter a number, Please?\n";
	std::cin >> number;

	return number;
}


float mySqrt(float userInput){

	return pow(userInput, 0.5);
}



int main(){
	float userInput = readNumber();


	std::cout << "\nMy mySqrt result: " << mySqrt(userInput) << "\n";

	std::cout << "C++ sqrt result: " << sqrt(userInput) << std::endl;

	return 0;
}
