/*
Project 1- Requirements

Problem:
Write a small game program for Stone-Paper-Scissor.

Requirements:
- Ask for how many rounds the game will be.
- Start each round Player vs Computer.
- Show the results with each round.
- If computer wins the round ring a bill, and screed red
- If player won the round show green screen.
- After all rounds show game over the print game results, then ask the user if she want to play again?

*/


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


// ---------- Data Definition ----------

constexpr int MIN_SIZE = 1;
constexpr int MAX_SIZE = 10;


enum enGameChoice{ STONE = 1, PAPER = 2, SCISSORS = 3 };
enum enWinner{ PLAYER1 = 1, COMPUTER = 2, DRAW = 3 };


struct stRoundInfo{
	short int roundNumber = 0;
	enGameChoice player1Choice;
	enGameChoice computerChoice;
	enWinner winner;
	std::string winnerName = "";
};


struct stGameResults{
	short gameRounds = 0;
	short player1WinTimes = 0;
	short computerWinTimes = 0;
	short drawTimes = 0;
	enWinner gameWinner;
	std::string winnerName = "";
};


// ---------- Utility Functions ----------

int randomNumber(short int from, short int to){

	short int randNum = rand() % (to - from + 1) + from;

	return randNum;
}


std::string tabs(short int numberOfTabs) {
    return std::string(numberOfTabs, '\t');
}


void beep(){

	system("paplay /usr/share/sounds/freedesktop/stereo/complete.oga 2>/dev/null &");
}


void resetScreen(){

	std::cout << "\033[0m\033[2J\033[H";

}



// ---------- Display Functions ----------

void setWinnerScreenColor(enWinner winner){

	switch (winner){
		case enWinner::PLAYER1:
			std::cout << "\033[42;97m"; // Trun screen to green 
			std::cout << "\033[2J\033[H"; // Clear the screen
		break;

		case enWinner::COMPUTER:
			std::cout << "\033[41;97m"; // Trun screen to red
			beep();
			std::cout << "\033[2J\033[H"; // Clear the screen
		break;

		default:
			std::cout << "\033[43;30m"; // Trun screen to yellow
			std::cout << "\033[2J\033[H"; // Clear the screen
		break;
	}
}


std::string choiceName(enGameChoice choice){

	std::string arrayGameChoices[3] = {"Stone", "Paper", "Scissors"};

	return arrayGameChoices[choice - 1];
}


std::string winnerName(enWinner winner){

	std::string arrayWinnerName[3] = {"Player1", "Computer", "No Winner (Draw)"};

	return arrayWinnerName[winner - 1];
}


void showGameOverScreen(){

	std::cout << tabs(4) << "----------------------------------------------------\n\n";
	std::cout << tabs(4) << "		+++ Game Over +++\n";
	std::cout << tabs(4) << "----------------------------------------------------\n\n";
}


void printRoundResults(stRoundInfo roundInfo){

	setWinnerScreenColor(roundInfo.winner);

	std::cout << tabs(4) << "____________ Round [" << roundInfo.roundNumber << "] ____________\n\n";
	std::cout << tabs(4) << "Player1 choice: " << choiceName(roundInfo.player1Choice) << "\n";
	std::cout << tabs(4) << "Computer choice: " << choiceName(roundInfo.computerChoice) << "\n";
	std::cout << tabs(4) << "Round winner   : [" << roundInfo.winnerName << "] \n";
	std::cout << tabs(4) << "___________________________________\n" << std::endl;

}



// ---------- Game Logic ----------

enWinner whoWonTheRound(stRoundInfo roundInfo){

	if(roundInfo.player1Choice == roundInfo.computerChoice){
		return enWinner::DRAW;
	}

	switch(roundInfo.player1Choice){

		case enGameChoice::STONE:
			if(roundInfo.computerChoice == enGameChoice::PAPER){
				return enWinner::COMPUTER;
			}
		break;

		case enGameChoice::PAPER:
			if(roundInfo.computerChoice == enGameChoice::SCISSORS){
				return enWinner::COMPUTER;
			}
		break;

		case enGameChoice::SCISSORS:
			if(roundInfo.computerChoice == enGameChoice::STONE){
				return enWinner::COMPUTER;
			}
		break;
	}

	return enWinner::PLAYER1;
}


