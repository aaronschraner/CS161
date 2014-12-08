/* CS 161 
 * Assignment 3
 * Aaron Schraner
 * Geometry Fun pt. 2
 * 10-1-14
 * Developed using Vim + G++ on Arch Linux 
 */
#include <math.h>
#include <iomanip>
#include <iostream>
using namespace std;

const float PI=3.14159;//declare Pi. 


//float polyArea(int sides, int sidelength) //will eventually return area of a regular polygon
//{ 
//}
int main()
{
	cout << fixed << setprecision(3);
	int number; //to store user input
	char indent = '\t'; //6 spaces
	cout << "Please enter a positive whole number." << endl << "> "; //prompt for input
	cin >> number;//read user input
	int sperimeter = number*4; //declare square perimeter
	int sarea = number*number; //declate square area
	////Begin square////
	cout << "A square with side length of " << number << endl; //print side length
	cout << indent << "has a perimeter of " << sperimeter << endl; //print perimeter
	cout << indent << "has an area of " << sarea << endl; //print area
	cout << endl << endl; //add some space between square and circle
	////Begin circle////
	float cradius = number/2; //declare circle radius
	float cperimeter = number * PI; //declare circle perimeter
	float carea = pow(number/2,2) * PI; //declare circle area
	cout << "A circle with a diameter of " << number << endl; //print diameter
	cout << indent << "has a radius of " << cradius << endl; //print radius
	cout << indent << "has a perimeter of " << cperimeter << endl; //print perimeter
	cout << indent << "has an area of " << carea << endl; //print area
	int tperimeter=number*3; //declare triangle perimeter
	float tarea=(number/2) * (sqrt((pow(number,2) - pow(number/2,2)))); //declare triangle area
	cout << endl << endl; //add some space for clarity
	////Begin triangle////
	cout << "An equilateral triangle with side length " << number << endl; //print side length
	cout << indent << "has a perimeter of " << tperimeter << endl; //print perimeter
	cout << indent << "has an area of " << tarea << endl; //print area
	cout << "\nPress enter to close.\n";
	cin.ignore();
	cin.get();
	return 0;

}
