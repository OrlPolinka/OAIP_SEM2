#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>


using namespace std;

struct TRAIN {
    string destination;
    int trainNumber;   
    string departureTime; 
};

// Функция для сравнения по пункту назначения для сортировки
bool compareDestinations(const TRAIN& train1, const TRAIN& train2) {
    return train1.destination < train2.destination;
}

void printTrains(const TRAIN trains[], int size, const string& time) {
    bool found = false;
    cout << "Поезда, отправляющиеся после времени " << time << ":\n";
    for (int i = 0; i < size; ++i) {
        if (trains[i].departureTime > time) {
            cout << "Пункт назначения: " << trains[i].destination << endl;
            cout << "Номер поезда: " << trains[i].trainNumber << endl;
            cout << "Время отправления: " << trains[i].departureTime << endl << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Поездов, отправляющихся после указанного времени, нет.\n";
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "ru");
    const int SIZE = 8; 

    TRAIN trains[SIZE];

    cout << "Введите данные о поездах:\n";
    for (int i = 0; i < SIZE; ++i) {
        cout << "Поезд " << i + 1 << ":\n";
        cout << "Пункт назначения: ";
        cin >> trains[i].destination;
        cout << "Номер поезда: ";
        cin >> trains[i].trainNumber;
        cout << "Время отправления (в формате HH:MM): ";
        cin >> trains[i].departureTime;
        cout << endl;
    }

    // Сортировка массива по пунктам назначения
    sort(trains, trains + SIZE, compareDestinations);

    string searchTime;
    cout << "Введите время, после которого хотите найти поезда (в формате HH:MM): ";
    cin >> searchTime;

    printTrains(trains, SIZE, searchTime);

    return 0;
}