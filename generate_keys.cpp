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
#include <cstdlib>
#include <ctime>
#include <string>


enum enCharType{ smallLetter = 1, capitalLetter = 2, specialCharacter = 3, digit = 4,};


int readPositiveNumber(std::string message){

	int number = 0;
	do{
		std::cout << message << std::endl;
		std::cin >> number;

	} while(number < 0);

	return number;
}



int randNumber(int short from, int short to){

	int randNum = rand() % (to - from + 1) + from;

	return randNum;

}


char getRandomCharacter(enCharType charType){

	switch(charType){
		case enCharType::smallLetter:{
			return char(randNumber(61, 122));
			break;
		}

		case enCharType::capitalLetter:{
			return char(randNumber(65, 90));
			break;
		}

		case enCharType::specialCharacter:{
			return char(randNumber(33, 47));
			break;
		}
		case enCharType::digit:{
			return char(randNumber(48, 57));
			break;
		}
	}


	return 0;
}


std::string generateWord(enCharType charType, int short length){

	std::string word = "";

	for(int i = 1; i <= length; ++i){
		word = word + getRandomCharacter(charType);

	}

	return word;
}


std::string generateKey(){

	std::string key = "";

	key = generateWord(enCharType::capitalLetter, 4) + "-";
	key = key + generateWord(enCharType::capitalLetter, 4) + "-";
	key = key + generateWord(enCharType::capitalLetter, 4) + "-";
	key = key + generateWord(enCharType::capitalLetter, 4);

	return key;

}

void generateKeys(int short numberOfKeys){
	
	std::cout << "********************************************\n";

	for(int i = 1; i <= numberOfKeys; ++i){
		std::cout << "Key [" << i << "]: " << generateKey() << std::endl;

	}
}

int main(){
	srand((unsigned)time(NULL));

	generateKeys(readPositiveNumber("Enter how many keys to generates, Please?"));	

	return 0;

}
