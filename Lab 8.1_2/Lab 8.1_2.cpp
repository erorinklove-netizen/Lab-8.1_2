// Lab 8.1_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
#define _CRT_SECURE_NO_WARNINGS // Щоб Visual Studio не сварилася на strcpy
#include <iostream>
#include <cstring>

using namespace std;

int CountWhileRec(const char* s, int i)
{
    // Перевіряємо просто чи не закінчився рядок
    if (s[i] == '\0')
        return 0;

    if (strncmp(s + i, "while", 5) == 0)
        return 1 + CountWhileRec(s, i + 5); // Крокуємо на 5 символів вперед

    return CountWhileRec(s, i + 1); // Крокуємо на 1 символ вперед
}

void ChangeWhileRec(const char* s, char* res, int i, int j)
{
    if (s[i] == '\0')
    {
        res[j] = '\0';
        return;
    }

    if (strncmp(s + i, "while", 5) == 0)
    {
        // Копіюємо зірочки в результат
        strcat(res + j, "*****");
        // Або вручну: res[j]=res[j+1]=res[j+2]=res[j+3]=res[j+4]='*';
        ChangeWhileRec(s, res, i + 5, j + 5);
    }
    else
    {
        res[j] = s[i];
        ChangeWhileRec(s, res, i + 1, j + 1);
    }
}

int main()
{
    char str[101];
    cout << "Enter string: ";
    cin.getline(str, 100);

    cout << "Count: " << CountWhileRec(str, 0) << endl;

    char res[201] = ""; // Важливо ініціалізувати порожнім рядком
    ChangeWhileRec(str, res, 0, 0);

    cout << "Result: " << res << endl;

    return 0;
}