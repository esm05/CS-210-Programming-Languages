#include "GroceryRecords.h"

int main() {
	int input;
	string item;
	GroceryRecords list;
	
	// Set exception mask for cin stream
	cin.exceptions(ios::failbit);

	list.InputRecords();
	list.OutputRecordsToFile();
	// Display menu to user
	DisplayMenu();
	validateInt(input);

	while (input != 4) {
		switch (input) {
			case 1:
				cout << "What item would you like to search?:" << endl;
				validateString(item);
				cout << "There are " << list.GetValue(item) << endl;
				break;
			case 2:
				list.OutputRecords();
				break;
			case 3:
				list.OutputRecordsHisto();
				break;
			case 4:
				break;
		}
		cout << endl << endl;
		DisplayMenu();
		validateInt(input);
	}
	
	return 0;
}