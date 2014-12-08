/*===================================
Program name: FunFun
Developer name: Aaron Schraner
Date: 11/03/2014
Purpose: To mess with some functions.
=====================================*/

#include <iostream>
#include <cmath>
using namespace std;

int getInteger(int,int);
void printRangeAndAvg(int,int);
void printBox(int,int);
void printWedge(int);

int main()
{
	int boxW, boxH; //declare box width and height variables

	cout << "Please enter a box height between 3 and 10 (inclusive)\n> "; //prompt for height

	boxH=getInteger(3,10); //get width from user

	cout << "Please enter a box width between " << boxH << " and 20.\n> "; //prompt for width

	boxW=getInteger(boxH,20); //get height from user

	cout << "Thank you.\n"; //thank user for being cooperative.

	printBox(boxH, boxW);

	printWedge(boxH);
	return 0;

}

int getInteger(int low, int high) //get a number from the user between two values.
{
	int result=0;
	while(result>high||result<low)
	{
		cin >> result;
		if(result < low)
			cout << "Please enter a number greater than or equal to " << low << ".\n> ";
		else if(result > high)
			cout << "Please enter a number less than or equal to "<< high << ".\n> ";
	}
	//ensure number is within range
	
	return result;
}

void printRangeAndAvg(int low, int high) //print the integers between and mean of two numbers
{
	cout << "Numbers between " << low << " and " << high << " are: \n";

	for(int i=low;i<=high;i++)
	{
		cout << i << " ";

	}
	//print a space separated list of numbers between the 
	//box width and height. 

	float mean=(low+high)/2.0; //calculate mean of numbers between h and w (efficiently)
	cout << "\nMean: " << mean << endl;
}

void printBox(int height, int width) //print a hollow box of asterisks (*)
{
	for(int y=0;y<height;y++) //iterate a Y coordinate variable from 0 to the box height - 1
	{
		for(int x=0;x<width;x++) //iterate an X coordinate from 0 to box width - 1 
		{
			if(x==width-1||x==0||y==height-1||y==0) 
			{
				cout << "*";
			}//put a * if the current coordinate is on an "edge" of the rectangle,
			else
			{
				cout << " "; //otherwise put a blank space
			}
		}
		cout << endl; //go to the next line
	} //print a box with the specified width and height
}

void printWedge(int height) //print a pyramid of asterisks
{
	for(int n=0; n<=height; n++) //to store Y position in triangle
	{
		for(int x=1;x<=n;x++) //to store X position in triengle
		{
			cout << "##";
		}
		cout << "\n";
	}
	cout << endl;
}
