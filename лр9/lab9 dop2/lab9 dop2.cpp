#include <iomanip>
#include <iostream>
using namespace std;
const unsigned int NAME_SIZE = 30;

struct Address
{
	char name[NAME_SIZE];
	char surname[NAME_SIZE];
	char parentname[NAME_SIZE];
	int year;
	int course;
	int group;
	float math;
	float OAIP;
	float English;
	float KPO;
	float Kyar;
	Address* next;
	Address* prev;
};

void insert(Address* e, Address** phead, Address** plast)
{
	Address* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
	}
}

Address* setElement()
{
	Address* temp = new Address();
	if (!temp)
	{
		cerr << "Ошибка выделения памяти";
		return NULL;
	}
	cout << "Введите фамилию: ";
	cin >> temp->surname;
	cout << "Введите имя: ";
	cin >> temp->name;
	cout << "Введите отчество: ";
	cin >> temp->parentname;
	cout << "Введите год рождения: ";
	cin >> temp->year;
	cout << endl;
	cout << "Введите номер курса: ";
	cin >> temp->course;
	cout << "Введите номер группы: ";
	cin >> temp->group;
	cout << "Введите оценки по предметам: " << endl;
	cout << "Математика:";
	cin >> temp->math;
	cout << endl;
	cout << "ОАиП:";
	cin >> temp->OAIP;
	cout << endl;
	cout << "Английский язык:";
	cin >> temp->English;
	cout << endl;
	cout << "КПО:";
	cin >> temp->KPO;
	cout << endl;
	cout << "КЯР:";
	cin >> temp->Kyar;
	cout << endl;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

void outputList(Address** phead, Address** plast)
{
	Address* t = *phead;
	if (t == NULL)
	{
		cout << "Список пуст!" << endl;
	}
	while (t)
	{

		cout << "--------------------------------------------------" << endl;
		cout << "Фамилия:" << t->surname << endl;
		cout << "Имя:" << t->name << endl;
		cout << "Отчество:" << t->parentname << endl;
		cout << "Год рождения:" << t->year << endl;
		cout << "Курс:" << t->course << endl;
		cout << "Группа:" << t->group << endl;
		cout << "Оценки:" << endl;
		cout << "Математика:" << t->math << endl;
		cout << "ОАиП:" << t->OAIP << endl;
		cout << "Английский язык:" << t->English << endl;
		cout << "КПО:" << t->KPO << endl;
		cout << "КЯР:" << t->Kyar << endl;
		t = t->next;

	}
}

void outputFirstCourse(Address** phead, Address** plast)
{
	int i = 0;
	Address* t = *phead;
	if (t == NULL)
	{
		cout << "Список пуст!" << endl;
	}
	cout << "---------------------Студенты 1 курса-------------------" << endl;
	if (strcmp(t->surname, (t->next)->surname) > 0)
	{
		t = t->next;
		t->next = t->prev;
		t->prev = t;
	}
	while (i != 2)
	{


		if (t->course == 1)
		{
			cout << "--------------------------------------------------" << endl;
			cout << "Фамилия:" << t->surname << endl;
			cout << "Имя:" << t->name << endl;
			cout << "Отчество:" << t->parentname << endl;
			cout << "Год рождения:" << t->year << endl;
			cout << "Курс:" << t->course << endl;
			cout << "Группа:" << t->group << endl;
			cout << "Оценки:" << endl;
			cout << "Математика:" << t->math << endl;
			cout << "ОАиП:" << t->OAIP << endl;
			cout << "Английский язык:" << t->English << endl;
			cout << "КПО:" << t->KPO << endl;
			cout << "КЯР:" << t->Kyar << endl;
			t = t->next;
		}
		else
		{
			t = t->next;
		}

		i++;
	}
}

void outputSecondCourse(Address** phead, Address** plast)
{
	Address* t = *phead;
	if (t == NULL)
	{
		cout << "Список пуст!" << endl;
	}
	cout << "--------------------Студенты 2 курса----------------" << endl;
	while (t)
	{
		if (t->course == 2)
		{
			cout << "--------------------------------------------------" << endl;
			cout << "Фамилия:" << t->surname << endl;
			cout << "Имя:" << t->name << endl;
			cout << "Отчество:" << t->parentname << endl;
			cout << "Год рождения:" << t->year << endl;
			cout << "Курс:" << t->course << endl;
			cout << "Группа:" << t->group << endl;
			cout << "Оценки:" << endl;
			cout << "Математика:" << t->math << endl;
			cout << "ОАиП:" << t->OAIP << endl;
			cout << "Английский язык:" << t->English << endl;
			cout << "КПО:" << t->KPO << endl;
			cout << "КЯР:" << t->Kyar << endl;
			t = t->next;
		}
		else
			t = t->next;

	}
}

void outputThirdCourse(Address** phead, Address** plast)
{
	Address* t = *phead;
	if (t == NULL)
	{
		cout << "Список пуст!" << endl;
	}
	cout << "--------------------Студенты 3 курса----------------" << endl;
	while (t)
	{
		if (t->course == 3)
		{
			cout << "--------------------------------------------------" << endl;
			cout << "Фамилия:" << t->surname << endl;
			cout << "Имя:" << t->name << endl;
			cout << "Отчество:" << t->parentname << endl;
			cout << "Год рождения:" << t->year << endl;
			cout << "Курс:" << t->course << endl;
			cout << "Группа:" << t->group << endl;
			cout << "Оценки:" << endl;
			cout << "Математика:" << t->math << endl;
			cout << "ОАиП:" << t->OAIP << endl;
			cout << "Английский язык:" << t->English << endl;
			cout << "КПО:" << t->KPO << endl;
			cout << "КЯР:" << t->Kyar << endl;
			t = t->next;
		}
		else
			t = t->next;

	}
}

void outputFourthCourse(Address** phead, Address** plast)
{
	Address* t = *phead;
	if (t == NULL)
	{
		cout << "Список пуст!" << endl;
	}
	cout << "--------------------Студенты 4 курса----------------" << endl;
	while (t)
	{
		if (t->course == 4)
		{
			cout << "--------------------------------------------------" << endl;
			cout << "Фамилия:" << t->surname << endl;
			cout << "Имя:" << t->name << endl;
			cout << "Отчество:" << t->parentname << endl;
			cout << "Год рождения:" << t->year << endl;
			cout << "Курс:" << t->course << endl;
			cout << "Группа:" << t->group << endl;
			cout << "Оценки:" << endl;
			cout << "Математика:" << t->math << endl;
			cout << "ОАиП:" << t->OAIP << endl;
			cout << "Английский язык:" << t->English << endl;
			cout << "КПО:" << t->KPO << endl;
			cout << "КЯР:" << t->Kyar << endl;
			t = t->next;
		}
		else
			t = t->next;

	}
}

void studentOld(Address** phead, Address** plast)
{
	int old = 0;
	Address* tmp = *phead;
	old = tmp->year;
	while (tmp)
	{

		if (tmp->year < old)
		{
			old = tmp->year;
		}
		tmp = tmp->next;

	}
	Address* t = *phead;
	while (t)
	{
		if (t->year == old)
		{
			cout << "Старший студент=" << t->surname << endl;
		}
		t = t->next;
	}

}

void studentYoung(Address** phead, Address** plast)
{
	int young = 0;
	Address* tmp = *phead;
	young = tmp->year;
	while (tmp)
	{

		if (tmp->year > young)
		{
			young = tmp->year;
		}
		tmp = tmp->next;

	}
	Address* t = *phead;
	while (t)
	{
		if (t->year == young)
		{
			cout << "Младший студент=" << t->surname << endl;
		}
		t = t->next;
	}
}

void average(Address** phead, Address** plast)
{
	Address* t = *phead;
	float bestAverage = 0;
	Address* bestStudent = nullptr;

	while (t)
	{
		float currentAverage = (t->English + t->math + t->Kyar + t->KPO + t->OAIP) / 5;
		cout << "Студент: " << t->surname << " Средний балл: " << currentAverage << endl;

		// Проверяем, является ли текущий студент лучшим
		if (currentAverage > bestAverage)
		{
			bestAverage = currentAverage;
			bestStudent = t;
		}

		t = t->next;
	}

	if (bestStudent)
	{
		cout << "Лучший студент: " << bestStudent->surname << endl;
	}
	else
	{
		cout << "Лучший студент не найден." << endl;
	}
}

int main()
{
	Address* head = NULL;
	Address* last = NULL;
	setlocale(LC_CTYPE, "Rus");
	int choice;
	char s[80]; int c;
	cout << endl;
	cout << "1. Ввод элемента" << endl;
	cout << "2. Старший студент" << endl;
	cout << "3. Младший студент" << endl;
	cout << "4. Лучший ученик" << endl;
	cout << "5. вывод списка" << endl;
	cout << "6. 1 курс" << endl;
	cout << "7. 2 курс" << endl;
	cout << "8. 3 курс" << endl;
	cout << "9. 4 курс" << endl;
	cout << "10. Выход" << endl;
	cout << endl;
	for (;;)
	{
		cout << "Ваш выбор: ";
		cin >> choice;
		switch (choice)
		{
		case 1: insert(setElement(), &head, &last);
			break;
		case 2: studentOld(&head, &last);
			break;
		case 3: studentYoung(&head, &last);
			break;
		case 4: average(&head, &last);
			break;
		case 5: outputList(&head, &last);
			break;
		case 6: outputFirstCourse(&head, &last);
			break;
		case 7:
			outputSecondCourse(&head, &last);
			break;
		case 8:
			outputThirdCourse(&head, &last);
			break;
		case 9:
			outputFourthCourse(&head, &last);
			break;
		case 10: exit(0);
		default: exit(1);
		}
	}
	return 0;
}