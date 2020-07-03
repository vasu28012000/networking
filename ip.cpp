#include <iostream>
#include<string>

using namespace std;

bool isValid(string str)
{
    return (stoi(str) >= 0 && stoi(str) <= 255 && (str.length() > 0 && str.length() < 4));
}

char classIP(string str)
{
    int a = stoi(str);

    if (a <= 127)
        return 'A';
    else if (a > 127 && a <= 191)
        return 'B';
    else if (a > 191 && a <= 223)
        return 'C';
    else if (a > 223 && a <= 239)
        return 'D';
    else
        return 'E';
}

int main()
{
    cout << "\nEnter IP address : ";
    string ip;
    getline(cin, ip);

    string buff = "";
    int var = 0, counter = 0;
    bool flag = true;
    char ip_class;

    while (var <= ip.length())
    {
        if (ip[ip.length() - 1] == '.')
        {
            cout << "\nInvalid IP!";
            return -1;
        }
        else if ((ip[var] != '.' && counter < 3) || (var < ip.length() && counter == 3))
            buff += ip[var];
        else
        {
            ++counter;
            if (!isValid(buff))
            {
                cout << "\nnot valid ip!";
                return -1;
            }

            if (flag)
            {
                ip_class = classIP(buff);
                flag = false;
            }

            buff = "";	
        }

        ++var;
    }

    if (counter == 4)
        cout << "\nvalid IP and class is " << ip_class;
    else
        cout << "\nInvalid IP!";

    cout << "\n\n";
    system("pause");
    return 0;
}
