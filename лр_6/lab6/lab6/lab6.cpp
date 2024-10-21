#include <iostream>
#include <Windows.h>
#include <fstream>
using namespace std;

struct list {
    float number;
    list* next;
};

void insert(list*&, float); //функция добавления элемента, передается адрес списка и символ, который добавляется 
float del(list*&, float);   //функция удаления, передается адрес списка и символ, который удаляется 
int IsEmpty(list*);         //функция, которая проверяет, пуст ли список
void printList(list*);      //функция вывода
void menu(void);     //функция, показывающая меню
void toFile(list*& p);         //Запись в файл
void fromFile(list*& p);       //Считывание из файла
void pro10(list*);  //функция подсчета произведения чисел, меньших 10  
void search(list*);  //функция поиска элемента

int main()
{
    setlocale(LC_ALL, "RU");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    list* first = NULL;
    int choice;
    float value;
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
            pro10(first);
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
    cout << "7.Подсчет произведения чисел, меньших 10" << endl;
    cout << "0.Выход" << endl;
}

void insert(list*& p, float value) //Добавление числа value в список 
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

float del(list*& p, float value)  // Удаление числа 
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

void pro10(list* p)  // Подсчет произведения чисел, меньших 10
{
    float pr = 1;
    if (p == NULL) {
        cout << "Список пуст" << endl;
        return;
    }
    else
    {
        while (p != NULL)
        {
            if (p->number < 10)
                pr = pr * (p->number);
            p = p->next;
        }
    }

    if (pr != 1) {
        cout << "Произведение = " << pr << endl;
    }
    else {
        cout << "Нет чисел меньше 10 в списке." << endl;
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
    float number;
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
    float a;
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