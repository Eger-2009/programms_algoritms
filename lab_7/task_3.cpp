#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    srand(time(nullptr));

    cout << "=======================\n";
    cout << "Умножение матриц A на B\n";
    cout << "=======================\n\n";

    const int ROWS_A = 2, ROWS_B = 3;
    const int COLS_A = 3, COLS_B = 4;
    int arr_A[ROWS_A][COLS_A], arr_B[ROWS_B][COLS_B], arr_C[ROWS_A][COLS_B] = { 0 };
    int count_pol = { 0 }, count_otr = { 0 }, nyli = { 0 };

    // заполнение матрицы A случайными числами от 1 до 10
    for (int i = 0; i < ROWS_A; i++){
        for (int j = 0; j < COLS_A; j++) {
            arr_A[i][j] = 1 + rand() % 9;
        }
    }

    // заполнение матрицы B случайными числами от 1 до 10
    for (int i = 0; i < ROWS_B; i++) {
        for (int j = 0; j < COLS_B; j++) {
            arr_B[i][j] = 1 + rand() % 9;
        }
    }

    cout << "--- Полученная матрица A ---" << endl;
    //Вывод матрицы A
    for (int i = 0; i < ROWS_A; i++) {
        for (int j = 0; j < COLS_A; j++) {
            cout << setw(4) << arr_A[i][j];
        }
        cout << "\n";
    }

    cout << "--- Полученная матрица B ---" << endl;
    //Вывод матрицы B
    for (int i = 0; i < ROWS_B; i++) {
        for (int j = 0; j < COLS_B; j++) {
            cout << setw(4) << arr_B[i][j];
        }
        cout << "\n";
    }

    // умножение матриц A на B 
    for (int i = 0; i < ROWS_A; i++) {
        for (int j = 0; j < COLS_B; j++) {
            for (int k = 0; k < ROWS_B; k++) {
                arr_C[i][j] += arr_A[i][k] * arr_B[k][j];
            }
        }
    }

    cout << "--- Полученная матрица C ---" << endl;
    //Вывод матрицы C
    for (int i = 0; i < ROWS_A; i++) {
        for (int j = 0; j < COLS_B; j++) {
            cout << setw(4) << arr_C[i][j];
        }
        cout << "\n";
    }

    return 0;
}
