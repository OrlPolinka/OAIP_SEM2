// Вариант 10 Задание 2

#include <iostream>
#include <string>
using namespace std;

//функция для нахождения слова на первую букву алфавита и сортировке выводимых слов в алфавитном порядке
int sort(string word, ...) {
    char first = 'a';//присвоиваем значение первой буквы = a
    
    for (int i = 0; i < 26; i++) {

        //проходим по всем словам и в случае если найдено слово с первой буквы алфавита, то выводим его на экран
        if (word[0] == first) {
            for (int i = 0; i < size(word); i++) {
                if (word[i] == ' ') {
                    cout << ' ';
                    break;
                }
                cout << word[i];
            }
        }
        for (int j = 0; j < size(word); j++) {
            if ((word[j] == ' ' && word[j + 1] == first)) {
                for (int q = j + 1; q < size(word); q++) {
                    cout << word[q];
                    if (word[q] == ' ') {
                        cout << ' ';
                        break;
                    }
                }
                cout << ' ';
            }
        }

        first++;//увеличиваем первую букву алфавита до следующей и снова проходимся по циклу
    }
    cout << endl;
    return 0;
}

int main()
{
    setlocale(LC_CTYPE, "Russian");
    string word;
    getline(cin, word);//вводим строку слов
    sort(word);//вызываем функцию
    getline(cin, word);//вводим строку слов
    sort(word);//вызываем функцию
    getline(cin, word);//вводим строку слов
    sort(word);//вызываем функцию
    return 0;
}