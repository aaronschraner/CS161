/*===============
Program name: Rice bag calculator
Developer name: Aaron Schraner
Date: 10/08/2014
Purpose: Find how many bags are required to store a metric ton of rice.
===============*/
#include <iostream>
using namespace std;
const int METRIC_TON = 2205;
int main()
{
	unsigned long int pounds;
	int bags;
	cout << "How many pounds of rice do you want to store?\n> ";
	cin >> pounds;
	bags=pounds/METRIC_TON;
	if(pounds-bags*METRIC_TON > 0)
		bags++;

	cout << "at least " << bags << " metric ton bags are required to store " << pounds << " pounds of rice\n";
	return 0;
}
