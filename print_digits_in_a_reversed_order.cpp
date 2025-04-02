/*

Writea program to read a number and print it in a reversed order.
Input:
1234

Output:
4
3
2
1

*/

#include <iostream>
#include <string>
#include <cmath>

int readPositiveNumber(std::string message){
	int number = 0;

	do{
		std::cout << message << std::endl;
		std::cin >> number;
	} while(number <= 0);

	return number;
}


void printDigits(int number){

	int remainder = 0;

	while(number > 0){
	
		remainder = number % 10;
		number = floor(number / 10); // floor() This function is used to round a number to the nearest integer, becouse 1234 / 10 = 123.4

		std::cout << remainder << std::endl;
	}
}

int main(){

	printDigits(readPositiveNumber("Enter positive number, Please?"));

	return 0;
}

