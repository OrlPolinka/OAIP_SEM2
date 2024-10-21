#include "List.h"
#include <iostream>
using namespace std;

struct Car
{
	string marka; //марка машины
	string color; //цвет
	int number; //заводсокй номер
	string datev; //дата выпуска в формате dd.mm.yyyy
	string kyzov; // тип кузова
	string datet; //дата последнего техосмотра в формате dd.mm.yyyy  
	string name; //владелец
	Car* next;
};

void print(void* b)       //Функция используется при выводе 
{
	Car* a = (Car*)b;
	cout << a->marka << "  " << a->color << " " << a->number << " " << a->datev << " " << a->kyzov << " " << a->datet << " " << a->name << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	bool rc;
	Object L1 = Create();   // создание списка с именем L1
	Car a1 = { "Джип", "красный", 1245, "12.02.2020","седан", "01.02.2024", "Сергей" };
	Car a2 = { "Мерседес", "белый", 9834, "27.11.2017","универсал", "27.03.2022", "Даниил" };
	Car a3 = { "Ауди", "черная", 7788, "01.09.2023","седан", "30.01.2024", "Григорий" };
	int choice;
	do {
		cout << "\n\nМеню:" << endl;
		cout << "1. Добавление элемментов в список" << endl;
		cout << "2. Печать списка" << endl;
		cout << "3. Поиск элемента" << endl;
		cout << "4. Удаление элемента" << endl;
		cout << "5. Подсчет количества элементов в списке" << endl;
		cout << "6. Очистка списка" << endl;
		cout << "0. Выход" << endl << endl;
		cout << "Ваш выбор: ";
		cin >> choice;

		switch (choice) {
		case 1: {

			L1.Insert(&a1);
			L1.Insert(&a2);
			L1.Insert(&a3);
			cout << "\nЭлементы добавлены в список";
			break;
		}
		case 2: {
			cout << "\nСписок:" << endl;
			L1.PrintList(print);
			break;
		}
		case 3: {
			Element* e = L1.Search(&a3);
			Car* aa = (Car*)e->Data;
			cout << "\nНайден элемент = " << aa->name << endl;
			break;
		}
		case 4: {
			rc = L1.Delete(&a2);
			if (rc == true) cout << "\nУдален элемент" << endl;
			break;
		}
		case 5: {
			cout << "\nКоличество элементов в списке: " << L1.CountList();
			break;
		}
		case 6: {
			L1.DeleteList();
			cout << "\nСписок очищен";
			break;
		}
		}
	} while (choice != 0);
	
	return 0;
}
