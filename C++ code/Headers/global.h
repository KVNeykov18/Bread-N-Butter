
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
using namespace std;

struct USER_INFO
{
	size_t id = 0;
	string username = "";
	string password = "";
	string first_name = "";
	string last_name = "";
	string address = "";
	string studentName = "";
	size_t studentAge = 0;
	bool adminPrivileges = 0;
};

bool intCheck(int*);

//this entire header file is for everything that is used throughout the whole program