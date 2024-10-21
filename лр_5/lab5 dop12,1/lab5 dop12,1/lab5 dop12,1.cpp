#include <iostream>
#include <string>
#include <Windows.h>
#define size 3
using namespace std;

struct Date {
    int day : 5;
    int month : 4;
    int year : 12;
};

struct people {
    string surname;
    string name;
    string patronymic;
    string add;
    int tel;
    Date date;
};
struct people c[size];
struct people bad;

void input() {
    SetConsoleCP(1251);
    for (int i = 0; i < size; i++) {
        cout << "Фамилия: ";
        cin >> c[i].surname;
        cout << "Имя: ";
        cin >> c[i].name;
        cout << "Отчество: ";
        cin >> c[i].patronymic;
        cin.ignore();
        cout << "Адрес: ";
        getline(cin, c[i].add);
        cout << "Телефон: ";
        cin >> c[i].tel;
        
        cout << "Дата рождения: " << endl;
        cout << "День: ";
        cin >> c[i].date.day;
        cout << "Месяц: ";
        cin >> c[i].date.month;
        cout << "Год: ";
        cin >> c[i].date.year;
    }
}

void output() {
    SetConsoleOutputCP(1251);
    for (int i = 0; i < size; i++) {
        cout << "Фамилия: " << c[i].surname << endl;
        cout << "Имя: " << c[i].name << endl;
        cout << "Отчество: " << c[i].patronymic << endl;
        cout << "Адрес: " << c[i].add << endl;
        cout << "Телефон: " << c[i].tel << endl;
        
        cout << "Дата рождения: " << c[i].date.day << "." << c[i].date.month << "." << c[i].date.year << endl;

    }
}

void find() {
    string surname;
    bool found = false;
    do {
        cout << "Введите фамилию: ";
        cin >> surname;

        for (int i = 0; i < size; i++) {
            if (c[i].surname == surname) {
                cout << "Фамилия: " << c[i].surname << endl;
                cout << "Имя: " << c[i].name << endl;
                cout << "Отчество: " << c[i].patronymic << endl;
                cout << "Адрес: " << c[i].add << endl;
                cout << "Телефон: " << c[i].tel << endl;
                cout << "Дата рождения: " << c[i].date.day << "." << c[i].date.month << "." << c[i].date.year << endl;
                found = true;
                break;
            }

        }
        if (!found) {
            cout << "Такой фамилии нет." << endl;
        }
    } while (!found);
}

void del() {
    int a, ch;

    cout << "Выберите фамилию: " << endl;
    for (int i = 0; i < size; i++) {
        cout << i + 1 << "." << c[i].surname << endl;
    }
    cin >> a;

    if (a >= 1 && a <= size) {
        c[a - 1] = bad;
    }
    else {
        cout << "Некорректный выбор." << endl;
    }

}

int main()
{
    setlocale(LC_ALL, "RU");

    int choice;
    do {
        cout << "Меню" << endl;
        cout << "1.Ввод данных." << endl;
        cout << "2.Вывод данных." << endl;
        cout << "3.Удаление." << endl;
        cout << "4.Поиск." << endl;
        cout << "0.Выход из программы." << endl;
        cin >> choice;

        switch (choice) {
        case 1: {
            input();
            break;
        }
        case 2: {
            output();
            break;
        }
        case 3: {
            del();
            break;
        }
        case 4: {
            find();
            break;
        }
        }
    } while (choice != 0);
}