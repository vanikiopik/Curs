#pragma once
#include "User.h"
#include <iostream>
class Client : public User
{
public:
	void UserMenu() override;
	void ShowFeesTable();
	void ShowOperationsMenu();
};

