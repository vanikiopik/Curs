#include "UserInput.h"

std::string StringInput(std::string_view message)
{
    return StringInput(message, "");
}

std::string StringInput(std::string_view message, std::string_view invalidChars)
{
    std::string str;
    while (true)
    {
        std::cout << message;
        std::cin >> str;

        if (str.empty())
            continue;

        bool invalidInput = false;

        for (char c : invalidChars)
        {
            if (str.contains(c))
            {
                invalidInput = true;
                break;
            }
        }

        if (invalidInput)
            continue;

        invalidInput = true;

        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] != ' ')
            {
                invalidInput = false;
                str = str.substr(i, str.size());
                break;
            }
        }

        if (invalidInput)
            continue;

        for (int i = str.size() - 1; i != 0; i--)
        {
            if (str[i] != ' ')
            {
                str = str.substr(0, i + 1);
                break;
            }
        }
        return str;
    }
}

int IntInput(std::string message)
{
    std::cout << message;
    int a;
    while (!(std::cin >> a) || (std::cin.peek() != '\n'))
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "ќшибка! ¬ведите число." << std::endl;
    }
    return a;
}


int IntProductIDInput(std::string message)
{
    std::cout << message;

    const int LOWID = 1;
    const int HIGHID = 9;
    int a;
    while (!(std::cin >> a) || (std::cin.peek() != '\n') || a < LOWID || a > HIGHID)
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "ќшибка! ¬ведите ID из таблицы " << std::endl;
    }
    return a;
}
