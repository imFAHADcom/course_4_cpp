/*


Write a program to fill array with max size 100 with random numbers from 1 to 100, read number and return its index in array if found otherwise return -1.


Input:								Input:
10								10	


Output:								Output:
Array 1 elements:						Array 1 elements:
83 92 66 21 62 96 40 13 19 30					80 79 12 80 81 29 3 37 25 91



Please enter a number to search for?				Please enter a number to search for?
66								55

Number you are looking for is: 66				Number you are looking for is: 55
Yes, The number is found :-)					No, The number is not found :-(

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

void fillArrayWithRandomNumbers(int array[100], unsigned short arrayLength){

	for(unsigned short i = 0; i < arrayLength; ++i){
		array[i] = randomNumber(1, 100);
	}
}

void printArray(int array[100], unsigned short arrayLength){

	for(unsigned short i = 0; i < arrayLength; ++i){

		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

short int findPositionNumberInArray(int array[100], unsigned short arrayLength, unsigned short checkNumber){

	for(unsigned short i = 0; i < arrayLength; ++i){
			if(array[i] == checkNumber){
				return i;
			}
	}
		return -1;
}

bool isNumberInArray(int array[100], unsigned short arrayLength, unsigned short checkNumber){

	return findPositionNumberInArray(array, arrayLength, checkNumber) != -1;

}

void printSearchResult(int array[100], unsigned short arrayLength, unsigned short checkNumber){

	std::cout << "\nNumber you are looking for is: " << checkNumber << "\n";

	if(!isNumberInArray(array, arrayLength, checkNumber)){
		std::cout << "No, The number is not found :-(" << std::endl;
	}
	else{
		std::cout << "Yes, The number is found :-)" << std::endl;
	}
}


int main(){
	srand((unsigned)time(NULL));

	int array[100];
	unsigned short arrayLength = readPositiveNumber("Enter how many generate numbers in array elements?");

	fillArrayWithRandomNumbers(array, arrayLength);
	
	std::cout << "\n**************************************\n";
	std::cout << "Array elements:\n"; 
	printArray(array, arrayLength);

	std::cout << "\n\n";
	unsigned short checkNumber = readPositiveNumber("Enter a number to search for?");

	printSearchResult(array, arrayLength, checkNumber);

	return 0;
}
