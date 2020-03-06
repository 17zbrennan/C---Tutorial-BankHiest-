//Brings in outside resources
#include <iostream>
#include <ctime>
void PrintIntroduction(int Difficulty){
	std::cout << "\n \nYou're sneaking around a world class bank. You need to get through the safe!\n";
	std::cout << "Your hacker needs to enter the correct code for a level " << Difficulty << " secure safe to continue...\n";
	std::cout << "There are 3 numbers in the code: \n";
	std::cout << " ____\n|,--.|\n||__||\n|+  o|\n|,'o |\n`----'\n";
}

bool PlayGame(int Difficulty){
// Creating and initializing our constant variables
	const int CodeA = (rand() % (Difficulty + Difficulty)) + 1; 
	const int CodeB = (rand() % (Difficulty + Difficulty)) + 1;
	const int CodeC = (rand() % (Difficulty + Difficulty)) + 1;

	const int CodeSum = CodeA + CodeB + CodeC; 
	const int CodeProduct = CodeA * CodeB * CodeC;
	
	int GuessA, GuessB, GuessC;
	int GuessSum;
	int GuessProduct;

	PrintIntroduction(Difficulty); 

	//Reads output into the terminal
	std::cout << "The code adds up to " << CodeSum << "\n";
	std::cout << "The code numbers multiply up to " << CodeProduct << "\n";
	std::cout << "Seperate code numbers with spaces!";
	//Store player Guess
	std::cin >> GuessA;
	std::cin >> GuessB;
	std::cin >> GuessC;
	GuessSum = GuessA + GuessB + GuessC;
	GuessProduct = GuessA * GuessB * GuessC;
	
	//Checks player guess
	if(GuessSum == CodeSum && GuessProduct == CodeProduct){
		if(Difficulty != 5){
			std::cout << "You got the correct numbers on to the next safe!";
		}
		return true;
	}else{
		std::cout << "The code was incorrect.. try again you don't have much time.";
		return false;
	}
}

//start of the main function
int main (){
	const int MaxDifficulty = 5;
	int Difficulty = 1;
	bool bLevelComplete = true;
	//Plays while we wanna play
	srand(time(NULL));
	while	(Difficulty <= MaxDifficulty){
		bLevelComplete = PlayGame(Difficulty);
		std::cin.clear();
		std::cin.ignore();
		if(bLevelComplete == true){
			Difficulty++;
		}

	}
	std::cout << "You got out of the bank with a grand total of $1,560,533.";
	//returns 0 to end the program
	return 0;
}