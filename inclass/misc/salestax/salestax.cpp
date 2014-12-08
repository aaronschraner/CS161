/*===============
Program name: Tax calculator
Developer name: Aaron Schraner
Date: 10/08/2014
Purpose: Calculates sales tax for items outside of Oregon
===============*/
#include <iostream>
#include <iomanip>
using namespace std;
const float tax=0.05; //tax factor
int main()
{
	float initcost; //initial cost
	cout << "List cost? \n>"; //prompt for initial cost
	cin >> initcost; //store input
	cout << "Adjusted cost: $" << fixed << setprecision(2) << initcost * (tax+1)  << " (with sales tax of " << tax*100 <<  "%)\n"; //print adjusted cost
	return 0;
}
