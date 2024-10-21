#include <iostream>
#include <fstream>
using namespace std;

void function(int A, int* number, int digitsLeft, int size, ofstream& f) {
    if (digitsLeft == 0) {
        for (int i = 0; i < size; ++i) {
            f << number[i]; // Записываем число в файл
        }
        f << endl;
        return;
    }

    for (int i = 0; i <= A; ++i) {
        number[size - digitsLeft] = i; // Записываем текущую цифру в массив числа
        function(A, number, digitsLeft - 1, size, f); // Рекурсивный вызов для каждой возможной цифры
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    int A;
    cout << "Введите цифру: ";
    cin >> A;
    while (A < 0 || A > 9) {
        cout << "Ошибка. Повторите ввод: ";
        cin >> A;
    }

    ofstream f("file.txt");
    if (!f.is_open()) {
        cout << "Не удалось открыть файл для записи.";
        return 1;
    }

    int* number = new int[A]; // Создаем массив для хранения числа
    function(A, number, A, A, f); 
    delete[] number;

    cout << "Результат записан в файл.";
    f.close();
    return 0;
}