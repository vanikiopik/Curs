#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "User.h"
#include "Client.h"
#include "Admin.h"
#include "UserInput.h"
#include "Menus.h"

using namespace std;
using namespace cast;


auto MakePassword(const std::string& password){
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
		while (line[j] != '\0'){
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

	while (getline(file, line)){
		if (login == FindName(line.c_str())) {
			return true;
		}
	}
	return false;
	file.close();
}


void Login(){
	string login, password;
	string userLogin, userPassword;
	ifstream file;
	string line;

	file.open("Users.txt", ios::app);
	cout << "Введите логин: "; cin >> login; cout << endl;


	while (getline(file, line)) {
		userLogin = FindName(line.c_str());
		userPassword = FindPassword(line.c_str());

		if (login == userLogin) {
			while (true) {
				cout << "Введите пароль: ";
				cin >> password;
				if (MakePassword(password) == userPassword) {
					break;
				}
				else {
					cout << "Ошибка. Повторите поптку.\n";
				}
			}
		}
	}
}


void Register() {
	ofstream in("Users.txt", ios_base::app);
	if (!in){
		cout << "fail";
	}

	string login, password;
	cout << "login: "; cin >> login;
	cout << "password: "; cin >> password;


	if (IsUserExist(login)) {
		cout << "That name's already exist. Try again\n";
	}
	else {
		in << login << " " << MakePassword(password) << "\n";
	}
	in.close();
}


void ShowMainMenu() {
	int choice;
	shared_ptr<User> user = nullptr;


	while (true)
	{
		system("cls");
		cout <<
			"1.Зайти как пользователь\n"
			"2.Зайти как администратор\n"
			"3.Регистрация\n"
			"0.Выход\n";
		choice = IntInput("Выберите пункт меню: ");
		system("cls");

		switch (choice)
		{
		case 1:
			user = shared_ptr<User>(new Client());
			LoginMenu(user);
			user = nullptr;
			break;
		case 2:
			user = shared_ptr<User>(new Admin());
			LoginMenu(user);
			user = nullptr;
			break;
		case 3:
			Register();
			system("pause");
			break;
		case 0:
			exit(0);
		default:
			break;
		}
	}
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	MoveWindow(console, r.left, r.top, 1350, 700, TRUE); // 800 width, 100 height

	ShowMainMenu();

	return 0;
}