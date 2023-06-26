#ifndef GROCERYRECORDS_H
#define GROCERYRECORDS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <map>

using namespace std;
void DisplayMenu();

// Validating input function
int validateInt(int& input);
string validateString(string& input);

class GroceryRecords{
	public:
		// Acts as a way to intialize map with data from file
		void InputRecords();
		// Outputs a record to a file as a fail-safe for emergencies
		void OutputRecordsToFile();

		// Prints the item and the frequency like OutputRecordsToFile but to the console
		void OutputRecords();
		//Prints the item and the frequency with astriks
		void OutputRecordsHisto();
		
		// Gets the frequency of an item
		int GetValue(string key);

	private:
		map<string, int> records;
		ifstream inFS;
		ofstream outFS;
};

#endif