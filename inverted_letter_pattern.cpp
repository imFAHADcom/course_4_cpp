/*

Werite a program to read a number and print inverted letter pattern as Follows?

Input:		Input:
3		  5

Output:		Output:
CCC 		  EEEEE
BB 		  DDDD
A 		  CCC
		  BB
		  A

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



void printInvertedLetterPattern(int number){
	
	std::cout << "******\n";

	for(int i = 65 + number - 1; i >= 65; i--){

		for(int j = 1; j <= number - (65 + number - 1 - i); j++){
			std::cout << char(i);
		}

		std::cout << std::endl;
	}

}



int main(){
	printInvertedLetterPattern(readPositiveNumber("Enter a positive number, Please?"));


	return 0;
}
