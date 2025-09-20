/*

Write a program to fill array with max size 100 with random numbers from -100 to 100, then print the count of Negative numbers.

Input:
10

Output:

Array Elements: -58 -16 -21 -4 -91 82 98 66 -8 -33

Negative Numbers count is: 7

*/


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

const unsigned short MAX_SIZE = 100;
const unsigned short MAX_VAL = 100;
const short int MIN_VAL = -100;



unsigned short readPositiveNumber(const std::string& message){

	unsigned short number = 0;
	do{
		std::cout << message << "\n";
		std::cin >> number;

	} while(number < 1 || number > MAX_SIZE);

	return number;
}

short int randomNumber(short int from, short int to){

	short int randNum = rand() % (to - from + 1) + from;

	return randNum;

}


void fillArrayWithRandomNumber(short int array[MAX_SIZE], unsigned short arrayLength){

	for(unsigned short i = 0; i < arrayLength; ++i){

		array[i] = randomNumber(MIN_VAL, MAX_VAL);
	}
	
}


unsigned short negativeCount(const short int array[MAX_SIZE], unsigned short arrayLength){

	unsigned short counter = 0;
	for(unsigned short i = 0; i < arrayLength; ++i){
		if(array[i] < 0){
			counter++;
		}

	}

	return counter;



}


void printArray(const short int array[MAX_SIZE], unsigned short arrayLength){

	for(unsigned short i = 0; i < arrayLength; ++i){

		std::cout << array[i] << " ";

	}
	std::cout << std::endl;

}


int main(){
	srand((unsigned)time(NULL));

	short int array[MAX_SIZE];
	unsigned short arrayLength = readPositiveNumber("Enter a number of elements?");

	fillArrayWithRandomNumber(array, arrayLength);

	std::cout << "\n\nArray elements: ";
	printArray(array, arrayLength);

	std::cout << "\nNegative numbers count is: ";
	std::cout << negativeCount(array, arrayLength) << std::endl;

	return 0;
}
