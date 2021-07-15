#include "login.h"
#include "global.h"

//a function for logging in
bool login(vector <USER_INFO>& accounts, USER_INFO& currentUser)
{
	USER_INFO user;
	bool loggedIn = 0;
	int index;
	while (!loggedIn)
	{
		cout << "Log in (Any key) or Exit (Esc)" << endl;
		int key = _getch();
		if (key == 27) { cout << "See you next time." << endl; return 0; }
		cout << "Username: ";
		cin >> user.username;
		cout << "Password: ";
		cin >> user.password;
		for (size_t i = 0; i < accounts.size(); i++)
		{
			if (accounts[i].username == user.username and accounts[i].password == user.password)
			{ 
				loggedIn = 1; 
				index = i;
			}
		}
		system("CLS");
		if (!loggedIn) { cout << "Wrong username or password!" << endl; }
		else
		{ 
			cout << "Successfully logged in!" << endl; 
			currentUser = accounts[index];
		}
	}
	return 1;
}