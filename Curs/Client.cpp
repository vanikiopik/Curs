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
            "0. Назад\n";
            choice = IntInput("Выберите пункт меню: ");

        system("cls");

        switch (choice)
        {
        case 1:
            cout << "Логин: " << GetLogin() << " | Пароль: " << GetPassword() << endl;
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
            "0. Назад\n";
            choice = IntInput("Выберите пункт меню: ");

        system("cls");

        switch (choice)
        {
        case 1:
            cout << "ВВОЗ\n"
                "Номер\tНаименование\t\tКатегория\t\tПроцент за ед.\n"
                "1\tПродукты\t\tПродукты\t\t7%\n"
                "2\tМясные изделия\t\tПродукты\t\t7% +3%\n"
                "3\tАлкоголь\t\tПродукты\t\t7% +5%\n"
                "4\tТабак\t\t\tПродукты\t\t7% +8%\n"
                "5\tНепродовольствие\tНепродовольствие\t15%\n"
                "6\tТопливо\t\t\tНепродовольствие\t15% +10%\n"
                "7\tОдежда\t\t\tНепродовольствие\t15% +3%\n"
                "8\tЭлектротовары\t\tНепродовольствие\t15% +5%\n"
                "9\tПарфюмерия\t\tНепродовольствие\t15% +7%\n";
                system("pause");
                break;
        case 2:
            cout << "ВЫВОЗ\n"
                "Номер\tНаименование\t\tКатегория\t\tПроцент за ед.\n"
                "1\tПродукты\t\tПродукты\t\t10%\n"
                "2\tМясные изделия\t\tПродукты\t\t10% +7%\n"
                "3\tАлкоголь\t\tПродукты\t\t10% +10%\n"
                "4\tТабак\t\t\tПродукты\t\t10% +13%\n"
                "5\tНепродовольствие\tНепродовольствие\t20%\n"
                "6\tТопливо\t\t\tНепродовольствие\t20% +15%\n"
                "7\tОдежда\t\t\tНепродовольствие\t20% +6%\n"
                "8\tЭлектротовары\t\tНепродовольствие\t20% +9%\n"
                "9\tПарфюмерия\t\tНепродовольствие\t20% +10%\n";
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
        cout << "ВВОЗ\n"
            "Номер\tНаименование\t\tКатегория\t\tПроцент за ед.\n"
            "1\tПродукты\t\tПродукты\t\t7%\n"
            "2\tМясные изделия\t\tПродукты\t\t7% +3%\n"
            "3\tАлкоголь\t\tПродукты\t\t7% +5%\n"
            "4\tТабак\t\t\tПродукты\t\t7% +8%\n"
            "5\tНепродовольствие\tНепродовольствие\t15%\n"
            "6\tТопливо\t\t\tНепродовольствие\t15% +10%\n"
            "7\tОдежда\t\t\tНепродовольствие\t15% +3%\n"
            "8\tЭлектротовары\t\tНепродовольствие\t15% +5%\n"
            "9\tПарфюмерия\t\tНепродовольствие\t15% +7%\n";
        break;
    case 2:
        cout << "ВЫВОЗ\n"
            "Номер\tНаименование\t\tКатегория\t\tПроцент за ед.\n"
            "1\tПродукты\t\tПродукты\t\t10%\n"
            "2\tМясные изделия\t\tПродукты\t\t10% +7%\n"
            "3\tАлкоголь\t\tПродукты\t\t10% +10%\n"
            "4\tТабак\t\t\tПродукты\t\t10% +13%\n"
            "5\tНепродовольствие\tНепродовольствие\t20%\n"
            "6\tТопливо\t\t\tНепродовольствие\t20% +15%\n"
            "7\tОдежда\t\t\tНепродовольствие\t20% +6%\n"
            "8\tЭлектротовары\t\tНепродовольствие\t20% +9%\n"
            "9\tПарфюмерия\t\tНепродовольствие\t20% +10%\n";
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
            "1.Показать список операций\n"
            "2.Составить заявку на ввоз\n"
            "3.Составить заявку на вывоз\n"
            "4.Найти заявку\n"
            "5.Отменить заявку\n"
            "6.Применить фильтр поиска\n"
            "7.Отсортировать операции\n"
            "0.Назад\n";
            choice = IntInput("Выберите пункт меню: ");

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
    
    number = IntInput("Введите ID заявки : ");
    
    
    ShowFeesTableHeader();
    while (getline(file, line)) {
        if (to_string(number) == GetIDOfOrder(line.c_str())) {
            if (GetLogin() == FindClientName(line.c_str())) {
                GetOperationInfo(line.c_str());
                system("pause");
                break;
            }
            else {
                cout << "Отказано в доступе\n";
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
    ID = IntPositiveInput("Введите ID: ");


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
        cout << "!!!Сортировка происхоит по возрастанию!!!\n";
        cout << "1.Сортировать по количеству товара\n";
        cout << "2.Сортировать по названию товара\n";
        cout << "0. Назад\n";
        choice = IntInput("Выберите пункт меню: ");

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
            "1.Рассмотреть заявки на вывоз\n"
            "2.Рассмотреть заявки на ввоз\n"
            "0.Назад\n";
            choice = IntInput("Выберите пункт меню: ");

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
            "1.Просмотреть принятые заявки\n"
            "2.Просмотреть отклонённые заявки\n"
            "3.Посмотреть не рассмотренные заявки\n"
            "0.Назад\n";
            choice = IntInput("Выберите пункт меню: ");

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
            "1. Продукты\n"
            "2. Мясные изделия\n"
            "3. Алкоголь\n"
            "4. Табак\n"
            "5. Непродовольственные\n"
            "6. Топливо\n"
            "7. Одежда\n"
            "8. Электротовары\n"
            "9. Парфюмерия\n"
            "0.Назад\n";
            choice = IntInput("Выберите пункт меню: ");

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
            "1.Применить фильтр для ввоза/вывоза заявок\n"
            "2.Применить фильтр для статуса заявок\n"
            "3.Применить фильтр для наименования товара в заявке\n"
            "0.Назад\n";
            choice = IntInput("Выберите пункт меню: ");

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

    ID_tovar = IntProductIDInput("Введите ID товара: ");
    Count = IntPositiveInput("Введите количество товара: ");
    Price = FloatMoneyInput("Введите цену товара за одну еденицу: "); //Сделать Input для денег и сделать его float!!!!!

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

    ID_tovar = IntProductIDInput("Введите ID товара: ");
    Count = IntPositiveInput("Введите количество товара: ");
    Price = FloatMoneyInput("Введите цену товара за одну еденицу: "); //Сделать Input для денег и сделать его float!!!!!

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
