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

void copyAndReverseArray(int arraySource[100],int arrayDestination[100], int arraylength){

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

	copyAndReverseArray(array, array2, arraylength);
	std::cout << "\nArray 2 elements after copying array 1 in reversed order:\n";
	printArray(array2, arraylength);




	return 0;
}
