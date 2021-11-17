#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

bool checkChar(char check);
void encryptLine(string line, int shift);
void decryptLine(string line, int shift);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Что вы хотите сделать? (1 - зашифровать строку, 2 - дешифровать строку)" << endl;
    int input;
    cin >> input;

    string line;
    cout << "Введите строку: ";
    cin >> line;

    int shift;
    cout << "Введите значение сдвига: ";
    cin >> shift;

    switch (input)
    {
    case 1:
        encryptLine(line, shift);
        break;
    case 2:
        decryptLine(line, shift);
        break;
    default:
        cout << "Неверный ввод" << endl;
        break;
    }

}

bool checkChar(char check) {
    if (check == ' ' || check == '.' || check == ',' ||
        check == '!' || check == '?' || check == ':' ||
        check == ';') {
        return true;
    }
    else {
        return false;
    }
}

void encryptLine(string line, int shift)
{
    string encrypted_line;
    for (unsigned int i = 0; i < line.length(); i++)
    {
        if (checkChar(line[i]))
        {
            encrypted_line.push_back(line[i]);
        }
        else
        {
            unsigned char symbol = line[i] + shift;

            if (symbol > 'z')
            {
                symbol = 'a' + (symbol - 'z') - 1;
                encrypted_line.push_back(symbol);
            }
            else if (symbol < 'a') 
            {
                symbol = 'z' - ('a' - symbol) + 1;
                encrypted_line.push_back(symbol);
            }
            else 
            {
                encrypted_line.push_back(symbol);
            }
        }
    }

    cout << "Вывод результата: " << endl;
    cout << encrypted_line << endl;

    return;
}

void decryptLine(string line, int shift)
{
    string decrypted_line;
    for (unsigned int i = 0; i < line.length(); i++)
    {
        if (checkChar(line[i]))
        {
            decrypted_line.push_back(line[i]);
        }
        else
        {
            unsigned char symbol = line[i] - shift;

            if (symbol < 'a')
            {
                symbol = 'z' - ('a' - symbol) + 1;
                decrypted_line.push_back(symbol);
            }
            else if (symbol < 'a')
            {
                symbol = 'a' + (symbol - 'z') - 1;
                decrypted_line.push_back(symbol);
            }
            else
            {
                decrypted_line.push_back(symbol);
            }
        }
    }

    cout << "Вывод результата: " << endl;
    cout << decrypted_line << endl;

    return;
}