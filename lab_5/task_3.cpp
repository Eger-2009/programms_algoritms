#include <iostream>
#include <iomanip>
#include <cmath>
#include <Windows.h>

using namespace std;

double lnTaylor(double x, double epsilon, int& iterations) {
    double sum = 0.0;
    double term = x;  // первый член ряда: a_1 = x
    int n = 1;
    iterations = 0;

    while (fabs(term) > epsilon) {
        sum += term;
        iterations++;      // считаем итерации

        // a_{n+1} = -a_n * x * n / (n+1)
        term = -term * x * n / (n + 1);
        n++;
    }

    return sum;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    double a, b, h, epsilon;

    cout << "\t\t\t\t\t\t==========================================\n";
    cout << "\t\t\t\t\t\tтабуляция y = ln(1+x) и суммы ряда Тейлора\n";
    cout << "\t\t\t\t\t\t==========================================\n";

    cout << "Введите начало интервала a (|a| < 1): ";

    while (!(cin >> a)) {
        cout << "Ошибка! Введите число: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Введите конец интервала b (|b| < 1): ";

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

    cout << "Введите точность epsilon (например, 1e-6): ";
    while (!(cin >> epsilon)) {
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

    if (fabs(a) >= 1 || fabs(b) >= 1) {
        cout << "Ошибка: интервал должен быть в пределах |x| < 1 " << "(область сходимости ряда)!" << endl;
        return 1;
    }

    if (epsilon <= 0) {
        cout << "Ошибка: точность должна быть положительной!" << endl;
        return 1;
    }

    cout << "\n+------+------------+------------+------------+------+\n";
    cout << "|  x   |  ln(1+x)   | Ряд Тейлора| Погрешность| Итер |\n";
    cout << "+------+------------+------------+------------+------+\n";
    cout << fixed << setprecision(6);

    double totalError = 0.0;
    int totalIterations = 0;
    int pointCount = 0;

    for (double x = a; x <= b + 1e-9; x += h) {

        if (x <= -1 + 1e-9) {
            cout << "| " << setw(4) << x
                << " |  НЕ ОПРЕД. |     -      |     -      |  -   |\n";
            continue;
        }

        double yLib = log(1 + x);

        // Вычисление через ряд Тейлора
        int iter = 0;
        double yTaylor = lnTaylor(x, epsilon, iter);

        // Погрешность
        double error = fabs(yLib - yTaylor);

        cout << "| " << setw(4) << x
            << " | " << setw(10) << yLib
            << " | " << setw(10) << yTaylor
            << " | " << setw(10) << error
            << " | " << setw(4) << iter << " |\n";

        // Накопление статистики
        totalError += error;
        totalIterations += iter;
        pointCount++;
    }

    cout << "+------+------------+------------+------------+------+\n";

    cout << "\n=== Статистика ===" << endl;
    cout << "Количество точек:          " << pointCount << endl;
    cout << "Средняя погрешность:       " << totalError / pointCount << endl;
    cout << "Среднее число итераций:    " << totalIterations / pointCount << endl;
    cout << "Заданная точность epsilon: " << epsilon << endl;

    return 0;
}
