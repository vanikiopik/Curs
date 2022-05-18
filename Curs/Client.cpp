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
            "6.��������� ������ ������\n"
            "0.�����\n"
            "�������� ����� ����: ";
        std::cin >> choice;

        system("cls");

        switch (choice)
        {
        case 1:
            FindClientOperations();
            break;
        case 2:
            CreateOperationToImport();
            break;
        case 3:
            CreateOperationToExport();
            break;
        case 4:
            FindOperation();
            break;
        case 5:
            CancelTheOperation();
            break;
        case 6:
            ShowSearchFilterMenu();
            break;
        case 0:
            return;
        default:
            break;
        }
    }
}


void Client::FindClientOperations()
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

void Client::FindOperation()
{
    string number;


    ifstream file;
    string line;

    file.open("Operations.txt", ios::app);
    
    
    cout << "������� ID ������: ";
    cin >> number;

    while (getline(file, line)) {
        if (number == GetIDOfOrder(line.c_str())) {
            if (GetLogin() == FindClientName(line.c_str())) {
                GetOperationInfo(line.c_str());
                system("pause");
                break;
            }
            else {
                cout << "Permission denied\n";
                break;
            }
        }
    }
}

void Client::CancelTheOperation()
{
    int positionOfOperation = 0;
    int i = 0;

    bool isTrueUser = false;

    list <string> ListOfOperations;


    string line;
    ofstream out;
    ifstream file;

    string ID;
    cout << "������� ID ������: ";
    cin >> ID;


    //Copy all info of operations 
    file.open("Operations.txt", ios::app);

    for (int i = 0; file.peek() != EOF; i++) {
        getline(file, line);
        ListOfOperations.push_back(line);
    }
    file.close();


    //Copy info of current operation and remember the position of this in  file
    file.open("Operations.txt", ios::app);

    for (int i = 0; file.peek() != EOF; i++) {
        getline(file, line);
        if (ID == GetIDOfOrder(line.c_str())) {
            if (GetLogin() == FindClientName(line.c_str())) {
                positionOfOperation = i;
                break;
            }
            else {
                cout << "Permission denied\n";
                return;
            }
        }
    }
    file.close();


    i = 0;
    for (std::list<string>::iterator it = ListOfOperations.begin(); it != ListOfOperations.end(); i++) {
        if (positionOfOperation == i) {
            ListOfOperations.erase(it);
            break;
        }
        else {
            it++;
        }
    }


    out.open("Operations.txt");

    //Rewriting the file
    for (auto& name : ListOfOperations) {
        out << name << "\n";
    }
    file.close();
    system("pause");
}


////True - count up number, False - below number
//void Client::GetSearchFilterProductResult(int number, bool choice)
//{
//    string line;
//    ifstream file;
//
//    file.open("Operations.txt", ios::app);
//
//
//    if (choice) {
//        for (int i = 0; file.peek() != EOF; i++) {
//            getline(file, line);
//            if (GetLogin() == FindClientName(line.c_str())) {
//                if  (GetValueOfProducts(line.c_str())) {
//                    GetOperationInfo(line.c_str());
//                }
//            }
//        }
//    }
//
//    else {
//        for (int i = 0; file.peek() != EOF; i++) {
//            getline(file, line);
//            if (GetLogin() == FindClientName(line.c_str())) {
//                if (to_string(number) > GetValueOfProducts(line.c_str())) {
//                    GetOperationInfo(line.c_str());
//                }
//            }
//        }
//    }
//    system("pause");
//    file.close();
//}

//void Client::ShowFilterProductCounterMenu()
//{
//    int choice;
//    int number;
//    while (true)
//    {
//        std::cout <<
//            "1.���������� ������ ������ ��� ��������� ��������\n"
//            "2.���������� ������ ������ ��� ��������� ��������\n"
//            "0.�����\n"
//            "�������� ����� ����: ";
//        cin >> choice;
//        system("cls");
//
//        switch (choice)
//        {
//        case 1:
//            cout << "������� ��������� �����: ";
//            cin >> number;
//            GetSearchFilterProductResult(number, false);
//            break;
//        case 2:
//            cout << "������� ��������� �����: ";
//            cin >> number;
//            GetSearchFilterProductResult(number, true);
//            break;
//        case 0:
//            return;
//        default:
//            break;
//        }
//    }
//}






