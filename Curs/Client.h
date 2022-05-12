#pragma once
#include "User.h"
#include <iostream>
#include <fstream>
#include <vector>

class Client : public User
{
private:

public:
	void UserMenu() override;
	void ShowFeesTable();
	void ShowOperationsMenu();
	void FindClientOperation();
	void CreateOperationToImport();
	void CreateOperationToExport();
};

