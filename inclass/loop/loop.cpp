#include <iostream>
using namespace std;
int main()
{
	int n=0;
	while(n<=100)
	{
		cout << n << "\n";
		n+=2;
	}
	cout << "Now for the other ones.\n";
	n=10;
	while(n>0)
	{
		cout << n << "\n";
		n--;
	}
	return 0;
}
