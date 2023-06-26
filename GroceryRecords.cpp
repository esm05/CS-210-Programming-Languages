#include "GroceryRecords.h"

void GroceryRecords::InputRecords()
{
	string item; //variable for file input
	// Open input file into project to be able to read information
	inFS.open("CS210_Project_Three_Input_File.txt");
	// Check if files are open

	if (!(inFS.is_open())) {
		cout << "Could not open CS210_Project_Three_Input_File.txt" << endl;
		exit(-1);
	}
	else {
		// fail() checks if the apprioate data type was passed through the stream
		// maps are automatically sorted with a built-in function
		while (!inFS.fail()) {
			inFS >> item;

			// Check if key exists if it doesn't intailize item to 1
			if (records.count(item) == 0) records.emplace(item, 1);
			
			// If it does exist increment 1 to item
			else records.at(item) += 1;
		}
	}
	// Close file 
	inFS.close();
}
void GroceryRecords::OutputRecordsToFile()
{
	// Open output file for data collection
	outFS.open("frequency.dat");
	if (!(outFS.is_open())) {
		cout << "Could not open frequency.dat" << endl;
		exit(-1);
	}
	else {
		// Output frequencies to file
		for (auto i = records.begin(); i != records.end(); i++) {
			outFS << i->first << " " << i->second << endl;
		}
	}
	// Closing file
	outFS.close();
}

void GroceryRecords::OutputRecords()
{
	for (auto i = records.begin(); i != records.end(); i++) {
		cout << i->first << " " << i->second << endl;
	}
}



void GroceryRecords::OutputRecordsHisto()
{
	// Let user enter what the histogram looks like 
	char user_char;
	cout << "Choose character to represent histogram" << endl;
	cin >> user_char;
	cout << endl;

	for (auto i = records.begin(); i != records.end(); i++) {
		cout << i->first << " ";
		for (int j = 0; j <= i->second; j++) {
			cout << user_char;
		}
		cout << endl;
	}
}



int GroceryRecords::GetValue(string key)
{
	while (records.count(key) == 0) {
		cout << "This item does not match our records. Enter another value." << endl;
		validateString(key);
	}
	return records.at(key);
}

void DisplayMenu()
{
	// Menu display for the user
	cout << setw(84) << setfill('*') << "" << endl;
	cout 
		<< "  Choose from one of these four options:" << endl
		<< "  1. Input an item and the frequency will be displayed" << endl
		<< "  2. List of items will be displayed with the frequency" << endl
		<< "  3. List of items will be displayed with the frequency represented by a histogram" << endl
		<< "  4. exit" << endl;
	cout << setw(84) << "" << endl;
}

int validateInt(int& input)
{
	cout << "Enter a number between 1-4" << endl;
	while (true) {
		try {
			cin >> input;
			if (input <= 0 || input > 4) {
				throw runtime_error("Invalid input try again. Enter 1 - 4");
			}
			else {
				cin.clear();
				cin.ignore(1234, '\n');
				cout << endl;
				return input;
			}
		}
		// If user enters a string
		catch (ios_base::failure& e) {
			cout << "Invlaid input try entering a number between 1 - 4" << endl;
			cin.clear();
			cin.ignore(123, '\n');
			
		}
		// If it does not match the parameters of the input 
		catch (runtime_error& e) {
			cout << "Invalid input try enter a number between 1 - 4" << endl;
			cin.clear();
			cin.ignore(123, '\n');
			
		}
	}
}

string validateString(string& input)
{
	// Validates user input to just be one word and not a number
	getline(cin, input);
	size_t index = input.find(" "); // Have to use size_t because npos is of type size_t

	// If not matches are found then find returns npos and checks if the first char is a number or special char
	while (index != string::npos || !(isalpha(input.at(0)))) {
		cout << "Enter a valid string with no spaces!" << endl;
		getline(cin, input);
		size_t index = input.find(" ");
	}
	return input;
}
