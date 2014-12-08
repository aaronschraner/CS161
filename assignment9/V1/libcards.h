//Cards are 8 bits.
//
//01234567
//
//Bits 0 and 1 are reserved for suit.
//Bits 4 through 7 are reserved for card number
/* Drawing space
 *  ( )   /\.  _ _   /\
 * (   ) <  > ( v ) (  ) 
 *  /_\\  \/   \ /   /\
 */
//this program uses 8 bit cards and bitwise sorting to optimize efficiency.

char suits[4][3][6] = {
	{
		//Clubs
		" ( ) ",
		"(   )",
		" /_\\ "},

	{
		//Diamonds
		" /\\  ",
		"<  > ",
		" \\/  "},

	{
		//Hearts
		" _ _ ",
		"( v )",
		" \\ / "},

	{
		//Spades
		" /\\  ",
		"(  ) ",
		" /\\  "}
}; //card ASCII art definitions.
 //each card must be exactly 5 characters wide and 3 tall
#include <iostream>
#include <cstdlib>
#include <time.h>
//suits:
#define SUIT_CLUBS 0x00
#define SUIT_DIAMONDS 0x40
#define SUIT_HEARTS 0x80
#define SUIT_SPADES 0xC0
//non-numeric ranks
#define RANK_ACE 0x01
#define RANK_JACK 0x0B
#define RANK_QUEEN 0x0C
#define RANK_KING 0x0D
//address reservation
#define SUITBITS 0xC0// b11000000
#define RANKBITS 0x0F // b00001111
#define DECKSIZE 52
using namespace std;
//RAW DATA MANIPULATION//
void shuffle(int, char[]);
void wipedeck(char[]);
void deal(char[], char[], int&);
bool haswinner(char[] , char[] );
int getscore(char[]);
char suit(char);
void initdeck(char []);
//GUI STUFF//
void printcard(char, string[6]);
void dumpscr(string[6]);
void clear(string[6]);
void printdeck(char[], string[6]);
void printcard(char, string[6]);
string display[6];
//virtual display for printing cards


/*
 * Name: getscore(char deck[])
 * Description: finds the score of a deck of cards
 * Args: deck (char[]) : the deck to find the score of
 * Automatically converts aces to ones instead of 11s if necessary
 */
int getscore(char deck[])
{
	int score=0;
	int aces=0; //number of aces found
	for(int i=0;i<DECKSIZE;i++)
	{
		if(deck[i]!=0)
		{
			if((int)(deck[i]&RANKBITS)==RANK_ACE)
			{
				aces++;
				score+=11;
			}
			else
			{
				score+=deck[i]&RANKBITS;
			}
		}
	}
	if(score>21 && aces>0)
	{
		while(score>21 && aces>0)
		{
			score-=10;
			aces--;
		}
	}
	return score;
}

/*
 * Name: haswinner(playerdeck, dealerdeck)
 * Description: find if the game has been one given two hands of cards
 * Args: playerdeck, dealerdeck (char[]) : hands of cards to search for winner in
 * uses getscore()
 */
bool haswinner(char playerdeck[], char dealerdeck[])
{
	int pscore=getscore(playerdeck);
	int dscore=getscore(dealerdeck);
	if(dscore>=21||pscore>=21)
	{
		if(dscore==21||pscore>21)
			cout << "Dealer has won. ";
		else 
			cout << "You have won! ";
		return true;
	}
	else
		return false;
	
	
}

/*
 * Name: deal(fromdeck, todeck, tocardindex)
 * Description: deals a card from the main deck to a player or dealer's deck
 * Args: 
 * 		fromdeck (char[]): the deck to grab the card from, must always be the same deck
 * 		todeck (char[]): the deck to put the card in, can change as long as tocardindex changes
 * 		tocardindex (int): a reference to an integer to store the index of the last card written to deck.
 */
