/*

Write a program to read a number and print the sum of its digits.

Input:
1234

Output:
Sum Of Digits = 10
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


int sumOfDigits(int number){
	
	int remainder = 0;
	int sum = 0;
	while(number > 0){
		remainder = number % 10;
		sum += remainder;
		number = floor(number / 10);
	}

	return sum;
}

void printSumOfDigits(int number){

	std::cout << "Sum of digits = " << sumOfDigits(number) << std::endl;;

}


int main(){

	printSumOfDigits(readPositiveNumber("Enter positive number, Please?"));

	return 0;
}
