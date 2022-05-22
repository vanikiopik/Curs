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
            "0. �����\n";
            choice = IntInput("�������� ����� ����: ");

        system("cls");

        switch (choice)
        {
        case 1:
            cout << "�����: " << GetLogin() << " | ������: " << GetPassword() << endl;
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
            "0. �����\n";
            choice = IntInput("�������� ����� ����: ");

        system("cls");

        switch (choice)
        {
        case 1:
            cout << "����\n"
                "�����\t������������\t\t���������\t\t������� �� ��.\n"
                "1\t��������\t\t��������\t\t7%\n"
                "2\t������ �������\t\t��������\t\t7% +3%\n"
                "3\t��������\t\t��������\t\t7% +5%\n"
                "4\t�����\t\t\t��������\t\t7% +8%\n"
                "5\t����������������\t����������������\t15%\n"
                "6\t�������\t\t\t����������������\t15% +10%\n"
                "7\t������\t\t\t����������������\t15% +3%\n"
                "8\t�������������\t\t����������������\t15% +5%\n"
                "9\t����������\t\t����������������\t15% +7%\n";
                system("pause");
                break;
        case 2:
            cout << "�����\n"
                "�����\t������������\t\t���������\t\t������� �� ��.\n"
                "1\t��������\t\t��������\t\t10%\n"
                "2\t������ �������\t\t��������\t\t10% +7%\n"
                "3\t��������\t\t��������\t\t10% +10%\n"
                "4\t�����\t\t\t��������\t\t10% +13%\n"
                "5\t����������������\t����������������\t20%\n"
                "6\t�������\t\t\t����������������\t20% +15%\n"
                "7\t������\t\t\t����������������\t20% +6%\n"
                "8\t�������������\t\t����������������\t20% +9%\n"
                "9\t����������\t\t����������������\t20% +10%\n";
            system("pause");
            break;
        case 0:
            return;
        default:
            break;
        }
    }
}

