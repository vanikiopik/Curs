#include "User.h"

auto User::GetLogin()
{
	return login;
}

auto User::GetPassword()
{
	return password;
}

void User::SetLogin(std::string login)
{
	this->login = login;
}

void User::SetPassword(std::string password)
{
	this->password = password;
}
