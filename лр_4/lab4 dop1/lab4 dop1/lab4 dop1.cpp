// СПЕРВА НУЖНО ПРОЧЕСТЬ ФАЙЛ(3), ЗАТЕМ ВЫПОЛНЯТЬ ОСТАЛЬНЫЕ ДЕЙСТВИЯ

#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    string name;
    int maths;
    int physics;
    int english;
    int oap;
};

void exams(Student* students, int SIZE) {

    int numStudents = 0;
    for (int i = 0; i < SIZE; ++i) {

        if ((students[i].maths == 5 || students[i].maths == 4) &&
            (students[i].physics == 5 || students[i].physics == 4) &&
            (students[i].english == 5 || students[i].english == 4) &&
            (students[i].oap == 5 || students[i].oap == 4))
        {
            cout << i << ") Студент: " << students[i].name << " сдал экзамены на 4 или 5" << endl;
            numStudents++;
        }
        else cout << i << ") Студент: " << students[i].name << " не сдал экзамены на 4 или 5" << endl;
    }
    cout << "Сотношение студентов, сдавших экзамен на 4 или 5, ко всем студентам " << ((double)numStudents / (double)SIZE) * 100 << " % " << endl;
}

void displayInfo(Student* students, int SIZE) {
    for (int i = 0; i < SIZE; ++i) {
        cout << "Имя студента: " << students[i].name << endl;
        cout << "Математика: " << students[i].maths << endl;
        cout << "Физика: " << students[i].physics << endl;
        cout << "Английский: " << students[i].english << endl;
        cout << "ОАП: " << students[i].oap << endl;
    }
}

void  ifileStud(Student* students, int SIZE) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream fin("file.txt");
    if (!fin.is_open()) {
        cout << "Не удаётся открыть файл для чтения " << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < SIZE; ++i) {
        fin >> students[i].maths;
        fin >> students[i].physics;
        fin >> students[i].english;
        fin >> students[i].oap;
        fin >> students[i].name;
    }
    cout << "\nСчитана информация из файла\n";
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, ".1251");
    const int SIZE = 10;
    Student students[SIZE];
    short choose;
    do {
        cout << "\nВыберите, что сделать:\n1 — проверить, сколько студентов положительно сдали экзамены;\n2 — вывести в консоль информацию о студенте;\n3 — считать информацию из файла;\n4 — выход из программы.\n";
        cin >> choose;
        switch (choose)
        {
        case 1: exams(students, SIZE); break;
        case 2: displayInfo(students, SIZE); break;
        case 3: ifileStud(students, SIZE); break;
        case 4: exit(0); break;
        }
    } while (choose != 4);
}