#pragma once
#include <string>
#include <fstream>
#include <string>
#include "UserInput.h"

using namespace std;

class User
{
protected:
	string _login;
	string _password;
	bool _isLoggedIn = false;
public:
	string GetLogin();
	string GetPassword();

	void SetLogin(string login);
	void SetPassword(string password);

	bool IsUserInSystem();

	auto MakePassword(const string& password){
		return to_string(std::hash<std::string>()(password));
	}


	string FindName(const char* line) {
		int i = 0;
		string word;
		while (line[i] != ' '){
			word += line[i];
			i++;
		}
		return word;
	}

	string FindPassword(const char* line) {
		int i = 0;
		int j = 0;
		string word;
		while (line[i] != ' '){
			i++;
		}

		if (line[i] == ' '){
			j = i + 1;
			while (line[j] != '\0')
			{
				word += line[j];
				j++;
			}
		}
		return word;
	}


	bool IsUserExist(string login) {
		ifstream file;
		string line;
		file.open("Users.txt", ios::app);

		while (getline(file, line)) {
			if (login == FindName(line.c_str())) {
				return true;
			}
		}
		return false;
		file.close();
	}

	void Login() {
		string login, password;
		string userLogin, userPassword;
		string line;
		ifstream file;

		file.open("Users.txt", ios::app);
		cout << "Enter login: "; cin >> login;


		while (getline(file, line)) {
			userLogin = FindName(line.c_str());
			userPassword = FindPassword(line.c_str());

			if (login == userLogin) {
				while (true) {
					cout << "Enter the password: ";
					cin >> password;
					if (MakePassword(password) == userPassword) {

						SetLogin(login);
						SetPassword(password);
						_isLoggedIn = true;
						break;
					}
					else {
						cout << "Try again\n";
					}
				}
			}
		}
	}

	string FindClientName(const char* line) {
		int i = 0;
		int j = 0;
		string word;

		while (line[i] != ' ') {
			i++;
		}

		j = i + 1;
		while (line[j] != '\0')
		{
			word += line[j];
			j++;
		}
		return word;
	}

	string GetValueOfProducts(const char* line) {
		string word;
		int countStarting = 8;

		while (line[countStarting] != ' ') {
			word += line[countStarting];
			countStarting++;
		}
		return word;
	}

	string GetIDOfOrder(const char* line) {
		string word;
		int countStarting = 0;

		while (line[countStarting] != '_') {
			word += line[countStarting];
			countStarting++;
		}
		return word;
	}


	void GetOperationInfo(const char* line) {
		cout << "ID Заказа: " << GetIDOfOrder(line) << endl;

		cout << "Тип сделки: ";
		if (line[2] == '0') {
			cout << "Ввоз\n";
		}
		else {
			cout << "Вывоз\n";
		}

		cout << "Статус заявки: ";
		if (line[4] == '0') {
			cout << "Не рассмотрена\n";
		}
		else {
			cout << "Рассмотрена\n";
		}

		//I WANNA DIE
		cout << "ID товара:";
		if (line[6] == '0') 
			cout << "Продукты\n";
		else if (line[6] == '1')
			cout << "Мясные изделия\n";
		else if (line[6] == '2')
			cout << "Алкоголь\n";
		else if (line[6] == '3') 
			cout << "Табак\n";
		else if (line[6] == '4') 
			cout << "Непродовальственные\n";
		else if (line[6] == '5') 
			cout << "Топливо\n";
		else if (line[6] == '6') 
			cout << "Одежда\n";
		else if (line[6] == '7') 
			cout << "Электротовары\n";
		else if (line[6] == '8') 
			cout << "Парфюмерия\n";

		cout << "Количество товара: " << GetValueOfProducts(line) << endl;
		cout << "===========\n";
	}

	virtual void UserMenu() = 0;

};
