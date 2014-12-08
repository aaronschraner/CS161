/*===============
Program name: Assignment 4
Developer name: Aaron Schraner
Date: 11/04/2014
Purpose: Perform a series of conditional operations on a user's favorite integer, character, and floating point number
===============*/
#include <iostream>
#include <cctype>
#include <cmath>
using namespace std;
int main()
{
	float rawUserNumber; 
	int intUserNumber;
	int userNumber;
	bool isPositive;
	cout << "What is your favorite integer?\n> "; 
	cin >> userNumber;
	//prompt for integer and store

	isPositive=(userNumber>=0); //find if number is positive

	if(isPositive)
	{
		cout << "\tThat number is positive!\n";
	}
	else
	{
		cout << "\tThat number is negative!\n";
	} //print if the number is positive

	int greaterThan=1; //greatest number userNumber is greater than.

	for(int i=10;i<=1000;i*=10)
	{
		if(userNumber>i)
		{
			greaterThan=i;
		}
	}
	cout << "\tThat number is greater than " << greaterThan << endl;
	//print largest power of 10 that the number is greater than
	
	bool isEven=(userNumber%2==0);
	if(isEven)
		cout << "\tThat number is also even.\n";
	else
		cout << "\tThat number is also odd.\n";
	//say if the number is even or odd
	

	switch(userNumber)
	{
		case 2:
			cout << "\tThat is also the atomic number of Helium!\n";
			break;
		case 10:
			cout << "\tThat is also the atomic number of Neon!\n";
			break;
		case 18:
			cout << "\tThat is also the atomic number of Argon!\n";
			break;
		case 36:
			cout << "\tThat is also the atomic number of Krypton!\n";
			break;
		case 54:
			cout << "\tThat is also the atomic number of Xenon!\n";
			break;
		case 86:
			cout << "\tThat is also the atomic number of Radon!\n";
			break;
		default:
			cout << "\tThat is not the atomic number of a noble gas. \n";
			break;
	}
   	//check if number is the atomic number of an atomic gas
	//and indicate if so.
	
	cout << "\nWhat is your favorite character?\n> ";
	char userChar;
	cin >> userChar;
	//prompt for and store a character from the user

	if(userChar >= '0' && userChar <= '9')
	{
		cout << "\tThat is a number.\n";
	}
	else
		cout << "\tThat is not a number.\n";
	//determine if character is a number

	switch(tolower(userChar))
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			cout << "\tThat is a vowel!\n";
			break;
		default:
			if(tolower(userChar) >= 'a' && tolower(userChar)<='z')
			{
				cout << "\tThat is a consonant!\n";
			}
			break;
	}
	//determine if character is a vowel or consonant
	
	if(tolower(userChar)!=userChar && tolower(userChar) >= 'a' && tolower(userChar) <= 'z')
		cout << "\tThat is a capital letter.\n";
	else if (tolower(userChar) >= 'a' && tolower(userChar) <= 'z')
		cout << "\tThat is a lowercase letter.\n";
	else
		cout << "\tThat is not a letter.\n";
	//determine if letter is lowercase, capital, or not a letter.

	cout << "\nWhat is your favorite floating point number?\n> ";
	cin >> rawUserNumber;
	//prompt for and store a floating point number

	cout << "\tNumbers after decimal: " <<  rawUserNumber - (long)rawUserNumber << endl;
	cout << "\tNumbers before decimal: " << (int)rawUserNumber << endl;
	//print digits before and after decimal

	if((float)intUserNumber == rawUserNumber)
	{
		cout << "\tThat number can be stored as an integer!\n";
	}
	else
	{
		cout << "\tThat number could not be stored as an integer!\n";
	}
	//find if number could be stored as an integer.
	
	cout << "Hit enter to continue.";
	cin.get();
	cin.ignore();
	//pause before exiting
	
	return 0;
	//exit program
}
