#include "User.h"

auto User::MakePassword(const std::string& password)
{
	return std::to_string(std::hash<std::string>()(password));
}



void User::SetLogin(std::string login)
{
	this->login = login;
}

void User::SetPassword(std::string password)
{
	this->password = MakePassword(password);
}

auto User::GetLogin()
{
	return this->login;
}

auto User::GetPassword()
{
	return this->password;
}

void User::TryToLogin()
{
	if (login == this->login and MakePassword(password) == this->password)
		isInitialized = true;
}

void User::LogOut()
{
	isInitialized = false;
}


