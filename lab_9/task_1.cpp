#include <iostream>
#include <Windows.h>

using namespace std;

double divide(double a, double b) {
    return a / b;
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    cout << "=========================================" << endl;
    cout << "Вычислить частное двух вещественных чисел" << endl;
    cout << "=========================================" << endl << endl;

    double a, b;

    cout << "Введите число a: ";
    while (!(cin >> a)) {
        cout << "Ошибка! Введите корректное дробное число a: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << endl << "Введите число b (кроме нуля): ";
    while (!(cin >> b) or (b == 0)) {
        cout << "Ошибка! Введите корректное дробное число b: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "--- Частное двух чисел ---" << endl;
    cout << "a / b = " << divide(a, b);

    return 0;
}
