/*

Write a program to fill array with max size 100 with random
numbers from 1 to 100, copy only prime numbers to another
array and print it.

Input:
10

Output:

Array 1 elements:
42 68 35 1 70 25 79 59 63 65

Prime Numbers in Array2:
1 79

*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>


enum enPrimeNotPrime{PRIME = 1, NOTPRIME = 2};


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


void fillArrayWithRandomNumbers(int array1[100], int array1Length){

	for(int i = 0; i < array1Length; ++i){
		array1[i] = randomNumber(1, 100);
	}


}

void printArray(int array1[100], int array1Length){

	for(int i = 0; i < array1Length; ++i){
		std::cout << array1[i] << " ";
	}
	std::cout << std::endl;
}


enPrimeNotPrime checkPrime(int number){

    int m = floor(sqrt(number)); 

	for(int i = 2; i <= m; ++i){
		if(number % i == 0){
			return enPrimeNotPrime::NOTPRIME;
		}
	}
	
	return enPrimeNotPrime::PRIME;
}



void copyOnlyPrimeNumbers(int arraySource[100], int arrayDestination[100], int array1Length, int &array2Length)
{
    int counter = 0;
 
    for (int i = 0; i < array1Length; i++){

	if (checkPrime(arraySource[i]) == enPrimeNotPrime::PRIME){

            arrayDestination[counter] = arraySource[i];
            counter++;
	}
    }
    
    array2Length = counter;
}



int main(){
	srand((unsigned)time(NULL));

	int array1[100], array2[100], array1Length, array2Length = 0;

	array1Length = readPositiveNumber("Enter numbers of array elements? ");

	fillArrayWithRandomNumbers(array1, array1Length);

	std::cout << "\n****************************************\n";
	std::cout << "Array 1 elements:\n";
	printArray(array1, array1Length);

	

	copyOnlyPrimeNumbers(array1, array2, array1Length, array2Length);

	std::cout << "\nPrime Numbers in Array 2:\n";
	printArray(array2, array2Length);
	return 0;
}
