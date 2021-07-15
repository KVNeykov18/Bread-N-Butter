#include "main menu.h"
#include "global.h"

//fixes up the IDs after removing a registry
void idRefresh(vector<USER_INFO>& accounts, int id)
{
	for (size_t i = id - 1; i < accounts.size(); i++) { accounts[i].id--; } //changes ID for all regstries after the deleted one
}

//checks if the age is valid
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

//adds a registry
void addRegistry(vector <USER_INFO>& accounts, USER_INFO& currentUser, int adminRegistry)
{
	bool repeat = 1;
	accounts.push_back(USER_INFO());
	if (adminRegistry == 1) //this function is used in two situations (by a regular user and by an admin user), some info is automatically entered for regular users
	{
		cout << "Create username: ";
		cin >> accounts[accounts.size() - 1].username;
		cout << "Create password: ";
		cin >> accounts[accounts.size() - 1].password;
		cout << "Enter address: ";
		cin >> accounts[accounts.size() - 1].address;
	}
	else
	{
		accounts[accounts.size() - 1].username = currentUser.username;
		accounts[accounts.size() - 1].password = currentUser.password;
		accounts[accounts.size() - 1].address = currentUser.address;
	}
	cout << "Enter first name: ";
	cin >> accounts[accounts.size() - 1].first_name;
	cout << "Enter last name: ";
	cin >> accounts[accounts.size() - 1].last_name;
	cout << "Enter student name: ";
	cin >> accounts[accounts.size() - 1].studentName;
	while (repeat) { repeat = ageCheck(accounts); }
	accounts[accounts.size() - 1].id = accounts.size();
	accounts[accounts.size() - 1].adminPrivileges = 0;
	system("CLS");
	cout << "Registry successfully created" << endl;
	system("PAUSE"); system("CLS");
}

//message for when you edit a registry
void editMessage()
{
	system("CLS");
	cout << "Successfully edited registry" << endl;
	system("PAUSE"); system("CLS");
}

//edit a registry
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
	if ((size_t)id > accounts.size()) 
	{
		system("CLS");
		cout << "No registry with that ID exists" << endl;
		system("PAUSE"); system("CLS");
		return; 
	}
	int choice = menuDisplay(2, 8);
	repeat = 1;
	system("CLS");
	switch (choice)
	{
	case 1: 
	{
		cout << "Edit username (Type 0 to cancel): ";
		cin >> input;
		if (input != "0") { accounts[id - 1].username = input; editMessage(); }
		break;
	}
	case 2:
	{
		cout << "Edit password (Type 0 to cancel): ";
		cin >> input;
		if (input != "0") { accounts[id - 1].password = input; editMessage(); }
		break;
	}
	case 3:
	{
		cout << "Edit first name (Type 0 to cancel): ";
		cin >> input;
		if (input != "0") { accounts[id - 1].first_name = input; editMessage(); }
		break;
	}
	case 4:
	{
		cout << "Edit last name (Type 0 to cancel): ";
		cin >> input;
		if (input != "0") { accounts[id - 1].last_name = input; editMessage(); }
		break;
	}
	case 5:
	{
		cout << "Edit address (Type 0 to cancel): ";
		cin >> input;
		if (input != "0") { accounts[id - 1].address = input; editMessage(); }
		break;
	}
	case 6:
	{
		cout << "Edit student name (Type 0 to cancel): ";
		cin >> input;
		if (input != "0") { accounts[id - 1].studentName = input; editMessage(); }
		break;
	}
	case 7:
	{
		while (repeat) { repeat = ageCheck(accounts); }
		break;
	}
	default:
	{
		system("CLS");
		cout << "Notice: Not an option";
		system("PAUSE"); system("CLS");
		break;
	}
	case 0:
	{
		system("CLS"); break;
	}
	}
}

//remove a registry
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
	if ((size_t)id > accounts.size())
	{
		system("CLS");
		cout << "No registry with that ID exists" << endl;
		system("PAUSE"); system("CLS");
		return;
	}
	else 
	{ 
		accounts.erase(accounts.begin() + id - 1);
		idRefresh(accounts, id);
		system("CLS");
		cout << "Successfully deleted registry" << endl;
		system("PAUSE"); system("CLS");
	}
}

//outputs a list with all of the registries
void listAllCurrentRegistries(vector<USER_INFO>& accounts)
{
	system("CLS");
	cout << "ID, Username, Password, First name, Last name, Address, Student name, Student age" << endl;
	for (size_t i = 0; i < accounts.size(); i++)
	{
		cout << accounts[i].id << " ";
		cout << accounts[i].username << " ";
		cout << accounts[i].password << " ";
		cout << accounts[i].first_name << " ";
		cout << accounts[i].last_name << " ";
		cout << accounts[i].address << " ";
		cout << accounts[i].studentName << " ";
		cout << accounts[i].studentAge << " ";
		cout << "[ is admin:" << accounts[i].adminPrivileges << " ]";
		cout << endl;
	}
	cout << endl;
}