#include <iostream>
using namespace std;

int F(int m, int n) {
	if (m == 0 || n == 0) {
		return(n + 1);
	}
	else {
		return F(m - 1, F(m, n - 1));
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	int m, n;
	cout << "Введите число m и n: ";
	cin >> m >> n;
	while (m < 0 || n < 0) {
		cout << "Ошибка. Повторите попытку: ";
		cin >> m >> n;
	}
	cout << F(m, n);
	return 0;
}