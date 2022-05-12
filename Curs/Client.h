#pragma once
#include "User.h"
#include <iostream>
#include <vector>

class Client : public User
{
private: 
	vector <std::string> operations;
public:
	void UserMenu() override;
	void ShowFeesTable();
	void ShowOperationsMenu();
	void FindClientOperation();
};

