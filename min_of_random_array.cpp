/*

Write a program to fill array with max size 100 with random
numbers from 1 to 100, then print Minimum Number

Input:
10

Output:
Array Elements: 30 99 72 47 95 67 29 13 80 64

Min Number is : 13

*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int readPositiveNumber(std::string message){

	int number = 0;
	do{
		std::cout << message << std::endl;
		std::cin >> number;

	} while(number < 1 || number > 100 );

	return number;
}


int randomNumber(int from, int to){

	int randNum = rand() % (to - from + 1) + from;

	return randNum;
}


void fillArraywithRandomNumbers(int array[100], int arrayLength){

	for(int i = 0; i < arrayLength; ++i){
		array[i] = randomNumber(1, 100);
	}
}

int minNumberInArray(int array[100], int arrayLength){
	int minNum = array[0];

	for(int i = 0; i < arrayLength; ++i){

		if(array[i] < minNum){
			minNum = array[i];
		}

	}

	return minNum;
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

	arrayLength = readPositiveNumber("Enter how many array elements?");
	
	fillArraywithRandomNumbers(array, arrayLength);

	std::cout << "\n********************************************************\n";
	std::cout << "Array elements: ";
	printArray(array, arrayLength);

	std::cout << "\nMin number is: ";
	std::cout << minNumberInArray(array, arrayLength);
	std::cout << std::endl;

	return 0;
}
