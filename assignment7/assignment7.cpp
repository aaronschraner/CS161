/*====================================================
Program name: TimeFun
Developer name: Aaron Schraner
Date: 11/03/2014
Purpose: Practice with functions and pass-by-reference
======================================================*/
#include <iostream>
#include <iomanip>
#include <time.h>
#include <cstdlib>
using namespace std;


void convertTime24to12(int&,int&,string&);
void getTime24(int&, int&);
void printTime24(int,int);
void printTime12(int,int,string);
bool userWantsToContinue(string);
void getCurrentTime(int&,int&);


int main()
{
	int hours, minutes;
	string pm;
	char timesrc; //source of time to use (user or system clock)
	cout << "Do you want to [E]nter a time or use [C]urrent time? \n[E|C] > ";
	cin >> timesrc;
	switch(timesrc)
	{
		case 'E': //if the user wants to enter their own time
		case 'e':
			do
			{
				getTime24(hours, minutes);
				//ask them for a time

				printTime24(hours,minutes);
				//print the time they entered

				convertTime24to12(hours, minutes, pm);
				//convert the time they entered into 12-hour time

				printTime12(hours,minutes,pm);
				//print the 12 hour time.
			}
			while(userWantsToContinue("Would you like to convert more time?")); 
			//repeat until user wants to stop

			break;
		case 'C': //if the user wants to use the system time
		case 'c':
			cout << "Using current time.\n";
			//tell them what's going on

			getCurrentTime(hours,minutes);
			//get the current system time

			printTime24(hours,minutes);
			//print the time in 24 hour format

			convertTime24to12(hours, minutes, pm);
			//convert the 24 hour format time to 12 hour format

			printTime12(hours,minutes,pm);
			//print the result
			break;
			//exit
	}

}


void convertTime24to12(int &hours, int &minutes, string &pm)
{
	//convert 24 hour time to 12 hour time by reference
	
	if(hours>=12 )
	{
		pm=" PM";
	}
	else
	{
		pm=" AM";
	}
	hours=(hours+11)%12+1;
}

void getTime24(int &hours, int &minutes )
{
	//get a 24 hour time from the user
	
	char ch; //placeholder for colon
	cout << "Enter a 24 hour time. (Hours:Minutes)\n> ";
	cin >> hours >> ch >> minutes ;
}

void printTime24(int hours, int minutes)
{
	//print 24-hour format time
	cout << "24 hour time: " << hours << ":" << setfill('0') << setw(2) << minutes << endl;
}

void printTime12(int hours, int minutes, string pm)
{
	//print 12-hour format time
	cout << "12 hour time: " << hours << ":" << setfill('0') << setw(2) << minutes << pm << endl;
}

bool userWantsToContinue(string promptstr)
{
	//function to ask if user wants to continue
	
	char uinp; //User INPut

	bool hasResult, wantsToContinue;

	//be persistent if program recieves invalid input
	while(!hasResult)
	{
		cout << promptstr << "\n[Y|N]> ";
		//prompt with question
		
		cin >> uinp;
		//store answer
		
		switch(uinp)
		{
			case 'y':
			case 'Y':
				wantsToContinue=true;
				hasResult=true;
				break;
			case 'n':
			case 'N':
				wantsToContinue=false;
				hasResult=true;
				break;
			default:
				hasResult=false;
				cout << "Please type either Y or N followed by enter.\n> ";
				break;
		}
		//process user input
		
	}
	return wantsToContinue;
	//return result
}

void getCurrentTime(int &hours, int &minutes) 
{
	//pass the current system time by reference into hours and minutes
	time_t timer;
	time(&timer);
	struct tm *tm_struct = localtime(&timer);
	hours=tm_struct->tm_hour;
	minutes=tm_struct->tm_min;
}
