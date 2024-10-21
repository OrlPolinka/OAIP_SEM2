/*Разбили страны, чтобы страны, имеющие общую груницу, были в разных группах
0-не имеют общую границу
1-имеют общую границу*/

#include <iostream>
using namespace std;

const int MAX_COUNTRIES = 100;//макс количество стран

//функция для проверки, можно ли присвоить стране определенную группу
bool canPartition(int matrix[MAX_COUNTRIES][MAX_COUNTRIES], int groups[MAX_COUNTRIES], int numCountries, int country, int group) {
    for (int i = 0; i < numCountries; ++i) {
        if (matrix[country][i] && groups[i] == group) { //если страна смежная с другой страной из этой же группы
            return false;
        }
    }
    return true;
}

//функция для разбиения стран на 2 группы
bool partitionCountries(int matrix[MAX_COUNTRIES][MAX_COUNTRIES], int groups[MAX_COUNTRIES], int numCountries, int country) {
    if (country == numCountries) { //если все страны просмотрены
        return true;
    }

    //пробуем присвоить текущей стране группу 1
    if (canPartition(matrix, groups, numCountries, country, 1)) {
        groups[country] = 1; //присваиваем группу 1
        if (partitionCountries(matrix, groups, numCountries, country + 1)) { //продолжаем разбиение для следующей страны
            return true;
        }
        groups[country] = 0; //если разбиение не удалось, сбрасываем группу
    }

    //пробуем присвоить текущей стране группу 0
    if (canPartition(matrix, groups, numCountries, country, 0)) {
        groups[country] = 0; //присваиваем стране группу 0
        if (partitionCountries(matrix, groups, numCountries, country + 1)) { //продолжаем разбиение для следующей страны
            return true;
        }
        groups[country] = -1; //если разбиение не удалось, сбрасываем группу
    }

    return false; //если ни одной разбиение не удалось, возвращаем false
}

int main() {
	setlocale(LC_ALL, "ru");
	int matrix[MAX_COUNTRIES][MAX_COUNTRIES] = {
		{0, 0, 0, 0},
		{0, 0, 1, 0},
		{0, 1, 0, 1},
		{0, 0, 1, 0}
	};

	int numCountries = 4;
	int groups[MAX_COUNTRIES];
	fill_n(groups, MAX_COUNTRIES, -1); //заполняем массив элементов значениями -1, для обазначения того, что страна еще не присвоена ни одной группе

	if (partitionCountries(matrix, groups, numCountries, 0)) {
		cout << "Группы стран:\n";
		for (int i = 0; i < numCountries; ++i) {
			cout << "Страна " << i + 1 << " в группе " << groups[i] + 1 << endl;
		}
	}
	else {
		cout << "Не удалось разделить страны на две группы с минимальным количеством граничащих пар." << endl;
	}

	return 0;
}