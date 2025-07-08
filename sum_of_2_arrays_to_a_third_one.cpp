/*
Write a program to fill array two arrays with max size 100 with random numbers from 1 to 100, sum their elements in a third array and print the results.


Input:
10

Output:
Array 1 elements:
42 68 35 1 70 25 79 59 63 65

Array 2 elements:
6 46 82 28 62 92 96 43 28 37

Sum of arrayl and array2 elements:
48 114 117 29 132 117 175 102 91 102

*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
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

void fillArray(int array1[100], int arrayLength){

	for(int i = 0; i < arrayLength; ++i){
		array1[i] = randomNumber(1, 100);
	}

}


void printArray(int array1[100], int arrayLength){
	for(int i = 0; i < arrayLength; ++i){
		std::cout << array1[i] << " ";
	}
	std::cout << std::endl;
}


void sumOf2Arrays(int array1[100], int array2[100], int arraysSum[100], int arrayLength){

	for(int i = 0; i < arrayLength; ++i){
		arraysSum[i] = array1[i] + array2[i];
	} 

}


int main(){
	srand((unsigned)time(NULL));
	int array1[100], array2[100], arraysSum[100];

	int arrayLength = readPositiveNumber("Enter number of array elements");

	fillArray(array1, arrayLength);

	std::cout << "\n**************************************\n";
	std::cout << "Array 1 elements:\n";
	printArray(array1, arrayLength);

	fillArray(array2, arrayLength);

	std::cout << "\nArray 2 elements:\n";
	printArray(array2, arrayLength);


	sumOf2Arrays(array1, array2, arraysSum, arrayLength);
	std::cout << "\nSum of array 1 and array2 elements:\n";
	printArray(arraysSum, arrayLength);

	return 0;
}
