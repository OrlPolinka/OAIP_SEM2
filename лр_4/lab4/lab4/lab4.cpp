//Вариант 10

#include <iostream>
#include <fstream>
#include <windows.h>
#define size 3
using namespace std;

struct Cars {
    char marks[100];
    char color[100];
    int serialNumber;
    int prodactionDate;
    char bodyType[100];
    int dateInspection;
    char name[100];
};
struct Cars cars_directory[size];
struct Cars bad;

int choice;
int current_size = 0;


int del() {
    int par, num;

    cout << "Введите имя владельца: ";
    do
    {
        for (int i = 0; i < size; i++) {
            cout << i + 1 << "." << cars_directory[i].name << endl;
        }
        cin >> par;
        if (par > 0 && par <= size) {
            cout << "Выбрете то что нужно удалить: " << endl;
            cout << "1.Марка автомобиля: " << cars_directory[par - 1].marks << endl;
            cout << "2.Цвет: " << cars_directory[par - 1].color << endl;
            cout << "3.Заводской номер: " << cars_directory[par - 1].serialNumber << endl;
            cout << "4.Дата выпуска: " << cars_directory[par - 1].prodactionDate << endl;
            cout << "5.Тип кузова: " << cars_directory[par - 1].bodyType << endl;
            cout << "6.Дата последнего техосмотра: " << cars_directory[par - 1].dateInspection << endl;
            cout << "7.Владелец: " << cars_directory[par - 1].name << endl;
            cout << "8.Вернуться назад: " << endl;
            cin >> num;
            do
            {
                switch (num) {
                case 1: {
                    cars_directory[par - 1].marks[0] == '\0';
                    break;
                }

                case 2: {
                    cars_directory[par - 1].color[0] == '\0';
                    break;
                }

                case 3: {
                    cars_directory[par - 1].serialNumber = 0;
                    break;
                }

                case 4: {
                    cars_directory[par - 1].prodactionDate = 0;
                    break;
                }

                case 5: {
                    cars_directory[par - 1].bodyType[0] == '\0';
                    break;
                }

                case 6: {
                    cars_directory[par - 1].dateInspection = 0;
                    break;
                }

                case 7: {
                    cars_directory[par - 1].name[0] == '\0';
                    break;
                }

                case 8: {
                    return 0;
                }
                }
                cin >> num;
            } while (num != 0);
            {

            }
        }
    } while (par != 0);

    //cout << "Переменная удалена." << endl;
    return 0;
}

void input() {
    SetConsoleCP(1251);
    ofstream fout("file.txt");
    if (!fout.is_open()) {
        cout << "Файл не может быть открыт!" << endl;
    }
    else {
        cout << "Ввод информации." << endl;
        cin.ignore();
        while (current_size < size) {
            cout << "Строка номер " << current_size + 1 << endl;

            cout << "Марка автомобиля ";
            cin.ignore();
            cin >> cars_directory[current_size].marks;

            cout << "Цвет ";
            cin.ignore();
            cin >> cars_directory[current_size].color;

            cout << "Заводской номер ";
            cin.ignore();
            cin >> cars_directory[current_size].serialNumber;

            cout << "Дата выпуска ";
            cin.ignore();
            cin >> cars_directory[current_size].prodactionDate;

            cout << "Тип кузова ";
            cin.ignore();
            cin >> cars_directory[current_size].bodyType;

            cout << "Дата последнего техосмотра ";
            cin.ignore();
            cin >> cars_directory[current_size].dateInspection;

            cout << "Владелец ";
            cin.ignore();
            cin >> cars_directory[current_size].name;

            fout << cars_directory[current_size].marks << ' ' 
                << cars_directory[current_size].color << ' ' 
                << cars_directory[current_size].serialNumber << ' ' 
                << cars_directory[current_size].prodactionDate << ' '  
                << cars_directory[current_size].bodyType << ' ' 
                << cars_directory[current_size].dateInspection << ' ' 
                << cars_directory[current_size].name << endl;
           
            current_size++;
        }

        cout << "Введено максимальное количество строк." << endl;
    }
    fout.close();
}

