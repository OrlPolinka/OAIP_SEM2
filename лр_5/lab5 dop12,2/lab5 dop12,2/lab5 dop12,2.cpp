#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#define size 5
using namespace std;

int ch;

union JobPlace {
    string job;
    string study;
};

struct people {
    string surname;
    string name;
    string patronymic;
    string add;
    int tel;
    string birthDate;
    string post;
    JobPlace place;
};
struct people c[size];

void newInf() {
    SetConsoleCP(1251);
    string place;
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
        cout << "Дата рождения: ";
        cin >> c[i].birthDate;

        cout << "Место работы/учебы: " << endl;
        cout << "1. Работа" << endl;
        cout << "2. Учеба" << endl;
        
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "Место работы: ";
            getline(cin, c[i].place.job);
            break;
        case 2:
            cout << "Место учебы: ";
            getline(cin, c[i].place.study);
            break;
        default:
            cout << "Некорректный выбор" << endl;
            break;
        }

        cout << "Должность: ";
        cin >> c[i].post;


    }
}

void readInf() {
    SetConsoleOutputCP(1251);
    for (int i = 0; i < size; i++) {
        cout << "Фамилия: " << c[i].surname << endl;
        cout << "Имя: " << c[i].name << endl;
        cout << "Отчество: " << c[i].patronymic << endl;
        cout << "Адрес: " << c[i].add << endl;
        cout << "Телефон: " << c[i].tel << endl;
        cout << "Дата рождения: " << c[i].birthDate << endl;
        
        cout << "Место работы/учебы: ";
        if (ch == 1) {
            cout << c[i].place.job;
        }
        else if (ch == 2) {
            cout << c[i].place.study;
        }

        cout << "Должность: " << c[i].post << endl;
    }
}

void input() {
    SetConsoleCP(1251);
    ofstream f1("file.txt");
    if (!f1) {
        cout << "Не удалось открыть файл для записи!" << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        f1 << c[i].surname << endl;
        f1 << c[i].name << endl;
        f1 << c[i].patronymic << endl;
        f1 << c[i].add << endl;
        f1 << c[i].tel << endl;
        f1 << c[i].birthDate << endl;
        if (ch == 1) {
            f1 << c[i].place.job;
        }
        else if (ch == 2) {
            f1 << c[i].place.study;
        }

        f1 << c[i].post << endl;

    }

    f1.close();
    cout << "Данные записаны в файл" << endl;
}

void output() {
    SetConsoleOutputCP(1251);
    ifstream f2("file.txt");
    if (!f2) {
        cout << "Не удалось открыть файл для чтения!" << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        f2 >> c[i].surname;
        f2 >> c[i].name;
        f2 >> c[i].patronymic;
        f2 >> c[i].add;
        f2 >> c[i].tel;
        f2 >> c[i].birthDate;
        if (ch == 1) {
            f2 >> c[i].place.job;
        }
        else if (ch == 2) {
            f2 >> c[i].place.study;
        }
        f2 >> c[i].post;

        
    }

    f2.close();
    cout << "Данные прочитаны" << endl;
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
                cout << "Дата рождения: " << c[i].birthDate << endl;
                cout << "Место работы/учебы: ";
                if (ch == 1) {
                    cout << c[i].place.job;
                }
                else if (ch == 2) {
                    cout << c[i].place.study;
                }
                cout << "Должность: " << c[i].post << endl;
                found = true;
                break;
            }

        }
        if (!found) {
            cout << "Такой фамилии нет." << endl;
        }
    } while (!found);
}

int main()
{
    setlocale(LC_ALL, "RU");

    int choice;
    do {
        cout << "\nМеню" << endl;
        cout << "1.Ввод данных." << endl;
        cout << "2.Вывод данных." << endl;
        cout << "3.Запись данных в файл." << endl;
        cout << "4.Чтение данных из файла." << endl;
        cout << "5.Поиск." << endl;
        cout << "0.Выход из программы." << endl;
        cin >> choice;

        switch (choice) {
        case 1: {
            newInf();
            break;
        }
        case 2: {
            readInf();
            break;
        }
        case 3: {
            input();
            break;
        }
        case 4: {
            output();
            break;
        }
        case 5: {
            find();
            break;
        }
        }
    } while (choice != 0);
}