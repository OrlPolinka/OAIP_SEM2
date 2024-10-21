#include <iostream>
#include <ctime>
using namespace std;

void sort(int D[], int N) {
	for (int i = 0; i < N; i++) {
		int min = i;
		for (int j = i + 1; j < N; j++) {
			min = (D[j] < D[min]) ? j : min;
		}
		if (i != min) {
			swap(D[i], D[min]);
		}
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	int size = 1000;
	int* A = new int[size];

	for (int i = 0; i < size; i++)
	{
		A[i] = rand() % 1000;
	}

	clock_t start1 = clock();
	sort(A, size);
	clock_t stop1 = clock();
	long long duration1 = static_cast<int>(floor(static_cast<double>(stop1 - start1) * 1000 / CLOCKS_PER_SEC));
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << endl << "Сортировка выбором. Количество элементов " << size << ", время: " << duration1 << " милисекунд" << endl << endl;

	delete[] A;

	return 0;
}