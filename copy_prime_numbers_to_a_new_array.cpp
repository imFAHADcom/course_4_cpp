/*

Write a program to fill array with max size 100 with random numbers from 1 to 100, copy only prime numbers to another array using AddArrayElement, and print it.

Input:
10

Output:

Array 1 elements:
61 100 32 75 81 95 50 98 13 70

Array 2 Prime numbers:
61 13

*/


#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

enum enPrimeNotPrime{IS_PRIME = 1, NOT_PRIME = 2};

unsigned short readPositiveNumber(const std::string message){
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



enPrimeNotPrime checkPrime(unsigned short checkNumber){
	unsigned short m = sqrt(checkNumber); 

	for(unsigned short i = 2; i <= m; ++i){
		if(checkNumber % i == 0){
			return enPrimeNotPrime::NOT_PRIME;
		}
	}
	

	return enPrimeNotPrime::IS_PRIME;
}

void fillArrayWithRandomNumbers(unsigned short array[100], unsigned short arrayLength ){

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

void addElement(unsigned short newNumber, unsigned short array[100], unsigned short& arrayLength ){

	++arrayLength;
	array[arrayLength - 1] = newNumber;

}

void copyArrayOnlyPrimeNumbers(unsigned short arraySource[100], unsigned short arrayDestion[100], unsigned short arraySourceLenght, unsigned short& arrayDestionLength){

	for(unsigned short i = 0; i < arraySourceLenght; ++i){
		if(checkPrime(arraySource[i]) == enPrimeNotPrime::IS_PRIME){
	
			addElement(arraySource[i], arrayDestion, arrayDestionLength);
		}
	
	}
}



int main(){
	srand((unsigned)time(NULL));

	unsigned short array[100];
	unsigned short arrayLength = readPositiveNumber("Enter number of elements? ");
	
	fillArrayWithRandomNumbers(array, arrayLength);
	
	std::cout << "\nArray 1 elements:\n";
	printArray(array, arrayLength);

	unsigned short array2[100];
	unsigned short array2Length = 0;

	copyArrayOnlyPrimeNumbers(array, array2, arrayLength, array2Length);

	std::cout << "\nArray only prime Numbers:\n";
	printArray(array2, array2Length);




	return 0;
}
