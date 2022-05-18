#pragma once
#include "User.h"
#include <vector>
#include <list>
#include <map>
#include <iterator>


class Admin : public User
{
public:

	void Login() override;

	void UserMenu() override;

	void ManageToClients();
	void ManageToOperations();

	void ShowAvailableClients();
	void ShowAllStatistics();
	void ShowAllAvailableOperations();
	void ShowClientOperations();

	void ReviseClientOperation();

	string GetStatusOfOperations();

};
 