/*
Write a program to fill array with max size 100 with random
numbers from 1 to 100, then print Max

Input:
10

Output:
Array Elements: 65 91 54 42 75 32 53 57 57 30

Max Number is : 91

*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

int readPositiveNumber(std::string message){
	int number = 0;
	do{
		std::cout << message << std::endl;
		std::cin >> number;

	} while(number < 1 || number > 100);

	return number;
}


int randomNumber(int from, int to){
	int randNum = rand() % (to - from + 1) + from;

	return randNum;
}


void fillArrayWithRandomNumbers(int array[100], int arrayLength){

	for(int i = 0; i < arrayLength; ++i){
		array[i] = randomNumber(1, 100);
	}

}

int maxNumberInArray(int array[100], int arrayLength){

	int mxNum = array[0];
	for(int i = 0; i < arrayLength; ++i){

		if(array[i] > mxNum){
			mxNum = array[i];
		}	

	}

	return mxNum;
}

void printArray(int array[100], int arrayLength){

	for(int i = 0; i < arrayLength; ++i){
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}


int main(){
	srand((unsigned)time(NULL));
	int array[100], arrayLength;

	arrayLength = readPositiveNumber("Enter number of array elements: ");
	fillArrayWithRandomNumbers(array, arrayLength);

	std::cout << "Array Elements: ";
	printArray(array, arrayLength);

	std::cout << "Max Number is: ";
	std::cout << maxNumberInArray(array, arrayLength);
	std::cout << std::endl;
	return 0;
}
