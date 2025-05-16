/*

Write a program to print all words from AAA to ZZZ:


Output:
AAA
AAB
AAC
.
.
.
ZZZ

*/

#include <iostream>
#include <string>


void printAllWordsFromAAAToZZZ(){

	std::cout << "******************\n";
	std::string word = "";

	for(int i = 65; i <= 90; i++){
		for(int j = 65; j <= 90; j++){
			for(int k = 65; k <= 90; k++){
				word = word + char(i);
				word = word + char(j);
				word = word + char(k);
	
				std::cout << word << "\n";
				word = "";

			}

		}

			std::cout << "******************" << std::endl;
	}


}


int main(){

	printAllWordsFromAAAToZZZ();

	return 0;
}
