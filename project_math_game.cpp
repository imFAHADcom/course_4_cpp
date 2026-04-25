/*

Math Game


Project - Requirements

Problem:

Build a simple console-based Math Game in C++ that asks the player a number of random math questions, checks the answers, shows whether each answer is right or wrong, and displays the final result.

Requirements:
1. The program shall ask the user how many questions they want to answer.
2. The number of questions shall be from 1 to 10.
3. The program shall allow the user to choose the question level:
-Easy
-Medium
-Hard
-Mix

4. The program shall allow the user to choose the operation type:
-Addition
-Subtraction
-Multiplication
-Division
-Mix

5. The program shall generate random questions based on the selected level.
6. If the user selects **Mix**, the program shall randomly choose the level or operation.
7. The program shall read the player’s answer for each question.
8. The program shall compare the player’s answer with the correct answer.
9. The program shall count:
-Right answers
-Wrong answers

10. The program shall show feedback after each answer:
-Right Answer
-Wrong Answer
-Correct answer if the player is wrong

11. The program shall change the screen color:
-Green for right answer
-Red for wrong answer

12. The program shall play a sound when the answer is wrong.
13. The program shall show the final quiz result:
-Number of questions
-Question level
-Operation type
-Number of right answers
-Number of wrong answers
-Pass or Fail

14. The player shall pass if the number of right answers is greater than or equal to the number of wrong answers.
15. The program shall ask the player if they want to play again.

*/

#include <iostream> 
#include <cstdlib>   
#include <ctime>
#include <string>


// ---------- Data Definition ----------

enum enQuestionsLevel{ easyLevel = 1, medLevel = 2, hardLevel = 3, mix = 4 };
enum enOperationType{ add = 1, sub = 2, mult = 3, division = 4, mixOp = 5 };

struct stQuestion{
	int number1 = 0;
	int number2 = 0;
	enOperationType operationType;
	enQuestionsLevel questionLevel;
	int correctAnswer = 0;
	int playerAnswer = 0;
	bool answerResult = false;
};


struct stQuizz{
	stQuestion questionList[100];
	short numberOfQuestions;
	enQuestionsLevel questionsLevel;
	enOperationType opType;
	short numberOfWrongAnswers = 0;
	short numberOfRightAnswers = 0;
	bool isPass = false;
};


// ---------- Utility / Formatting Functions ----------

std::string getOpTypeSymbol(enOperationType opType){
	switch (opType){
	case enOperationType::add:
		return "+";
	case enOperationType::sub:
		return "-";
	case enOperationType::mult:
		return "x";
	case enOperationType::division:
		return "/";
	default:
		return "Mix";
	}
}


std::string getQuestionLevelText(enQuestionsLevel questionLevel){
	std::string arrQuestionLevelText[4] = { "Easy","Medium","Hard","Mixed" };
	return arrQuestionLevelText[questionLevel - 1];
}


std::string getFinalResultsText(bool pass){
	if(pass){
		return "PASS :-)";
	}
	else{
		return "Fail :-(";
	}
}


short randomNumber(int from, int to){
	return rand() % (to - from + 1) + from;
}


enOperationType getRandomOperationType(){
	return (enOperationType)randomNumber(1, 4);
}


// ---------- Input Functions ----------

short readHowManyQuestions(){
	short numberOfQuestions;
	do{
		std::cout << "How Many Questions do you want to answer? ";
		std::cin >> numberOfQuestions;
	} while(numberOfQuestions < 1 || numberOfQuestions > 10);

	return numberOfQuestions;
}


enQuestionsLevel readQuestionsLevel(){
	short questionLevel = 0;
	do{
		std::cout << "Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? "; 
		std::cin >> questionLevel;
	} while(questionLevel < 1 || questionLevel > 4);

	return (enQuestionsLevel)questionLevel;
}


enOperationType readOpType(){
	short opType;
	do{
		std::cout <<  "Enter operation type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
		std::cin >> opType;
	} while(opType < 1 || opType > 5);

	return (enOperationType)opType;
} 


int readQuestionsAnswer(){
	int answer = 0;
	std::cin >> answer;
	return answer;
}


// ---------- Display Functions ----------

//This code is compatible with Linux Mint
void beep(){
	system("paplay /usr/share/sounds/freedesktop/stereo/complete.oga 2>/dev/null &");
}


//This code is compatible with Linux Mint
void setScreenColor(bool right){
	if(right){
		std::cout << "\033[42;97m"; // Turn screen to green 
		std::cout << "\033[2J\033[H"; // Clear the screen
	}
	else{   
		std::cout << "\033[41;97m"; // Turn screen to red
		beep();
		std::cout << "\033[2J\033[H"; // Clear the screen
	}
}


//This code is compatible with Linux Mint
void resetScreen(){
	std::cout << "\033[0m\033[2J\033[H";
}


