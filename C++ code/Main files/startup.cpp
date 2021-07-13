#include "global.h"

void initAdmin(vector <USER_INFO>& accounts)
{
	accounts.push_back(USER_INFO());
	accounts[0].id = 0;
	accounts[0].username = "admin";
	accounts[0].password = "adminpass";
	accounts[0].adminPrivileges = 1;
}

void readFromFile(vector <USER_INFO>& accounts)
{

}