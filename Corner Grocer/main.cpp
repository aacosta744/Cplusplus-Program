#include "GroceryTracker.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	GroceryTracker tracker;

	const string inputFile = "CS210_Project_Three_Input_File.txt";
	const string backupFile = "frequency.dat";

	tracker.LoadFile(inputFile);

	tracker.BackupFile(backupFile);

	int menuChoice = 0;

	cout << "Corner Grocer Item Tracker" << endl;
	cout << "==========================" << endl;

	while (menuChoice != 4)
	{
		cout << endl;
		cout << "1. Search for an item" << endl;
		cout << "2. Display all item frequencies" << endl;
		cout << "3. Display item frequency histofram" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your choice: ";

		if (!(cin >> menuChoice))
		{
			cout << "Invalid input. Please enter a number from 1 to 4."
				<< endl;

			cin.clear();
			cin.ignore(10000, '\n');

			continue;
		}

		switch (menuChoice)
		{
		case 1:
		{
			string itemName;

			cout << "Enter the item you wish to search for : ";
			cin >> itemName;

			int frequency = tracker.GetItemFrequency(itemName);

			cout << itemName << " was purchased "
				<< frequency << " time";

			if (frequency != 1)
			{
				cout << "s";
			}
			
			cout << "." << endl;
				
			break;
		}

		case 2:
			tracker.PrintAllItems();
			break;

		case 3:
			tracker.PrintHistogram();
			break;

		case 4:
			cout << endl;
			cout << "Thank you for using the Corner Grocer Item Tracker."
				<< endl;
			cout << "Program ending..." << endl;
			break;

		default:
			cout << "Invalid menu choice. Please enter a number from 1 to 4."
				<< endl;
			break;
		}
	}

	return 0;
}