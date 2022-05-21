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

	virtual void Login() {
		string login, password;
		string userLogin, userPassword;
		string line;
		ifstream file;

		file.open("Users.txt", ios::app);
		cout << "Введите логин: "; cin >> login;


		while (getline(file, line)) {
			userLogin = FindName(line.c_str());
			userPassword = FindPassword(line.c_str());

			if (login == userLogin) {
				while (true) {
					cout << "Введите пароль: ";
					cin >> password;
					if (MakePassword(password) == userPassword) {
						SetLogin(login);
						SetPassword(password);
						_isLoggedIn = true;
						break;
					}
					else {
						cout << "Ошибка. Повторите попытку\n";
					}
				}
			}
		}
	}


	string FindClientName(const char* line) {
		int i = 0;
		int j = 0;
		string word;
		if (line[0] == '\0')
			return "";
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

	int GetValueOfProducts(const char* line) {
		string word;
		int countStarting = 6;

		while (line[countStarting] != '_') {
			word += line[countStarting];
			countStarting++;
		}
		return stoi(word);
	}



	string GetIDOfOrder(const char* line) {
		string word;
		int i = 0;
		int j = 0;
		int underlineCounter = 0;

		while (line[i] != ' ') {
			if (line[i] == '_'){
				underlineCounter++;
				if (underlineCounter == 4) {
					j = i + 1;
					while (line[j] != ' ') {
						word += line[j];
						j++;
					}
				}
			}
			i++;
		}
		return word;
	}

	int GetCountOfUsers(string fileName);

	int GetLastOrderID() {
		string line;
		ifstream file;
		int temp = -1;

		file.open("Operations.txt", ios::app);

		while (file.peek() != EOF) {
			getline(file, line);
			if (stoi(GetIDOfOrder(line.c_str())) > temp) {
				
				temp = stoi(GetIDOfOrder(line.c_str()));
			}
		}
		file.close();
		return temp + 1;
	}

	string GetStatusOfOperation(const char* line);

	string GetIDOfProduct(const char* line);

	int GetIDOfProductInt(const char* line);

	string GetDirectionOfOperation(const char* line);

	void ShowTableHeader() {
		cout << "ID Заказа\t" << "Тип сделки\t" << "Статус заявки\t" << "Название товарав\t" << "Количество товара\n";
	}

	void GetOperationInfo(const char* line) {

		cout << GetIDOfOrder(line) << "\t\t";

		if (line[0] == '1') {
			cout << "Ввоз";
		}
		else {
			cout << "Вывоз";
		}

		cout << "\t\t";

		if (line[2] == '0') {
			cout << "Не рассмотрена";
		}
		else if (line[2] == '1') {
			cout << "Принята\t";
		}
		else if (line[2] == '2') {
			cout << "Отклонена";
		}
		
		cout << "\t";

		//I WANNA DIE
		if (line[4] == '1') 
			cout << "Продукты\t\t";
		else if (line[4] == '2')
			cout << "Мясные изделия\t\t";
		else if (line[4] == '3')
			cout << "Алкоголь\t\t";
		else if (line[4] == '4') 
			cout << "Табак\t\t\t";
		else if (line[4] == '5') 
			cout << "Непродовольственные\t";
		else if (line[4] == '6') 
			cout << "Топливо\t\t\t";
		else if (line[4] == '7') 
			cout << "Одежда\t\t";
		else if (line[4] == '8') 
			cout << "Электротовары\t\t";
		else if (line[4] == '9') 
			cout << "Парфюмерия\t\t";

		cout <<  GetValueOfProducts(line) << endl;
		cout << "====================================================================================================\n";
	}

	virtual void UserMenu() = 0;
};
