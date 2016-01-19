#include <ctime>
#include <cctype>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include "Game.h"
using namespace std;

const void displayChrono()
{
	time_t now;
	struct tm info;
	time(&now);
	localtime_s(&info, &now);

	cout << "Date: " << (info.tm_mon + 1) << "/" << info.tm_mday << "/" << (info.tm_year + 1900) << endl;
}

const void displayRules()
{
	cout << "\nEnter numbers 1 through 9 to select a position\n";
	cout << "\n 1  2  3\n 4  5  6\n 7  8  9";
}

bool continueGame()
{
	while (true)
	{
		string input;

		cout << "Play again, (y)es or (n)o? ";
		cin >> input;
		
		if (input != "y" || input != "Y" || input != "n" || input != "N")
		{
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
		if (input == "y" || input == "Y")
		{
			return true;
		}
		if (input != "n" || input != "N")
		{
			return false;
		}
	}
}

int main()
{
	displayChrono();
	displayRules();
	cout << endl;

	try{
		Game g;
		do
		{
			g.setGame();
		} while (continueGame());
	}
	catch (invalid_argument &e)
	{
		cout << "\nException: " << e.what() << endl;
	}

	cout << endl;
	system("PAUSE");
	return 0;
}