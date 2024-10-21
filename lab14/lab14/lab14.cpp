#include "Hash_Chain.h"
#include <iostream>
#include <string>
using namespace std;
struct AAA
{
	int number;
	string* name;
	AAA(int k, string* z)
	{
		number = k;
		name = z;
	}
	AAA()
	{
		number = 0;
		name = nullptr;
	}
};
// Функция hf, возвращающая хеш-значение ключа
int hf(void* d)
{
	AAA* f = (AAA*)d;
	return f->number;
}
//-------------------------------
void AAA_print(listx::Element* e)
{
	std::cout << ((AAA*)e->data)->number << '-' << *((AAA*)e->data)->name << " / ";
}
//-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	int current_size = 7;
	cout << "Введите размер хеш-таблицы" << endl;
	cin >> current_size;
	hashTC::Object H = hashTC::create(current_size, hf);
	int choice;
	int k;
	for (;;)
	{
		cout << "1 - вывод хеш-таблицы" << endl;
		cout << "2 - добавление номера счета" << endl;
		cout << "3 - удаление номера счета" << endl;
		cout << "4 - поиск номера счета" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: exit(0);
		case 2: {	AAA* a = new AAA;
			cout << "введите номер счета" << endl;
			cin >> k;
			a->number = k;
			cout << "введите ФИО" << endl;
			cin.ignore();
			string str;
			getline(cin, str);
			a->name = new string(str);
			H.insert(a);
		}
			  break;
		case 1: H.Scan();
			break;
		case 3: {	AAA* b = new AAA;
			cout << "введите номер счета" << endl;
			cin >> k;
			b->number = k;
			H.deleteByData(b);
		}
			  break;
		case 4: AAA * c = new AAA;
			cout << "введите номер счета" << endl;
			cin >> k;
			c->number = k;
			if (H.search(c) == NULL)
				cout << "Номер счета не найден" << endl;
			else
			{
				cout << "Первый клиент с данным номером счета" << endl;
				AAA_print(H.search(c));
				cout << endl;
			}
			break;
		}
	}
	return 0;
}
