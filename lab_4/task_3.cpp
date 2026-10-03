// =============
// Тест-тренажёр
// =============


#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int menuChoice = { 0 };       // выбор в меню
    int count = { 0 };   // счётчик правильных ответов
    bool testCompleted = { false }; // проходил ли тест

    // Главное меню (повторяется, пока не выберут выход)
    do {
        cout << "\t\t\t\t\t\t=============\n";
        cout << "\t\t\t\t\t\tТест-тренажёр\n";
        cout << "\t\t\t\t\t\t=============\n";
        cout << "1. Начать тест\n";
        cout << "2. Показать последние результаты\n";
        cout << "3. Выход\n";
        cout << "========================================\n";
        cout << "Ваш выбор: ";

        // Защита от ошибок ввода (пункт меню)
        while (!(cin >> menuChoice) || menuChoice < 1 || menuChoice > 3) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Ошибка! Введите число от 1 до 3: ";
        }
        cin.ignore(10000, '\n');

        switch (menuChoice) {

        case 1: {
            cout << "\n--- НАЧАЛО ТЕСТА ---\n\n";
            count = 0;

            // Цикл по 5 вопросам
            for (int i = 1; i <= 5; i++) {
                cout << "Вопрос " << i << "-й " << " из 5:\n";

                switch (i) {
                case 1:
                    cout << "Сколько будет 2 + 2\n";
                    cout << "1) 3\n";
                    cout << "2) 999\n";
                    cout << "3) 7\n";
                    cout << "4) 4\n";
                    break;
                case 2:
                    cout << "Какой тег используется для создания ссылки в HTML?\n";
                    cout << "1) link\n";
                    cout << "2) a\n";
                    cout << "3) href\n";
                    cout << "4) url\n";
                    break;
                case 3:
                    cout << "Какое свойство CSS задаёт цвет текста?\n";
                    cout << "1) text-color\n";
                    cout << "2) font-color\n";
                    cout << "3) color\n";
                    cout << "4) text-style\n";
                    break;
                case 4:
                    cout << "Кто такой Пушкин?\n";
                    cout << "1) Хороший человек\n";
                    cout << "2) Строитель\n";
                    cout << "3) Поэт\n";
                    cout << "4) Программист\n";
                    break;
                case 5:
                    cout << "Что значит оценка 5?\n";
                    cout << "1) Супер\n";
                    cout << "2) Отлично\n";
                    cout << "3) Хорошо\n";
                    cout << "4) Очень хорошо\n";
                    break;
                }

                cout << "Ваш ответ (1-4): ";

                // Защита от ошибок ввода (ответ на вопрос)
                int answer = 0;
                while (!(cin >> answer) || answer < 1 || answer > 4) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Ошибка! Введите число от 1 до 4: ";
                }
                cin.ignore(10000, '\n');

                switch (i) {
                case 1:
                    if (answer == 4) {
                        cout << "Правильно!\n";
                        count++;
                    }
                    else cout << "Неправильно. Правильный ответ: 1\n";
                    break;
                case 2:
                    if (answer == 2) {
                        cout << "Правильно!\n";
                        count++;
                    }
                    else cout << "Неправильно. Правильный ответ: 2\n";
                    break;
                case 3:
                    if (answer == 3) {
                        cout << "Правильно!\n";
                        count++;
                    }
                    else cout << "Неправильно. Правильный ответ: 3\n";
                    break;
                case 4:
                    if (answer == 3) {
                        cout << "Правильно!\n";
                        count++;
                    }
                    else cout << "Неправильно. Правильный ответ: 3\n";
                    break;
                case 5:
                    if (answer == 2) {
                        cout << "Правильно!\n";
                        count++;
                    }
                    else cout << "Неправильно. Правильный ответ: 2\n";
                    break;
                }
                cout << "\n";
            }

            testCompleted = true;

            cout << "========================================\n";
            cout << "       ТЕСТ ЗАВЕРШЁН!\n";
            cout << "========================================\n";
            cout << "Правильных ответов: " << count << " из 5\n";
            cout << "Ваша оценка: ";

            switch (count) {
            case 5: cout << "5 (Отлично)\n"; break;
            case 4: cout << "4 (Хорошо)\n"; break;
            case 3: cout << "3 (Удовлетворительно)\n"; break;
            default: cout << "2 (Неудовлетворительно)\n"; break;
            }
            break;
        }

        case 2: {
            if (!testCompleted) {
                cout << "\nВы ещё не проходили тест. Сначала выберите пункт 1.\n";
            }
            else {
                cout << "\n--- ПОСЛЕДНИЕ РЕЗУЛЬТАТЫ ---\n";
                cout << "Правильных ответов: " << count << " из 5\n";
                cout << "Ваша оценка: ";
                switch (count) {
                case 5: cout << "5 (Отлично)\n"; break;
                case 4: cout << "4 (Хорошо)\n"; break;
                case 3: cout << "3 (Удовлетворительно)\n"; break;
                default: cout << "2 (Неудовлетворительно)\n"; break;
                }
            }
            break;
        }

        case 3: {
            cout << "\nДо свидания!\n";
            break;
        }
        }

    } while (menuChoice != 3);

    return 0;
}
