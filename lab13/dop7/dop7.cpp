﻿#include "Hash.h"
#include <iostream>
#include <ctime> 

using namespace std;
struct AAA
{
	int key;
	char* mas;
	AAA(int k, char* z)
	{
		key = k;  mas = z;
	} AAA() {}
};
//-------------------------------
int key(void* d)
{
	AAA* f = (AAA*)d;
	return f->key;
}
//-------------------------------
void AAA_print(void* d)
{
	cout << " ключ " << ((AAA*)d)->key << " - " << ((AAA*)d)->mas << endl;
}
//-------------------------------
int main()
{
	
	setlocale(LC_ALL, "rus");
	int siz = 10, choice, k;
	cout << "Введите размер хеш-таблицы" << endl;
	cin >> siz;
	Object H = create(siz, key);
	Object H1 = create(32, key);
	Object H2 = create(64, key);
	Object H3 = create(128, key);
	for (;;)
	{
		cout << "1 - вывод хеш-таблицы" << endl;
		cout << "2 - добавление элемента" << endl;
		cout << "3 - удаление элемента" << endl;
		cout << "4 - поиск элемента" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;   cin >> choice;
		switch (choice)
		{
		case 0: exit(0);
		case 1: H.scan(AAA_print);  break;
		case 2: {  AAA* a = new AAA;
			char* str = new char[20];
			cout << "введите ключ" << endl;
			cin >> k;
			a->key = k;
			cout << "введите строку" << endl;
			cin >> str;
			a->mas = str;
			if (H.N == H.size && H1.N == H1.size && H2.N == H2.size && H3.N == H3.size)
				cout << "Таблица заполнена" << endl;
			else {
				H.insert(a);
				H1.insert(a);
				H2.insert(a);
				H3.insert(a);
			}
		} break;
		case 3: {  cout << "введите ключ для удаления" << endl;
			cin >> k;
			H.deleteByKey(k);
		}  break;
		case 4: {  cout << "введите ключ для поиска" << endl;
			cin >> k;
			if (H.search(k) == NULL)
				cout << "Элемент не найден" << endl;
			else
				AAA_print(H.search(k));

			clock_t start1 = clock();
			H1.search(k);
			clock_t stop1 = clock();
			long long duration1 = (stop1 - start1) * 1000 / CLOCKS_PER_SEC;
			cout << "Время поиска элемента для размера 32 " << duration1 << " милисекунд." << endl;

			clock_t start2 = clock();
			H2.search(k);
			clock_t stop2 = clock();
			long long duration2 = (stop2 - start2) * 1000 / CLOCKS_PER_SEC;
			cout << "Время поиска элемента для размера 64 " << duration2 << " милисекунд." << endl;

			clock_t start3 = clock();
			H3.search(k);
			clock_t stop3 = clock();
			long long duration3 = (stop3 - start3) * 1000 / CLOCKS_PER_SEC;
			cout << "Время поиска элемента для размера 128 " << duration3 << " милисекунд." << endl;
		}  break;
		}
	}
	return 0;
}

