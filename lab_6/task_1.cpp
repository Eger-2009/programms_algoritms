#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    cout << "=================================\n";
    cout << "Найти максимальный элемент списка\n";
    cout << "=================================\n\n\n";

    double list[6], max_el = 1e-9;

    for (int i = 0; i <= 5 ; i++) {
        double num_list;

        cout << "Введите " << i + 1 << "-й элемент списка: ";
        
        while (!(cin >> num_list)) {
            cout << "Ошибка ввода! Введите корректное число: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        list[i] = num_list;

    }

    for (int i = 0; i <= 5; i++) {
        if (max_el < list[i]) max_el = list[i];
    }
    
    cout << "\nМаксимальный элемент списка: " << max_el;

    return 0;
}
