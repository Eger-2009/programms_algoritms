#include <iostream>
#include <Windows.h>
#include <random>

using namespace std;

// Максимальное количество записей в истории
const int MAX_HISTORY = 10;

// массивы для хранения истории
double historyOp1[MAX_HISTORY];   // первый операнд
double historyOp2[MAX_HISTORY];   // второй операнд
char   historySign[MAX_HISTORY];  // знак операции
double historyRes[MAX_HISTORY];   // результат
int    historyCount = 0;          // количество записей

// скелет ф-й
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
void saveToHistory(double op1, double op2, char sign, double result);
void showHistory();
void calculate();
void showMenu();


int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);


    cout << "==========" << endl;
    cout << "Calculator" << endl;
    cout << "==========" << endl << endl;

    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            calculate();
            break;
        case 2:
            showHistory();
            break;
        case 3:
            historyCount = 0;
            cout << "История очищена." << endl;
            break;
        case 4:
            cout << "До свидания!" << endl;
            break;
        default:
            cout << "Неверный выбор!" << endl;
        }
    } while (choice != 4);

    return 0;
}


// ===== Арифметические функции =====
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        cout << "Ошибка: деление на ноль!" << endl;
        return 0;
    }
    return a / b;
}

// ===== Функция сохранения результата в массив истории =====
void saveToHistory(double op1, double op2, char sign, double result) {
    if (historyCount < MAX_HISTORY) {
        historyOp1[historyCount] = op1;
        historyOp2[historyCount] = op2;
        historySign[historyCount] = sign;
        historyRes[historyCount] = result;
        historyCount++;
    }
    else {
        cout << "История заполнена!" << endl;
    }
}

// ===== Функция вывода истории =====
void showHistory() {
    if (historyCount == 0) {
        cout << "\nИстория пуста." << endl;
        return;
    }

    cout << "\n=== История операций ===" << endl;
    for (int i = 0; i < historyCount; i++) {
        cout << i + 1 << ". "
            << historyOp1[i] << " "
            << historySign[i] << " "
            << historyOp2[i] << " = "
            << historyRes[i] << endl;
    }
    cout << "========================" << endl;
}

// ===== Функция выполнения вычисления =====
void calculate() {
    double num1, num2, result;
    char sign;

    cout << "\nВведите первый операнд: ";
    cin >> num1;

    cout << "Введите операцию (+, -, *, /): ";
    cin >> sign;

    cout << "Введите второй операнд: ";
    cin >> num2;


    // Выполнение операции
    switch (sign) {
    case '+': result = add(num1, num2); break;
    case '-': result = subtract(num1, num2); break;
    case '*': result = multiply(num1, num2); break;
    case '/': {
        if (num2 == 0) {
            cout << "Ошибка! На ноль деление невозможно!";
        }
        result = divide(num1, num2);
        break;
    }
    default:
        cout << "Неизвестная операция!" << endl;
        return;
    }

    cout << "Результат: " << num1 << " " << sign << " " << num2
        << " = " << result << endl;

    // Сохранение в историю
    saveToHistory(num1, num2, sign, result);
}

// ===== Функция отображения меню =====
void showMenu() {
    cout << "\n=== Калькулятор ===" << endl;
    cout << "1. Выполнить вычисление" << endl;
    cout << "2. Показать историю" << endl;
    cout << "3. Очистить историю" << endl;
    cout << "4. Выход" << endl;
    cout << "===================" << endl;
    cout << "Выберите действие: ";
}
