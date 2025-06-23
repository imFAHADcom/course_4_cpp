/*

Write a program to fill array with max size 100 with random
numbers from 1 to 100, then print sum of all number

Input:
10

Output:

Array Elements: 10 6 22 40 12 75 23 32 25 75

Sum of all number is : 320

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

int sumNumbersInArray(int array[100], int arrayLength){

	int sum = 0;
	
	for(int i = 0; i < arrayLength; ++i){
		sum += array[i];
	}
	

	return sum;
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

	arrayLength = readPositiveNumber("Enter the number of array elements? ");
	
	fillArrayWithRandomNumbers(array, arrayLength);

	std::cout << "\n**********************************************\n";
	std::cout << "Array elements: ";
	printArray(array, arrayLength);

	std::cout << "\nSum of all numbers is: ";
	std::cout << sumNumbersInArray(array, arrayLength) << std::endl;

	return 0;
}
