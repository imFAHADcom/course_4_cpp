/*

Write a program to fill array with max size 100 with random numbers from
1 to 100, copy it to another array in reverse order and print it.

Input
10

Output:

Array 1 elements:
64 8 62 19 2 21 15 74 96 85

Array 2 elements after copying array 1 in reversed order:
85 96 74 15 21 2 19 62 8 64

*/


#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

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

void fillArrayWithRandomNumber(int array[100], int& arraylength){

	for(int i = 0; i < arraylength; ++i){
		array[i] = randomNumber(1, 100);
	}

}

void copyArrayInReverseOrder(int arraySource[100],int arrayDestination[100], int arraylength){

	for(int i = 0; i < arraylength; ++i){
		arrayDestination[i] = arraySource[arraylength - 1 -i];
	}

}


void printArray(int array[100], int arraylength){
	for(int i = 0; i < arraylength; ++i){
		std::cout << array[i] << " ";
	}

	std::cout << std::endl;
}

int main(){
	srand((unsigned)time(NULL));

	int array[100];
	int array2[100];
	int arraylength = readPositiveNumber("Enter how many number of array elements?");


	fillArrayWithRandomNumber(array, arraylength);

	std::cout << "\n********************************\n";
	std::cout << "\nArray 1 elements:\n";
	printArray(array, arraylength);

	copyArrayInReverseOrder(array, array2, arraylength);
	std::cout << "\nArray 2 elements after copying array 1 in reversed order:\n";
	printArray(array2, arraylength);




	return 0;
}
