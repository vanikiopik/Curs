#include "Admin.h"

void Admin::Login()
{
    string login, password;
    string userLogin, userPassword;
    string line;
    ifstream file;

    file.open(AdminsFileName, ios::app);
    cout << "������� �����: "; cin >> login;


    while (getline(file, line)) {
        userLogin = FindName(line.c_str());
        userPassword = FindPassword(line.c_str());

        if (login == userLogin) {
            while (true) {
                cout << "������� ������: ";
                cin >> password;
                if (MakePassword(password) == userPassword) {
                    SetLogin(login);
                    SetPassword(password);
                    _isLoggedIn = true;
                    break;
                }
                else {
                    cout << "������. ��������� �������.\n";
                }
            }
        }
    }
}

void Admin::UserMenu()
{
    int choice;
    while (true)
    {
        system("cls");
        std::cout <<
            "1.������ � ���������\n"
            "2.������ � ����������\n"
            "3.�������� ���������� ����������\n"
            "0. �����\n";
            choice = IntInput("�������� ����� ����: ");

        system("cls");

        switch (choice)
        {
        case 1:
            ManageToClients();
            break;
        case 2:
            ManageToOperations();
            break;
        case 3:
            ShowAllStatistics();
            break;
        case 0:
            return;
        default:
            break;
        }
    }
}


