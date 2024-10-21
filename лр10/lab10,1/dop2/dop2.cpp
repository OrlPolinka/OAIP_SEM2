#include <iostream>
using namespace std;

const int MAX_COUNTRIES = 100;//макс количество стран

bool canGroups(int matrix[MAX_COUNTRIES][MAX_COUNTRIES], int groups[MAX_COUNTRIES], int numCountries, int country, int group) {
	for (int i = 0; i < numCountries; i++) {
		if (matrix[country][i] && groups[i] == group) {
			return false; // если у текущей страны есть смежная страна с той же группой
		}
	}
	return true;
}

bool splitCountries(int matrix[MAX_COUNTRIES][MAX_COUNTRIES], int groups[MAX_COUNTRIES], int numCountries, int country) {
	if (country == numCountries) {
		return true;
	}

	// Пытаемся присвоить текущей стране группу 1
	if (canGroups(matrix, groups, numCountries, country, 1)) {
		groups[country] = 1;
		if (splitCountries(matrix, groups, numCountries, country + 1)) {
			return true; // Если разбиение продолжается успешно, возвращаем true
		}
		groups[country] = 0; // Если не удалось разбить, сбрасываем группу
	}

	// Пытаемся присвоить текущей стране группу 0
	if (canGroups(matrix, groups, numCountries, country, 0)) {
		groups[country] = 0;
		if (splitCountries(matrix, groups, numCountries, country + 1)) {
			return true; // Если разбиение продолжается успешно, возвращаем true
		}
		groups[country] = -1; // Если не удалось разбить, сбрасываем группу
	}

	return false; // Если не удалось разбить страны, возвращаем false
}

int main() {
	setlocale(LC_ALL, "ru");
	int matrix[MAX_COUNTRIES][MAX_COUNTRIES] = {
		{0, 1, 1, 0},
		{1, 0, 0, 1},
		{1, 0, 0, 0},
		{0, 1, 0, 0}
	};
	
	int numCountries = 4;//количество стран
	int groups[MAX_COUNTRIES];//массив для хранения групп
	fill_n(groups, MAX_COUNTRIES, -1); //заполняем массив элементов значениями -1, для обазначения того, что страна еще не присвоена ни одной группе

	if (splitCountries(matrix, groups, numCountries, 0)) {
		cout << "Группы стран: " << endl;
		for (int i = 0; i < numCountries; i++) {
			cout << "Страна " << i+1 << " в группе " <<1 + groups[i] << endl;
		}
	}
	else {
		cout << "Не удалось разбить страны на две группы" << endl;
	}
	return 0;
}