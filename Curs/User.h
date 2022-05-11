#pragma once
#include <string>
#include <fstream>
#include <string>
#include "UserInput.h"

using namespace std;

class User
{
protected:
	std::string login;
	std::string password;
public:
	auto GetLogin();
	auto GetPassword();

	void SetLogin(std::string login);
	void SetPassword(std::string password);

	auto MakePassword(const std::string& password)
	{
		return to_string(std::hash<std::string>()(password));
	}


	string FindName(const char* line) {
		int i = 0;
		string word;
		while (line[i] != ' ')
		{
			word += line[i];
			i++;
		}
		return word;
	}


	string FindPassword(const char* line) {
		int i = 0;
		int j = 0;
		string word;
		while (line[i] != ' ')
		{
			i++;
		}

		if (line[i] == ' ')
		{
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
		ifstream file;
		string line;

		file.open("Users.txt", ios::app);
		cout << "Enter login: "; cin >> login; cout << endl;


		while (getline(file, line)) {
			userLogin = FindName(line.c_str());
			userPassword = FindPassword(line.c_str());

			if (login == userLogin) {
				while (true) {
					cout << "Enter the password: ";
					cin >> password;
					if (MakePassword(password) == userPassword) {
						cout << "You are logged in\n";
						break;
					}
					else {
						cout << "Try again\n";
					}
				}
			}
		}
	}

	virtual void UserMenu() = 0;
};
