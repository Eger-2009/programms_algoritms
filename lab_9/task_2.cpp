#include <iostream>
#include <Windows.h>
#include <random>

using namespace std;


// скелет (прототип) ф-й
void fillPrintArray(int arr[], int size);
void maxElArray(int arr[], int size);


int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);


    cout << "==================================" << endl;
    cout << "Найти максимальный элемент массива" << endl;
    cout << "==================================" << endl << endl;

    int arr[5];

    cout << "--- Массив ---\n";
    fillPrintArray(arr, 5);

    cout << "Максимальное число массива: ";
    maxElArray(arr, 5);
    
    return 0;
}


// ф-я заполнения массима случайными числами от 0 до 99 и вывода
void fillPrintArray(int arr[], int size) {
    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ф-я нахождения наибольшего числа массива
void maxElArray(int arr[], int size) {
    int max_el = 0;
    for (int i = 0; i < size; i++) {
        if (max_el < arr[i]) {
            max_el = arr[i];
        }
    }
    cout << max_el << endl;
}
