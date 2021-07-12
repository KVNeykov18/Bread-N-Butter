#include <iostream>
#include "login.h"
#include "startup.h"
#include "main menu.h"
#include "global.h"

int main()
{
	vector <USER_INFO> accounts;
	initAdmin(accounts);
	login(accounts);
	mainMenu();
}