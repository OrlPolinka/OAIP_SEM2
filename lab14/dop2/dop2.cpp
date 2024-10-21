#include "Hash.h"
#include "AAA.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <set>
#include <algorithm>
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
	cout << " ключ " << ((AAA*)d)->key << " - " << ((AAA*)d)->word << endl;
}
//-------------------------------
string* fromFile(ifstream& f, int size)
{
	f.open("file.txt");
	if (!f)
	{
		cout << "Ошибка открытия файла";
		exit(1);
	}

	string line;
	string* words = new string[size];
	set<string> unique_words;// Создание множества для хранения уникальных слов
	int i = 0;
	while (getline(f, line))
	{
		istringstream iss(line);// Создание объекта istringstream для разбиения строки на слова
		string word;
		while (iss >> word)
		{
			word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());// Удаление пунктуации
			if (unique_words.find(word) == unique_words.end() && i < size)// Проверка на уникальность слова и на превышение размера массива
			{
				words[i++] = word;
				unique_words.insert(word);// Добавление слова в множество уникальных слов
			}
		}
	}

	f.close();
	return words;
}
//-------------------------------
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int siz = 10, choice;
	cout << "Введите размер хеш-таблицы" << endl;
	cin >> siz;
	Object H = create(siz, key);

	ifstream f;
	string* words = fromFile(f, siz);
	for (int i = 0; i < siz; i++)
	{
		int key = rand() % 1001;
		AAA* a = new AAA(key, words[i]);
		H.insert(a);
	}

	H.scan(AAA_print);

	string search_word;
	cout << endl << "Введите слово для поиска" << endl;
	cin >> search_word;
	AAA* search_result = (AAA*)H.searchByWord(search_word);
	if (search_result != nullptr)
		AAA_print(search_result);
	else
		cout << "Слово не найдено" << endl;

	char del_letter;
	cout << endl << "Введите букву для удаления слов" << endl;
	cin >> del_letter;
	for (int i = 0; i < siz; i++)
	{
		AAA* a = (AAA*)H.data[i];
		if (a != nullptr && a->word[0] == del_letter)
			H.deleteByValue(a);
	}

	H.scan(AAA_print);

	return 0;
}
