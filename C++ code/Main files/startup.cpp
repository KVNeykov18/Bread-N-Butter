#include "global.h"

//initializes Admin account
void initAdmin(vector <USER_INFO>& accounts)
{
	accounts.push_back(USER_INFO());
	accounts[0].id = 1;
	accounts[0].username = "admin";
	accounts[0].password = "adminpass";
	accounts[0].adminPrivileges = 1;
}