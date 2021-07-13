#include "global.h"

bool intCheck(int* number)
{
	cin >> *number;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "ERROR: Not a number" << endl;
		return 1;
	}
	return 0;
}