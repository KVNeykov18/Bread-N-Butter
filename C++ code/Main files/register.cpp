#include "main menu.h"
#include "global.h"

void idRefresh(vector<USER_INFO>& accounts, int id)
{
	for (size_t i = id - 1; i < accounts.size(); i++) { accounts[i].id--; }
}

bool ageCheck(vector<USER_INFO>& accounts)
{
	cout << "Enter student age: ";
	cin >> accounts[accounts.size() - 1].studentAge;
	if (cin.fail())
	{ 
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "ERROR: Not a number" << endl;
		return 1;
	}
	if (accounts[accounts.size() - 1].studentAge < 12) { cout << "Student is too young" << endl; return 1; }
	if (accounts[accounts.size() - 1].studentAge > 16) { cout << "Student is too old" << endl; return 1; }
	return 0;
}

void addRegistry(vector <USER_INFO>& accounts)
{
	bool repeat = 1;
	accounts.push_back(USER_INFO());
	cout << "Create username: ";
	cin >> accounts[accounts.size() - 1].username;
	cout << "Create password: ";
	cin >> accounts[accounts.size() - 1].password;
	cout << "Enter first name: ";
	cin >> accounts[accounts.size() - 1].first_name;
	cout << "Enter last name: ";
	cin >> accounts[accounts.size() - 1].last_name;
	cout << "Enter address: ";
	cin >> accounts[accounts.size() - 1].address;
	cout << "Enter student name: ";
	cin >> accounts[accounts.size() - 1].studentName;
	while (repeat) { repeat = ageCheck(accounts); }
	accounts[accounts.size() - 1].id = accounts.size();
	accounts[accounts.size() - 1].adminPrivileges = 0;
	system("CLS");
	cout << "Registry successfully created" << endl;
}

void editRegistry(vector <USER_INFO>& accounts)
{
	int id = 0;
	int* ptr = &id;
	bool repeat = 1;
	string input;
	while (repeat)
	{
		cout << "Choose User ID (Type 0 to cancel): ";
		repeat = intCheck(ptr);
	}
	if (id == 0) return;
	if (id > accounts.size()) { cout << "No registry with that ID exists" << endl; return; }
	int choice = menuOutput(2, 7);
	switch (choice)
	{
	case 1: 
	{
		cout << "Edit username (Type 0 to cancel): ";
		cin >> input;
		if (input != "0") { accounts[id - 1].username = input; }
		break;
	}
	case 2:
	{
		cout << "Edit password (Type 0 to cancel): ";
		cin >> input;
		if (input != "0") { accounts[id - 1].password = input; }
		break;
	}
	case 3:
	{
		cout << "Edit first name (Type 0 to cancel): ";
		cin >> input;
		if (input != "0") { accounts[id - 1].first_name = input; }
		break;
	}
	case 4:
	{
		cout << "Edit last name (Type 0 to cancel): ";
		cin >> input;
		if (input != "0") { accounts[id - 1].last_name = input; }
		break;
	}
	case 5:
	{
		cout << "Edit address (Type 0 to cancel): ";
		cin >> input;
		if (input != "0") { accounts[id - 1].address = input; }
		break;
	}
	case 6:
	{
		cout << "Edit student name (Type 0 to cancel): ";
		cin >> input;
		if (input != "0") { accounts[id - 1].studentName = input; }
		break;
	}
	case 7:
	{
		while (repeat) { repeat = ageCheck(accounts); }
	}
	}
}

void removeRegistry(vector <USER_INFO>& accounts)
{
	int id = 0;
	int* ptr = &id;
	bool repeat = 1;
	while (repeat)
	{
		cout << "Choose User ID (Type 0 to cancel): ";
		repeat = intCheck(ptr);
	}
	if (id == 0) { return; }
	if (id > accounts.size()) { cout << "No registry with that ID exists" << endl; }
	else 
	{ 
		accounts.erase(accounts.begin() + id - 1);
		idRefresh(accounts, id);
	}
}