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
            cout << "Login: " << GetLogin() << "\n| Password: " << GetPassword() << endl;
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
                "1\t������ �������\t\t��������\t\t7% +3%\n"
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
                "0\t��������\t\t��������\t\t10%\n"
                "1\t������ �������\t\t��������\t\t10% +7%\n"
                "2\t��������\t\t��������\t\t10% +10%\n"
                "3\t�����\t\t\t��������\t\t10% +13%\n"
                "4\t����������������\t����������������\t20%\n"
                "5\t�������\t\t\t����������������\t20% +15%\n"
                "6\t������\t\t\t����������������\t20% +6%\n"
                "7\t�������������\t\t����������������\t20% +9%\n"
                "8\t����������\t\t����������������\t20% +10%\n";
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
            "4.����� ������\n"
            "5.�������� ������\n"
            "0.�����\n"
            "�������� ����� ����: ";
        std::cin >> choice;

        system("cls");

        switch (choice)
        {
        case 1:
            FindClientOperation();
            break;
        case 2:
            CreateOperationToImport();
            break;
        case 3:
            CreateOperationToExport();
            break;
        case 4:
            break;
        case 5:
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
    const int IMPORT = 1;
    const int STATUS = 0;
    int ID_tovar;
    int Count;
    cout << "������� ID ������: "; cin >> ID_tovar;
    cout << "\n������� ���������� ������: "; cin >> Count;

    fstream file;
    file.open("Operations.txt", ios::app);
    file << IMPORT << "_" << STATUS << "_" << ID_tovar << "_" << Count << "_" << GetLastOrderID() << " " << this->GetLogin() << "\n";
    file.close();

}


void Client::CreateOperationToExport()
{
    const int IMPORT = 0;
    const int STATUS = 0;
    int ID_tovar;
    int Count;
    cout << "������� ID ������: "; cin >> ID_tovar;
    cout << "\n������� ���������� ������: "; cin >> Count;


    fstream file;
    file.open("Operations.txt", ios::app);
    file << IMPORT << "_" << STATUS << "_" << ID_tovar << "_" << Count << "_" << GetLastOrderID() << " " << this->GetLogin() << "\n";
    file.close();
}
