/*

Write a program to fill array with max size 100 with random
numbers from 1 to 100.
Input:
10
Output:
Array Elements: 56 55 83 71 32 52 17 28 71 52

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


int randomNumbers(int from, int to){

	int randomNum = rand() % (to - from + 1) + from;

	return randomNum;
}


void fillArrayWithRandomNumbers(int array[100], int arrayLength){
 
	for(int i = 0; i < arrayLength; ++i){
		array[i] = randomNumbers(1, 100);
	}

}

void printArray(int array[100], int arrayLength){

    for (int i = 0; i < arrayLength; i++){
        std::cout << array[i] << " ";
    }

    	std::cout << "\n";

}

int main(){
	srand((unsigned)time(NULL));

	int array[100], arrayLength;

	arrayLength  = readPositiveNumber("Enter of elements number? ");

	fillArrayWithRandomNumbers(array, arrayLength); 

	std::cout << "\nArray Elements: "; 
	printArray(array, arrayLength);

	return 0;
}
