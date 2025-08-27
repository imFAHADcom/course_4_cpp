/*
Write a program to dynamically read numbers and save them in an array Max size of array is 100, allocate simi-dynamic array length.

Output:
Please enter a number? 10
Do you want to add more numbers? [0]:No,[1]:yes? 1

Please enter a number? 20
Do you want to add more numbers? [O]:No,[1]:yes? 1

Please enter a number? 30
Do you want to add more numbers? [0]:No,[1]:yes? 0


Array Length: 3
Array elements: 10 20 30

*/

#include <iostream>
#include <string>

unsigned short readPositiveNumber(std::string message){
	unsigned short number = 0;
	do{
		std::cout << message;
		std::cin >> number;
	} while(number < 1);

	return number;
}

void addArrayElement(unsigned short number, int array[100], unsigned short& arrayLength){

	arrayLength++;
	array[arrayLength - 1] = number;
}

void inputUserNumbersInArray(int array[100], unsigned short& arrayLength){

	bool addMore = true;

	do{
		addArrayElement(readPositiveNumber("Enter a number, Please? "), array, arrayLength);		

		std::cout << "Do you want to add more numbers? [0]:No, [1]:Yes? ";
		std::cin >> addMore;
		std::cout << "\n\n";
	} while(addMore);
}


void printArray(int array[100], unsigned short arrayLength){
	std::cout << "\n\nArray Length: " << arrayLength << "\n";
	std::cout << "Array elements: ";

	for(unsigned short i = 0; i < arrayLength; ++i){
		std::cout << array[i] << " ";

	}

	std::cout << std::endl;
}
int main(){
	int array[100];
	unsigned short arrayLength = 0;
 
	inputUserNumbersInArray(array, arrayLength);

	printArray(array, arrayLength);

	return 0;
}
