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

    const int SIZE = 15;
    int arr[SIZE];
    int index_arr, vibor, currentSize = SIZE;


    // Заполняем список случайнми числами от 0 до 100
    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 101;
    }

    // Выводим сгенерированный список
    cout << "Исходный массив (" << currentSize << " элементов):\n";
    for (int i = 0; i < SIZE; i++) {
        cout << setw(4) << arr[i];
    }

    cout << "\n\n\t--- Ваши действия: ---\n";
    cout << "1. --- Удалить рандомный элемент списка";
    cout << "\n2. --- Ввести самому индекс списка\n\n";


    // Проверка на корректность ввода
    cout << "Введите значение (1-2): ";
    while (!(cin >> vibor) || vibor < 1 || vibor > 2) {
        cout << "Ошибка ввода! Введите корректное значение (1-2): ";
        cin.clear();
        cin.ignore(10000, '\n');
    }


    switch (vibor) {
    case 1: {
        index_arr = rand() % currentSize;
        cout << "Случайный индекс для удаления: " << index_arr << " (значение: " << arr[index_arr] << ")" << endl;

        for (int i = index_arr; i < currentSize - 1; i++) {
            arr[i] = arr[i + 1];
        }

        currentSize--;

        cout << "Массив после удаления (" << currentSize << " элементов):\n";
        for (int i = 0; i < currentSize; i++) {
            cout << setw(4) << arr[i];
        }
        cout << "\n";

        break;
    }
    case 2: {
        cout << "Введите индекс элемента для удаления (0.." << currentSize - 1 << "): ";
        cin >> index_arr;

        if (index_arr < 0 || index_arr >= currentSize) {
            cout << "Ошибка!Индекс выходит за границы массива.\n";
            return 1;
        }

        cout << "\nУдаляем элемент с индексом " << index_arr
            << " (значение: " << arr[index_arr] << ")\n\n";

        for (int i = index_arr; i < currentSize - 1; i++) {
            arr[i] = arr[i + 1];
        }

        currentSize--;

        cout << "Массив после удаления (" << currentSize << " элементов):\n";
        for (int i = 0; i < currentSize; i++) {
            cout << setw(4) << arr[i];
        }
        cout << "\n";

        break;
    }
    }

    return 0;
}
