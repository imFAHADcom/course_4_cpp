/*

Write a program to fill array with ordered numbers from 1 to N,
then print it, after that shuffle this array and print it after shuffle.

Input:
10

Output:

Array elements before shuffle:
1 2 3 4 5 6 7 8 9 10

Array elements after shuffle:
2 4 6 3 10 1 7 8 5 9


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


void swap(int& a, int& b){

	int temp = a;
	a = b;
	b = temp;

}

void fillArrayWith1ToN(int array[100], int arrayLength){

	for(int i = 0; i < arrayLength; ++i){
		array[i] = i + 1;
	}

}


void shuffleArray(int array[100], int arrayLength){

	for(int i = 0; i < arrayLength; ++i){

		int randIndex = randomNumber(i, arrayLength - 1);

		swap(array[i], array[randIndex]);
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
	
	int array[100];
	int arrayLength = readPositiveNumber("Enter number of array elements?");

	fillArrayWith1ToN(array, arrayLength);

	std::cout << "\n*********************************************\n";
	std::cout << "Array elements before shuffle:\n";
	printArray(array, arrayLength);

	shuffleArray(array, arrayLength);

	std::cout << "\nArray elements after shuffle:\n";
	printArray(array, arrayLength);
	

	return 0;
}
