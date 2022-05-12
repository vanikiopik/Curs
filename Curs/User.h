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
						//cout << "You are logged in\n";
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

	void GetOperationInfo(const char* line) {
		cout << "ID ������: " << line[0] << endl;
		cout << "��� ������: ";
		if (line[2] == '0') {
			cout << "����\n";
		}
		else {
			cout << "�����\n";
		}
		cout << "������ ������: ";
		if (line[4] == '0') {
			cout << "�� �����������\n";
		}
		else {
			cout << "�����������\n";
		}
		cout << "ID ������:";
		if (line[6] == '8') {
			cout << "����������\n";
		}
		cout << "���������� ������: " << GetValueOfProducts(line);

	}

	virtual void UserMenu() = 0;

};
