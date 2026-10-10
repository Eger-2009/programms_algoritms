#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <cstdlib>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    cout << "=================================\n";
    cout << "Найти количество двузначных чисел\n";
    cout << "=================================\n\n\n";

    const int SIZE = 20;
    int arr[SIZE];
    int count_num = 0;

    // заполнение списка случайными числами
    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = 10 + rand() % 90;
    }

    // Вывод списка на экран
    cout << "Сгенерированный рандомом список:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << setw(4) << arr[i];
    }

    for (int i = 0; i < SIZE; i++) {
        if (arr[i] >= 10 || arr[i] <= 99) { count_num++; }
    }
    // Поскольку весь диапазон 10..99 состоит только из двузначных чисел,
    // результат всегда будет равен 20 (размеру массива).
    // Если бы диапазон был шире (например, 1..200), тогда проверка имела бы практический смысл.

    cout << "\n\nКол-во двухзначный чисел: " << count_num;

    return 0;
}
