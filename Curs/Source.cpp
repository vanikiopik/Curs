#include <iostream>
#include <Windows.h>
#include "User.h"
#include "Client.h"
#include "UserInput.h"

void ShowMainMenu();
void ShowLoginMenu();
void ShowRegistrationMenu();
void ShowClientMenu();
void ShowAdminMenu();


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //stores the console's current dimensions

    MoveWindow(console, r.left, r.top, 1350, 700, TRUE); // 800 width, 100 height

    ShowMainMenu();

    return 0;
}


void ShowMainMenu() {
    int choice;

    while (true)
    {
        system("cls");
        std::cout <<
            "1.Зайти как пользователь\n"
            "2.Зайти как администратор\n"
            "3.Регистрация\n"
            "0.Выход\n"
            "Выберите пункт меню: ";
        std::cin >> choice;

        system("cls");

        switch (choice)
        {
        case 1:
            ShowClientMenu();
            break;
        case 2:
            ShowAdminMenu();
            break;
        case 3:
            ShowRegistrationMenu();
            break;
        default:
            break;
        }
    }
}


bool isInClientBase() {
    return false;
}

bool isInAdminBase() {
    return false;
}


void ShowLoginMenu() {
    std::string login, password;

    login = StringInput("Введите логин");

}


void ShowClientMenu() {
    Client client;

    client.UserMenu();
}


void ShowAdminMenu() {
}


void ShowRegistrationMenu() {

}
