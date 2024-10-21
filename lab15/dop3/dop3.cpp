#include <iostream>
#include <ctime>
using namespace std;

void sort(int C[], int N) {
	for (int i = 1; i < N; i++) {
		int buff = C[i];
		int j = i - 1;
		while (j >= 0 && C[j] > buff) {
			C[j + 1] = C[j];
			j--;
		}
		C[j + 1] = buff;
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
	cout << endl << "Сортировка вствкой. Количество элементов " << size << ", время: " << duration1 << " милисекунд" << endl << endl;

	delete[] A;

	return 0;
}