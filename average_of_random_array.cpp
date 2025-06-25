/*

Write a program to fill array with max size 100 with random
numbers from 1 to 100, then print average of all number

Input:
10

Output:

Array Elements: 24 36 44 73 8 56 98 67 33 71

Average of all number is : 51

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

void printArray(int array[100], int arrayLength){

	for(int i = 0; i < arrayLength; ++i){

		std::cout << array[i] << " ";

	}
	std::cout << std::endl;
}


int sumArray(int array[100], int arrayLength){

	int sum = 0;
	for(int i = 0; i < arrayLength; ++i){
		sum += array[i];
	}

	return sum;
}


float averageArray(int array[100], int arrayLength){

	
	return (float)sumArray(array, arrayLength) / arrayLength;
}

int main(){
	srand((unsigned)time(NULL));

	int array[100], arrayLength;

	arrayLength = readPositiveNumber("Enter number of array elements?");

	fillArrayWithRandomNumbers(array, arrayLength);

	std::cout << "\n***********************************************\n";
	std::cout << "Array elements: ";
	printArray(array, arrayLength);

	std::cout << "\nAverage of all numbers is: ";
	std::cout << averageArray(array, arrayLength);
	std::cout << std::endl;
	
	return 0;
}
