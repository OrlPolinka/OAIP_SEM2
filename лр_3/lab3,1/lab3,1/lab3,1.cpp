//Вариант 10 Задание 1

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "RU");
    char buff[50]; 
    char firstWord[50]; 
    
    ofstream fout("FILE2.txt");    
    ifstream fin("FILE1.txt");    
    
    if (!fin.is_open())       
        cout << "Файл не может быть открыт!\n"; 
    else {
        fin >> firstWord;          
    }

    fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорируем остаток строки
    
    while (fin.getline(buff, 50)) { 
        if (strstr(buff, firstWord) == nullptr) { // функция strstr ищет первое вхождение слова firstWord в данной строке
            fout << buff << endl; 
        }
    }
    
    fin.close();  
    fout.close(); 

    int consonants = 0;
    
    ifstream fin2("FILE2.txt");    
    if (!fin2.is_open())
        cout << "Файл не может быть открыт!\n";
    else {
        fin2.getline(buff, 50); 
        
        const char* consonantLetters = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";

        for (int i = 0; buff[i] != '\0'; ++i) {
            if (strchr(consonantLetters, buff[i])) { // если текущий символ - согласная буква, то
                consonants++; // добавляем + 1 к количеству согласных букв
            }
        }
    }

    fin2.close();
    cout << "В первой строке файла FILE2 " << consonants << " согласных букв." << endl;

    return 0;


}
