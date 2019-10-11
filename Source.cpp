/* Gustavo Nomura
   C++ Fall 2019
   Due data:
   Lab 4 Temperature output


	Description: Design and write a C++ program that inputs a series of hourly temperature
from a file, and outputs a bar chart (using stars) of the temperatures for the day. The
temperature should be printed to the left of the corresponding bar, and there should be
a heading that gives the scale of the chart. The range of temperatures should be from
-30 to 120. Because it is hard to display 150 characters on the screen, you should have
each star represent a range of 3 degrees. That way, the bars will be at most 50
characters wide. Use meaningful variable names, proper indentation, and appropriate
comments. Thoroughly test the program using your own data sets. Make sure to vet the
values from the input file.

*/


#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

void printPositiveTemperature(int stars, float temperature)
{
	int s;
	cout << setw(5) << temperature << setw(20) << '|';
	for (s = 0; s < stars; s++)
	{
		cout << "*";
	}
	cout << endl;
}

void printNegativeTemperature(int stars, float temperature)
{
	int s;
	cout << setw(5) << temperature << setw(20 + (stars));
	for (s = 0; s > stars; s--)
	{
		cout << "*";
	}
	cout << '|' << endl;
}

int main()
{
	int counter, s;
	float temperature;
	float stars;
	int pos;
	

	string inputDataName = "temperature.dat";
	ifstream inData;
	inData.open(inputDataName);

	if (!inData)
	{
		cout << "invalid file";
			return 1;
	}

		cout << "Temperature for 24 hours: " << endl;
		cout << "          30          0          60          90          120          " << endl;
		for (counter = 0; counter < 24; counter++)
		{
			inData >> temperature;
			if ((temperature < -30) || (temperature > 120))
			{
				cout << "invalid" << endl;
				continue;
			}
			stars = round((temperature / 3));
			if (stars > 0)
			{
				printPositiveTemperature(stars, temperature);
			}
			else
			{
				printNegativeTemperature(stars, temperature);
			}
			
		}
		
	
	inData.close();

	return 0;
}



