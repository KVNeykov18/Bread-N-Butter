#include "global.h"
#include "login.h"
#include "register.h"

vector<vector<string>> menus
{
	{
		{"<> Welcome to the Dormitory! <>"},
		{"Register a student (1)"},
		{"(ADMIN ONLY) Manage registries (2)"},
		{"Log out (0)"}
	},
	{
		{"Add registry (1)"},
		{"Edit registry (2)"},
		{"Remove registry (3)"},
		{"List all current registries (4)"},
		{"Exit (0)"}
	},
	{
		{"Edit username (1)"},
		{"Edit password (2)"},
		{"Edit first name (3)"},
		{"Edit last name (4)"},
		{"Edit address (5)"},
		{"Edit student name (6)"},
		{"Edit student age (7)"},
		{"Exit (0)"}
	}
};

int menuOutput(int menu, int menuSize)
{
	int choice;
	int* ptr = &choice;
	bool repeat = 1;
	for (int i = 0; i < menuSize; i++) { cout << menus[menu][i] << endl; }
	while (repeat) { repeat = intCheck(ptr); }
	return choice;
}

int menuHandler(vector <USER_INFO>& accounts, USER_INFO& currentUser)
{
	bool repeat = 1;
	while (repeat)
	{
		int choice = menuOutput(0, 4);
		system("CLS");
		switch (choice)
		{
		case 1:
			addRegistry(accounts, currentUser, 0); break;
		case 2:
			if (currentUser.adminPrivileges == 1)
			{
				choice = menuOutput(1, 5);
				system("CLS");
				switch (choice)
				{
				case 1: addRegistry(accounts, currentUser, 1); break;
				case 2: editRegistry(accounts); break;
				case 3: removeRegistry(accounts); break;
				case 4: listAllCurrentRegistries(accounts); break;
				default:
				{
					system("CLS");
					cout << "Notice: Not an option" << endl;
					system("PAUSE"); system("CLS");
					break;
				}
				case 0: break;
				}
			}
			else
			{ 
				system("CLS");
				cout << "Notice: User is not an admin" << endl; 
				system("PAUSE");system("CLS");
			}
			break;
		default:
			system("CLS");
			cout << "Notice: Not an option" << endl;
			system("PAUSE"); system("CLS");
			break;
		case 0:
			repeat = login(accounts, currentUser); break;
		}
	}
	return 0;
}