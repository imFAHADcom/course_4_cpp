/*
Werite a program read a digit and a number , then print digit frequency in that number.

Input:
1223222
2

Output:
Digit 2 Frequency is 5 Time(s).
*/

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


int countDigitFrequency(unsigned int number, unsigned short digitToCheck){


	int remainder = 0, freqCount = 0;

	while(number > 0){
		remainder = number % 10;
		number = floor(number / 10);
		
		if(remainder == digitToCheck){
			freqCount++;
		}

	}
	return freqCount;
}


void printResult(unsigned int number, unsigned short digit){

	std::cout << "Digit " << digit <<" Frequency is " << countDigitFrequency(number, digit) << " Time(s)." << std::endl;

}
int main(){

	int userNumber = readPositiveNumber("Enter the main number, Please?");
	unsigned short userDigit = readPositiveNumber("Enter one digit to check, Please?");

	printResult(userNumber, userDigit);

	return 0;
}