void printTheQuestion(stQuizz& quizz, short questionNumber){
	std::cout << "\n"; 
	std::cout << "Question [" << questionNumber + 1 << "/" << quizz.numberOfQuestions << "] \n\n"; 
	std::cout << quizz.questionList[questionNumber].number1 << std::endl;
	std::cout << quizz.questionList[questionNumber].number2 << " ";
	std::cout << getOpTypeSymbol(quizz.questionList[questionNumber].operationType);
	std::cout << "\n---------" << std::endl;
}


void printQuizzResults(stQuizz quizz){
	std::cout << "\n";
	std::cout << "-----------------------------\n";
	std::cout << "Final Results is " << getFinalResultsText(quizz.isPass); 
	std::cout << "\n-----------------------------\n\n";

	std::cout << "Number of Questions     : " << quizz.numberOfQuestions << std::endl; 
	std::cout << "Questions Level         : " << getQuestionLevelText(quizz.questionsLevel) << std::endl;
	std::cout << "OpType                  : " << getOpTypeSymbol(quizz.opType) << std::endl;
	std::cout << "Number of Right Answers : " << quizz.numberOfRightAnswers << std::endl;
	std::cout << "Number of Wrong Answers : " << quizz.numberOfWrongAnswers << std::endl;
	std::cout << "-----------------------------\n";
}


// ---------- Game Logic ----------

int simpleCalculator(int number1, int number2, enOperationType opType){
	switch (opType){
		case enOperationType::add:
			return number1 + number2;
		case enOperationType::sub:
			return number1 - number2;
		case enOperationType::mult:
			return number1 * number2;
		case enOperationType::division:
			return (number2 != 0) ? (number1 / number2) : 0;  // Avoid division by zero.
	}
	return 0;
}


stQuestion generateQuestion(enQuestionsLevel questionLevel, enOperationType opType){
	stQuestion question;

	if (questionLevel == enQuestionsLevel::mix)
		questionLevel = (enQuestionsLevel)randomNumber(1, 3);

	if (opType == enOperationType::mixOp)
		opType = getRandomOperationType();

	question.operationType = opType;

	switch (questionLevel){
		case enQuestionsLevel::easyLevel:
			question.number1 = randomNumber(5, 10);
			question.number2 = randomNumber(1, 4);
			break;
		case enQuestionsLevel::medLevel:
			question.number1 = randomNumber(30, 50);
			question.number2 = randomNumber(10, 29);
			break;
		case enQuestionsLevel::hardLevel:
			question.number1 = randomNumber(80, 100);
			question.number2 = randomNumber(50, 79);
			break;
	}

	question.correctAnswer = simpleCalculator(question.number1, question.number2, question.operationType);
	question.questionLevel = questionLevel;

	return question;
}


void generateQuizzQuestions(stQuizz& quizz){
	for (short question = 0; question < quizz.numberOfQuestions; question++)
	{
		quizz.questionList[question] = generateQuestion(quizz.questionsLevel, quizz.opType);
	}
}


void correctTheQuestionAnswer(stQuizz& quizz, short questionNumber){
	if(quizz.questionList[questionNumber].playerAnswer != quizz.questionList[questionNumber].correctAnswer){
		quizz.questionList[questionNumber].answerResult = false;
		quizz.numberOfWrongAnswers++;

		std::cout << "Worng Answer       :-( \n";
		std::cout << "The right answer is: ";
		std::cout << quizz.questionList[questionNumber].correctAnswer;
		std::cout << "\n";
	}
	else{
		quizz.questionList[questionNumber].answerResult = true;
		quizz.numberOfRightAnswers++;
	
		std::cout << "Right Answer :-) \n";
	}

	
	std::cout << std::endl;

	setScreenColor(quizz.questionList[questionNumber].answerResult);
}


void askAndCorrectQuestionListAnswers(stQuizz& quizz){
	for (short questionNumber = 0; questionNumber < quizz.numberOfQuestions; questionNumber++){
		printTheQuestion(quizz, questionNumber);
		quizz.questionList[questionNumber].playerAnswer = readQuestionsAnswer();
		correctTheQuestionAnswer(quizz, questionNumber);
	}

//	quizz.isPass = (quizz.numberOfRightAnswers >= quizz.numberOfWrongAnswers);

	if(quizz.numberOfRightAnswers >= quizz.numberOfWrongAnswers){
		quizz.isPass = true;
	}
	else{
		quizz.isPass = false;
	}
}


// ---------- Main Game Flow ----------

void playMathGame(){
	stQuizz quizz;

	quizz.numberOfQuestions = readHowManyQuestions();
	quizz.questionsLevel = readQuestionsLevel();
	quizz.opType = readOpType();

	generateQuizzQuestions(quizz);
	askAndCorrectQuestionListAnswers(quizz);

	printQuizzResults(quizz);
}


void startGame(){
	char PlayAgain = 'Y';
	do{
		resetScreen();
		playMathGame();

		std::cout << std::endl << "Do you want to play again? Y/N? ";
		std::cin >> PlayAgain;

	} while(PlayAgain == 'Y' || PlayAgain == 'y');

	resetScreen();
}



int main(){
	//Seed the random number generator in c++, called only once 
	srand((unsigned)time(NULL));

	startGame();
	
	return 0;
}
