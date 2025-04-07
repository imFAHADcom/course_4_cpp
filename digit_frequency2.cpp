/*

Write a program read a number , then print all digit frequency in that number

Input:
1223222

Output:
Digit 1 Frequency is 1 Time(s).
Digit 2 Frequency is 5 Time(s).
Digit 3 Frequency is 1 Time(s). 
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


int countDigitFrequency(unsigned short int digitToCheck, int number){

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


void printAllDigitFrequency(int number){

	std::cout << "********" << std::endl;

	for(int i = 0; i < 10; i++){
		short int digitFrequency = 0;
		digitFrequency = countDigitFrequency(i, number);

		if(digitFrequency > 0){
			std::cout << "Digit " << i << " Frequency is " << digitFrequency << " Time(s). \n";
		}

	}

}



int main(){
	printAllDigitFrequency(readPositiveNumber("Enter a positive number, Please?"));


	return 0;
}
