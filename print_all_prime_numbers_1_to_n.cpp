#include <iostream>
#include <string>
#include <cmath>

enum enPrimeNotPrime{PRIME = 1, NOTPRIME = 2};

int readPositiveNumber(std::string messgae){
	int number = 0;
	do{
		std::cout << messgae << std::endl;
		std::cin >> number;
	
	} while(number < 0);

	return number;
}


enPrimeNotPrime checkPrime(int number){

	if(number < 2) {
		return enPrimeNotPrime::NOTPRIME;
	}

	int m = round(number / 2);
	for(int i = 2; i <= m; ++i){
		if(number % i == 0){
			return enPrimeNotPrime::NOTPRIME;
		}
	}
	return enPrimeNotPrime::PRIME;
}

void printPrimeNumbersFrom1ToN(int number){

	std::cout << "*****\n" << "Prime numbers from 1 to " << number << " are: "<< std::endl;
	for(int i = 2; i <= number; ++i){
		if(checkPrime(i) == enPrimeNotPrime::PRIME){
			std::cout << i << std::endl;
		}
	}
}

int main(){
	
	printPrimeNumbersFrom1ToN(readPositiveNumber("Enter a positive number, Please?"));

	return 0;
}
