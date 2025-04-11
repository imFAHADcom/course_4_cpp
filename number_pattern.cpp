/*
Write a program fo read a number and print inverted pattern as follows?
Input:		Input: 
3		  5 
Output:		Output:
1 		  1
22		  22
333 		  333
		  4444
		  55555
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


void printNumberPattern(int number){
	std::cout << "********\n";

	for(int i = 1; i <= number; i++){
		for(int j = 1; j <= i; j++){
			std::cout << i;
		}
		
		std::cout << std::endl;
	}


}


int main(){
	printNumberPattern(readPositiveNumber("Enter a positive number, Please?"));


	return 0;
}
