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

string User::GetStatusOfOperation(const char* line)
{
	string word;
	word += line[2];
	return word;
}

string User::GetIDOfProduct(const char* line)
{
	string word;
	word += line[4];
	return word;
}

int User::GetIDOfProductInt(const char* line)
{
	string word;
	word += line[4];
	return stoi(word);
}

string User::GetDirectionOfOperation(const char* line)
{
	string word;
	word += line[0];
	return word;
}
