/*

Write a program to fill array with max size 100 with random numbers from 1 to 100, copy it to another array using AddArrayElement, and print it.

Input:
10

Output:

Array 1 elements:
1 47 51 18 85 62 51 61 82 4

Array 2 elements after copy:
1 47 51 18 85 62 51 61 82 4


*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

unsigned short readPositiveNumber(const std::string message){

	unsigned short number = 0;
	do{

		std::cout << message << std::endl;
		std::cin >> number;

	} while(number < 1 || number > 100);

	return number;
}


unsigned short randomNumber(unsigned short from, unsigned short to){

	unsigned short randNum = rand() % (to - from + 1) + from;

	return randNum;

}

void fillArrayWithRandomNumbers(unsigned short array[100], unsigned short arrayLength){

	for(unsigned short i = 0; i < arrayLength; ++i){
		array[i] = randomNumber(1, 100);
	}

}

void printArray(unsigned short array[100], unsigned short arrayLength){

	for(unsigned short i = 0; i < arrayLength; ++i){
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

void addArrayElement(unsigned short newNumber, unsigned short array[100], unsigned short& arrayLength){


	++arrayLength;
	array[arrayLength - 1] = newNumber;
}


void copyArrayUsingaddArrayElement(unsigned short arraySource[100], unsigned short arrayDestination[100], unsigned short arraySourceLength, unsigned short arrayDestinationLength){

		for(unsigned short i = 0; i < arraySourceLength; ++i){
			addArrayElement(arraySource[i],arrayDestination, arrayDestinationLength);
		}

}

int main(){
	srand((unsigned)time(NULL));

	unsigned short array[100];
	unsigned short arrayLength = readPositiveNumber("Enter number of elements, Please? ");


	fillArrayWithRandomNumbers(array, arrayLength);

	std::cout << "\nArray 1 elements: ";
	printArray(array, arrayLength);

	unsigned short array2[100];
	unsigned short arrayLength2 = 0;

	copyArrayUsingaddArrayElement(array, array2, arrayLength, arrayLength2);

	std::cout << "\nArray 2 elements: ";
	printArray(array2, arrayLength);


	return 0;
}
