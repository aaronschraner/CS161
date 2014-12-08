#include <iostream>
#include <cstdlib>
#include <time.h>
#include "libcards.h"
using namespace std;

char clr[]={0x1b, 0x5b, 0x48, 0x1b, 0x5b, 0x32, 0x4a}; //clears the terminal when printed

int main() //main loop
{
	string display[6]; //virtual display to print cards on

	//initialize game elements//
	char deck[DECKSIZE],playerdeck[DECKSIZE], dealerdeck[DECKSIZE];
	int dealerindex=0, playerindex=0; //holds current write position in card array
	initdeck(deck);
	shuffle(10000,deck);
	wipedeck(playerdeck);
	wipedeck(dealerdeck);
	//declare some decks for player, dealer, and card deck
	
	cout << clr;
	cout << "Dealing cards...\n";
	deal(deck,playerdeck,playerindex);
	char dodeal = 'n';
	bool breakloop=false;

	do{
		cout << "New player deck\n";
		printdeck(playerdeck,display);
		cout << "Player score: " << getscore(playerdeck) << endl;
		cout << "Would you like another card? (y/n)\n> ";
		cin >> dodeal;
		if(dodeal=='y'||dodeal=='Y')
		{
			deal(deck,playerdeck,playerindex);
		}
		else
			breakloop=true;
		cout << clr;
	}
	while(!(haswinner(playerdeck,dealerdeck)||breakloop));
	cout << "Final deck:\n";
	printdeck(playerdeck, display);
	cout << "player score: " << getscore(playerdeck) << endl;
	if(getscore(playerdeck)==21)
	{
		cout << "You win!\n";
		return 0;
	}
	else if(getscore(playerdeck)>21)
	{
		cout << "Too high! Dealer wins by default.\n";
		return 0;
	}
	cout << "Dealer's turn. \n";
	while(getscore(dealerdeck)<15 && getscore(dealerdeck)<getscore(playerdeck))
		deal(deck,dealerdeck,dealerindex);
	cout << "Dealer score: " << getscore(dealerdeck) << endl;
	cout << "Dealer's hand: \n";
	printdeck(dealerdeck, display);
	if(getscore(dealerdeck)<getscore(playerdeck) || getscore(dealerdeck) > 21)
		cout << "You have won!";
	else if(getscore(dealerdeck)>getscore(playerdeck))
		cout << "The dealer has won.";
	else
		cout << "It's a tie!";
	cout << endl;
	cout << "Thanks for playing!\n";
}

