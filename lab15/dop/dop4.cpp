#include <iostream>
#include <ctime>
using namespace std;

void sort(int a[], int size) {
	int j, step, i;
	for (step = size / 2; step > 0; step /= 2) {
		for (i = step; i < size; i++)
		{
			int tmp = a[i];
			for (j = i; j >= step; j -= step)
			{
				if (tmp < a[j - step]) {
					a[j] = a[j - step];
				}
				else {
					break;
				}
			}
			a[j] = tmp;
		}
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	int size = 2000;
	int* A = new int[size];

	for (int i = 0; i < size; i++)
	{
		A[i] = rand() % 2000;
	}

	clock_t start1 = clock();
	sort(A, size);
	clock_t stop1 = clock();
	long long duration1 = static_cast<int>(floor(static_cast<double>(stop1 - start1) * 1000 / CLOCKS_PER_SEC));
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << endl << "Сортировка Шелла. Количество элементов " << size << ", время: " << duration1 << " милисекунд" << endl << endl;

	delete[] A;

	return 0;
}