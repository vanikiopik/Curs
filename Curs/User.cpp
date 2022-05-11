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
