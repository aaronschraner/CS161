/*===============================================
Program name: CardSuperFun
Developer name: Aaron Schraner
Date: 11/03/2014
Purpose: A C++ implementation of the card game 21
=================================================*/
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

void shuffle(int);
void printcard(char);
void dumpscr(string[6]);
void clear();
void printdeck();

int main()
{
	cout << "Unshuffled:\n";
	printdeck();
	shuffle(1000);
	cout << "Shuffled:\n";
	printdeck();
	cin.get();
}
string display[6];
char deck[] = {
	0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, //Clubs
	0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, //Diamonds
	0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, //Hearts
	0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD};//Spades

void printcard(char);

char suit(char card)
{
	return ((card&SUITBITS) >> 6)&0x03;
}

void shuffle(int numberOfTimes)
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

void printcard(char card)
{
	/*switch(card&SUITBITS)
	{
		case SUIT_CLUBS:
			cout << "--Clubs\n";
			break;
		case SUIT_DIAMONDS:
			cout << "--Diamonds\n";
			break;
		case SUIT_HEARTS:
			cout << "--Hearts\n";
			break;
		case SUIT_SPADES:
			cout << "--Spades\n";
			break;
	}*/
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
	display[1] += "|";   display[1] += rankid; display[1] += suits[suit(card)][0]; display[1] += "| ";
	display[2] += "|  "; display[2] += suits[suit(card)][1]; display[2] += "| ";
	display[3] += "|  "; display[3] += suits[suit(card)][2]; display[3] += "| ";
	//cout << "|  "<< suits[suit(card)][1] << "|\n";
	//cout << "|  "<< suits[suit(card)][2] << "|\n";
	display[4] += " -------  " ; //<< (int)(suit(card)) <<"\n";
}

void dumpscr(string screen[6])
{
	for(int i=0;i<6;i++)
	{
		cout << screen[i] << endl;
	}
}

void clear()
{
	for(int i=0;i<6;i++)
	{
		display[i]=" ";
	}
}
void printdeck()
{
	clear();
	for(int i=0; i<DECKSIZE;i++)
	{
		printcard(deck[i] );
		if(i%(DECKSIZE/4)==DECKSIZE/4-1)
		{
			dumpscr(display);
			clear();
		}
	}
}


