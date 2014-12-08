/*==============================================================================
Program name: Card fun (main loop)
Developer name: Aaron Schraner
Date: 11/24/2014
Purpose: Create and shuffle a card deck. (most computing is done by libcards2.h)
This version uses custom classes to make code easier to follow and more abstract.
================================================================================*/
#include <iostream>
#include "libcards2.h"
#ifndef WINDOWS
#define WINDOWS //uncomment to use windows style suit characters
#endif
#ifndef AA
//#define AA //uncomment to enable ascii art
#endif
using namespace std;

/*
 * Main loop
 * Description of operation:
 * 1. Create a 52-card standard deck
 * 2. Shuffle that deck
 * 3. Print that deck
 */
int main()
{
	Deck gameDeck; 
	//declare the deck
	
	gameDeck.populate52();
	//populate it with a standard 52-card deck
	
	cout << "Unshuffled deck:\n";
#ifdef WINDOWS
	gameDeck.printWin();
#else
	gameDeck.print();
#endif
	//print the unshuffled deck
	
	cout << endl << "Shuffled deck:" << endl;
	gameDeck.shuffle();
	gameDeck.setHidden(0,true);
	//shuffle the deck
	//and hide the first card
	
	
#ifdef AA
	gameDeck.printAA();
	//print shuffled deck (Ascii Art version)
#endif

#ifdef WINDOWS
	gameDeck.printWin();
	cin.get();
	//print shuffled deck (Windows version)
	//then wait for user to exit
#else
	gameDeck.print();
	//print the shuffled deck
#endif
	return 0;
}
