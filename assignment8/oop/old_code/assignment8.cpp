/*====================================================================
Program name: Card Fun V2
Developer name: Aaron Schraner
Date: 11/24/2014
Purpose: To create and shuffle a card deck (version 2: object vectors)
======================================================================*/
#include <iostream>
#include <time.h>
#include <vector>
//suit definitions
#define SUIT_CLUBS 0x00
#define SUIT_DIAMONDS 0x20
#define SUIT_HEARTS 0x40
#define SUIT_SPADES 0x60
//rank definitions
#define RANK_ACE 0x01
#define RANK_JACK 0x0B
#define RANK_QUEEN 0x0C
#define RANK_KING 0x0D
//bit access holders
#define RANKBITS 0x0F // b00001111
#define SUITBITS 0x60 // b00110000
//other constants
#define SHUFFLE_THOROUGHNESS 10000

using namespace std;
//Card class
//for cards
class Card
{
	public:
		char suitAA[4][3][6] = {
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
		char suit; //card suit 
		char rank; //card rank
		bool hidden=false;

		/*
		 * Name: init(suit,rank)
		 * Purpose: populate the card's suit and rank with the specified arguments
		 */
		void init(char suit,char rank)
		{
			this->suit=suit;
			this->rank=rank;
		}

		/*
		 * Name: fromChar(oldchar)
		 * Purpose: populate the card from an 8-bit format card
		 * Provided for compatibility with older version, deprecated
		 */
		void fromChar(char oldchar)
		{
			suit=oldchar&SUITBITS;
			rank=oldchar&RANKBITS;
		}

		/*
		 * Name: getrank()
		 * Purpose: Get character to represent rank of card
		 * A: Ace
		 * X: 10
		 * J: Jack
		 * Q: Queen
		 * K: King
		 */
		char getrank()
		{
			switch(rank)
			{
				case RANK_ACE:
					return 'A';
					break;
				case 10:
					return 'X';
					break;
				case RANK_JACK:
					return 'J';
					break;
				case RANK_QUEEN:
					return 'Q';
					break;
				case RANK_KING:
					return 'K';
					break;
				default:
					return rank + '0';
					break;
			}
		}

		/*
		 * Name: toString()
		 * Purpose: return a string format version of the card
		 * Used for simple printing
		 */
		string toString()
		{
			string result="[";
			switch(suit)
			{
				case SUIT_CLUBS:
					result+="C";
					break;
				case SUIT_DIAMONDS:
					result+="D";
					break;
				case SUIT_HEARTS:
					result+="H";
					break;
				case SUIT_SPADES:
					result+="S";
					break;
			}
			result += getrank();
			result += "]";
			if(hidden)
				result="[--]";

			return result;
		}

		/*
		 * Name: toChar()
		 * Purpose: return an 8-bit format copy of the card
		 * Provided for compatibility with older versions, deprecated
		 */
		char toChar()
		{
			return suit|rank;
		}

		/*
		 * Name: addAAto(display[])
		 * Purpose: append the card's ASCII art to a virtual display (string array)
		 */
		void addAAto(string display[])
		{
			if(!hidden)
			{
				display[0] += " -------  ";
				if(getrank()=='X')
				{
					display[1] += "|10";
					display[1] += suitAA[(int)(suit>>6)][0];
					display[1] += "| ";
				}
				else
				{
					display[1] += "|";
					display[1] += getrank();
					display[1] += " ";
					display[1] += suitAA[(int)(suit>>6)][0];
					display[1] += "| ";
				}
				display[2] += "|  "; 
				display[2] += suitAA[(int)(suit>>6)][1];
				display[2] += "| ";

				display[3] += "|  "; 
				display[3] += suitAA[(int)(suit>>6)][2];
				display[3] += "| ";
				display[4] += " -------  ";
			}
			else
			{
				display[0] += " -------  ";
				display[1] += "|--/////| ";
				display[2] += "|///////| ";
				display[3] += "|///////| ";
				display[4] += " -------  ";
			}
		}
};

/*
 * Name: Deck
 * Purpose: is a sort of wrapper for a vector of Cards.
 * Has built-in functions for appending, dealing, filling with 52-card standard deck, printing, shuffling, etc.
 */
class Deck
{
	public:
		
		//vector of cards to manipulate
		vector<Card> cards;

		/*
		 * Name: addCard(card)
		 * Purpose: append the specified card to the deck
		 */
		void addCard(Card card)
		{
			cards.push_back(card);
		}

		/*
		 * Name: init()
		 * Purpose: fill cards with empty data
		 * Not really used but it's there.
		 */
		void init()
		{
			for ( Card card : cards)
			{
				card.init(0,0);
			}
		}

		/*
		 * Name: populate52()
		 * Purpose: Add a 52-card standard deck to this deck
		 */
		void populate52()
		{
			for(int i=0;i<52;i++)
			{
				Card newCard;
				newCard.init(i/13*SUIT_DIAMONDS,i%13+1);
				addCard(newCard);
			}
		}
		
		/*
		 * Name: print()
		 * Purpose: display the deck in a plain format
		 * (no ascii art)
		 */
		void print()
		{
			int i=0;
			for (Card card : cards)
			{
				if(i%13==0)
					cout << endl;
				cout << card.toString() << " ";
				i++;
			}
			cout << endl;
		}

		/*
		 * Name: shuffle()
		 * Purpose: shuffle the cards
		 * Uses SHUFFLE_THOROUGHNESS to determine how many times the algorithm should run
		 * 10,000 seems to work well.
		 */
		void shuffle()
		{
			static int seedoffset=0;
			for(int x=0;x<SHUFFLE_THOROUGHNESS;x++)
			{
				Card tempcard;
				int i1;
				int i2;

				srand(time(NULL)+seedoffset);
				i1=rand()%52;
				srand(x+seedoffset);
				i2=rand()%52;
				//generate two random numbers

				tempcard=cards[i2];
				cards[i2]=cards[i1];
				cards[i1]=tempcard;
			}
		}

		/*
		 * Name: deal(toDeck)
		 * Purpose: move a card from this deck to another deck (toDeck) 
		 * Removes the top card in this deck and puts it on top of toDeck.
		 */
		void deal(Deck &toDeck)
		{
			Card sharecard;
			sharecard=cards.back();
			toDeck.addCard(sharecard);
			cards.pop_back();
		}

		/*
		 * Name: printAA()
		 * Purpose: print the deck in Ascii art
		 * card characters don't work on my Linux setup
		 */
		void printAA()
		{
			string display[6];

			for (unsigned int i=0;i<cards.size();i++)
			{
				cards[i].addAAto(display);
				if(i%8==7)
				{
					for(int x=0;x<6;x++)
					{
						cout << display[x] << endl;
						display[x]="";
					}
				}
			}
		}

		void setHidden(int index, bool hidden)
		{
			cards[index].hidden=hidden;
		}
};
//Many of these methods will not be useful until we make an actual game.

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
	gameDeck.print();
	//print the unshuffled deck
	
	cout << endl << "Shuffled deck:" << endl;
	gameDeck.shuffle();
	gameDeck.setHidden(0,true);
	//shuffle the deck
	
	gameDeck.print();
#ifdef AA
	//print the shuffled deck
	gameDeck.printAA();
#endif
	return 0;
}
