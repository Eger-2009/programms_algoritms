#include <iostream>
#include <string>
#include <Windows.h>
#include <cctype>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    cout << "=================================================" << endl;
    cout << "Преобразовать все символы строки в нижний регистр" << endl;
    cout << "=================================================" << endl << endl;

    string str;
    int count = { 0 };
    bool Flag = { false };

    cout << "Введите строку: ";
    getline(cin, str);


    // перевод  в нижний регистр
    for (char& c : str) {
        c = tolower(c);
    }

    cout << "\n--- Строка, получившаяся после преобразований ---\n";
    cout << str;
