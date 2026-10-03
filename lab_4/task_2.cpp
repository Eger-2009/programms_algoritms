// =============
// Сезон и месяц
// =============


#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	cout << "\t\t\t\t\t=============\n";
	cout << "\t\t\t\t\tСезон и месяц\n";
	cout << "\t\t\t\t\t=============\n\n";

	int seasons; // переменная типа инт - месяц - (1-12)

	bool Flag = { true }; // объявляем флаг для while

	while (Flag) {
		cout << "Введите месяц 1-12: ";
		cin >> seasons;

		if (cin.fail()) {
			cout << "Неверный ввод!\n\n";

			cin.clear();
			cin.ignore(10000, '\n');

		}
		else {
			switch (seasons) {
				case 1:
					cout << "Январь - Зима";
					Flag = false;
					break;
				case 2:
					cout << "Февраль - Зима";
					Flag = false;
					break;
				case 3:
					cout << "Март - Весна";
					Flag = false;
					break;
				case 4:
					cout << "Апрель - Весна";
					Flag = false;
					break;
				case 5:
					cout << "Май - Весна";
					Flag = false;
					break;
				case 6:
					cout << "Июнь - Лето";
					Flag = false;
					break;
				case 7:
					cout << "Июль - Лето";
					Flag = false;
					break;
				case 8:
					cout << "Август - Лето";
					Flag = false;
					break;
				case 9:
					cout << "Сентябрь - Осень";
					Flag = false;
					break;
				case 10:
					cout << "октябрь - Весна";
					Flag = false;
					break;
				case 11:
					cout << "Ноябрь - Весна";
					Flag = false;
					break;
				case 12:
					cout << "Декабрь - Зима";
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