void Client::ShowFeesTable(int table)
{
    //0 - IMPORT
    //1 - EXPORT
    switch (table) {
    case 1:
        cout << "����\n"
            "�����\t������������\t\t���������\t\t������� �� ��.\n"
            "1\t��������\t\t��������\t\t7%\n"
            "2\t������ �������\t\t��������\t\t7% +3%\n"
            "3\t��������\t\t��������\t\t7% +5%\n"
            "4\t�����\t\t\t��������\t\t7% +8%\n"
            "5\t����������������\t����������������\t15%\n"
            "6\t�������\t\t\t����������������\t15% +10%\n"
            "7\t������\t\t\t����������������\t15% +3%\n"
            "8\t�������������\t\t����������������\t15% +5%\n"
            "9\t����������\t\t����������������\t15% +7%\n";
        break;
    case 2:
        cout << "�����\n"
            "�����\t������������\t\t���������\t\t������� �� ��.\n"
            "1\t��������\t\t��������\t\t10%\n"
            "2\t������ �������\t\t��������\t\t10% +7%\n"
            "3\t��������\t\t��������\t\t10% +10%\n"
            "4\t�����\t\t\t��������\t\t10% +13%\n"
            "5\t����������������\t����������������\t20%\n"
            "6\t�������\t\t\t����������������\t20% +15%\n"
            "7\t������\t\t\t����������������\t20% +6%\n"
            "8\t�������������\t\t����������������\t20% +9%\n"
            "9\t����������\t\t����������������\t20% +10%\n";
        break;
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
            "7.������������� ��������\n"
            "0.�����\n";
            choice = IntInput("�������� ����� ����: ");

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
        case 7:
            ShowSortingMenu();
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

    ShowFeesTableHeader();
    file.open("Operations.txt", ios::app);
    while (getline(file, line)) {
        if (GetLogin() == FindClientName(line.c_str())) {
            GetOperationInfo(line.c_str());
        }
    }
}

void Client::FindOperation()
{
    int number;


    ifstream file;
    string line;

    file.open("Operations.txt", ios::app);
    
    number = IntInput("������� ID ������ : ");
    
    
    ShowFeesTableHeader();
    while (getline(file, line)) {
        if (to_string(number) == GetIDOfOrder(line.c_str())) {
            if (GetLogin() == FindClientName(line.c_str())) {
                GetOperationInfo(line.c_str());
                system("pause");
                break;
            }
            else {
                cout << "�������� � �������\n";
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
    ID = IntPositiveInput("������� ID: ");


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
                isTrueUser = true;
                break;
            }
            else {
                cout << "Permission denied\n";
                return;
            }
        }
    }
    file.close();

    if (!isTrueUser) {
        cout << "ID wasn't found\n";
        system("pause");
        return;
    }

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


void Client::SortElements(int choice)
{
    multimap <int, string> mapOper;

    string line;
    ifstream file;

    file.open("Operations.txt", ios::app);

    if (choice == 1) {

        for (int i = 0; file.peek() != EOF; i++) {
            getline(file, line);
            if (GetLogin() == FindClientName(line.c_str())) {
                mapOper.emplace(GetValueOfProducts(line.c_str()), line);
            }
        }
        file.close();
    }

    else if (choice == 2) {
        for (int i = 0; file.peek() != EOF; i++) {
            getline(file, line);
            if (GetLogin() == FindClientName(line.c_str())) {
                mapOper.emplace(GetIDOfProductInt(line.c_str()), line);
            }
        }
        file.close();
    }

    ShowFeesTableHeader();
    for (auto& name : mapOper) {
        GetOperationInfo(name.second.c_str());
    }

    system("pause");
}


void Client::ShowSortingMenu()
{
    int choice;

    while (true)
    {
        system("cls");
        cout << "!!!���������� ��������� �� �����������!!!\n";
        cout << "1.����������� �� ���������� ������\n";
        cout << "2.����������� �� �������� ������\n";
        cout << "0. �����\n";
        choice = IntInput("�������� ����� ����: ");

        switch (choice)
        {
        case 1:
            SortElements(choice);
            break;
        case 2:
            SortElements(choice);
            break;
        case 0:
            return;
        default:
            break;
        }
    }
}

void Client::GetDirectionResult(string direction)
{
    string line;
    ifstream file;

    file.open("Operations.txt", ios::app);

    ShowFeesTableHeader();
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
            "0.�����\n";
            choice = IntInput("�������� ����� ����: ");

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

    ShowFeesTableHeader();
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
            "0.�����\n";
            choice = IntInput("�������� ����� ����: ");

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

    ShowFeesTableHeader();
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
            "0.�����\n";
            choice = IntInput("�������� ����� ����: ");

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
            "0.�����\n";
            choice = IntInput("�������� ����� ����: ");

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
    float Price;


    ShowFeesTable(IMPORT); cout << endl;

    ID_tovar = IntProductIDInput("������� ID ������: ");
    Count = IntPositiveInput("������� ���������� ������: ");
    Price = FloatMoneyInput("������� ���� ������ �� ���� �������: "); //������� Input ��� ����� � ������� ��� float!!!!!

    fstream file;
    file.open("Operations.txt", ios::app);
    file << IMPORT << "_" << STATUS << "_" << ID_tovar << "_" << Count << "_" << GetLastOrderID() << "_" << CalculateFullPrice(ID_tovar, IMPORT, Count, Price) << " " << this->GetLogin() << "\n";
    file.close();
}


void Client::CreateOperationToExport()
{
    const int IMPORT = 0;
    const int STATUS = 0;
    int ID_tovar;
    int Count;
    float Price;

    ShowFeesTable(IMPORT); cout << endl;

    ID_tovar = IntProductIDInput("������� ID ������: ");
    Count = IntPositiveInput("������� ���������� ������: ");
    Price = FloatMoneyInput("������� ���� ������ �� ���� �������: "); //������� Input ��� ����� � ������� ��� float!!!!!

    fstream file;
    file.open("Operations.txt", ios::app);
    file << IMPORT << "_" << STATUS << "_" << ID_tovar << "_" << Count << "_" << GetLastOrderID() << "_" << CalculateFullPrice(ID_tovar, IMPORT, Count, Price) << " " << this->GetLogin() << "\n";

    file.close();
}

//Get ID of product, status of export/import, value of product, price for one peace
float Client::CalculateFullPrice(int ID, int status, int value, float price)
{
    //I LOST MY MIND
    switch (status) {
    case 0:
        switch (ID)
        {
        case 1:
            return value * (price + price * 0.1);
            break;
        case 2:
            return value * (price + price * 0.17);
            break;
        case 3:
            return value * (price + price * 0.2);
            break;
        case 4:
            return value * (price + price * 0.23);
            break;
        case 5:
            return value * (price + price * 0.2);
            break;
        case 6:
            return value * (price + price * 0.35);
            break;
        case 7:
            return value * (price + price * 0.26);
            break;
        case 8:
            return value * (price + price * 0.29);
            break;
        case 9:
            return value * (price + price * 0.30);
            break;
        }
        break;


    case 1:
        switch (ID)
        {
        case 1:
            return value * (price + price * 0.07);
            break;
        case 2:
            return value * (price + price * 0.1);
            break;
        case 3:
            return value * (price + price * 0.12);
            break;
        case 4:
            return value * (price + price * 0.13);
            break;
        case 5:
            return value * (price + price * 0.15);
            break;
        case 6:
            return value * (price + price * 0.25);
            break;
        case 7:
            return value * (price + price * 0.18);
            break;
        case 8:
            return value * (price + price * 0.2);
            break;
        case 9:
            return value * (price + price * 0.22);
            break;
        }
        break;
    }
    return 0;
}
