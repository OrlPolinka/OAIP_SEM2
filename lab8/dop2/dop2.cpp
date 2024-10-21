#include <iostream>
using namespace std;

struct Queue {
	float num;
	Queue* next;
};


//функция ввода чисел в очередь
void into(Queue** begin, Queue** end, float p)
{
	Queue* t = new Queue;
	t->num = p;
	t->next = NULL;
	if (*begin == NULL) {
		*begin = *end = t;
	}
	else
	{

		(*end)->next = t;
		*end = t;
	}
}

//функция вывода очереди на экран
void from(Queue* begin)
{
	Queue* t = begin; 
	if (t == NULL)
	{
		cout << "Очередь пуста\n";
	}
	else {
		while (t != NULL)
		{
			cout << t->num << " ";
			t = t->next;
		}
	}
	cout << endl;
}

//функция для нахождения максимального элемента и сдвига очереди
void function(Queue*& begin, Queue*& end) {
	if (begin == nullptr) {
		cout << "Очередь пуста\n";
		return;
	}
	Queue* Max = begin;
	Queue* PrevMax = NULL;
	Queue* t = begin->next;
	float max = begin->num;
	while (t) {
		if (t->num > max) {
			max = t->num;
			Max = t;
		}
		t = t->next;
	}
	if (Max != begin) {
		t = begin;
		while (t->next != Max) {
			t = t->next;
		}
		t->next = Max->next;
		Max->next = begin;
		begin = Max;
		if (t->next == NULL) {
			end = t;
		}
		
	}
}

int main() {
	setlocale(LC_ALL, "RU");
	int choice;
	int x;

	Queue* begin = NULL, * end, * t;
	t = new Queue;
	int size;
	float p;
	cout << "\nВведите максимальный размер очереди: ";
	cin >> size;

	do {
		cout << "Меню: " << endl;
		cout << "1.Добавление элементов в очередь" << endl;
		cout << "2.Вывод очереди на экран" << endl;
		cout << "3.Сдвиг очереди" << endl;
		cout << "0.Завершение работы" << endl;
		cout << "Ваш выбор: " << endl;
		cin >> choice;

		switch (choice) {
		case 1: {
			for (int i = 0; i < size; i++)
			{
				cout << "Введите число для добавления в очередь: ";
				cin >> p;
				into(&begin, &end, p);
			}
			break;
		}
		case 2: {
			cout << "Очередь: ";
			from(begin);
			break;
		}
		case 3: {
			function(begin, end);
			break;
		}
		}
	} while (choice != 0);

	return 0;
}