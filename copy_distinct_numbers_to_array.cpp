/*

Write a program to fill array with numbers, then print distinct numbers to another array.

Output:

Array 1 elements:
10 10 10 50 50 70 70 70 70 90


Array 2 distinct elements:
10 50 70 90

*/


#include <iostream>


void fillArray(unsigned short arraySource[100], unsigned short& arraySourceLength){

	arraySourceLength = 10;

	arraySource[0] = 10; 
	arraySource[1] = 10;
	arraySource[2] = 10; 
	arraySource[3] = 50; 
	arraySource[4] = 50;
	arraySource[5] = 70; 
	arraySource[6] = 70; 
	arraySource[7] = 70; 
	arraySource[8] = 70; 
	arraySource[9] = 90;

}


void printArray(unsigned short arraySource[100], unsigned short arraySourceLength){

	for(unsigned short i = 0; i < arraySourceLength; ++i){

		std::cout << arraySource[i] << " ";

	}
	std::cout << std::endl;
}


short int findPositionNumberInArray(unsigned short number, unsigned short arraySource[100], unsigned short arraySourceLength){

	for(unsigned short i = 0; i < arraySourceLength; ++i){
		if(arraySource[i] == number){
			return i;
		}

	}
	return -1;
}


bool isNumberInArray(unsigned short number, unsigned short arraySource[100], unsigned short arraySourceLength){

	return findPositionNumberInArray(number, arraySource, arraySourceLength) != -1;
}

void addArrayElement(unsigned short number, unsigned short arraySource[100], unsigned short& arraySourceLength){

	++arraySourceLength;
	arraySource[arraySourceLength - 1] = number;
}


void copyDistinctNumbersToArray(unsigned short arraySource[100], unsigned short arrayDestination[100], unsigned short arraySourceLength, unsigned short& arrayDestinationLength){

	for(unsigned short i = 0; i < arraySourceLength; ++i){
		if(!isNumberInArray(arraySource[i], arrayDestination,  arraySourceLength)){
			addArrayElement(arraySource[i], arrayDestination, arrayDestinationLength);			
		}
	}


}


int main(){
	unsigned short arraySource[100], arraySourceLength = 0, arrayDestination[100], arrayDestinationLength = 0;

	fillArray(arraySource, arraySourceLength);

	std::cout << "\nArray 1 elements:\n";
	printArray(arraySource, arraySourceLength);


	copyDistinctNumbersToArray(arraySource, arrayDestination, arraySourceLength, arrayDestinationLength);
	
	std::cout << "\nArray 2 distinct elements:\n";
	printArray(arrayDestination, arrayDestinationLength);

	return 0;
}
