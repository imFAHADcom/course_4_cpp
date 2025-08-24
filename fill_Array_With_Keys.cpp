/*

Write a program to read how many keys to generate and fill them in array then print them on the screen

Input:
5

Output:
Array elements:
Array[O] : NRXC-DXRO-QEAM-WRWE
Array[1] : BJTR-KIKF-ATEW-WNTT
Array[2] : QOFX-KZEL-SSDP-AKSI
Array[3] : GFOI-ELFX-ZCVE-PSTP
Array[4] : MATF-PRQA-PQEQ-TRIM

*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

enum enCharType{
	DIGIT = 1,
	SPICIAL_CHARACTER = 2,
	SMALL_LETTER = 3,
	CAPITAL_LETTER = 4,	

};



int readPositiveNumber(std::string message){

	int number = 0;
	do{
		std::cout << message << std::endl;
		std::cin >> number;
	} while(number < 1);
	
	return number;
}

int randomNumber(int from, int to){

	int randNum = rand() % (to - from + 1) + from;

	return randNum;

}


char getRandomCharacter(enCharType charType){

	switch(charType){
		case enCharType::DIGIT:
		{
			return char(randomNumber(48,57));
			break;
		}


		case enCharType::SPICIAL_CHARACTER:
		{
			return char(randomNumber(33,47));
			break;
		}
		case enCharType::SMALL_LETTER:
		{
			return char(randomNumber(97,122));
			break;
		}

		case enCharType::CAPITAL_LETTER:
		{
			return char(randomNumber(65,90));
			break;
		}

	}	

	return 0;
}


std::string generateWord(enCharType charType, short length){

	std::string word = "";
	for(int i = 0; i < length; ++i){
		word = word + getRandomCharacter(charType);
	}

	return word;
}

std::string generateKeys(){
	std::string key = "";
	
	key = generateWord(enCharType::CAPITAL_LETTER, 4) + "-";
	key = key + generateWord(enCharType::CAPITAL_LETTER, 4) + "-";
	key = key + generateWord(enCharType::CAPITAL_LETTER, 4) + "-";
	key = key + generateWord(enCharType::CAPITAL_LETTER, 4);

	return key;
}

void fillArrayWithKeys(std::string array[100], int arrayLength){
	for(int i = 0; i < arrayLength; ++i){
		array[i] = generateKeys();
	}

}

void printStringArray(std::string array[100], int arrayLength){

	for(int i = 0; i < arrayLength; ++i){
		std::cout << "Arry[" << i << "] : ";
		std::cout << array[i] << "\n";
	}

	std::cout << std::endl;
}


int main(){
	srand((unsigned)time(NULL));

	std::string array[100];
	int arrayLength = 0;
	arrayLength = readPositiveNumber("How many do you want to generate?");

	fillArrayWithKeys(array, arrayLength);

	std::cout << "\n*********************************\n";
	std::cout << "Array elements:\n\n";
	
	printStringArray(array, arrayLength);

	return 0;
}
