/*

Write a program to fill array with max size 100 with random
numbers from 1 to 100, copy it to another array and print it.

Input
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

void copyArray(int arraySource[100], int arrayDestination[100], int arrayLength){

	for(int i = 0; i < arrayLength; ++i){
		arrayDestination[i] = arraySource[i];
	}

}

void printArray(int array[100], int arrayLength){

	for(int i = 0; i < arrayLength; ++i){
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}


int main(){
	srand((unsigned)time(NULL));
	
	int array[100], array2[100], arrayLength;



	arrayLength = readPositiveNumber("Enter number of array elements?");

	fillArrayWithRandomNumbers(array, arrayLength);

	std::cout <<"\n*******************************************\n";
	
	std::cout << "Array 1 elements:\n";
	printArray(array, arrayLength);

	copyArray(array, array2, arrayLength);

	std::cout << "\nArray 2 elements after copy:\n";
	printArray(array2, arrayLength);

	return 0;
}
