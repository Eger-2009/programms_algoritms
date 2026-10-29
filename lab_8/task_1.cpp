#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    srand(time(nullptr));

    cout << "=====================================================" << endl;
    cout << "Вввод строки и вывод ее символов на нечётных позициях" << endl;
    cout << "=====================================================" << endl << endl;

    string s;

    cout << "Введите строку: ";
    getline(cin, s);

    for (int i = 1; i < s.length(); i+=2) {
        cout << "Символ позиции [ " << i << " ]: " << s.at(i) << endl;
    }

    return 0;
}
