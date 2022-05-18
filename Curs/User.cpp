#include "User.h"

string User::GetLogin()
{
	return _login;
}

string User::GetPassword()
{
	return _password;
}

void User::SetLogin(std::string login)
{
	_login = login;
}

void User::SetPassword(std::string password)
{
	_password = password;
}

bool User::IsUserInSystem()
{
	return _isLoggedIn;
}

int User::GetCountOfUsers(string fileName)
{
	string line;
	ifstream file;
	int counter = 0;
	file.open(fileName, ios::app);

	while (file.peek() != EOF) {
		getline(file, line);
		counter++;
	}
	file.close();
	return counter;
}
