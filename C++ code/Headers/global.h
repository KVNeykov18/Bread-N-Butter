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
	bool adminPriveleges = 0;
};

bool intCheck(int*);