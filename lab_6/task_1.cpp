#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <cstdlib>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    cout << "=================================\n";
    cout << "Найти максимальный элемент списка\n";
    cout << "=================================\n\n\n";

    const int SIZE = 10;
    double list[SIZE], max_el = 1e-9;


    // Заполнение списка случайными числами
    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < SIZE; i++) {
        list[i] = rand() % 51;
    }

    // Вывод списка
    for (int i = 0; i < SIZE; i++) {
        cout << setw(3) << list[i];
    }

    // Нахождение максимального элемента
    for (int i = 0; i < SIZE; i++) {
        if (max_el < list[i]) max_el = list[i];
    }

    cout << "\nМаксимальный элемент списка: " << max_el;

    return 0;
}
