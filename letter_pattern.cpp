/*

Write a program to read a number and print letter pattern as
follows?

Input:		Input:
  3		  5
Output:		Output:
A 		A
BB		BB
CCC		CCC
		DDDD 
		EEEEE

*/
#include <iostream>
#include <string>


int readPositiveNumber(std::string message){
	int number = 0;
	do{
		std::cout << message << std::endl;
		std::cin >> number;
	} while(number < 0);

	return number;
}


void printLetterPattern(int number){
	std::cout << "***********\n";

	for(int i = 65; i <= (65 + number - 1); i++){
		for(int j = 1; j <= (i - 65 + 1) ; j++){
			std::cout << char(i);
		}
		std::cout << std::endl;
	}
}


int main(){

	printLetterPattern(readPositiveNumber("Enter a number, Please?"));

	return 0;
}
