#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	//create an output file
	//instantiate the output filestream object
	ofstream outputFile;
	//open the output filestream object
	//and specify a name for the text file
	outputFile.open("SuperCreativeFilename.txt");

	//create the output using the insertion operator
	outputFile << "Woohoo - this is friggin awesome!" << endl;
	outputFile << "free crap 4 u" << endl;
	//close the output filestream object
	outputFile.close();
}

