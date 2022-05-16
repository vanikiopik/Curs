#pragma once
#include "User.h"
#include <iostream>
#include <fstream>
#include <list>

class Client : public User
{
private:

public:
	void UserMenu() override;

	void ShowFeesTable();

	void ShowOperationsMenu();

	void FindClientOperations();

	void FindOperation();

	void CancelTheOperation();

	void CreateOperationToImport();
	void CreateOperationToExport();
};
