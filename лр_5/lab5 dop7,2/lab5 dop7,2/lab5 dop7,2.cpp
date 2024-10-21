#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#define size 5
using namespace std;

int per;

union PercentInfo {
    int percent5;
    int percent7;
    int percent11;
    int percent20;
    int percent25;
    int percent30;

};

struct Stock {
    string name;
    int price;
    int sum;
    PercentInfo percentInfo;
};
struct Stock c[size];

void newInf() {
    SetConsoleCP(1251);
    
    for (int i = 0; i < size; i++) {
        cout << "Наименование товара: ";
        cin >> c[i].name;
        cout << "Цена: ";
        cin >> c[i].price;
        cout << "Количество: ";
        cin >> c[i].sum;
        cout << "Процент торговой надбавки(5, 7, 11, 20, 25, 30): ";
        cin >> per;

        switch (per) {
        case 5: {
            c[i].percentInfo.percent5 = per;
            break;
        }
        
        case 7: {
            c[i].percentInfo.percent7 = per;
            break;
        }
            
        case 11: {
            c[i].percentInfo.percent11 = per;
            break;
        }
            
        case 20: {
            c[i].percentInfo.percent20 = per;
            break;
        }
            
        case 25: {
            c[i].percentInfo.percent25 = per;
            break;
        }
            
        case 30: {
            c[i].percentInfo.percent30 = per;
            break;
        }
            
        default: {
            cout << "Некорректный ввод процента." << endl;
            break;
        }
            
        }
    }
}

void readInf() {
    SetConsoleOutputCP(1251);
    for (int i = 0; i < size; i++) {
        cout << "Наименование товара: " << c[i].name << endl;
        cout << "Цена: " << c[i].price << endl;
        cout << "Количество: " << c[i].sum << endl;
        cout << "Процент торговой надбавки: ";
        if (per == 5) {
            cout << c[i].percentInfo.percent5 << "%" << endl;
        }
        else if (per == 7) {
            cout << c[i].percentInfo.percent7 << "%" << endl;
        }
        else if (per == 11) {
            cout << c[i].percentInfo.percent11 << "%" << endl;
        }
        else if (per == 20) {
            cout << c[i].percentInfo.percent20 << "%" << endl;
        }
        else if (per == 25) {
            cout << c[i].percentInfo.percent25 << "%" << endl;
        }
        else if (per == 30) {
            cout << c[i].percentInfo.percent30 << "%" << endl;
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
        f1 << c[i].name << endl;
        f1 << c[i].price << endl;
        f1 << c[i].sum << endl;
        if (c[i].percentInfo.percent5) {
            f1 << c[i].percentInfo.percent5 << "%" << endl << endl;
        }
        else if (c[i].percentInfo.percent7) {
            f1 << c[i].percentInfo.percent7 << "%" << endl << endl;
        }
        else if (c[i].percentInfo.percent11) {
            f1 << c[i].percentInfo.percent11 << "%" << endl << endl;
        }
        else if (c[i].percentInfo.percent20) {
            f1 << c[i].percentInfo.percent20 << "%" << endl << endl;
        }
        else if (c[i].percentInfo.percent25) {
            f1 << c[i].percentInfo.percent25 << "%" << endl << endl;
        }
        else if (c[i].percentInfo.percent30) {
            f1 << c[i].percentInfo.percent30 << "%" << endl << endl;
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
        f2 >> c[i].name;
        f2 >> c[i].price;
        f2 >> c[i].sum;
        
        f2 >> c[i].percentInfo.percent5;
        f2 >> c[i].percentInfo.percent7;
        f2 >> c[i].percentInfo.percent11;
        f2 >> c[i].percentInfo.percent20;
        f2 >> c[i].percentInfo.percent25;
        f2 >> c[i].percentInfo.percent30;

        cout << "Наименование товара: " << c[i].name << endl;
        cout << "Цена: " << c[i].price << endl;
        cout << "Количество: " << c[i].sum << endl;
        cout << "Процент торговой надбавки: ";
        if (per == 5) {
            cout << c[i].percentInfo.percent5 << "%" << endl;
        }
        else if (per == 7) {
            cout << c[i].percentInfo.percent7 << "%" << endl;
        }
        else if (per == 11) {
            cout << c[i].percentInfo.percent11 << "%" << endl;
        }
        else if (per == 20) {
            cout << c[i].percentInfo.percent20 << "%" << endl;
        }
        else if (per == 25) {
            cout << c[i].percentInfo.percent25 << "%" << endl;
        }
        else if (per == 30) {
            cout << c[i].percentInfo.percent30 << "%" << endl;
        }
       
    }

    f2.close();
    cout << "Данные прочитаны" << endl;
}

void find() {
    string name;
    bool found = false;
    do {
        cout << "Введите наименование товара: ";
        cin >> name;

        for (int i = 0; i < size; i++) {
            if (c[i].name == name) {
                cout << "Наименование товара: " << c[i].name << endl;
                cout << "Цена: " << c[i].price << endl;
                cout << "Количество: " << c[i].sum << endl;
                cout << "Процент торговой надбавки: ";
                if (per == 5) {
                    cout << c[i].percentInfo.percent5 << "%" << endl;
                }
                else if (per == 7) {
                    cout << c[i].percentInfo.percent7 << "%" << endl;
                }
                else if (per == 11) {
                    cout << c[i].percentInfo.percent11 << "%" << endl;
                }
                else if (per == 20) {
                    cout << c[i].percentInfo.percent20 << "%" << endl;
                }
                else if (per == 25) {
                    cout << c[i].percentInfo.percent25 << "%" << endl;
                }
                else if (per == 30) {
                    cout << c[i].percentInfo.percent30 << "%" << endl;
                }
                found = true;
                break;
            }

        }
        if (!found) {
            cout << "Такой товара нет." << endl;
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