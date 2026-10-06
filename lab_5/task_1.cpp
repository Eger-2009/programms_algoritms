#include <iostream>
#include <iomanip>
#include <cmath>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    double a, b, h;

    cout << "\t\t\t\t\t\t=========================\n";
    cout << "\t\t\t\t\t\tТабуляция функции y = 1/x\n";
    cout << "\t\t\t\t\t\t=========================\n";

    cout << "Введите начало интервала a: ";

    while (!(cin >> a)) {
        cout << "Ошибка! Введите число: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Введите конец интервала b: ";

    while (!(cin >> b)) {
        cout << "Ошибка! Введите число: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Введите шаг h: ";

    while (!(cin >> h)) {
        cout << "Ошибка! Введите число: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    if (a > b) {
        cout << "Ошибка! a должно быть <= b\n";
        return 1;
    }

    if (h <= 0) {
        cout << "Ошибка! h должно быть > 0\n";
        return 1;
    }

    std::cout << "\n+------------+------------+\n";
    std::cout << "|     x      |    y=1/x   |\n";
    std::cout << "+------------+------------+\n";

    for (double x = a; x <= b + 1e-9; x += h) {
        if (fabs(x) < 1e-9) {
            cout << "| " << setw(10) << x << " | НЕ ОПРЕД.  |\n";
            continue;
        }

        double y = 1.0 / x;
        cout << "| " << setw(10) << x << " | " << setw(10) << y << " |\n";
    }

    std::cout << "+------------+------------+\n";


    return 0;
}