void Client::GetDirectionResult(string direction)
{
    string line;
    ifstream file;

    file.open("Operations.txt", ios::app);

    for (int i = 0; file.peek() != EOF; i++) {
        getline(file, line);
        if (GetLogin() == FindClientName(line.c_str())) {
            if (GetDirectionOfOperation(line.c_str()) == direction) {
                GetOperationInfo(line.c_str());
            }
        }
    }
    system("pause");
}

void Client::ShowOperationDirectionFilterMenu()
{
    int choice;
    while (true)
    {
        //system("cls");
        std::cout <<
            "1.����������� ������ �� �����\n"
            "2.����������� ������ �� ����\n"
            "0.�����\n"
            "�������� ����� ����: ";
        std::cin >> choice;

        system("cls");

        switch (choice)
        {
        case 1:
            GetDirectionResult("0");
            break;
        case 2:
            GetDirectionResult("1");
            break;
        case 0:
            return;
        default:
            break;
        }
    }
}


void Client::GetStatusResult(string status)
{
    string line;
    ifstream file;

    file.open("Operations.txt", ios::app);

    for (int i = 0; file.peek() != EOF; i++) {
        getline(file, line);
        if (GetLogin() == FindClientName(line.c_str())) {
            if (GetStatusOfOperation(line.c_str()) == status) {
                GetOperationInfo(line.c_str());
            }
        }
    }
    system("pause");
}

void Client::ShowStatusSearchFilter()
{
    int choice;
    while (true)
    {
        std::cout <<
            "1.����������� �������� ������\n"
            "2.����������� ���������� ������\n"
            "3.���������� �� ������������� ������\n"
            "0.�����\n"
            "�������� ����� ����: ";
        std::cin >> choice;

        system("cls");

        switch (choice)
        {
        case 1:
            GetStatusResult("1");
            break;
        case 2:
            GetStatusResult("2");
            break;
        case 3:
            GetStatusResult("0");
            break;
        case 0:
            return;
        default:
            break;
        }
    }
}


void Client::GetNameResult(string name)
{
    string line;
    ifstream file;

    file.open("Operations.txt", ios::app);

    for (int i = 0; file.peek() != EOF; i++) {
        getline(file, line);
        if (GetLogin() == FindClientName(line.c_str())) {
            if (GetIDOfProduct(line.c_str()) == name) {
                GetOperationInfo(line.c_str());
            }
        }
    }
    system("pause");
}

void Client::ShowNameSearchFilter()
{
    int choice;
    while (true)
    {
        std::cout <<
            "1. ��������\n"
            "2. ������ �������\n"
            "3. ��������\n"
            "4. �����\n"
            "5. �������������������\n"
            "6. �������\n"
            "7. ������\n"
            "8. �������������\n"
            "9. ����������\n"
            "0.�����\n"
            "�������� ����� ����: ";
        std::cin >> choice;

        system("cls");

        switch (choice)
        {
        //I HATE MY LIFE
        case 1:
            GetNameResult("0");
            break;
        case 2:
            GetNameResult("1");
            break;
        case 3:
            GetNameResult("2");
            break;
        case 4:
            GetNameResult("3");
            break;
        case 5:
            GetNameResult("4");
            break;
        case 6:
            GetNameResult("5");
            break;
        case 7:
            GetNameResult("6");
            break;
        case 8:
            GetNameResult("7");
            break;
        case 9:
            GetNameResult("8");
            break;
        case 0:
            return;
        default:
            break;
        }
    }
}


void Client::ShowSearchFilterMenu()
{
    int choice;
    while (true)
    {
        std::cout <<
            "1.��������� ������ ��� �����/������ ������\n"
            "2.��������� ������ ��� ������� ������\n"
            "3.��������� ������ ��� ������������ ������ � ������\n"
            "0.�����\n"
            "�������� ����� ����: ";
        std::cin >> choice;

        system("cls");

        switch (choice)
        {
        case 1:
            ShowOperationDirectionFilterMenu();
            break;
        case 2:
            ShowStatusSearchFilter();
            break;
        case 3:
            ShowNameSearchFilter();
            break;
        case 0:
            return;
        default:
            break;
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
