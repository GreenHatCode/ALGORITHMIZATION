#include <iostream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    string input, ms;
    int number_int;
    bool fg1, fg2, fg3, fg4, fg5, fg6, fg7, fg8, fg9, fg0;

    fg0 = false;
    fg1 = false;
    fg2 = false;
    fg3 = false;
    fg4 = false;
    fg5 = false;
    fg6 = false;
    fg7 = false;
    fg8 = false;
    fg9 = false;

    ms = "ќтвет: ";

    cout << "¬ведите номер телефона: ";
    cin >> input;

    if (input.length() == 9)
    {
        for (int i = 0; i < input.length(); i++)
        {
            if ((int)input[i] == 48)fg0 = true; //0
            if ((int)input[i] == 49)fg1 = true; //1
            if ((int)input[i] == 50)fg2 = true; //2
            if ((int)input[i] == 51)fg3 = true; //3
            if ((int)input[i] == 52)fg4 = true; //4
            if ((int)input[i] == 53)fg5 = true; //5
            if ((int)input[i] == 54)fg6 = true; //6
            if ((int)input[i] == 55)fg7 = true; //7
            if ((int)input[i] == 56)fg8 = true; //8
            if ((int)input[i] == 57)fg9 = true; //9
        }

        ms += "в номере отсутствуют ";

        if (fg0 == false)ms += "0,";
        if (fg1 == false)ms += "1,";
        if (fg2 == false)ms += "2,";
        if (fg3 == false)ms += "3,";
        if (fg4 == false)ms += "4,";
        if (fg5 == false)ms += "5,";
        if (fg6 == false)ms += "6,";
        if (fg7 == false)ms += "7,";
        if (fg8 == false)ms += "8,";
        if (fg9 == false)ms += "9,";

        ms.erase((ms.length()-1), 1);
        ms += ".";

    }
    else
    {
        ms += "это не номер телефона";
    }
    
    cout << ms;

}

