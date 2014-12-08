/* CS 161 
 * Assignment 1
 * Aaron Schraner
 * Pizza cost and furniture markup calculator
 * 10-1-14
 * Developed using Vim + G++ on Arch Linux
 */

#include <iostream> //for cout
#include <math.h> //for Pi
using namespace std;
float getPricePerSqInch(float radius, float cost)
{
	//find the cost per  sq. inch of a pizza
	return (cost/(radius*radius*M_PI));
}
int sellingPrice(int cost) //find markup "sale" price of furniture
{
	return cost*1.8*9/10;
}
int main() //test algorithms
{
	cout << getPricePerSqInch(10, 30) << endl;
	cout << sellingPrice(100) << endl;
	return 0;
}
