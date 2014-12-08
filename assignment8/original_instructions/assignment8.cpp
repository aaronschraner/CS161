/*========================================
Program name: Card fun
Developer name: Aaron Schraner
Date: 11/24/2014
Purpose: Create and shuffle a 52 card deck
(this version is closest to the original 
instructions and best documented)
==========================================*/
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void shuffle(char[], int);
void fill(char[52]);
void print(char[]);

/*
 * Main loop
 * Procedure:
 * 1. Declare a deck of 52 cards
 * 2. Populate it with a standard set of cards
 * 3. Shuffle the deck
 * 4. Print the shuffled deck
 */
int main()
{
	char deck[52];
	//declare deck
	
	fill(deck);
	//populate with standard cards
	
	cout << "Unshuffled deck:\n";
	print(deck);
	cout << endl;
	//print unshuffled deck
	
	cout << "Shuffled deck:\n";
	shuffle(deck,10000);
	print(deck);
	cout << endl;
	//print shuffled deck
}

/*
 * Name: fill(deck)
 * Purpose: populate a deck with the standard set of cards
 * (Ace,1-10,J,Q,K | Clubs, diamonds, hearts, spades)
 * Params:
 * deck (char[52]) - the deck to populate
 */
void fill(char deck[52])
{
	for(int i=0;i<52;i++) //iterate 0-51
	{
		deck[i]=(i/13 * 0x40)|(char)((i%13+1)&0x0F); 
		//suit bits are equal to i/13
		//rank bits are equal to i%13+1
	}
}

/*
 * Name: shuffle(deck,numberOfTimes)
 * Purpose: shuffle a card deck by running an algorithm a given number of times
 * Params:
 * deck (char[]) - the deck to shuffle
 * numberOfTimes (int) - the number of times to run the shuffling algorithm
 */
void shuffle(char deck[], int numberOfTimes)
{
	static int seedoffset=0;
	//increments each time shuffle is called
	//to allow for rapid reshuffling
	
	int i1,i2;
	//card indeces to swap
	
	char tempcard;
	//holds card for swapping
	
	for(int i=0;i<numberOfTimes;i++)
	{
		srand(time(NULL)+seedoffset);
		i1=rand()%52;
		//select the first random index

		srand(time(NULL)+i+seedoffset);
		i2=rand()%52;
		//select the second random index

		tempcard=deck[i1];
		deck[i1]=deck[i2];
		deck[i2]=tempcard;
		//swap the selected cards
	}
	seedoffset++;
	//increment the seed offset
}

/*
 * Name: print(deck)
 * Purpose: print a deck of card using cout (windows compatible version)
 * Params:
 * deck (char[]) - the deck to print
 */
void print(char deck[])
{
	char suit;
	//character to represent suit
	//(uses windows native card characters)
	
	string rank="";
	//string to represent rank
	
	for(int i=0;i<52;i++)
	{
		suit=(char)(((deck[i]&0xC0)/0x40))+3;
		//set the suit

		switch(deck[i]&0x0F)
		{
			case 1:
				rank="A";
				break;
			case 11:
				rank="J";
				break;
			case 12:
				rank="Q";
				break;
			case 13:
				rank="K";
				break;
			case 10:
				rank="10";
				break;
			default:
				rank=(char)('0' + (deck[i]&0x0F));
				break;
		}
		//set the rank

		cout << "[" << rank << suit << "] ";
		//print the card's rank and suit
	}
}

