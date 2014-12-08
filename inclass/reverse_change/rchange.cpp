/*===============
Program name: Change calculator
Developer name: Aaron Schraner
Date: 10/06/2014
Purpose: Take a list of coin counts and get
the total change.
===============*/
#include <iostream>
using namespace std;
int main()
{
	//print some program information
	cout << "This program finds total cash from how many dollars,\n\
 quarters, dimes, nickels, and pennies you input.\n";
	//create the variables to store change amounts
	int dollars, quarters, dimes, nickels, pennies;
	//prompt for and store all required coin counts
	cout << "How many dollars? \n> ";
	cin >> dollars;
	cout << "How many quarters? \n> ";
	cin >> quarters;
	cout << "How many dimes? \n> ";
	cin >> dimes;
	cout << "How many nickels? \n> ";
	cin >> nickels;
	cout << "How many pennies? \n> ";
	cin >> pennies;
	//calculate and print the total
	int totalCents = dollars*100 + quarters*25 + dimes*10 + nickels*5 + pennies;
	cout << "Total: $" << totalCents/100 << "." << totalCents%100 << endl;
	return 0;
}
