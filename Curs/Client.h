#pragma once
#include "User.h"
#include <iostream>
#include <fstream>
#include <list>
#include "UserInput.h"
#include <map>


class Client : public User
{
private:

public:
	void UserMenu() override;


	void ShowFeesTable();
	void ShowFeesTable(int table);

	void ShowOperationsMenu();

	void FindClientOperations();

	void FindOperation();

	void CancelTheOperation();

	void SortElements(int choice);
	void ShowSortingMenu();

	void GetDirectionResult(string direction);
	void ShowOperationDirectionFilterMenu();

	void GetStatusResult(string status);
	void ShowStatusSearchFilter();


	void GetNameResult(string name);
	void ShowNameSearchFilter();

	void ShowSearchFilterMenu();


	void CreateOperationToImport();
	void CreateOperationToExport();

	float CalculateFullPrice(int ID, int status, int value, float price);

};
