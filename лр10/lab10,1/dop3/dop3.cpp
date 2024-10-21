#include <iostream>
using namespace std;

const int n = 5;
int nums[n] = { 1, 2, 3, 4, 5 };

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void perest(int arr[], int size, int start) {
	if (start == size) {
		printArray(arr, size);
		return;
	}

	for (int i = start; i < size; i++) {
		swap(arr[start], arr[i]);//меняем местами числа
		perest(arr, size, start + 1);
		swap(arr[start], arr[i]);//меняем числа обратно
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	cout << "Перестановки: " << endl;
	perest(nums, n, 0);
	return 0;
}