void deal(char fromdeck[], char todeck[], int &tocardindex)
{
	static int topcard=0; 
	//increments after each card dealt
	todeck[tocardindex]=fromdeck[topcard];
	topcard++;
	tocardindex++;
}
//deal a card from a deck to a player

/*
 * Name: initdeck(deck)
 * Description: populates an empty card deck variable with a legal deck of cards
 * Args: deck (char[]): the deck to fill with cards
 */
void initdeck(char deck[])
{
	for(int i=0;i<DECKSIZE;i++)
	{
		deck[i]=0x00;
		deck[i]|=(i%13+1 ) & RANKBITS;
		deck[i]|=((char)(i/(DECKSIZE/4)) << 6 ) & SUITBITS;
	}


}
//initialize deck 

/*
 * Name: wipedeck(deck)
 * Description: Erases the contents of a card deck or hand
 * Args: deck (char[]): the deck or hand to reset
 */
void wipedeck(char deck[])
{
	for(int i=0;i<DECKSIZE;i++)
	{
		deck[i]=0x00;
	}
}

char suit(char card)
{
	return ((card&SUITBITS) >> 6)&0x03;
}
//returns the suit of a card

void shuffle(int numberOfTimes, char deck[])
{
	static int seedoffset=0; //incremented each time shuffle is called to prevent unshuffling
	char tempcard; //for swapping cards
	int i1; //random index of first card to swap
	int i2; //random index of second card to swap
	for(int i=0;i<numberOfTimes;i++) //run the specified number of times
	{
		srand(time(NULL)+seedoffset);
		i1=rand()%DECKSIZE;
		srand(i+seedoffset);
		i2=rand()%DECKSIZE;
		//generate two random numbers

		tempcard=deck[i2];
		deck[i2]=deck[i1];
		deck[i1]=tempcard;
		//swap the randomly selected cards
	} //repeat
	seedoffset++;
}
//shuffle the deck

void printcard(char card, string display[6])
{
	display[0] += " -------  ";
	//add the top edge of the card to our virtual screen
	
	char rankid[3] = "  ";

	switch(card&RANKBITS)
	{
		case RANK_ACE:
			rankid[0]='A';
			break;
		case 10:
			rankid[0]='1';
			rankid[1]='0';
			break;
		case RANK_JACK:
			rankid[0]='J';
			break;
		case RANK_QUEEN:
			rankid[0]='Q';
			break;
		case RANK_KING:
			rankid[0]='K';
			break;
		case 0:
			break; break;

		default:
			rankid[0]=(card&RANKBITS)-2+'2';
	}
	//determine the character to indicate card rank with
	
	display[1] += "|";   display[1] += rankid; display[1] += suits[suit(card)][0]; display[1] += "| ";
	display[2] += "|  "; display[2] += suits[suit(card)][1]; display[2] += "| ";
	display[3] += "|  "; display[3] += suits[suit(card)][2]; display[3] += "| ";
	display[4] += " -------  " ; //<< (int)(suit(card)) <<"\n";
	//add the rest of the card to the virtual screen
}
//add a card to the virtual display

void dumpscr(string screen[6])
{
	for(int i=0;i<6;i++)
	{
		cout << screen[i] << endl;
	}
}
//print the contents of the virtual display

void clear(string display[6])
{
	for(int i=0;i<6;i++)
	{
		display[i]=" ";
	}
}
//reset the virtual display

void printdeck(char deck[], string display[6])
{
	clear(display);
	int realdecksize=0;
	for(int i=0; i<DECKSIZE;i++)
	{
		if(deck[i]!=0)
			realdecksize++;
	}


	for(int i=0;i<realdecksize; i++)
	{
		printcard(deck[i], display);
		if(realdecksize>DECKSIZE/4 && i%(DECKSIZE/4)==DECKSIZE/4-1)
		{
			dumpscr(display);
			clear(display);
		}
	}

	if(realdecksize<=DECKSIZE/4)
	{
		dumpscr(display);
		clear(display);
	}
}
//print all cards in virtual deck
