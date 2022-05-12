#include "Admin.h"

void Admin::UserMenu()
{
    int choice;
    while (true)
    {
        system("cls");
        std::cout <<
            "1.Показать персональную информацию\n"
            "2.Изменить персональную информацию\n"
            "3.Таблица процентов на сборы\n"
            "4.Операции\n"
            "0. Назад\n"
            "Выберите пункт меню: ";
        std::cin >> choice;

        system("cls");

        switch (choice)
        {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

        case 0:

            return;
        default:
            break;
        }
    }
}
