#include <iostream>
#include <string>
#include <cmath>

int readPositiveNumber(std::string message){
	int number = 0;
	do{
		std::cout << message << std::endl;
		std::cin >> number;

	} while(number <= 0);

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

void printDigits(int number){

		
	std::cout << "*******\n";
	int remainder = 0;
	while(number > 0){
		remainder = number % 10; 
		number = floor(number / 10);
		
	std::cout << remainder << std::endl;
	}
}


int main(){
	printDigits(reverseNumber(readPositiveNumber("Enter positive number, Please? ")));


	return 0;
}

