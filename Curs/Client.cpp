#include "Client.h"

void Client::UserMenu()
{
    int choice;
    while (true)
    {
        //system("cls");
        std::cout <<
            "1.�������� ������������ ����������\n"
            "2.������� ��������� �� �����\n"
            "3.��������\n"
            "0. �����\n"
            "�������� ����� ����: ";
        std::cin >> choice;

        system("cls");

        switch (choice)
        {
        case 1:
            cout << "Login: " << GetLogin() << "| Password: " << GetPassword() << endl;
            break;
        case 2:
            ShowFeesTable();
            break;
        case 3:
            ShowOperationsMenu();
            break;
        case 0:

            return;
        default:
            break;
        }
    }
}


void Client::ShowFeesTable()
{
    int choice;
    while (true)
    {
        system("cls");
        std::cout <<
            "1.�������� �������� �� ���� �������\n"
            "2.�������� �������� �� ����� �������\n"
            "0. �����\n"
            "��������: ";
        std::cin >> choice;

        system("cls");

        switch (choice)
        {
        case 1:
            cout << "����\n"
                "�����\t������������\t\t���������\t\t������� �� ��.\n"
                "0\t��������\t\t��������\t\t7%\n"
                "1\t������ �������\t\t��������\t\t7%+ 3%\n"
                "2\t��������\t\t��������\t\t7% +5%\n"
                "3\t�����\t\t\t��������\t\t7% +8%\n"
                "4\t����������������\t����������������\t15%\n"
                "5\t�������\t\t\t����������������\t15% +10%\n"
                "6\t������\t\t\t����������������\t15% +3%\n"
                "7\t�������������\t\t����������������\t15% +5%\n"
                "8\t����������\t\t����������������\t15% +7%\n";
            system("pause");
            break;
        case 2:
            cout << "�����\n"
                "�����\t������������\t\t���������\t\t������� �� ��.\n"
                "9\t��������\t\t��������\t\t10%\n"
                "10\t������ �������\t\t��������\t\t10% +7%\n"
                "11\t��������\t\t��������\t\t10% +10%\n"
                "12\t�����\t\t\t��������\t\t10% +13%\n"
                "13\t����������������\t����������������\t20%\n"
                "14\t�������\t\t\t����������������\t20% +15%\n"
                "15\t������\t\t\t����������������\t20% +6%\n"
                "16\t�������������\t\t����������������\t20% +9%\n"
                "17\t����������\t\t����������������\t20% +10%\n";
            system("pause");
            break;
        case 0:
            return;
        default:
            break;
        }
    }
}


void Client::ShowOperationsMenu()
{
    int choice;
    while (true)
    {
        //system("cls");
        std::cout <<
            "1.�������� ������ ��������\n"
            "2.��������� ������ �� ����\n"
            "3.��������� ������ �� �����\n"
            "0.�������� ������\n"
            "�������� ����� ����: ";
        std::cin >> choice;

        system("cls");

        switch (choice)
        {
        case 1:
            FindClientOperation();
            break;
        case 2:
            break;
        case 3:
            break;
        case 0:
            return;
        default:
            break;
        }
    }
}


void Client::FindClientOperation()
{
    ifstream file;
    string line;

    file.open("Operations.txt", ios::app);

    while (getline(file, line)) {
        if (GetLogin() == FindClientName(line.c_str())) {
            cout << "User was found\n";
            GetOperationInfo(line.c_str());
        }
    }
}

void Client::CreateOperationToImport()
{
        
}
