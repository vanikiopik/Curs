#include "Menus.h"


void cast::LoginMenu(User* user)
{
	user->Login();
	if (user->IsUserInSystem()) {
		user->UserMenu();
	}
	else {
		cout << "User doesn't exist\n";
	}
	system("pause");
}
