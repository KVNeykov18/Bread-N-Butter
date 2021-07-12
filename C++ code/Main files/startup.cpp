#include "global.h"

void initAdmin(vector <USER_INFO> &accounts)
{
	accounts.push_back(USER_INFO());
	accounts[0].username = "admin";
	accounts[0].password = "adminpass";
	accounts[0].adminPriveleges = 1;
}