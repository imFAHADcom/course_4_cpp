/*

Write a program to read N elements and store them in array then print all array elements
and ask for a number to check, then print how many number a certain element repeated in
that array.

Input:
5

Enter array elements:
Element [1]: 1
Element [2] :1
Element [3]: 1
Element [4]: 2
Element [5]: 3

Enter the number you want fo check: 1

Output:

Original array: 1 1 1 2 3

1 is repeated 3 time(s)

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


void readArray(int array[100], int& arrayLength){


	std::cout << "Enter number of elements: \n";
	std::cin >> arrayLength;   

	std::cout << "Enter array elements:\n";
	for(int i = 0; i < arrayLength; ++i){
		std::cout << "Element [" << i + 1 << "]: ";
		std::cin >> array[i];
	}
}

void printArray(int array[100], int arrayLength){

	for(int i = 0; i < arrayLength; ++i){
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

int timesRepeated(int number, int array[100], int arrayLength){
	int arrayCounter = 0;
	for(int i = 0; i < arrayLength; ++i){
		if(number == array[i]){
			arrayCounter++;
		}
	}

	return arrayCounter;
}

int main(){
	int array[100], arrayLength, numberToCheck;

	readArray(array, arrayLength);

	numberToCheck = readPositiveNumber("Enter the number you want to check: ");

	std::cout << "\nOriginal array: ";
	printArray(array, arrayLength);

	std::cout << "Number " << numberToCheck;
	std::cout << " is repeated ";
	std::cout << timesRepeated(numberToCheck, array, arrayLength) << " time(s)\n";
	return 0;
}

