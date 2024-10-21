#include "Heap.h"
#include <iostream>

using namespace std;

heap::CMP cmpAAA(void* a1, void* a2)  //Функция сравнения для элементов типа ААА
{
#define A1 ((AAA*)a1) // Макроподстановка для преобразования указателя a1 в тип AAA
#define A2 ((AAA*)a2) // Макроподстановка для преобразования указателя a2 в тип AAA
	heap::CMP 
		rc = heap::EQUAL; 
	if (A1->x > A2->x) 
		rc = heap::GREAT; 
	else
		if (A2->x > A1->x) 
			rc = heap::LESS;
	return rc;
#undef A2
#undef A1 
}
//-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	int k, choice;
	heap::Heap h1 = heap::create(30, cmpAAA); // Создание объекта кучи с максимальным размером 30 и функцией сравнения cmpAAA
	heap::Heap h2 = heap::create(30, cmpAAA);
	for (;;)
	{
		cout << "1 - вывод кучи на экран" << endl;
		cout << "2 - добавить элемент" << endl;
		cout << "3 - удалить максимальный элемент" << endl;
		cout << "4 - удалить минимальный элемент" << endl;
		cout << "5 - удалить i-ый элемент" << endl;
		cout << "6 - объединение двух куч в одну" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl;  cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 1:  h1.scan(0);
			break;
		case 2: {	AAA* a = new AAA;
			cout << "введите ключ" << endl; 	
			cin >> k;
			a->x = k;
			h1.insert(a);
		}
			  break;
		case 3:   h1.extractMax();
			break;
		case 4:   h1.extractMin();
			break;
		case 5:   h1.extractI();
			break;
		case 6: {
			int k = 1;
			cout << "Введите вторую кучу:" << endl;
			while (k > 0) {
				AAA* a = new AAA;
				cout << "введите ключ" << endl;
				cin >> k;
				if (k > 0) {
					a->x = k;
					h2.insert(a);
				}
			}
			h1.unionHeap(&h2);
			break;
		}
		default:  cout << endl << "Введена неверная команда!" << endl;
		}
	} return 0;
}
