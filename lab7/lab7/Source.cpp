#include <iostream>
#include <fstream>
#include "Header.h"
using namespace std;

void show(Stack* myStk)    //Вывод стека
{
	int a;
	if (myStk == NULL)
		cout << "Стек пуст!" << endl;
	while (myStk != NULL)
	{
		a = myStk->data;          //запись значения в переменную a
		cout << a << " ";
		myStk = myStk->next;
	}
	cout << endl;
}

void push(int x, Stack*& myStk)   //Добавление элемента х в стек	
{
	Stack* e = new Stack;    //выделение памяти для нового элемента
	e->data = x;             //запись элемента x в поле data 
	e->next = myStk;         //перенос вершины на следующий элемент 
	myStk = e;               //сдвиг вершины на позицию вперед
}

void toFile(Stack*& myStk) //Запись в файл
{
	Stack* e = myStk;
	ofstream frm("file.txt");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	while (e)
	{
		frm << e->data << " ";
		e = e->next;
	}
	frm.close();
	cout << "Стек записан в файл file.txt\n";
}

void fromFile(Stack*& myStk)          //Считывание из файла
{
	Stack* first = nullptr;
	ifstream frm("file.txt");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	int number;
	while (frm >> number)
	{
		push(number, first);
		cout << " " << number;
	}
	cout << endl;
	frm.close();
	myStk = first;
	cout << "\nСписок считан из файла file.txt\n";
}

int clear(Stack*& myStk)  //Вывод стека с очисткой
{
	if (myStk == NULL)
	{
		cout << "Стек пуст!" << endl;
		return 0;
	}
	else
	{
		while (myStk != NULL) {
			Stack* e = myStk;        //е-переменная для хранения адреса элемента
			int x = myStk->data;    //запись элемента из поля data в перем. x 
			if (myStk)
				myStk = myStk->next;   //перенос вершины
			cout << x << " ";
			delete e;
		}

	}
		
	cout << endl;
}

int function(Stack*& myStk) {
	int min, max;
	cout << "Введите нижний предел для диапазона: ";
	cin >> min;
	cout << "Введите верхний предел для диапазона: ";
	cin >> max;
	int k = 0;

	if (myStk == NULL)
	{
		cout << "Стек пуст!" << endl;
		return 0;
	}
	else
	{
		while (myStk != NULL) {
			Stack* e = myStk;        //е-переменная для хранения адреса элемента
			
			int x = myStk->data;    //запись элемента из поля data в перем. x 
			if (myStk) {
				if (x >= min && x <= max) {
					cout << "Число в стеке, лежащее в заданном диапазоне: " << x << endl;
					k++;
				}
				myStk = myStk->next;   //перенос вершины
			}
				
			delete e;
		}
		if (k == 0) {
			cout << "В стеке нет чисел, лежащих в заданном диапазоне" << endl;
		}
	}

	cout << endl;
}