/*===============
Program name: Time calc
Developer name: Aaron Schraner
Date: 10/08/2014
Purpose: Converts time in milliseconds to days, hours, minutes, seconds, and remaining milliseconds.
===============*/
#include <iostream>
using namespace std;
const int SECOND=1000; //second definition
const unsigned int MINUTE=SECOND*60; //minute definition
const unsigned long HOUR=MINUTE*60; //hour definition
const unsigned long DAY=HOUR*24; //day definition
//all definitions in MS.

int main()
{
	unsigned long millis; //number of milliseconds to convert
	cout << "Enter time in milliseconds.\n> "; //prompt for number of MS to convert
	cin >> millis; //read number of milliseconds
	int days, hours, minutes, seconds, remMS; //declare variables to store converted times
	days  =  millis/DAY; //calculate days
	hours =  (millis%DAY)/HOUR; //calculate hours
	minutes= (millis%HOUR)/MINUTE; //calculate minutes
	seconds= (millis%MINUTE)/SECOND; //calculate seconds
	remMS  = millis%SECOND; //calculate remainder
	cout << millis << " milliseconds is equal to:\n"; //print result
	cout <<  "\t"  << days   << " days, \n";
	cout <<  "\t"  << hours  << " hours, \n";
	cout <<  "\t"  << minutes<< " minutes, \n";
	cout <<  "\t"  << seconds<< " seconds, \n";
	cout <<  "\t"  << remMS  << " milliseconds, \n";
	return 0;
}

