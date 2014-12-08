/*==========================================================================
Program name: CardFun V1
Developer name: Aaron Schraner
Date: 11/03/2014
Purpose: A program to create and shuffle a deck of cards (version 1: arrays)
============================================================================*/

//Cards are stored as 8-bit characters.
//
//01234567
//
//Bits 0 and 1 are reserved for suit.
//Bits 4 through 7 are reserved for card number (rank)

#include <iostream>
#include <cstdlib>
#include <time.h>
//suits:
const char SUIT_CLUBS = 0x00;
const char SUIT_DIAMONDS = 0x40;
const char SUIT_HEARTS = 0x80;
const char SUIT_SPADES = 0xC0;
//non-numeric ranks
const char RANK_ACE = 0x01;
const char RANK_JACK = 0x0B;
const char RANK_QUEEN = 0x0C;
const char RANK_KING = 0x0D;
//address reservation
const char SUITBITS =  0xC0;// = b11000000;
const char RANKBITS =  0x0F; // = b00001111;
const int DECKSIZE = 52;
const int SHUFFLE_THOROUGHNESS = 10000;
#ifndef CMD
#define CMD true //if using Windows command prompt (CMD)
#endif
//#define CMD false //if using Linux or launching from prompt instead of double-clicking

using namespace std;


/* Drawing space for card suits
 *  ( )   /\   _ _   /\
 * (   ) <  > ( v ) (  ) 
 *  /_\   \/   \ /   /\
 */
// Suits: a 3-dimensional array for the characters to use when printing the card as ASCII art
char suits[4][3][6] = {
	{
		" ( ) ",
		"(   )",
		" /_\\ "},
	{
		" /\\  ",
		"<  > ",
		" \\/  "},
	{
		" _ _ ",
		"( v )",
		" \\ / "},
	{
		" /\\  ",
		"(  ) ",
		" /\\  "}
};
void shuffle(char[],int);
void printcard(char,string[6]);
void dumpscr(string[6]);
void clear(string[6]);
void printdeck(char[], string[6]);
void initialize(char[]);
void cmdWarning();
/*
 * Main loop:
 * Procedure:
 * 1. Declare a standard 52-card deck
 * 2. Print that deck
 * 3. Shuffle the deck
 * 4. Print the shuffled deck
 */
int main()
{
	string display[6]; //for printing ASCII art cards
	bool run=true;
	char runagain;
	char deck[52];
	while(run)
	{
		initialize(deck);
		//fill the deck with standard 52 cards in order

		clear(display);
		//erase the virtual ASCII art display

		cout << "Unshuffled:\n";
		printdeck(deck,display);
		//print the unshuffled deck

		shuffle(deck,SHUFFLE_THOROUGHNESS );
		//shuffle the deck

		cout << "Shuffled:\n";
		printdeck(deck,display);
		//print the shuffled deck

		if(CMD) 
		{
			cmdWarning();
		}
		//if the user compiled with CMD defined as true,
		//print the warning about small consoles

		cout << "Would you like to run this again?\n[Y|N]> ";
		cin >> runagain;
		//find if the user would like to run the program again
		switch(runagain)
		{
			case 'y':
			case 'Y':
				run=true;
				break;
			case 'n':
			case 'N':
				run=false;
				break;
		}
		//handle their request by stopping or continuing the program
	}
	return 0;
}

void initialize(char deck[])
{
	for(int i=0;i<52;i++)
	{
		deck[i]=(i/13*SUIT_DIAMONDS)|(i%13+1);
	}
}

void cmdWarning()
{

	cout << "\nWARNING: This program uses large ASCII art to print cards. \n";
	cout << "If you are using Windows command prompt\n";
	cout << "and the screen just looks like a series of random characters, \n";
	cout << "your console may be too small.\n";
	cout << "Resize the console by right-clicking on the command prompt title bar,\n";
	cout << "clicking properties>layout and setting the screen buffer width to 132 or greater.\n";
	cout << "If running from Windows command prompt directly, you can also run\n";
	cout << "MODE CON COLS=132\nbefore running this program.\n";
	cout << "That will allow the ASCII art to render properly.\n";
	cout << "Ensure size is correct before running again.\n";
}

/*
 * Name: suit(card)
 * Purpose: return the suit of a card
 */
char suit(char card)
{
	return ((card&SUITBITS) >> 6)&0x03;
}

/*
 * Name: shuffle(deck,numberOfTimes)
 * Purpose: shuffle a card deck by running
 * an algorithm a given number of times.
 */
void shuffle(char deck[], int numberOfTimes)
{
	static int seedoffset=0;
	char tempcard;
	int i1;
	int i2;
	for(int i=0;i<numberOfTimes;i++)
	{
		srand(time(NULL)+seedoffset);
		i1=rand()%DECKSIZE;
		srand(i+seedoffset);
		i2=rand()%DECKSIZE;
		tempcard=deck[i2];
		deck[i2]=deck[i1];
		deck[i1]=tempcard;
	}
	seedoffset++;
}

void printcard(char card, string display[])
{
	display[0] += " -------  ";
	char rankid[3] = "  ";
	switch(card&RANKBITS)
	{
		case 1:
			rankid[0]='A';
			break;
		case 10:
			rankid[0]='1';
			rankid[1]='0';
			break;
		case 11:
			rankid[0]='J';
			break;
		case 12:
			rankid[0]='Q';
			break;
		case 13:
			rankid[0]='K';
			break;

		default:
			rankid[0]=(card&RANKBITS)-2+'2';
	}
	display[1] += "|";   display[1] += rankid; display[1] += suits[(int)suit(card)][0]; display[1] += "| ";
	display[2] += "|  "; display[2] += suits[(int)suit(card)][1]; display[2] += "| ";
	display[3] += "|  "; display[3] += suits[(int)suit(card)][2]; display[3] += "| ";
	display[4] += " -------  " ;
}

void dumpscr(string screen[6])
{
	for(int i=0;i<6;i++)
	{
		cout << screen[i] << endl;
	}
}

void clear(string display[])
{
	for(int i=0;i<6;i++)
	{
		display[i]=" ";
	}
}
void printdeck(char deck[], string display[])
{
	clear(display);
	for(int i=0; i<DECKSIZE;i++)
	{
		printcard(deck[i] ,display);
		if(i%(DECKSIZE/4)==DECKSIZE/4-1)
		{
			dumpscr(display);
			clear(display);
		}
	}
}