//Menu to oerate with client
void Admin::ManageToClients()
{
    int choice;
    while (true)
    {
        system("cls");
        std::cout <<
            "1.����������� ���� �������������\n"
            "2.����������� �������� ���������� ������������\n"
            "0. �����\n";
            choice = IntInput("�������� ����� ����: ");

        system("cls");

        switch (choice)
        {
        case 1:
            ShowAvailableClients();
            break;
        case 2:
            ShowClientOperations();
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

//Menu to oerate with client's operations 
void Admin::ManageToOperations()
{
    int choice;
    while (true)
    {
        system("cls");
        std::cout <<
            "1.�������� ��� ��������\n"
            "2.��������� ������ ������\n"
            "3.����������� �������� ������������\n"
            "4.������������� ��������\n"
            "0. �����\n";
            choice = IntInput("�������� ����� ����: ");

        system("cls");

        switch (choice)
        {
        case 1:
            ShowAllAvailableOperations();
            break;
        case 2:

            break;
        case 3:
            ReviseClientOperation();
            break;
        case 4:
            //Sort txt file by value of products
            ShowSortingMenu();
            break;
        case 0:
            return;
        default:
            break;
        }
    }
}


//Show clients that creates operations in system
void Admin::ShowAvailableClients()
{
    list <string> ListOfUsers;
    string line;
    ifstream file;


    file.open(OperationsFileName, ios::app);

    while (file.peek() != EOF) {
        getline(file, line);
        ListOfUsers.push_back(FindClientName(line.c_str()));
    }

    //Sotring the names
    ListOfUsers.sort();
    //Delete dupliates
    ListOfUsers.unique();


    for (auto name : ListOfUsers) {
        cout << name << endl;
    }
    system("pause");
    file.close();
}

void Admin::ShowAllStatistics()
{
    cout << "���������� ��������: " << GetCountOfUsers(UsersFileName) << endl;
    cout << "���������� ����������������: " << GetCountOfUsers(AdminsFileName) << endl;
    cout << "���������� ���� ������: " << GetCountOfUsers(OperationsFileName) << endl;
    cout << "�������� / ����������� / �� ����������� : " << GetStatusOfOperations() << endl;
    system("pause");

}

//Show all operations info 
void Admin::ShowAllAvailableOperations()
{
    string line;
    ifstream file;

    file.open(OperationsFileName, ios::app);

    ShowFeesTableHeader();
    while (file.peek() != EOF) {
        getline(file, line);
        cout << "Client name: " << FindClientName(line.c_str()) << endl;
        GetOperationInfo(line.c_str());
    }
    system("pause");
}

//Show current client operations
void Admin::ShowClientOperations()
{
    string line;
    ifstream file;


    string login;
    cout << "������� ����� ������������: ";
    cin >> login;

    file.open(OperationsFileName, ios::app);

    ShowFeesTableHeader();
    while (file.peek() != EOF) {
        getline(file, line);
        if (login == FindClientName(line.c_str())) {
            GetOperationInfo(line.c_str());
        }
    }
    system("pause");
    file.close();
}


void Admin::SortElements(int choice)
{
    list <string> ListOfOperations;
    multimap <int, string> mapOper;

    string line;
    ifstream file;
    fstream out;

    file.open(OperationsFileName, ios::app);

    if (choice == 1) {

        for (int i = 0; file.peek() != EOF; i++) {
            getline(file, line);
            mapOper.emplace(GetValueOfProducts(line.c_str()), line);
        }
        file.close();
    }
      
    else if (choice == 2) {
        for (int i = 0; file.peek() != EOF; i++) {
            getline(file, line);
            mapOper.emplace(GetIDOfProductInt(line.c_str()), line);
        }
        file.close();
    }

    out.open(OperationsFileName);

    for (auto& name : mapOper) {
        out << name.second;
        out << "\n";
    }
    file.close();
    
    system("pause");
}


void Admin::ShowSortingMenu()
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


//Confirm or reject client operations
void Admin::ReviseClientOperation()
{
    int position = 0;
    int decision;

    list <string> ListOfOperations;
    list <string> CurrentClientOperations;
    list <int> PositionOfClientInFile;


    string line;
    fstream out;
    ifstream file;

    string login;
    cout << "������� ����� ������������: ";
    cin >> login;


    //Copy all info of operations 
    file.open(OperationsFileName, ios::app);

    for (int i = 0; file.peek() != EOF; i++) {
        getline(file, line);
        ListOfOperations.push_back(line);
    }
    file.close();


    //Copy info of current user's operations and remember the position of this client in txt file
    file.open(OperationsFileName, ios::app);

    for (int i = 0; file.peek() != EOF; i++) {
        getline(file, line);
        if (login == FindClientName(line.c_str())) {
            CurrentClientOperations.push_back(line);
            PositionOfClientInFile.push_back(i);
        }
    }
    file.close();


    //Changing the decision's status: 1 - CONFIRM, 2 - REJECT
    ShowFeesTableHeader();
    for (auto &name : CurrentClientOperations) {
        GetOperationInfo(name.c_str());

        cout << "1.������� ����\n"
                "2.��������� ����\n"
                "0.(��� ������ �������) �� ������������� ����\n"
                "��� �����: ";
        cin >> decision;
        switch (decision)        
        {
        case 1:
            name[2] = '1';
            break;
        case 2:
            name[2] = '2';
            break;
        default:
            break;
        }
    }


    //Rewriting the file
    out.open(OperationsFileName);

    for (auto &name : ListOfOperations) {  //Go through all operation
        for (auto& numbers : PositionOfClientInFile) {  //If pos same -> change line to CurentClientOperation
            if (numbers == position) {
                name = CurrentClientOperations.front();
                CurrentClientOperations.pop_front();
                break;
            } 
        }
        out << name;
        out << "\n";
        position++;
    }
    file.close();
    system("pause");
}

//Get count by each operation stats
string Admin::GetStatusOfOperations()
{
    string line;
    ifstream file;

    int accepted = 0;
    int rejected = 0;
    int noStatus = 0;


    file.open(OperationsFileName, ios::app);
    while (file.peek() != EOF) {
        getline(file, line);
        if (line[2] == '0') {
            noStatus++;
        }
        else if (line[2] == '1') {
            accepted++;
        }
        else if (line[2] == '2') {
            rejected++;
        }
    }
        
    return  to_string(accepted) + " / " + to_string(rejected) + " / " + to_string(noStatus);
}