void output() {
    SetConsoleOutputCP(1251);
    Cars buf[100];
    ifstream fin("file.txt");
    if (!fin.is_open()) {
        cout << "Файл не может быть открыт!" << endl;
    }
    else {
        int sw, n;
        cout << "1-считывание и вывод 1 строки" << endl;
        cout << "2-считывание и вывод всех строк" << endl;
        cout << "Ваш выбор: ";
        cin >> sw;
        if (sw == 1) {
            cout << "Номер выводимой строки(1-3): ";
            cin >> n;

            for (int i = 0; i < n; i++) {
                fin >> cars_directory[current_size - n].marks 
                    >> cars_directory[current_size - n].color 
                    >> cars_directory[current_size - n].serialNumber 
                    >> cars_directory[current_size - n].prodactionDate 
                    >> cars_directory[current_size - n].bodyType 
                    >> cars_directory[current_size - n].dateInspection
                    >> cars_directory[current_size - n].name;
            }

            cout << "Марка автомобиля " << cars_directory[current_size - n].marks << endl;

            cout << "Цвет " << cars_directory[current_size - n].color << endl;

            cout << "Заводской номер " << cars_directory[current_size - n].serialNumber << endl;

            cout << "Дата выпуска " << cars_directory[current_size - n].prodactionDate << endl;

            cout << "Тип кузова " << cars_directory[current_size - n].bodyType << endl;

            cout << "Дата последнего техосмотра " << cars_directory[current_size - n].dateInspection << endl;

            cout << "Ваделец " << cars_directory[current_size - n].name << endl;
        }
        else if (sw == 2) {
            for (int i = 0; i < size; i++) {
                fin >> cars_directory[i].marks
                    >> cars_directory[i].color
                    >> cars_directory[i].serialNumber
                    >> cars_directory[i].prodactionDate
                    >> cars_directory[i].bodyType
                    >> cars_directory[i].dateInspection
                    >> cars_directory[i].name;

                cout << "Марка автомобиля " << cars_directory[i].marks << endl;

                cout << "Цвет " << cars_directory[i].color << endl;

                cout << "Заводской номер " << cars_directory[i].serialNumber << endl;

                cout << "Дата выпуска " << cars_directory[i].prodactionDate << endl;

                cout << "Тип кузова " << cars_directory[i].bodyType << endl;

                cout << "Дата последнего техосмотра " << cars_directory[i].dateInspection << endl;

                cout << "Ваделец " << cars_directory[i].name << endl;
            }
        }
    }
    fin.close();
}

//Функция для поиска строки по имени владельца
void find(char lastName[100]) {
    SetConsoleOutputCP(1251);
    bool flag = false;
    Cars buf;
    ifstream fin2("file.txt");
    if (fin2.is_open()) {
        while (fin2 >> buf.marks >> buf.color >> buf.serialNumber >> buf.prodactionDate >> buf.bodyType >> buf.dateInspection >> buf.name)
        {
            
            if (strcmp(lastName, buf.name) == 0)   //сравнение строк
            {
                cout << "Марка автомобиля " << buf.marks << endl;

                cout << "Цвет " << buf.color << endl;

                cout << "Заводской номер " << buf.serialNumber << endl;

                cout << "Дата выпуска " << buf.prodactionDate << endl;

                cout << "Тип кузова " << buf.bodyType << endl;

                cout << "Дата последнего техосмотра " << buf.dateInspection << endl;

                cout << "Ваделец " << buf.name << endl;
                flag = true; 
                break;
            }

        }
        fin2.close();
        if (!flag) cout << "Ничего не найдено\n";
    }
    else
    {
        cout << "Ошибка открытия файла";
        return;
    }


    
}

int main()
{
    setlocale(LC_ALL, "RU");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    char name[100];

    do {
        cout << "1.Ввод данных с клавиатуры и запись в файл\n";
        cout << "2.Считывание из файла и вывод данных в консольное окно\n";
        cout << "3.Удаление переменной\n";
        cout << "4.Поиск транспортного средства по хозяину\n";
        cout << "0.Выход из программы\n\n";
        
        cout << "Ваш выбор: ";
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
            cout << "Введите владельца: ";
            cin >> name;
            find(name);
            break;
        }

        case 0: {
            exit(0);
        }
        }
    } while (choice != 0);
}
