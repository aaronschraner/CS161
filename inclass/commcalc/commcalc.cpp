/*Commission calculator
 * Created by Aaron Schraner
 * 11/12/2014
 */
#include <iostream>
using namespace std;
/*
 * Name: commcalc(gross,commissionpercent)
 * Description: calculates commission for an expense
 * Args:
 * Returns:
 * 		calculated total with commission (float)
 */
double commcalc(double sales, double& commission)
{
	double paychecktotal=0;
	if ( sales > 5000 )
	{
		commission = sales * 0.1;
	}
	else
		commission = 0;
	paychecktotal = commission + 500;

}



//main 
int main()
{
	int rawsales=5001*100;
	cout << "Total: " << commcalc(rawsales)/100 << " dollars\n";
}
