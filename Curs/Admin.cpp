#include "Admin.h"

void Admin::UserMenu()
{
    int choice;
    while (true)
    {
        system("cls");
        std::cout <<
            "1.�������� ������������ ����������\n"
            "2.�������� ������������ ����������\n"
            "3.������� ��������� �� �����\n"
            "4.��������\n"
            "0. �����\n"
            "�������� ����� ����: ";
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
