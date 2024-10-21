#include "Lists.h"
#include <iostream>
using namespace std;

struct AAA        //элемент таблицы
{
	int number;
	string* name;
};
namespace listx
{
	bool Object::insert(void* data)
	{
		bool rc = true;
		if (head == NULL)
			head = new Element(NULL, data, head);
		else
			head = (head->prev = new Element(NULL, data, head));
		return rc;
	}
	//-------------------------------
	Element* Object::search(void* data)
	{
		Element* rc = head;
		while ((rc != NULL) && ((((AAA*)rc->data)->number) != ((AAA*)data)->number))
			rc = rc->next;
		return rc;
	}
	//-------------------------------
	bool Object::deleteByElement(Element* e)
	{
		bool rc = NULL;
		if (rc = (e != NULL))
		{
			if (e->next != NULL)
				e->next->prev = e->prev;
			if (e->prev != NULL)
				e->prev->next = e->next;
			else
				head = e->next;
			delete e;
			cout << "Номер счета удален" << endl;
		}
		else {
			cout << "Номер счета не найден" << endl;
		}
		
		return rc;
	}
	//-------------------------------
	bool Object::deleteByData(void* data)
	{
		return deleteByElement(search(data));
	}
	//-------------------------------
	Element* Object::getLast()
	{
		listx::Element* e = this->getFirst(), * rc = this->getFirst();
		while (e != NULL)
		{
			rc = e;
			e = e->getNext();
		};
		return rc;
	}

	Object create()
	{
		return *(new Object());
	};
	//-------------------------------
	void Object::scan()
	{
		listx::Element* e = this->getFirst();
		while (e != NULL)
		{
			cout << ((AAA*)e->data)->number << '-' << *((AAA*)e->data)->name << " / ";
			e = e->getNext();
		};
	}
}

