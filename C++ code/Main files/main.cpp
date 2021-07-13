#include <iostream>
#include "login.h"
#include "startup.h"
#include "main menu.h"
#include "global.h"

int main()
{
	vector <USER_INFO> accounts;
	USER_INFO currentUser;
	initAdmin(accounts);
	if (login(accounts, currentUser)) { menuHandler(accounts, currentUser); }
}