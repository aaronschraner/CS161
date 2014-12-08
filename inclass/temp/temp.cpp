/*===========================================================================================
Program name: Temp calc
Developer name: Aaron Schraner
Date: 10/13/2014
Purpose: Convert temperature in fahrenheit to Celsius and Kelvin and display in a nice format
=============================================================================================*/
#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
	string fullName; //name of user
	float degF, degC, degK; //degrees Fahrenheit, Celsius, Kelvin
	
	cout << "What is your full name? \n> "; 
	//get user name
	
	getline(cin,fullName);
	cout << "Conversion requested by " << fullName << endl;
	cout << "What temperature would you like to convert? (in Fahrenheit)\n> ";
	//get requested temperature to convert
	
	cin >> degF;
	degC = (degF - 32) * 5 / 9;
	degK = degC + 273.15;
	//calculate temperatures
	
	cout << fixed << setprecision(2);
	//set float formatting
	
	cout << degF << " degrees Fahrenheit is equal to:\n\t";
	cout << degC << " degrees Celsius\n\t";
	cout << degK << " degrees Kelvin\n\n";
	//print results

	cout << "Have a nice day, " << fullName << ".\n";
	cout << "Press Enter to continue...";
	
	//wait for exit
	cin.ignore();
	cin.get();
}

