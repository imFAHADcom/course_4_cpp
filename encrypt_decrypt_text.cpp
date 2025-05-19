/*

Write a program to read a text and encrypt it , decrypt it.

Input:
Mohammed

Output:
Text Before Encryption : Mohammed
Text After Encryption : Ogjcoogf
Text After Decryption : Mohammed


*/

#include <iostream>
#include <string>


std::string readText(std::string message){
	std::string text = "";

	std::cout << message << std::endl;
	std::getline(std::cin, text);

	return text;
}

std::string encryptionText (std::string text, int short encryptionKey){

	for(int i = 0; i < text.length(); ++i){

	text[i] = char((int)text[i] + encryptionKey);
		

	}
	return text;
}


std::string decryptionText (std::string text, int short encryptionKey){

	for(int i = 0; i < text.length(); ++i){

	text[i] = char((int)text[i] - encryptionKey);

	}
	return text;
}


int main(){
	const int short encryptionKeyConst = 2;

	std::string text = readText("Enter text, Please? ");
	std::string textAfterEncryption = encryptionText(text, encryptionKeyConst);
	std::string textAfterDecryption = decryptionText(textAfterEncryption, encryptionKeyConst);


	std::cout << "\n****************************************" << std::endl;
	std::cout << "Text Before Encryption: " << text << std::endl;
	std::cout << "Text After Encryption: " << textAfterEncryption << std::endl;
	std::cout << "Text After Decryption: " << textAfterDecryption << std::endl;

	return 0;
}
