#include <iostream>
#include <fstream>
#include "Header.h"
using namespace std;

void show(Stack* myStk)    //Вывод стека
{
	//Stack* e = ;    //объявляется указатель на вершину стека
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

void function(Stack*& myStk) {
	Stack* reversedStack = nullptr;
	Stack* current = myStk;

	// Переворачиваем стек
	while (current != nullptr) {
		Stack* next = current->next;
		current->next = reversedStack;
		reversedStack = current;
		current = next;
	}

	// Ищем и удаляем первое отрицательное число
	Stack* prev = nullptr;
	current = reversedStack;
	while (current != nullptr) {
		if (current->data < 0) {
			if (prev == nullptr) { // Если первый элемент отрицательный
				reversedStack = current->next;
			}
			else {
				prev->next = current->next;
			}
			cout << "Первое отрицательное число " << current->data << " удалено" << endl;
			delete current;
			break;
		}
		prev = current;
		current = current->next;
	}

	// Восстанавливаем исходный порядок стека
	myStk = nullptr;
	while (reversedStack != nullptr) {
		Stack* next = reversedStack->next;
		reversedStack->next = myStk;
		myStk = reversedStack;
		reversedStack = next;
	}

	if (current == nullptr) {
		cout << "В стеке нет отрицательных чисел" << endl;
	}
}

//int function(Stack*& myStk) {
//	bool k = false;
//
//	if (myStk == NULL)
//	{
//		cout << "Стек пуст!" << endl;
//		return 0;
//	}
//	else
//	{
//		Stack* e = myStk;        //е-переменная для хранения адреса элемента
//		Stack* prev = NULL;
//		while (myStk != NULL) {
//
//			int x = myStk->data;    //запись элемента из поля data в перем. x 
//			if (myStk) {
//				if (x < 0) {
//					cout << "Первое отрицательное число " << x << " удалено" << endl;
//					delete e;
//					k = true;
//					break;
//				}
//				myStk = myStk->next;   //перенос вершины
//			}
//
//			/*delete e;*/
//		}
//		if (k == false) {
//			cout << "В стеке нет отрицательных чисел" << endl;
//		}
//	}
//
//	cout << endl;
//}