// This function decides who won the game overall
enWinner whoWonTheGame(short int player1WinTimes, short int computerWinTimes){

	if(player1WinTimes > computerWinTimes){
		return enWinner::PLAYER1;
	}
	else if(computerWinTimes > player1WinTimes){
		return enWinner::COMPUTER;
	}
	else{
		return enWinner::DRAW;
	}
}


stGameResults fillGameResults(short int gameRounds, short int player1WinTimes, short int computerWinTimes, short int drawTimes){

	stGameResults gameResults;

	gameResults.gameRounds = gameRounds;
	gameResults.player1WinTimes = player1WinTimes;
	gameResults.computerWinTimes = computerWinTimes;
	gameResults.drawTimes = drawTimes;
	gameResults.gameWinner = whoWonTheGame(player1WinTimes, computerWinTimes);
	gameResults.winnerName = winnerName(gameResults.gameWinner);

	return gameResults;
}



// ---------- Input Functions ----------

short int readHowManyRounds(){

	short int gameRounds = 1;

	do{
		std::cout << "How many rounds 1 to 10 ? ";
		std::cin >> gameRounds;
	} while(gameRounds < MIN_SIZE || gameRounds > MAX_SIZE);


	return gameRounds;
}


enGameChoice getComputerChoice(){

	return (enGameChoice)randomNumber(1, 3);
}


enGameChoice readPlayer1Choice(){

	short int choice = 1;

	do{
		std::cout << "\nYour choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
		std::cin >> choice;
	} while(choice < 1 || choice > 3);

	return (enGameChoice)choice;
}



// ---------- Main Game Flow ----------

stGameResults playGame(short int howManyRounds){

	stRoundInfo roundInfo;
	short int player1WinTimes = 0, computerWinTimes = 0, drawTimes = 0;

	for(short int gameRounds = 1; gameRounds <= howManyRounds; gameRounds++){
		std::cout << "\nRound [" << gameRounds << "] begins: \n";
		roundInfo.roundNumber = gameRounds;
		roundInfo.player1Choice = readPlayer1Choice();
		roundInfo.computerChoice = getComputerChoice();
		roundInfo.winner = whoWonTheRound(roundInfo);
		roundInfo.winnerName = winnerName(roundInfo.winner);

		if(roundInfo.winner == enWinner::PLAYER1){
			player1WinTimes++;
		}
		else if(roundInfo.winner == enWinner::COMPUTER){
			computerWinTimes++;
		}
		else{
			drawTimes++;
		}

		printRoundResults(roundInfo);
	}

	return fillGameResults(howManyRounds, player1WinTimes, computerWinTimes, drawTimes);
}


void showFinalGameResults(stGameResults gameResults){

	setWinnerScreenColor(gameResults.gameWinner);
	showGameOverScreen();

	std::cout << tabs(4) << "_____________ [Game results] ____________\n\n";
	std::cout << tabs(4) << "Game rounds		: " << gameResults.gameRounds << "\n";
	std::cout << tabs(4) << "Player1 won times  : " << gameResults.player1WinTimes << "\n";
	std::cout << tabs(4) << "Computer won times : " << gameResults.computerWinTimes << "\n";
	std::cout << tabs(4) << "Draw times		 : " << gameResults.drawTimes << "\n";
	std::cout << tabs(4) << "Final winner	   : " << gameResults.winnerName << "\n";
	std::cout << tabs(4) << "----------------------------------------------------\n";
}


void startGame(){
	char playAgain = 'Y';
	do{
		resetScreen();
		stGameResults gameResults = playGame(readHowManyRounds());
		showFinalGameResults(gameResults);
		std::cout << "\n" << tabs(4) << "Do you want to play again? <Y/N>: ";
		std::cin >> playAgain;
	} while(playAgain == 'Y' || playAgain == 'y');

	resetScreen();
}


int main(){
	srand((unsigned)time(NULL));

	startGame();

	return 0;
}
