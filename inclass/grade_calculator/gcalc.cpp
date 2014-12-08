/* CS 161 
 * In-class Assignment
 * Aaron Schraner
 * Grade calculator
 * 10-1-14
 * (this version happens to calculate averages and best/worst scores in real time.)
 */
#include <iostream>
using namespace std;
int main()
{
	int nofstudents;
	float avg;
	int bestScore=0, worstScore=1000, bestId=0, worstId=0;
	cout << "Hit Ctrl+C to exit." << endl;
	int i=0;
	while(true)
	{
		int cScore, cId;
		cout << "Student's ID number:\n> ";
		cin >> cId;
		cout << "Student " << cId << "'s test grade:\n>";
		cin >> cScore;
		if(cScore>bestScore)
		{
			bestScore=cScore;
			bestId=cId;
		}
		if(cScore<worstScore)
		{
			worstScore=cScore;
			worstId=cId;
		}
		avg = (avg * (i) + cScore) / (i+1);
		cout << "Current best score: " << bestScore << " (ID: " << bestId << ")" << endl;
		cout << "Current worst score: " << worstScore << " (ID: " << worstId << ")" << endl;
		cout << "Current average: " << avg << " (of " << i+1 << " students)"<< endl;
		i++;
	}
	return 0;
}
