#include "Menus.h"


void cast::LoginMenu(shared_ptr<User> user)
{
	user->Login();
	if (user->IsUserInSystem()) {
		user->UserMenu();
	}
	else {
		cout << "������������ �� ����������.\n";
	}
	system("pause");
}
