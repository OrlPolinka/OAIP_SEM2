#include <iostream>
using namespace std;

struct Queue {
	int num;
	Queue* next;
};

//функция ввода чисел в очередь
void into(Queue** begin, Queue** end, int p)
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

//функция поиска минимального элемента
int minel(Queue* begin) {
	Queue* t = begin; 
	int min;
	if (t == NULL)
	{
		cout << "Очередь пуста\n"; 
		return 0;
	}
	else
	{
		min = t->num;
		while (t != NULL)
		{
			if (t->num <= min)
			{
				min = t->num;
			}
			t = t->next;
		}
	}
	return min;
}

//функция поиска максимального элемента
int maxel(Queue* begin) {
	Queue* t = begin; 
	int max;
	if (t == NULL)
	{
		cout << "Очередь пуста\n"; 
		return 0;
	}
	else
	{
		max = t->num;
		while (t != NULL)
		{
			if (t->num >= max)
			{
				max = t->num;
			}
			t = t->next;
		}
	}
	return max;
}

//функция деления очереди на 2
void function(Queue* begin) {
	Queue* begin1 = nullptr, * end1 = nullptr;
	Queue* begin2 = nullptr, * end2 = nullptr;

	int min, max;

	while (begin != nullptr) {
		min = minel(begin);
		max = maxel(begin);

		into(&begin1, &end1, min);
		into(&begin2, &end2, max);

		Queue* temp = begin; // Временный указатель на текущий элемент исходной очереди
		Queue* prev = nullptr; // Указатель на предыдущий элемент
		while (temp != nullptr) {
			if (temp->num == min || temp->num == max) {
				if (prev == nullptr) {
					begin = temp->next;
					delete temp;
					temp = begin;
				}
				else {
					prev->next = temp->next;
					delete temp;
					temp = prev->next;
				}
			}
			else {
				prev = temp;
				temp = temp->next;
			}
		}
	}

	cout << "Очередь Queue1: ";
	from(begin1);
	cout << "Очередь Queue2: ";
	from(begin2);
}

int main(){
	setlocale(LC_ALL, "RU");
	int choice;
	int x;

	Queue* begin = NULL, * end, * t;
	t = new Queue;
	int p, size;
	cout << "\nВведите максимальный размер очереди: ";  
	cin >> size;

	do {
		cout << "Меню: " << endl;
		cout << "1.Добавление элементов в очередь" << endl;
		cout << "2.Вывод очереди на экран" << endl;
		cout << "3.Функция деления очереди на две" << endl;
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
			function(begin);
			break;
		}
		}
	} while (choice != 0);

	return 0;
}