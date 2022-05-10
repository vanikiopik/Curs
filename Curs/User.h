#pragma once
#include <string>

class User
{
protected:
	std::string login;
	std::string password;
	bool isInitialized = false;

public:
	void SetLogin(std::string login);
	void SetPassword(std::string password);

	auto GetLogin();
	auto GetPassword();

	void TryToLogin();
	void LogOut();


	virtual void UserMenu() = 0;

	static auto MakePassword(const std::string& password);
	void ReadPasswordFromFile(const std::string& login);
};
