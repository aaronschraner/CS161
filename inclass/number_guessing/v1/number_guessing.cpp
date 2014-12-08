/*==================================
Program name: Number Guessing
Developer name: Aaron Schraner
Date: 10/22/2014
Purpose: Simple number guessing name
====================================*/
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
	
	cin>>usernum;
	
	if(usernum==randomNumber) //if they got it right...
	{
		cout << "Correct!\n";
	}
	
	else if(usernum>randomNumber) //if they were too high...
	{
		cout << "Not quite. You were only " << usernum-randomNumber << " too high.\n";
	}
	
	else //if they were too low...
	{
		cout << "Not quite. You were only " << randomNumber-usernum << " too low.\n";
	}

	cout << "Number was " << randomNumber << ".\n"; //tell the user the real number.
	return 0;
}
