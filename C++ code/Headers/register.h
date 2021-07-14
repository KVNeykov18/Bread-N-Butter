#pragma once
#include "global.h"

void addRegistry(vector <USER_INFO>& accounts, USER_INFO& currentUser, int adminRegistry);
void editRegistry(vector <USER_INFO>& accounts);
void removeRegistry(vector <USER_INFO>& accounts);
void listAllCurrentRegistries(vector<USER_INFO>& accounts);