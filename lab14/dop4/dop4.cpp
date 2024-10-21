#include "Hash.h"
#include "AAA.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

int key(void* d)
{
	AAA* f = (AAA*)d;
	return f->key;
}
//-------------------------------
void AAA_print(void* d)
{
	cout << " ключ " << ((AAA*)d)->key << " - " << ((AAA*)d)->value << endl;
}
//-------------------------------
int* fromFile(ifstream& f)
{
	f.open("file.txt");
	if (!f)
	{
		cout << "Ошибка открытия файла";
		exit(1);
	}

	string line;
	int i = 0;
	while (getline(f, line))
	{
		i++;
	}

	f.close();

	int* nums = new int[i];

	f.open("file.txt");
	f.seekg(0);// Установка указателя чтения в начало файла
	i = 0;
	while (f >> nums[i])
	{
		i++;
	}

	f.close();
	return nums;
}
//-------------------------------
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int siz = 10, choice;
	ifstream f;
	int* nums = fromFile(f);
	siz = _msize(nums) / sizeof(int);
	Object H = create(siz, key);
	vector <int> keys;
	for (int i = 0; i < siz; i++)
	{
		int key;
		bool unique;
		do
		{
			unique = true;
			key = rand() % 8;
			for (auto x : keys)
			{
				if (key == x)
				{
					unique = false;
					break;
				}
			}
		} while (!unique);
		keys.push_back(key);
		AAA* a = new AAA(key, nums[i]);
		H.insert(a);
	}


	H.scan(AAA_print);

	int num;
	cout << endl << "Введите целое число для поиска" << endl;
	cin >> num;
	AAA* search_result = (AAA*)H.searchByValue(num);
	if (search_result != nullptr)
		AAA_print(search_result);
	else
		cout << "Число не найдено" << endl;

	return 0;
}
