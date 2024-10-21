#include "Hash_Chain.h"
#include <iostream>
using namespace std;

namespace hashTC
{
	Object create(int size, int(*f)(void*))
	{
		return *(new Object(size, f));
	}

	int Object::hashFunction(void* data)
	{
		return (FunKey(data) % size);
	};

	int Object::nextHashFunction(void* data)
	{
		// ����������� ��������� �� ������ � ������ ������
		string* strPtr = (string*)data;
		string str = *strPtr;

		// �������������� ��������� ���-�������
		int hashValue = 0;

		// ��������� �������� ������������ ��� ��� ������� ������� � ������
		for (char c : str)
		{
			hashValue ^= c;
		}
		// ���������� ���������� �������� ���-�������
		return hashValue;
	}

	

	bool Object::insert(void* data)
	{
		return (Hash[hashFunction(data)].insert(data));
	};

	bool Object::deleteByData(void* data)
	{
		return (Hash[hashFunction(data)].deleteByData(data));
	};

	listx::Element* Object::search(void* data)
	{
		return Hash[hashFunction(data)].search(data);
	};

	void Object::Scan()
	{
		for (int i = 0; i < size; i++)
		{
			Hash[i].scan();
			cout << '\n';
		}
	};
}
