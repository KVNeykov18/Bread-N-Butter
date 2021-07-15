#include "global.h"

//used in a loop that breaks when the input is valid
bool intCheck(int* number)
{
	cin >> *number;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clears and ignores all input until the end of user's input
		cout << "ERROR: Not a number" << endl;
		return 1;
	}
	return 0;
}