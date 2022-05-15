#include "Admin.h"

void Admin::Login()
{
    string login, password;
    string userLogin, userPassword;
    string line;
    ifstream file;

    file.open("Admins.txt", ios::app);
    cout << "Enter login: "; cin >> login;


    while (getline(file, line)) {
        userLogin = FindName(line.c_str());
        userPassword = FindPassword(line.c_str());

        if (login == userLogin) {
            while (true) {
                cout << "Enter the password: ";
                cin >> password;
                if (MakePassword(password) == userPassword) {
                    SetLogin(login);
                    SetPassword(password);
                    _isLoggedIn = true;
                    break;
                }
                else {
                    cout << "Try again\n";
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
            "1.Работа с клиентами\n"
            "2.Работа с операциями\n"
            "0. Назад\n"
            "Выберите пункт меню: ";
        std::cin >> choice;

        system("cls");

        switch (choice)
        {
        case 1:
            ManageToClients();
            break;
        case 2:
            ManageToOperations();
            break;
        case 0:
            return;
        default:
            break;
        }
    }
}


void Admin::ManageToClients()
{
    int choice;
    while (true)
    {
        system("cls");
        std::cout <<
            "1.Просмотреть всех пользователей\n"
            "2.Просмотреть операции выбранного пользователя\n"
            "3.Применить фильтр поиска\n"
            "4.Рассмотреть операцию\n"
            "0. Назад\n"
            "Выберите пункт меню: ";
        std::cin >> choice;

        system("cls");

        switch (choice)
        {
        case 1:
            ShowAvailableUsers();
            break;
        case 2:
            ShowUserOperations();
            break;
        case 3:
            break;
        case 4:

            break;
        case 0:
            return;
        default:
            break;
        }
    }
}


void Admin::ManageToOperations()
{
    int choice;
    while (true)
    {
        system("cls");
        std::cout <<
            "1.Показать все операции\n"
            "2.Применить фильтр поиска\n"
            "3.Рассмотреть операции\n"
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
            ReviseClientOperation();
            break;
        case 0:

            return;
        default:
            break;
        }
    }
}


void Admin::ShowAvailableUsers()
{
    list <string> ListOfUsers;
    string line;
    ifstream file;


    file.open("Operations.txt", ios::app);

    while (file.peek() != EOF) {
        getline(file, line);
        ListOfUsers.push_back(FindClientName(line.c_str()));
    }

    //Sotring the names
    ListOfUsers.sort();
    //Delete dupliates
    ListOfUsers.unique();
    //Delete the first void element
    ListOfUsers.pop_front();

    for (auto name : ListOfUsers) {
        cout << name << endl;
    }
    system("pause");
    file.close();
}


void Admin::ShowUserOperations()
{
    string line;
    ifstream file;


    string login;
    cout << "Введите логин пользователя: ";
    cin >> login;

    file.open("Operations.txt", ios::app);

    while (file.peek() != EOF) {
        getline(file, line);
        if (login == FindClientName(line.c_str())) {
            GetOperationInfo(line.c_str());
        }
    }
    system("pause");
    file.close();
}


void Admin::ReviseClientOperation()
{
    int i = 0;
    int decision;

    list <string> ListOfOperations;
    list <string> CurrentClientOperations;
    list <int> PositionOfClientInFile;

   // list <string> :: iterator it = 

    string line;
    ifstream file;

    string login;
    cout << "Введите логин пользователя: ";
    cin >> login;


    //Copy all info of operations 
    file.open("Operations.txt", ios::app);

    for (int i = 0; file.peek() != EOF; i++) {
        getline(file, line);
        ListOfOperations.push_back(line);
    }
    file.close();
    cout << "All data was saved\n";


    //Copy info of current user's operations and remember the position of this client in txt file
    file.open("Operations.txt", ios::app);

    for (int i = 0; file.peek() != EOF; i++) {
        getline(file, line);
        if (login == FindClientName(line.c_str())) {
            CurrentClientOperations.push_back(line);
            PositionOfClientInFile.push_back(i);
        }
    }
    file.close();
    cout << "All CLIENT data was saved\n";


    //Changing the const position of decision's status 1 - CONFIRM, 2 - REJECT 
    for (auto &name : CurrentClientOperations) {
        GetOperationInfo(name.c_str());
        cout << "1.Принять сбор\n"
                "2.Отклонить сбор\n"
                "0.Не рассматривать сбор\n"
                "Ваш выбор: ";
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

    
    for (auto name : CurrentClientOperations) {
        GetOperationInfo(name.c_str());
    }
    system("pause");


}
