/*

Write a program to fill array with max size 100 with random numbers from 1 to 100, copy only odd numbers to another array using AddArrayElement, and print it.

Input:
10

Output:

Array 1 elements:
59 14 84 36 6 51 48 91 96 67

Array 2 Odd numbers:
59 51 91 67

*/

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>


unsigned short readPositiveNumber(const std::string message){

	unsigned short number = 0;
	do{

		std::cout << message;
		std::cin >> number;

	} while(number < 1 || number > 100);

	return number;
}

unsigned short randomNumber(unsigned short from, unsigned short to){

	unsigned short randNum = rand() % (to - from + 1) + from;

	return randNum;
}

void fillArrayWithRandomNumber(unsigned short array[100], unsigned short arrayLength){

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

void addElement(unsigned short newNumber, unsigned short array[100], unsigned short& array2Length){

	++array2Length;
	array[array2Length - 1] = newNumber;
}

void copyOnlyOddNumbersInArray(unsigned short arraySource[100], unsigned short arrayDestination[100], unsigned short arraySourceLenght, unsigned short& arrayDestinationLength){

	for(unsigned short i = 0; i < arraySourceLenght; ++i){
		if(arraySource[i] % 2 != 0){
			addElement(arraySource[i], arrayDestination, arrayDestinationLength);
		}
	}
}

int main(){

	srand((unsigned)time(NULL));
	unsigned short array[100];
	unsigned short arrayLength = readPositiveNumber("Enter number of elements? ");

	fillArrayWithRandomNumber(array, arrayLength);

	std::cout << "\nArray 1 elements: ";
	printArray(array, arrayLength);

	unsigned short array2[100];
	unsigned short array2Length = 0;

	copyOnlyOddNumbersInArray(array, array2, arrayLength, array2Length);

	std::cout << "\nArray 2 odd numbers: ";
	printArray(array2, array2Length);
	
	
	return 0;
}
