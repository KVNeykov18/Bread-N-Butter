#include "global.h"

bool intCheck(int* number)
{
	cin >> *number;
	if (cin.fail()) { cout << "ERROR: Not a number" << endl; return 1; }
	return 0;
}