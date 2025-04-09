/*
Write a program to read a number and check if it is Palindrome?
Palindrome is a number that reads the same from right to left.

Input:
1234
12321

Output:
No , it is NOT a Palindrome number.
Yes , it is a Palindrome number.

*/

#include <iostream>
#include <string>
#include <cmath>

int readPositiveNumber(std::string message){
	int number = 0;
	do{
		std::cout << message << std::endl;
		std::cin >> number;

	} while(number < 0);

	return number;
}

int reverseNumber(int number){

	int remainder = 0, number2 = 0;
	while(number > 0){
		remainder = number % 10;
		number = floor(number / 10);
		number2 = number2 * 10 + remainder;
	}

	return number2;
}


bool isPalindromeNumber(int number){
	return number == reverseNumber(number);
}


void printResult(int number){

	if(isPalindromeNumber(number)){

		std::cout << "*********\n" << "Yes , it is a Palindrome number." << std::endl;
	}
	else{

		std::cout << "*********\n" << "No , it is NOT a Palindrome number." << std::endl;
	}
}

int main(){

	printResult(readPositiveNumber("Enter a positive number, Please?"));

	return 0;
}
