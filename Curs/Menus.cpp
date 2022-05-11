#include "Menus.h"


void cast::LoginMenu(User* user)
{
	user->Login();
	system("pause");

	user->UserMenu();

}
