#include <iostream>
#include <Windows.h>
#define size 5
using namespace std;

enum Percent {
    Процент_5 = 1,
    Процент_7,
    Процент_11,
    Процент_20,
    Процент_25,
    Процент_30
};

struct Stock {
    string name;
    int price;
    int sum;
    Percent percent;
};
struct Stock c[size];
struct Stock bad;

void input() {
    SetConsoleCP(1251);
    int per;
    for (int i = 0; i < size; i++) {
        cout << "Наименование товара: ";
        cin >> c[i].name;
        cout << "Цена: ";
        cin >> c[i].price;
        cout << "Количество: ";
        cin >> c[i].sum;
        cout << "Процент торговой надбавки: ";
        cin >> per;
        c[i].percent = static_cast<Percent>(per);
    }
}

void output() {
    SetConsoleOutputCP(1251);
    for (int i = 0; i < size; i++) {
        cout << "Наименование товара: " << c[i].name << endl;
        cout << "Цена: " << c[i].price << endl;
        cout << "Количество: " << c[i].sum << endl;
        cout << "Процент торговой надбавки: ";
        if (c[i].percent == 1) {
            cout << "Процент_5" << endl;
        }
        else if (c[i].percent == 2) {
            cout << "Процент_7" << endl;
        }
        else if (c[i].percent == 3) {
            cout << "Процент_11" << endl;
        }
        else if (c[i].percent == 4) {
            cout << "Процент_20" << endl;
        }
        else if (c[i].percent == 5) {
            cout << "Процент_25" << endl;
        }
        else if (c[i].percent == 6) {
            cout << "Процент_30" << endl;
        }
    }
}

void find() {
    int price;
    bool found = false;
    do {
        cout << "Введите цену: ";
        cin >> price;

        for (int i = 0; i < size; i++) {
            if (c[i].price == price) {
                cout << "Наименование товара: " << c[i].name << endl;
                cout << "Цена: " << c[i].price << endl;
                cout << "Количество: " << c[i].sum << endl;
                cout << "Процент торговой надбавки: ";
                if (c[i].percent == 1) {
                    cout << "Процент_5" << endl;
                }
                else if (c[i].percent == 2) {
                    cout << "Процент_7" << endl;
                }
                else if (c[i].percent == 3) {
                    cout << "Процент_11" << endl;
                }
                else if (c[i].percent == 4) {
                    cout << "Процент_20" << endl;
                }
                else if (c[i].percent == 5) {
                    cout << "Процент_25" << endl;
                }
                else if (c[i].percent == 6) {
                    cout << "Процент_30" << endl;
                }
                found = true;
                break;
            }

        }
        if (!found) {
            cout << "Такой цены нет." << endl;
        }
    } while (!found);
}

void del() {
    int a, ch;

    cout << "Выберите цену: " << endl;
    for (int i = 0; i < size; i++) {
        cout << i + 1 << "." << c[i].price << endl;
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