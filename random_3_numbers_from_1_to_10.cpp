/*

Write a program to print 3 random numbers from 1 to 10.

output:
9
5
3


*/

#include <iostream>
#include <cstdlib>
#include <ctime>


int randomNumber(int from, int to){

	int randNum = rand() % (to - from + 1) + from;

	return randNum;
}


int main(){

	srand((unsigned)time(NULL));

	std::cout << randomNumber(1, 5) << std::endl;
	std::cout << randomNumber(1, 5) << std::endl;
	std::cout << randomNumber(1, 5) << std::endl;

	return 0;
}


