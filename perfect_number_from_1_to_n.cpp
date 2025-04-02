/*
Write a program to print all perfect numbers from 1 to N

Input:
500

Output:
6
28
496

*/

#include <iostream>
#include <string>

int readPositiveNumber(std::string message){
	int number = 0;
	do{
		std::cout << message << std::endl;
		std::cin >> number;

	} while(number <= 0);

	return number;
}

bool isPerfectNumber(int number){

	int sum = 0;

	for(int i = 1; i < number; i++){
		if(number % i == 0){
			sum += i;
		}
	}

	return number == sum;
}

void printResult(int number){

	for(int i = 1; i <= number; i++){
		if(isPerfectNumber(i)){
			std::cout << i << std::endl;
		}
	}

}


int main(){

	printResult(readPositiveNumber("Enter positive number, Please?"));

	return 0;
}
