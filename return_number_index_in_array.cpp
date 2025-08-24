/*


Write a program to fill array with max size 100 with random numbers from 1 to 100, read number and return its index in array if found otherwise return -1.


Input:								Input:
10								10	


Output:								Output:
Array 1 elements:						Array 1 elements:
80 79 12 80 81 29 3 37 25 91					80 79 12 80 81 29 3 37 25 91



Please enter a number to search for?				Please enter a number to search for?
12								55
Number you are looking for is: 12				Number you are looking for is: 55
The number found at position: 2					The number is not found :-(
The numberr found its order: 3



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

void fillArrayWithRandomNumbers(unsigned short array[100], unsigned short arrayLength, unsigned short from, unsigned short to){

	for(unsigned short i = 0; i < arrayLength; ++i){
		array[i] = randomNumber(from, to);
	}

}

unsigned short readNumberToSearch(unsigned short from, unsigned short to){
	unsigned short numberToSearch = 0;

	do{
		std::cout <<  "\nEnter a number to search for, Please?" << std::endl;
		std::cin >> numberToSearch;
	} while(numberToSearch < from || numberToSearch > to);

	return numberToSearch;
}

short int findNumberPositionInArray(unsigned short array[100], unsigned short arrayLength, unsigned short numberToSearch){
	for(unsigned short i = 0; i < arrayLength; ++i){
		if(array[i] == numberToSearch){
			return i;
		}
	}

	return -1;
}

void printArray(unsigned short array[100], unsigned short arrayLength){
	for(unsigned short i = 0; i < arrayLength; ++i){

		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

void printSearchResult(unsigned short array[100], unsigned short arrayLength, unsigned short numberToSearch){
	
	short int numberPosition = findNumberPositionInArray(array, arrayLength, numberToSearch); 

	std::cout << "\n\nNumber you are looking for is: " << numberToSearch << "\n";

	if(numberPosition == -1){
		std::cout << "The number is not found :-(" << std::endl;
	}
	else{
		std::cout << "The number found at position: " << numberPosition << "\n";
		std::cout << "The number found its order: " << numberPosition + 1<< std::endl;
	}

}



int main(){
	srand((unsigned)time(NULL));

	unsigned short array[100];
	unsigned short arrayLength = readPositiveNumber("Enter how many number to want generate in array elements, Please?");
	unsigned short from = 1;
	unsigned short to = 100;
	
	fillArrayWithRandomNumbers(array, arrayLength, from, to);
	printArray(array, arrayLength);
	
	unsigned short numberToSearch = readNumberToSearch(from, to);

	printSearchResult(array, arrayLength, numberToSearch);

	return 0;
}
