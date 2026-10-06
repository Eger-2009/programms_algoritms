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
    cout << "\t\t\t\t\t\tтабуляция функции y = e^x\n";
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

    int positiveCount = 0;   // счётчик положительных значений
    double sum = 0.0;        // сумма всех значений (для среднего)
    int count = 0;           // общее количество точек
    double minY = exp(a);  // инициализация первым значением
    double maxY = minY;
    double xMin = a, xMax = a;

    cout << "\n+----------+------------+" << endl;
    cout << "|    x     |   e^x      |" << endl;
    cout << "+----------+------------+" << endl;
    cout << fixed << setprecision(4);

    for (double x = a; x <= b + 1e-9; x += h) {
        double y = exp(x);

        cout << "| " << setw(8) << x
            << " | " << setw(10) << y << " |" << endl;

        if (y > 0) positiveCount ++;

        sum += y;
        count++;

        if (y < minY) { minY = y; xMin = x; }
        if (y > maxY) { maxY = y; xMax = x; }
    }

    cout << "+----------+------------+" << endl;

    double average = sum / count;

    cout << "\n=== Результаты анализа ===" << endl;
    cout << "Количество точек:            " << count << endl;
    cout << "Количество положительных y:  " << positiveCount << endl;
    cout << "Сумма всех значений:         " << sum << endl;
    cout << "Среднее арифметическое:      " << average << endl;
    cout << "Минимум: e^(" << xMin << ") = " << minY << endl;
    cout << "Максимум: e^(" << xMax << ") = " << maxY << endl;


    return 0;
}
