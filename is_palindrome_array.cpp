/*
Write a program to fill array with numbers, then check if it is Palindrome array or not, Note: Palindrome array can be read the same from right to left and from left to right.

Input:
10 20 30 30 20 19

Output:

Array Elements:
10 20 30 30 20 10

Yes array is Palindrome

*/

#include <iostream>

void fillArray(unsigned short array[100], unsigned short& arrayLength){

	arrayLength = 6;

	array[0] = 10;
	array[1] = 20;
	array[2] = 30;
	array[3] = 30;
	array[4] = 20;
	array[5] = 10;
}

void printArray(unsigned short array[100], unsigned short arrayLength){

	for(unsigned short i = 0; i < arrayLength; ++i){

		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

bool isPalindromeArray(unsigned short array[100], unsigned short length){

	for(unsigned short i = 0; i < length; ++i){
		if(array[i] != array[length - i - 1]){
			return false;
		}

	}

	return true;
}


void printIsPalindromeArray(unsigned short array[100], unsigned short length){


	if(isPalindromeArray(array, length)){
		std::cout << "\nYes array is palindrome\n";
	}
	else{
		std::cout << "\nNo Array is not palindrome\n";
	}


}

int main(){
	unsigned short array[100], length = 0;

	fillArray(array, length);

	std::cout << "Array elements:\n";
	printArray(array, length);

	printIsPalindromeArray(array, length);

	return 0;
}
