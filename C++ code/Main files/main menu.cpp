#include "global.h"

//vector <USER_INFO> accounts;
//accounts[n].name;
int mainMenu()
{
	int a;
	cout << "<> Welcome to the Dormitory! <>" << endl;
	cout << "Register a person (1) " << endl;
	cout << "Manage registries (2) " << endl;
	cout << "Logout (0) " << endl;
	cin >> a;
	return a;
}

int manageRegistriesMenu()
{
	int b;
	cout << "Add registry (1) " << endl;
	cout << "Delete registry (2) " << endl;
	cout << "Search registry (3) " << endl;
	cout << "Edit a registry (4) " << endl;
	cout << "List all current registry (5) " << endl;
	cout << "Exit (0) " << endl;
	cin >> b;
	return b;
}

int editRegistryMenu()
{
	int c;
	cout << "Edit username (1) " << endl;
	cout << "Edit password (2) " << endl;
	cout << "Edit first Name (3) " << endl;
	cout << "Edit last Name (4) " << endl;
	cout << "Edit address (5) " << endl;
	cout << "Edit age (6) " << endl;
	cout << "Exit (0) " << endl;
	cin >> c;
	return c;
}

int menuHandler()
{
	int choice = mainMenu();
	bool repeat = 1;

	switch (choice)
	{
	case 1:
		/*register a person function*/
		break;
	case 2:
		manageRegistriesMenu();
		break;
	default:
		break;
	case 0:
		/*logout();*/ repeat = 0; break;
	}
	return 0;
}