#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

const int MAX_SIZE = 5;
int current_size = 0;

enum Subjects {
    математика = 0,
    физика,
    литература,
    английский,
    история,
    химия,
    NUM_SUBJECTS
};

struct Klass {
    unsigned num : 4;
    char letter;
};

struct Pupils {
    char surname[50];
    char name[50];
    char middlename[50];
    Klass klass;
    int marks[NUM_SUBJECTS];
    float average;
} pupils[MAX_SIZE];

struct Pupils empty_pupil;

void input();
void displayOneStructure(Pupils onePupil);
void output();
void del();
void find();

int main() {
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    short choose;
    do {
        cout << "Введите:\n1 - ввести новую запись;\n2 - вывод информации;\n3 - удалить запись;\n4 - поиск\n5 - выход.\n";
        cin >> choose;
        switch (choose) {
        case 1: input(); break;
        case 2: output(); break;
        case 3: del(); break;
        case 4: find(); break;
        }
    } while (choose != 5);
    return 0;
}

void input() {
    cout << "Ввод информации" << endl;
    cout << "Номер записи " << current_size + 1 << endl;

    if (current_size < MAX_SIZE) {
        cout << "Фамилия: ";
        cin >> pupils[current_size].surname;

        cout << "Имя: ";
        cin >> pupils[current_size].name;

        cout << "Отчество: ";
        cin >> pupils[current_size].middlename;

        cout << "Класс (номер): ";
        int klass_num;
        cin >> klass_num;
        if (klass_num < 1 or klass_num > 11) {
            cout << "Неправильный ввод" << endl;
            return;
        }
        pupils[current_size].klass.num = klass_num;

        cout << "Класс (буква): ";
        cin >> pupils[current_size].klass.letter;

        cout << "Оценки (матем, физика, литература, английский, история, химия):" << endl;
        for (int i = 0; i < NUM_SUBJECTS; i++) {
            cout << "Оценка по предмету " << i + 1 << ": ";
            cin >> pupils[current_size].marks[i];
        }

        float sum = 0;
        for (int i = 0; i < NUM_SUBJECTS; i++) {
            sum += pupils[current_size].marks[i];
        }
        pupils[current_size].average = sum / NUM_SUBJECTS;

        current_size++;
    }
    else {
        cout << "Никакие другие записи не могут быть введены" << endl;
    }
}

void displayOneStructure(Pupils onePupil) {
    cout << endl;
    cout << "Фамилия: " << onePupil.surname << endl;
    cout << "Имя: " << onePupil.name << endl;
    cout << "Отчество: " << onePupil.middlename << endl;
    cout << "Класс (номер): " << onePupil.klass.num << endl;
    cout << "Класс (буква): " << onePupil.klass.letter << endl;
    cout << "Оценки: " << endl;
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        cout << "Предмет " << i + 1 << ": " << onePupil.marks[i] << endl;
    }
    cout << "Средний балл: " << fixed << setprecision(2) << onePupil.average << endl;
}

void output() {
        bool anyRecord = false;
        for (int i = 0; i < current_size; i++) {
            if (pupils[i].surname[0] != '\0') { 
                displayOneStructure(pupils[i]);
                anyRecord = true;
                cout << endl;
            }
        }
        if (!anyRecord) {
            cout << "Данных об учениках нет." << endl;
        }
}

void del() {
    int rec_number;
    cout << "Введите номер записи для удаления" << endl;
    cin >> rec_number;

    if (rec_number < 1 || rec_number > current_size) {
        cout << "Некорректный номер записи" << endl;
        return;
    }

    pupils[rec_number - 1] = empty_pupil; 

    cout << "Запись с номером " << rec_number << " удалена" << endl;
}

void find() {
    char surname[50];
    cout << "Введите фамилию для поиска: ";
    cin >> surname;
    cout << endl;
    bool found = false;
    for (int i = 0; i < current_size; i++) {
        if (strcmp(pupils[i].surname, surname) == 0) {
            found = true;
            displayOneStructure(pupils[i]);
        }
    }
    if (!found) {
        cout << "Нет данных об ученике с фамилией " << surname << endl;
    }
}