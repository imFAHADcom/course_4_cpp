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

	std::string lastNumber = "";
	int remainder = 0, number2 = 0;

	while(number > 0){
		remainder = number % 10;
		number = floor(number / 10);
		number2 = number2 * 10 + remainder;
	}

	return number2;
}

void printResult(int number){

	std::cout << "*******\n" << "Reverse is: " << reverseNumber(number) << std::endl;
}


int main(){
	printResult(readPositiveNumber("Enter positive number, Please? "));


	return 0;
}
