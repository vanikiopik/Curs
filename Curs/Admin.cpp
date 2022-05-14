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
            "3.Рассмотреть операцию\n"
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
        case 0:

            return;
        default:
            break;
        }
    }
}

void Admin::ShowAvailableUsers()
{
    list <string> ListOfNames;
    string line;
    ifstream file;


    file.open("Operations.txt", ios::app);

    while (file.peek() != EOF) {
        getline(file, line);
        ListOfNames.push_back(FindClientName(line.c_str()));
    }

    //Sotring the names
    ListOfNames.sort();
    //Delete dupliates
    ListOfNames.unique();
    //Delete the first void element
    ListOfNames.pop_front();

    for (auto name : ListOfNames) {
        cout << name << endl;
    }
    system("pause");
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
}
