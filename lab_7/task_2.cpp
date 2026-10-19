#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    srand(time(nullptr));

    cout << "=========================\n";
    cout << "Найтимаксимальный элемент\n";
    cout << "=========================\n\n";

    const int ROWS = 5;
    const int COLS = 5;
    int arr[ROWS][COLS];
    int count_pol = { 0 }, count_otr = { 0 }, nyli = { 0 };

    // заполнение матрицы случайными числами от -100 до 100
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++) {
            arr[i][j] = -100 + rand() % 200;
        }
    }

    cout << "--- Полученная матрица ---" << endl;
    //Вывод матрицы
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << setw(4) << arr[i][j];
        }
        cout << "\n";
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (arr[i][j] > 0) { count_pol++; }
            else if (arr[i][j] < 0) { count_otr++; }
            else { nyli++; }
        }
    }

    cout << "\nПоложительных чисел в массиве - " << count_pol << endl;
    cout << "Отрицательных чисел в массиве - " << count_otr << endl;
    cout << "Нулей в массиве - " << nyli << endl;

    return 0;
}
