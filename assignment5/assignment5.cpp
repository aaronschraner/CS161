/*=============================
Program name: Loop Fun
Developer name: Aaron Schraner
Date: 10/27/2014
Purpose: Draw a box and pyramid
===============================*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int boxW, boxH; //declare box width and height variables

	cout << "Please enter a box height between 3 and 10 (inclusive)\n> "; //prompt for height

	while(boxH>10||boxH<3)
	{
		cin >> boxH;
		if(boxH < 3)
			cout << "Please enter a number greater than or equal to 3.\n> ";
		else if(boxH > 10)
			cout << "Please enter a number less than or equal to 10.\n> ";
	}
	//ensure user enters a valid height

	cout << "Please enter a box width between " << boxH << " and 20.\n> "; //prompt for width

	while(boxW>20||boxW<boxH)
	{
		cin >> boxW;
		if(boxW < boxH)
			cout << "Please enter a number greater than or equal to " << boxH << ".\n> ";
		else if(boxH > 20)
			cout << "Please enter a number less than or equal to 20.\n> ";
	}
	//ensure user enters a valid width
	cout << "Thank you.\n"; //thank user for being cooperative.
	cout << "Numbers between " << boxH << " and " << boxW << " are: \n";

	for(int i=boxH;i<=boxW;i++)
	{
		cout << i << " ";

	}
	//print a space separated list of numbers between the 
	//box width and height. 

	float mean=(boxH+boxW)/2.0; //calculate mean of numbers between h and w (efficiently)
	cout << "\nMean: " << mean << endl;

	for(int y=0;y<boxH;y++) //iterate a Y coordinate variable from 0 to the box height - 1
	{
		for(int x=0;x<boxW;x++) //iterate an X coordinate from 0 to box width - 1 
		{
			if(x==boxW-1||x==0||y==boxH-1||y==0) 
			{
				cout << "*";
			}//if the current coordinate is on an "edge" of the rectangle,
			//put a * character to indicate it.
			else
			{
				cout << " "; //otherwise put a blank space
			}
		}
		cout << endl; //go to the next line

	} //print a box with the specified width and height
	for(int n=0; n<=boxH; n++) //to store Y position in triangle
	{
		for(int x=1;x<=n*2;x++) //to store X position in triengle
		{
			cout << "#";
		}
		cout << "\n";
	}
	cout << endl;

	cin.ignore();
	cin.get();

	return 0;

}
