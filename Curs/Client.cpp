#include "Client.h"

void Client::UserMenu()
{
    int choice;
    while (true)
    {
        //system("cls");
        std::cout <<
            "1.Показать персональную информацию\n"
            "2.Таблица процентов на сборы\n"
            "3.Операции\n"
            "0. Назад\n"
            "Выберите пункт меню: ";
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
            "1.Показать проценты на ввоз товаров\n"
            "2.Показать проценты на вывоз товаров\n"
            "0. Назад\n"
            "Выберите: ";
        std::cin >> choice;

        system("cls");

        switch (choice)
        {
        case 1:
            cout << "ВВОЗ\n"
                "Номер\tНаименование\t\tКатегория\t\tПроцент за ед.\n"
                "0\tПродукты\t\tПродукты\t\t7%\n"
                "1\tМясные изделия\t\tПродукты\t\t7%+ 3%\n"
                "2\tАлкоголь\t\tПродукты\t\t7% +5%\n"
                "3\tТабак\t\t\tПродукты\t\t7% +8%\n"
                "4\tНепродовольствие\tНепродовольствие\t15%\n"
                "5\tТопливо\t\t\tНепродовольствие\t15% +10%\n"
                "6\tОдежда\t\t\tНепродовольствие\t15% +3%\n"
                "7\tЭлектротовары\t\tНепродовольствие\t15% +5%\n"
                "8\tПарфюмерия\t\tНепродовольствие\t15% +7%\n";
            system("pause");
            break;
        case 2:
            cout << "ВЫВОЗ\n"
                "Номер\tНаименование\t\tКатегория\t\tПроцент за ед.\n"
                "9\tПродукты\t\tПродукты\t\t10%\n"
                "10\tМясные изделия\t\tПродукты\t\t10% +7%\n"
                "11\tАлкоголь\t\tПродукты\t\t10% +10%\n"
                "12\tТабак\t\t\tПродукты\t\t10% +13%\n"
                "13\tНепродовольствие\tНепродовольствие\t20%\n"
                "14\tТопливо\t\t\tНепродовольствие\t20% +15%\n"
                "15\tОдежда\t\t\tНепродовольствие\t20% +6%\n"
                "16\tЭлектротовары\t\tНепродовольствие\t20% +9%\n"
                "17\tПарфюмерия\t\tНепродовольствие\t20% +10%\n";
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
            "1.Показать список операций\n"
            "2.Составить заявку на ввоз\n"
            "3.Составить заявку на вывоз\n"
            "0.Отменить заявку\n"
            "Выберите пункт меню: ";
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
