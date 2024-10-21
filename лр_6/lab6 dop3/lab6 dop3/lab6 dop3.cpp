#include <iostream>
#include <Windows.h>
#include <fstream>
using namespace std;

struct list {
    int number;
    list* next;
};

void insert(list*&, int); //функция добавления элемента, передается адрес списка и символ, который добавляется 
int del(list*&, int);   //функция удаления, передается адрес списка и символ, который удаляется 
int IsEmpty(list*);         //функция, которая проверяет, пуст ли список
void printList(list*);      //функция вывода
void menu(void);     //функция, показывающая меню
void toFile(list*& p);         //Запись в файл
void fromFile(list*& p);       //Считывание из файла
void sum(list*);  //функция подсчета 
void search(list*);  //функция поиска элемента

int main()
{
    setlocale(LC_ALL, "RU");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    list* first = NULL;
    int choice;
    int value;
    menu();
    cin >> choice;
    while (choice != 0) {
        switch (choice) {
        case 1: {
            cout << "Введите символ ";
            cin >> value;
            insert(first, value);
            break;
        }
        case 2: {
            printList(first);
            break;
        }
        case 3: {
            search(first);
            break;
        }
        case 4: {
            if (!IsEmpty(first)) // удалить число из списка
            {
                cout << "Введите удаляемое число ";
                cin >> value;
                if (del(first, value))
                {
                    cout << "Удалено число " << value << endl;
                }
                else
                    cout << "Число не найдено" << endl;
            }
            else
                cout << "Список пуст" << endl;
            break;
        }
        case 5: {
            toFile(first);
            break;
        }
        case 6: {
            fromFile(first);
            break;
        }
        case 7: {
            sum(first);
            break;
        }
        default:  cout << "Неправильный выбор" << endl;
            menu();
            break;
        }
        cout << endl;
        menu();
        cin >> choice;
    }

    cout << "Конец." << endl;
    return 0;
}

void menu(void) {
    cout << "Ваш выбор:" << endl;
    cout << "1.Добавление элемента" << endl;
    cout << "2.Вывод списка в консольное окно" << endl;
    cout << "3.Поиск элемента" << endl;
    cout << "4.Удаление элемента" << endl;
    cout << "5.Запись списка в файл" << endl;
    cout << "6.Считывание списка из файла" << endl;
    cout << "7.Подсчет суммы положительных элементов, кратных 5" << endl;
    cout << "0.Выход" << endl;
}

void insert(list*& p, int value) //Добавление числа value в список 
{
    list* newP = new list;
    if (newP != NULL)     //есть ли место?  
    {
        newP->number = value;
        newP->next = p;
        p = newP;
    }
    else
        cout << "Операция добавления не выполнена" << endl;
}

void printList(list* p)  //Вывод списка 
{
    if (p == NULL)
        cout << "Список пуст" << endl;
    else
    {
        cout << "Список:" << endl;
        while (p != NULL)
        {
            cout << "-->" << p->number;
            p = p->next;
        }
        cout << "-->NULL" << endl;
    }
}

int IsEmpty(list* p) //Список  пустой? (1-да, 0-нет) 
{
    return p == NULL;
}

int del(list*& p, int value)  // Удаление числа 
{
    list* previous, * current, * temp;
    if (value == p->number)
    {
        temp = p;
        p = p->next;    // отсоединить узел 
        delete temp;      //освободить отсоединенный узел 
        return value;
    }
    else
    {
        previous = p;
        current = p->next;
        while (current != NULL && current->number != value)
        {
            previous = current;
            current = current->next; // перейти к следующему 
        }
        if (current != NULL)
        {
            temp = current;
            previous->next = current->next;
            delete(temp);
            return value;
        }
    }
    return 0;
}

void sum(list* p) 
{
    int s = 0;
    if (p == NULL) {
        cout << "Список пуст" << endl;
        return;
    }
    else
    {
        while (p != NULL)
        {
            if (p->number > 0 && p->number % 5 == 0)
                s += p->number;
            p = p->next;
        }
    }

    if (s != 0) {
        cout << "Сумма = " << s << endl;
    }
    else {
        cout << "Таких элементов нет." << endl;
    }
}

void toFile(list*& p)
{
    SetConsoleCP(1251);

    list* temp = p;
    ofstream frm("file.txt");
    if (frm.fail())
    {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    while (temp)
    {
        frm << temp->number << " ";
        temp = temp->next;
    }
    frm.close();
    cout << "Список записан в файл file.txt.\n";
}

void fromFile(list*& p)          //Считывание из файла
{
    SetConsoleOutputCP(1251);

    list* first = nullptr;
    ifstream frm("file.txt");
    if (frm.fail())
    {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    int number;
    while (frm >> number)
    {
        insert(first, number);
        cout << "-->" << number;
    }
    cout << "-->NULL" << endl;
    frm.close();
    p = first;
    cout << "\nСписок считан из файла file.txt\n";
}

void search(list* p) {
    int a;
    cout << "Введите число для поиска: ";
    cin >> a;
    while (p != nullptr) {
        if (a == p->number) {
            cout << "Найдено число: " << p->number << endl;
            return;  // Используем return, чтобы выйти из функции, когда число найдено
        }
        p = p->next;  // Переходим к следующему элементу списка
    }
    cout << "Такого элемента не существует." << endl;
}