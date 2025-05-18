/*

Write a program to guess a 3-Letter Password (all capital).

Input:
AAF

Output:
Trial [1]: AAA
Trial [2]: AAB
Trial [3]: AAC
Trial [4]: AAD
Trial [5]: AAE
Trial [6]: AAF

Password is AAF 
Found after 6 Trial(s)

*/


#include <iostream>
#include <string>

std::string readInput(std::string message){

	std::string input = "";
	std::cout << message << std::endl;
	std::cin >> input;

	return input;
}


bool guessPass(std::string input){

	std::cout << "\n************************\n";
	std::string pass = "";
	int counter = 0;
	for(int i = 65; i <= 90; ++i){
		for(int j = 65; j <= 90; ++j){
			for(int k = 65; k <= 90; ++k){
				pass = pass + char(i);
				pass = pass + char(j);
				pass = pass + char(k);
	
				counter++;
				std::cout << "Trail [" << counter << "]: " << pass << "\n";

				if(pass == input){
					std::cout << "************************\n";
					std::cout << "Passoword is " << pass << "\n";
					std::cout << "Found after " << counter << " Trial(s)" << std::endl;
					return true;
				}
				pass = "";	
			}
		}

	}
	return false;
}

int main(){
	guessPass(readInput("Please enter a 3-letter Password (all capital)"));


	return 0;
}

