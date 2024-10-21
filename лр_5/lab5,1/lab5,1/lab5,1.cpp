#include <iostream>
#include <Windows.h>
#define size 3
using namespace std;

enum Forms {
    Республика = 1, Монархия
};

struct Country {
    string name;
    string capital;
    int population;
    int square;
    Forms form;
};
struct Country c[size];
struct Country bad;

void input(){
    SetConsoleCP(1251);
    int forms;
    for (int i = 0; i < size; i++) {
        cout << "Наименование государства: ";
        cin >> c[i].name;
        cout << "Столица государства: ";
        cin >> c[i].capital;
        cout << "Численность населения: ";
        cin >> c[i].population;
        cout << "Площадь: ";
        cin >> c[i].square;
        cout << "Форма правления: ";
        cin >> forms;
        c[i].form = static_cast<Forms>(forms);
    }
}

void output() {
    SetConsoleOutputCP(1251);
    for (int i = 0; i < size; i++) {
        cout << "Наименование государства: " << c[i].name << endl;
        cout << "Столица государства: " << c[i].capital << endl;
        cout << "Численность населения: " << c[i].population << endl;
        cout << "Площадь: " << c[i].square << endl;
        cout << "Форма правления: ";
        if (c[i].form == 1) {
            cout << "Республика" << endl;
        }
        else if (c[i].form == 2) {
            cout << "Монархия" << endl;
        }

    }
}

void find() {
    string capital;
    bool found = false;
    do {
        cout << "Введите столицу: ";
        cin >> capital;

        for (int i = 0; i < size; i++) {
            if (c[i].capital == capital) {
                cout << "Наименование государства: " << c[i].name << endl;
                cout << "Столица государства: " << c[i].capital << endl;
                cout << "Численность населения: " << c[i].population << endl;
                cout << "Площадь: " << c[i].square << endl;
                cout << "Форма правления: ";
                if (c[i].form == 1) {
                    cout << "Республика" << endl;
                }
                else if (c[i].form == 2) {
                    cout << "Монархия" << endl;
                }
                found = true;
                break;
            }
            
        }
        if (!found) {
            cout << "Такой столицы нет." << endl;
        }
    } while (!found);
}

void del() {
    int a, ch;

    cout << "Выберите столицу: " << endl;
    for (int i = 0; i < size; i++) {
        cout << i + 1 << "." << c[i].capital << endl;
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

        switch(choice) {
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