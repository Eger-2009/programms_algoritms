#include <iostream>
#include <Windows.h>
#include <string>
#include <cctype>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    cout << "=====================================================================" << endl;
    cout << "Поиск и замена всех вхождений подстроки (заменить все \"abc\" на \"def\")" << endl;
    cout << "=====================================================================" << endl << endl;

    string s;
    string find_str = "abc";
    string replace_str = "def";

    cout << "Введите строку: ";
    getline(cin, s);

    cout << endl << "Исходная строка: " << s << endl;

    int count = 0;
    int pos = 0;

    while ((pos = s.find(find_str, pos)) != string::npos) {
        s.replace(pos, find_str.length(), replace_str);
        count++;
        pos += replace_str.length();
    }

    cout << "Результат:  " << s << endl;
    cout << "Количество замен: " << count << endl;

    return 0;
}
