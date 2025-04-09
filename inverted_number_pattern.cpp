/*

Write a program to read a number and print inverted pattern as follows?

Input:		Input:
3     		  5

Output:		Output:
333      	  55555
22 		  4444
1 		  333
		  22
		  1


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


void invertedPattern(int number){

	for(int i = number; i >= 1; i--){

		for(int j = 1; j <= i; j++){
			std::cout << i;
		}
		std::cout << std::endl;
	}
}


int main(){

	invertedPattern(readPositiveNumber("Enter a positive number, Please?"));

	return 0;
}
