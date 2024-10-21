#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

const int MAX_PRODUCTS = 30;

int current_size = 0;

void input();
void output();
void find();
void writeToFile();
void readFromFile();

union forstruct {
    char str[50];
    int numb;
    float fnumb;
};

struct Notebook {
    forstruct surname;
    forstruct name;
    forstruct middlename;
    forstruct product_name;
    forstruct price;
    forstruct pledge;
    int day;
    int month;
    int year;
    forstruct storage_time;
} products[MAX_PRODUCTS];

int main() {
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choose;
    do {
        cout << "\nВведите:\n1 - ввести новую запись;\n2 - вывести информацию;\n3 - поиск;\n4 - записать в файл;\n5 - считать из файла;\n6 - выход.\n";
        cin >> choose;
        switch (choose) {
        case 1: input(); break;
        case 2: output(); break;
        case 3: find(); break;
        case 4: writeToFile(); break;
        case 5: readFromFile(); break;
        }
    } while (choose != 6);
    return 0;
}

void input() {
    cout << "Ввод информации" << endl;
    cout << "Номер записи  " << current_size + 1 << endl;
    if (current_size < MAX_PRODUCTS) {
        cout << "Фамилия: ";
        cin >> products[current_size].surname.str;

        cout << "Имя: ";
        cin >> products[current_size].name.str;

        cout << "Отчество: ";
        cin >> products[current_size].middlename.str;

        cout << "Наименование товара: ";
        cin >> products[current_size].product_name.str;

        cout << "Цена(бел руб): ";
        cin >> products[current_size].price.fnumb;

        cout << "Залог(бел руб): ";
        cin >> products[current_size].pledge.fnumb;

        bool is_correct_date = false;
        do {
            cout << "Дата сдачи (ДД.ММ.ГГГГ): ";
            cin >> products[current_size].day;
            cin.ignore(); 
            cin >> products[current_size].month;
            cin.ignore();  
            cin >> products[current_size].year;

            if (products[current_size].day > 0 && products[current_size].day <= 31 &&
                products[current_size].month > 0 && products[current_size].month <= 12 &&
                products[current_size].year > 0) {
                is_correct_date = true;
            }
            else {
                cout << "Некорректная дата. Пожалуйста, введите снова." << endl;
            }
        } while (!is_correct_date);

        cout << "Срок хранения(дни): ";
        cin >> products[current_size].storage_time.numb;
        current_size++;
    }
    else
        cout << "Никакие другие записи не могут быть введены" << endl;
}

void displayOneStructure(Notebook oneProduct) {
    cout << endl;
    cout << "Фамилия: " << oneProduct.surname.str << endl;
    cout << "Имя: " << oneProduct.name.str << endl;
    cout << "Отчество: " << oneProduct.middlename.str << endl;
    cout << "Наименование товара: " << oneProduct.product_name.str << endl;
    cout << "Цена(бел руб): " << oneProduct.price.fnumb << endl;
    cout << "Залог(бел руб): " << oneProduct.pledge.fnumb << endl;
    cout << "Дата сдачи: " << oneProduct.day << "." << oneProduct.month << "." << oneProduct.year << endl;
    cout << "Срок хранения(дни): " << oneProduct.storage_time.numb << endl;
}

void output() {
    int num;
   
        for (int i = 0; i < current_size; i++) {
            displayOneStructure(products[i]);
            cout << endl;
        }
    
}

void find() {
    char product[50];
    cout << "Введите наименование товара: ";
    cin >> product;
    cout << endl;
    for (int i = 0; i < current_size; i++) {
        if (strcmp(products[i].product_name.str, product) == 0) {
            displayOneStructure(products[i]);
        }
    }
}

void writeToFile() {
    ofstream outFile("file.txt");
    if (!outFile) {
        cerr << "Невозможно открыть файл для записи." << endl;
        return;
    }

    for (int i = 0; i < current_size; i++) {
        outFile << products[i].surname.str << endl;
        outFile << products[i].name.str << endl;
        outFile << products[i].middlename.str << endl;
        outFile << products[i].product_name.str << endl;
        outFile << products[i].price.fnumb << endl;
        outFile << products[i].pledge.fnumb << endl;
        outFile << products[i].day << "." << products[i].month << "." << products[i].year << endl;
        outFile << products[i].storage_time.numb << endl;
    }

    outFile.close();
    cout << "Данные успешно записаны в файл." << endl;
}

void readFromFile() {
    ifstream inFile("file.txt");
    if (!inFile) {
        cerr << "Невозможно открыть файл для чтения." << endl;
        return;
    }

    current_size = 0;
    while (current_size < MAX_PRODUCTS &&
        inFile >> products[current_size].surname.str &&
        inFile >> products[current_size].name.str &&
        inFile >> products[current_size].middlename.str &&
        inFile >> products[current_size].product_name.str &&
        inFile >> products[current_size].price.fnumb &&
        inFile >> products[current_size].pledge.fnumb &&
        inFile >> products[current_size].day &&
        inFile.ignore() &&  
        inFile >> products[current_size].month &&
        inFile.ignore() && 
        inFile >> products[current_size].year &&
        inFile >> products[current_size].storage_time.numb) {
        current_size++;
    }

    inFile.close();
    cout << "Данные успешно считаны из файла." << endl;

    output();
}