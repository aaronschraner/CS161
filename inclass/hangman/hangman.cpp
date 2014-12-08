/*=================================
Program name: Hangman
Developer name: Aaron Schraner
Date: 12/01/2014
Purpose: C++ Hangman implementation
===================================*/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int MAX_WORD_SIZE = 15;
/*const string [] hangmanParts = {
	" | ", 
	"\n_", "0", "_",
   	"\n | ",
   	"\n/", " \\"};*/
//
//  |
//  |
// _0_
//  | 
// / \
//

int parseChars(const char, const char[],char[], char[]);
int main()
{
	char userWord[MAX_WORD_SIZE] = "";
	for ( int i=0;i<MAX_WORD_SIZE;i++)
		userWord[i]='-';
	char userLetters[26];
	char targetWord[MAX_WORD_SIZE];
	


	cout << "Enter a word for player 2 to guess. (Don't let them see it!) \n> ";
	cin >> targetWord;
	char userGuess;
	while(true)
	{
		cout << "Enter your guess.\n> ";
		cin >> userGuess;

		cout << "Your guess: " << userGuess << "\nCorrect letters: "<<  parseChars(userGuess, targetWord, userWord, userLetters) << "\ntargetWord: " << targetWord << "\nuserWord: " << userWord << "\nuserLetters: " << userLetters << endl;
		
	}
}

int parseChars(const char userGuess, const char targetWord[], char userString[], char failedLetters[])
{
	int points=0;
	static int failIndex = 0;
	for(int i=0;targetWord[i]!='\0' && i < MAX_WORD_SIZE ; i++)
	{
		if ( targetWord[i] == userGuess )
		{
			points++;
			userString[i] = targetWord[i];
		}
	}
	if(points==0)
	{
		failedLetters[failIndex] = userGuess;
		failIndex++;
	}

	return points;
}

void clearScreen()
{
	cout << 0x1B << 0x5B << 0x48 << 0x1B << 0x5B << 0x32 << 0x4A ;
}

