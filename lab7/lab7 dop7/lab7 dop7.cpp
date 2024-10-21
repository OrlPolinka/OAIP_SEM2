#include "Header.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	int choice;
	int x;
	Stack* myStk = new Stack; //выделение памяти для стека
	myStk = NULL;             //инициализация первого элемента
	do {
		cout << "Меню: " << endl;
		cout << "1.Добавление элемента в стек" << endl;
		cout << "2.Вывод стека на экран" << endl;
		cout << "3.Запись в файл" << endl;
		cout << "4.Считывание из файла" << endl;
		cout << "5.Удаление первого числа, которое больше 100" << endl;
		cout << "6.Вывод стека и очистка стека" << endl;
		cout << "0.Завершение работы" << endl;
		cout << "Ваш выбор: " << endl;
		cin >> choice;

		switch (choice) {
		case 1: {
			cout << "Введите элемент: " << endl;
			cin >> x;
			push(x, myStk);
			break;
		}
		case 2: {
			show(myStk);
			break;
		}
		case 5: {
			function(myStk);
			break;
		}
		case 6: {
			cout << "Весь стек: " << endl;
			clear(myStk);
			break;
		}
		case 3: {
			toFile(myStk);
			break;
		}
		case 4: {
			fromFile(myStk);
			break;
		}
		}
	} while (choice != 0);

	return 0;
}