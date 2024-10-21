#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#define size 5
using namespace std;

union Gender {
    string male;
    string female;
};

struct Townsman {
    string surname;
    string name;
    string patronymic;
    int day;
    string month;
    int year;
    string adds;
    Gender gender;
};

struct Townsman town[size];

void newInf() {
    SetConsoleCP(1251);
    for (int i = 0; i < size; i++) {
        cout << "\nФамилия: ";
        cin >> town[i].surname;
        cout << "Имя: ";
        cin >> town[i].name;
        cout << "Отчество: ";
        cin >> town[i].patronymic;
        cout << "Дата рождения: ";
        cin >> town[i].day;
        cin >> town[i].month;
        cin >> town[i].year;
        cout << "Адрес: ";
        cin.ignore();
        getline(cin, town[i].adds);
        cout << "Пол(м/ж): ";
        string gender;
        cin >> gender;
        if (gender == "м") {
            town[i].gender.male = "мужской";
        }
        else if (gender == "ж") {
            town[i].gender.female = "женский";
        }
    }
}

void readInf() {
    SetConsoleOutputCP(1251);
    for (int i = 0; i < size; i++) {
        cout << "\nФамилия: " << town[i].surname << endl;
        cout << "Имя: " << town[i].name << endl;
        cout << "Отчество: " << town[i].patronymic << endl;
        cout << "Дата рождения: " << town[i].day << " " << town[i].month << " " << town[i].year << endl;
        cout << "Адрес: " << town[i].adds << endl;
        cout << "Пол: ";
        if (!town[i].gender.male.empty()) {
            cout << town[i].gender.male << endl;
        }
        else if (!town[i].gender.female.empty()) {
            cout << town[i].gender.female << endl;
        }
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
        f1 << town[i].surname << endl;
        f1 << town[i].name << endl;
        f1 << town[i].patronymic << endl;
        f1 << town[i].day << " " << town[i].month << " " << town[i].year << endl;
        f1 << town[i].adds << endl;
        if (!town[i].gender.male.empty()) {
            f1 << town[i].gender.male << endl;
        }
        else if (!town[i].gender.female.empty()) {
            f1 << town[i].gender.female << endl;
        }
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
        f2 >> town[i].surname;
        f2 >> town[i].name;
        f2 >> town[i].patronymic;
        f2 >> town[i].day;
        f2 >> town[i].month;
        f2 >> town[i].year;
        f2.ignore();
        getline(f2, town[i].adds);
        string gender;
        f2 >> gender;
        if (gender == "м") {
            town[i].gender.male = "мужской";
        }
        else if (gender == "ж") {
            town[i].gender.female = "женский";
        }
    }

    f2.close();
    cout << "Данные прочитаны" << endl;
}

void find() {
    int year;
    bool found = false;
    do {
        cout << "Введите год: ";
        cin >> year;

        for (int i = 0; i < size; i++) {
            if (town[i].year == year) {
                cout << "\nФамилия: " << town[i].surname << endl;
                cout << "Имя: " << town[i].name << endl;
                cout << "Отчество: " << town[i].patronymic << endl;
                cout << "Дата рождения: " << town[i].day << " " << town[i].month << " " << town[i].year << endl;
                cout << "Адрес: " << town[i].adds << endl;
                cout << "Пол: ";
                if (!town[i].gender.male.empty()) {
                    cout << town[i].gender.male << endl;
                }
                else if (!town[i].gender.female.empty()) {
                    cout << town[i].gender.female << endl;
                }
                found = true;
                break;
            }

        }
        if (!found) {
            cout << "Такого года нет." << endl;
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