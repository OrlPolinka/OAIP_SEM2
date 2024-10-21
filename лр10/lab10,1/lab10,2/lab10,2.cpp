#include <iostream>
#include <cmath>
using namespace std;

double sumCos(int n, double x) {
	if (n == 1) {
		return cos(x);
	}
	else {
		return (cos(n * x) + sumCos(n - 1, x) * n);
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	int n;
	double x;
	cout << "Введите n: ";
	cin >> n;
	while (n <= 0) {
		cout << "Ошибка. Повторите попытку: ";
		cin >> n;
	}
	cout << "Введите x: ";
	cin >> x;
	cout << "Результат: " << sumCos(n, x);
	return 0;
}