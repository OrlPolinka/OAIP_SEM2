#include <iostream>
using namespace std;

struct Students {
	string surname;
	string name;
	string patronymic;
	int yearBirth;
	int course;
	int numbGroup;
	int OAP;
	int KPO;
	int MATH;
	int AISD;
	int HISTORY;
	Students* next;
	Students* prev;
};

void input(Students *e, Students **phead, Students **plast) {
	Students* p = *plast;
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

Students* SetElements() {
	Students* e = new Students();
	if (!e) {
		cerr << "Ошибка выделения памяти";
		return NULL;
	}
	cout << "Введите фамилию: ";
	cin >> e->surname;
	cout << "Введите имя: ";
	cin >> e->name; 
	cout << "Введите отчество: ";
	cin >> e->patronymic; 
	cout << "Введите год рождения: ";
	cin >> e->yearBirth; 
	cout << "Введите курс: ";
	cin >> e->course; 
	cout << "Введите номер группы: ";
	cin >> e->numbGroup; 
	cout << "Введите оценку по ОАП: ";
	cin >> e->OAP; 
	cout << "Введите оценку по КПО: ";
	cin >> e->KPO; 
	cout << "Введите оценку по матанализу: ";
	cin >> e->MATH; 
	cout << "Введите оценку по АИСД: ";
	cin >> e->AISD; 
	cout << "Введите оценку по истории: ";
	cin >> e->HISTORY;
	return e;
}

void output(Students **phead, Students **plast) {
	Students *t = *phead;
	while (t) {
		cout << t->surname << " " << t->name << " " << t->patronymic << " " << t->yearBirth << " " << t->course << " " 
		<< t->numbGroup << " " << t->OAP << " " << t->KPO << " " << t->MATH << " " << t->AISD << " " << t->HISTORY << endl;
		t = t->next;
	}
}

void outputFirstCourse(Address** phead, Address** plast)
{
	int i = 0;
	Address* t = *phead;
	if (t == NULL)
	{
		cout << "Список пуст" << endl;
	}
	cout << "\nСтуденты 1 курса:" << endl;
	if (strcmp(t->surname, (t->next)->surname) > 0)
	{
		t = t->next;
		t->next = t->prev;
		t->prev = t;
	}
	while (t)
	{


		if (t->course == 1)
		{
			cout << t->surname << " " << t->name << " " << t->patronymic << " " << t->yearBirth << " " << t->course << " "
				<< t->numbGroup << " " << t->OAP << " " << t->KPO << " " << t->MATH << " " << t->AISD << " " << t->HISTORY << endl;
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
		cout << "Список пуст" << endl;
	}
	cout << "\nСтуденты 2 курса:" << endl;
	while (t)
	{
		if (t->course == 2)
		{
			cout << t->surname << " " << t->name << " " << t->patronymic << " " << t->yearBirth << " " << t->course << " "
				<< t->numbGroup << " " << t->OAP << " " << t->KPO << " " << t->MATH << " " << t->AISD << " " << t->HISTORY << endl;
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
		cout << "Список пуст" << endl;
	}
	cout << "\nСтуденты 3 курса:" << endl;
	while (t)
	{
		if (t->course == 3)
		{
			cout << t->surname << " " << t->name << " " << t->patronymic << " " << t->yearBirth << " " << t->course << " "
				<< t->numbGroup << " " << t->OAP << " " << t->KPO << " " << t->MATH << " " << t->AISD << " " << t->HISTORY << endl;
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
		cout << "Список пуст" << endl;
	}
	cout << "\nСтуденты 4 курса:" << endl;
	while (t)
	{
		if (t->course == 4)
		{
			cout << t->surname << " " << t->name << " " << t->patronymic << " " << t->yearBirth << " " << t->course << " "
				<< t->numbGroup << " " << t->OAP << " " << t->KPO << " " << t->MATH << " " << t->AISD << " " << t->HISTORY << endl;
			t = t->next;
		}
		else
			t = t->next;

	}
}

//Students* merge(Students* first, Students* second) {
//	if (!first) return second;
//	if (!second) return first;
//
//	if (first->surname < second->surname) {
//		first->next = merge(first->next, second);
//		first->next->prev = first;
//		first->prev = NULL;
//		return first;
//	}
//	else {
//		second->next = merge(first, second->next);
//		second->next->prev = second;
//		second->prev = NULL;
//		return second;
//	}
//}
//
//Students* mergeSort(Students* head) {
//	if (!head || !head->next) return head;
//
//	Students* slow = head;
//	Students* fast = head->next;
//
//	while (fast && fast->next) {
//		slow = slow->next;
//		fast = fast->next->next;
//	}
//
//	Students* second = slow->next;
//	slow->next = NULL;
//
//	head = mergeSort(head);
//	second = mergeSort(second);
//
//	return merge(head, second);
//}
//
//void sortStudents(Students** phead) {
//	// Сортировка по фамилии
//	*phead = mergeSort(*phead);
//}

void averageScores(Students** phead) {
	// Создание массива для суммы оценок и количества студентов по каждой группе и предмету
	int scoresSum[6][7] = { 0 }; // 6 групп, 6 предметов + средний балл

	// Подсчет суммы оценок
	Students* current = *phead;
	while (current) {
		int groupIndex = current->numbGroup - 1; // Индекс группы в массиве (0-5)
		scoresSum[groupIndex][6]++; // Увеличиваем количество студентов в группе

		// Суммируем оценки
		scoresSum[groupIndex][0] += current->OAP;
		scoresSum[groupIndex][1] += current->KPO;
		scoresSum[groupIndex][2] += current->MATH;
		scoresSum[groupIndex][3] += current->AISD;
		scoresSum[groupIndex][4] += current->HISTORY;

		current = current->next;
	}

	// Вывод средних оценок по каждой группе и предмету
	cout << "Средний балл каждой группы по каждому предмету:" << endl;
	for (int i = 0; i < 6; ++i) {
		cout << "Группа " << i + 1 << ":" << endl;
		cout << "OAP: " << (double)scoresSum[i][0] / scoresSum[i][6] << endl;
		cout << "KPO: " << (double)scoresSum[i][1] / scoresSum[i][6] << endl;
		cout << "MATH: " << (double)scoresSum[i][2] / scoresSum[i][6] << endl;
		cout << "AISD: " << (double)scoresSum[i][3] / scoresSum[i][6] << endl;
		cout << "HISTORY: " << (double)scoresSum[i][4] / scoresSum[i][6] << endl;
		cout << endl;
	}
}

void findOldYoung(Students** phead) {
	Students* old = *phead;
	Students* young = *phead;
	Students* s = *phead;
	while (s) {
		if (s->yearBirth > young->yearBirth) {
			young = s;
		}
		if (s->yearBirth < old->yearBirth) {
			old = s;
		}
		s = s->next;
	}
	cout << "Самый старший студент: " << old->surname << " " << old->name << " " << old->patronymic << endl;
	cout << "Самый младший студент: " << young->surname << " " << young->name << " " << young->patronymic << endl;;
}

void findBestStudents(Students** phead) {
	// Создаем массив для хранения лучших студентов каждой группы
	Students* bestStudents[6] = { nullptr };

	// Проходим по списку студентов и для каждой группы находим лучшего студента
	Students* current = *phead;
	while (current) {
		int groupIndex = current->numbGroup - 1; // Индекс группы в массиве (0-5)

		if (!bestStudents[groupIndex] || current->OAP + current->KPO + current->MATH + current->AISD + current->HISTORY >
			bestStudents[groupIndex]->OAP + bestStudents[groupIndex]->KPO + bestStudents[groupIndex]->MATH +
			bestStudents[groupIndex]->AISD + bestStudents[groupIndex]->HISTORY) {
			bestStudents[groupIndex] = current;
		}

		current = current->next;
	}

	// Выводим результаты
	cout << "Лучший студент каждой группы:" << endl;
	for (int i = 0; i < 6; ++i) {
		if (bestStudents[i]) {
			cout << "Группа " << i + 1 << ": " << bestStudents[i]->surname << " " << bestStudents[i]->name << " " << bestStudents[i]->patronymic << endl;
		}
		else {
			cout << "Группа " << i + 1 << ": нет данных" << endl;
		}
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	Students* head = NULL;
	Students* last = NULL;
	int choice;
	do {
		cout << "\nМеню:" << endl;
		cout << "1. Добавить элемент в список" << endl;
		cout << "2. Вывод списка на экран" << endl;
		cout << "3. Упорядочить студентов" << endl;
		cout << "4. Средний балл каждой группы по каждому предмету" << endl;
		cout << "5. Определение самого старшего и самого младшего студентов" << endl;
		cout << "6. Лучший студент каждой группы" << endl;
		cout << "0. Выход" << endl;
		cin >> choice;
		switch (choice) {
		case 1: {
			input(SetElements(), &head, &last);
			break;
		}
		case 2: {
			output(&head, &last);
			break;
		}
		case 3: {
			outputFirstCourse(&head, &last);
			outputSecondCourse(&head, &last);
			outputThirdCourse(&head, &last);
			outputFourthCourse(&head, &last);
			break;
		}
		case 4: {
			averageScores(&head);
			break;
		}
		case 5: {
			findOldYoung(&head);
			break;
		}
		case 6: {
			findBestStudents(&head);
			break;
		}
		}
	} while (choice != 0);
	return 0;
}