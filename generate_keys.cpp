/*

Write a program to read how many keys to generate and print them on the screen.

Input:
5

Output:
Key [1]: ETAI-HJUV-PEIP-CFRX
Key [2]: UMCO-YSPQ-PHYK-STIL
Key [3]: QBSR-MZEC-BYNA-DSYK
Key [4]: MISQ-ULYB-ZRAZ-LMAG
Key [5]: NQCR-PPFJ-KZLF-ZHMT

*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>


enum enCharType{smallLetter = 1, capitalLetter = 2, specialCharacter  = 3, digit = 4};

int readPositiveNumber(std::string message){

	int number = 0;
	do{
		std::cout << message << std::endl;
		std::cin >> number;
	} while(number < 0);

	return number;
}


int randomNumber(short int from, short int to){

	int randomNum = rand() % (to - from + 1) + from;

	return randomNum;
}


char getRandomCharacter(enCharType charType){

	switch(charType){
		case enCharType::smallLetter:{
			return char(randomNumber(97, 122));
			break;
		}

		case enCharType::capitalLetter:{
			return char(randomNumber(65, 90));
			break;
		}

		case enCharType::specialCharacter:{
			return char(randomNumber(33, 47));
			break;
		}

		case enCharType::digit:{
			return char(randomNumber(48, 57));
			break;
		}
	}

	return 0;
}



std::string generateWord(enCharType charType, short int length){

	std::string word = "";

	for(int i = 1; i <=  length; i++){
		word = word + getRandomCharacter(charType);
	}

	return word;
}


std::string generateKey(int lengthOfKey){
	std::string key = "";
	
	for(int i = 1; i <= lengthOfKey; ++i){
		key = key + generateWord(enCharType::capitalLetter, 4);
		if(i != lengthOfKey){
			key = key + "-";
		}
	}

	return key;
}

void generateKeys(short int numberOfKeys){

	std::cout << "*********************************\n";

	for(int i = 1; i <= numberOfKeys; ++i){
		std::cout << "key[" << i << "]: " << generateKey(4) << std::endl;
	}
}




int main(){

	srand((unsigned)time(NULL));

	generateKeys(readPositiveNumber("Enter how many keys to generates, Please?"));

	return 0;
}

