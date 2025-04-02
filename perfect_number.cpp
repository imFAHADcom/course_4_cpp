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
	int getNumber = number / 2;

	for(int i = 1; i <= getNumber; i++){
		if(number % i == 0){
			sum += i;
		}
	}

	return number == sum;
}


void printResult(int number){

	if(isPerfectNumber(number)){
		std::cout << "*****\n" << number << " is perfect" << std::endl;
	}
	else {
		std::cout << "*****\n" << number << " is NOT perfect" << std::endl;
	}

}

int main(){

	printResult(readPositiveNumber("Enter positive number, Please?"));

	return 0;
}

