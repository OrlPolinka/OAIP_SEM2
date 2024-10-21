#include "Hash.h"
#include <iostream>
#include <string>
using namespace std;

struct AAA
{
	int key;
	char symbol;
	int count;
	AAA(int k, char z)
	{
		key = k;  symbol = z; count = 1;
	} AAA() {}
};
//-------------------------------
int key(void* d)
{
	AAA* f = (AAA*)d;
	return f->key;
}
//-------------------------------
void AAA_print(void* d)
{
	cout << " символ " << ((AAA*)d)->symbol << " - " << ((AAA*)d)->count << endl;
}
//-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	string str;
	cout << "Введите строку, состоящую из букв: ";
	getline(cin, str);
	Object H = create(32, key);

	for (char c : str)
	{
		if (isalpha(c))
		{
			AAA* a = (AAA*)H.search(c);
			if (a == nullptr)
			{
				a = new AAA(c, c);
				H.insert(a);
			}
			else
			{
				a->count++;
			}
		}
	}

	H.scan(AAA_print);

	char sym;
	cout << endl << "Введите букву для поиска" << endl;
	cin >> sym;
	if (H.search(sym) == nullptr)
		cout << "Элемент не найден" << endl;
	else
		AAA_print(H.search(sym));

	return 0;
}
