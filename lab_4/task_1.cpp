// ==========
// Время года
// ==========


#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	cout << "\t\t\t\t\t==========\n";
	cout << "\t\t\t\t\tВремя года\n";
	cout << "\t\t\t\t\t==========\n\n";

	int seasons; // переменная типа инт - время года - (1-4)

	bool Flag = { true }; // объявляем флаг для while

	cout << "1. Зима\n"; 
	cout << "2. Весна\n";
	cout << "3. Лето\n";
	cout << "4. Осень\n";

	while (Flag) {
		cout << "Введите время года 1-4: ";
		cin >> seasons;

		if (cin.fail()) {
			cout << "Неверный ввод!\n\n";

			cin.clear();
			cin.ignore(10000, '\n');

		}
		else {
			switch (seasons) {
				case 1:
					cout << "Зима";
					Flag = false;
					break;
				case 2:
					cout << "Весна";
					Flag = false;
					break;
				case 3:
					cout << "Лето";
					Flag = false;
					break;
				case 4:
					cout << "Осень";
					Flag = false;
					break;

				default:
					cout << "Неверный ввод!\n\n";

					cin.clear();
					cin.ignore(10000, '\n');
			}
		}

		

	}

	return 0;
}
