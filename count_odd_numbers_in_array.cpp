/*

Write a program to fill array with max size 100 with random numbers from 1 to 100, then print the count of Odd numbers.

Input:
10

Output:
Array Elements: 60 78 15 49 56 6 4 3 21 23

Odd Numbers count is: 5
*/


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


unsigned short readPositiveNumber(std::string message){

	unsigned short number = 0;
	do{
		std::cout << message << std::endl;
		std::cin >> number;

	} while(number < 1 || number > 100);

	return number;
}

unsigned short randomNumber(unsigned short from, unsigned short to){

	unsigned short randNum = rand() % (to - from + 1) + from;

	return randNum;
}

void fillArray(unsigned short array[100], unsigned short arrayLength){

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


unsigned short oddCount(unsigned short array[100], unsigned short length){

	unsigned short counter = 0;

	for(unsigned short i = 0; i < length; ++i){
		if(array[i] % 2 != 0){
			counter++;
		}
	}

	return counter;
}

int main(){
	srand((unsigned)time(NULL));

	unsigned short array[100], length;

	length = readPositiveNumber("Enter number of array elements, Please?");

	fillArray(array, length);

	std::cout << "\nArray elements:\n";
	printArray(array, length);


	std::cout << "\nOdd numbers count is: ";
	std::cout << oddCount(array, length) << std::endl;

	return 0;
}
