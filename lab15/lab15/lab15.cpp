#include <iostream>
#include <ctime>
using namespace std;

void bubbleSort(int a[], int n)
{
	int i, j, t;
	for (i = 1; i < n; i++)
		for (j = n - 1; j >= i; j--)
			if (a[j - 1] < a[j])
			{
				swap(a[j - 1], a[j]);
				/*t = a[j - 1];
				a[j - 1] = a[j];
				a[j] = t;*/
			}
}

void heapify(int A[], int pos, int n)
{
	int t, tm;
	while (2 * pos + 1 < n)
	{
		t = 2 * pos + 1;
		if (2 * pos + 2 < n && A[2 * pos + 2] <= A[t])
			t = 2 * pos + 2;
		if (A[pos] > A[t])
		{
			tm = A[pos];
			A[pos] = A[t];
			A[t] = tm;
			pos = t;
		}
		else break;
	}
}
void piramSort(int A[], int n)
{
	for (int i = n - 1; i >= 0; i--)
		heapify(A, i, n);
	while (n > 0)
	{
		int tm = A[0];
		A[0] = A[n - 1];
		A[n - 1] = tm;
		n--;
		heapify(A, 0, n);
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	int size = 2000;
	int* A = new int[size];
	int* B = new int[size];
	int* C = new int[size];
	int* C_copy = new int[size];

	for (int i = 0; i < size; i++)
	{
		A[i] = rand() % 2000;
		B[i] = rand() % 1000;
	}

	int maxB = 0;
	for (int i = 0; i < size; i++) {
		if (B[i] > maxB) {
			maxB = B[i];
		}
	}
	
	int indexC = 0;
	for (int i = 0; i < size; i++) {
		if (A[i] > maxB) {
			C[indexC++] = A[i];
		}
	}

	clock_t start1 = clock();
	bubbleSort(C, indexC);
	clock_t stop1 = clock();
	long long duration1 = static_cast<int>(floor(static_cast<double>(stop1 - start1) * 1000 / CLOCKS_PER_SEC));
	for (int i = 0; i < indexC; i++)
		cout << C[i] << " ";
	cout << endl << "Сортировка пузырьком. Количество элементов " << indexC << ", время: " << duration1 << " милисекунд" << endl << endl;

	for (int i = 0; i < indexC; i++)
		C_copy[i] = C[i];

	clock_t start2 = clock();
	piramSort(C_copy, indexC);
	clock_t stop2 = clock();
	long long duration2 = static_cast<int>(floor(static_cast<double>(stop2 - start2) * 1000 / CLOCKS_PER_SEC));
	for (int i = 0; i < indexC; i++)
		cout << C_copy[i] << " ";
	cout << endl << "Пирамидальная сортировка. Количество элементов " << indexC << ", время: " << duration2 << " милисекунд" << endl << endl;

	delete[] A;
	delete[] B;
	delete[] C;
	delete[] C_copy;

	return 0;
}

