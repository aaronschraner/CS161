/*===================================================================
Program name: Number Guessing V2.0
Developer name: Aaron Schraner
Date: 10/27/2014
Purpose: Like V 1.0 but with a while loop so the game is less boring.
=====================================================================*/
#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;
int main()
{

	srand(time(NULL)); //initialize random generator

	int randomNumber=(rand() % 100 + 1); //get a random number

	cout << "I'm thinking of a number from 1 to 100...\n";
	cout << "Guess what it is.\n> ";
	
	int usernum;

	do 
	{
		cin>>usernum;
		
		if(usernum==randomNumber) //if they got it right...
		{
			cout << "Correct!\n";
		}

		else if(usernum>randomNumber) //if they were too high...
		{
			cout << "Not quite. (too high)\n";
		}
		
		else //if they were too low...
		{
			cout << "Not quite. (too low)\n";
		}

	}
	while(usernum!=randomNumber);
	
	//repeat until user gets correct number.

	cout << "Number was " << randomNumber << ".\n"; //tell the user the real number.
	return 0;
}
