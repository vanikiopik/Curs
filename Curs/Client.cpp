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
                "1\tМясные изделия\t\tПродукты\t\t7% +3%\n"
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
                "0\tПродукты\t\tПродукты\t\t10%\n"
                "1\tМясные изделия\t\tПродукты\t\t10% +7%\n"
                "2\tАлкоголь\t\tПродукты\t\t10% +10%\n"
                "3\tТабак\t\t\tПродукты\t\t10% +13%\n"
                "4\tНепродовольствие\tНепродовольствие\t20%\n"
                "5\tТопливо\t\t\tНепродовольствие\t20% +15%\n"
                "6\tОдежда\t\t\tНепродовольствие\t20% +6%\n"
                "7\tЭлектротовары\t\tНепродовольствие\t20% +9%\n"
                "8\tПарфюмерия\t\tНепродовольствие\t20% +10%\n";
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
            "4.Найти заявку\n"
            "5.Отменить заявку\n"
            "6. Отсортировать операции\n"
            "0.Назад\n"
            "Выберите пункт меню: ";
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
            //Sort by value of products, not changing file

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
    
    
    cout << "Введите ID заявки: ";
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
    cout << "Введите ID заявки: ";
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


void Client::CreateOperationToImport()
{
    const int IMPORT = 1;
    const int STATUS = 0;
    int ID_tovar;
    int Count;
    cout << "Введите ID товара: "; cin >> ID_tovar;
    cout << "\nВведите количество товара: "; cin >> Count;

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
    cout << "Введите ID товара: "; cin >> ID_tovar;
    cout << "\nВведите количество товара: "; cin >> Count;


    fstream file;
    file.open("Operations.txt", ios::app);
    file << IMPORT << "_" << STATUS << "_" << ID_tovar << "_" << Count << "_" << GetLastOrderID() << " " << this->GetLogin() << "\n";
    file.close();
}
