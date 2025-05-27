/*

Write a program to print random Small Letter, Capital
Letter, Special Character, and Digit in order.

Output:
i
G
$
7

*/

#include <iostream>
#include <cstdlib>
#include <ctime>


enum enCharType{ 
	SmallLetter = 1, 

	CapitalLetter = 2,

	SpecialCharacter = 3,

	DigitInOrder = 4,
};



int randomNumber(int from, int to){

	int random = rand() % (to - from + 1) + from;

	return random;

}


char getRandomCharacter(enCharType charType){

	switch(charType){

		case enCharType::SmallLetter:{
			return char(randomNumber(97, 122));
			break;
		}

		case enCharType::CapitalLetter:{
			return char(randomNumber(65, 90));
			break;
		}
	

		case enCharType::SpecialCharacter:{
			return char(randomNumber(33, 47));
			break;
		}

		case enCharType::DigitInOrder:{
			return char(randomNumber(48, 57));
			break;
		}

	}

	return 0;
}


int main(){

	//Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));

	std::cout << getRandomCharacter(enCharType::SmallLetter) << std::endl;
	std::cout << getRandomCharacter(enCharType::CapitalLetter) << std::endl;
	std::cout << getRandomCharacter(enCharType::SpecialCharacter) << std::endl;
	std::cout << getRandomCharacter(enCharType::DigitInOrder) << std::endl;

	return 0;
}
