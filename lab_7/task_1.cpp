#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    cout << "=========================\n";
    cout << "Найтимаксимальный элемент\n";
    cout << "=========================\n";

    const int ROWS = 3;
    const int COLS = 4;
    int arr[ROWS][COLS];
    int max_el = 1e-9;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << "Введите [" << i << "]" << "[" << j << "] значение: ";
            int el_num;
            cin >> el_num;
            arr[i][j] = el_num;
        }
    }
    cout << "\n";

    cout << "Получившаяся матрица:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << setw(5) << arr[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++){
            if (arr[i][j] > max_el) { max_el = arr[i][j]; }
        }
    }

    cout << "Максимальный элемент матрицы:" << endl;
    cout << max_el;
    
    return 0;
}
