#include "Heap.h"
#include <iostream>
#include <iomanip> // ��� ������������� ������

void AAA::print() // ����������� ������ print() ��� ������ AAA
{
	cout << x; // ����� �������� ���������� x �� ����������� �����
}

namespace heap
{
	Heap create(int maxsize, CMP(*f)(void*, void*))
	{
		return *(new Heap(maxsize, f)); // �������� ������ ������� ���� � ����������� ���
	}

	int Heap::left(int ix)
	{
		return (2 * ix + 1 >= size) ? -1 : (2 * ix + 1);
	}
	
	int Heap::right(int ix)
	{
		return (2 * ix + 2 >= size) ? -1 : (2 * ix + 2); 
	}
	
	int Heap::parent(int ix)
	{
		return (ix + 1) / 2 - 1; 
	}
	
	void Heap::swap(int i, int j)
	{
		void* buf = storage[i];
		storage[i] = storage[j];
		storage[j] = buf;
	}
	
	void Heap::heapify(int ix) // �������� ���� � ������������ �������� ����, ������� � ���� � �������� ix
	{
		int l = left(ix), r = right(ix), irl = ix; 
		
		if (l > 0) 
		{
			if (isGreat(storage[l], storage[ix])) irl = l; 
			if (r > 0 && isGreat(storage[r], storage[irl])) 	irl = r; 
			if (irl != ix)
			{
				swap(ix, irl);
				heapify(irl); 
			}
		}
	}
	
	void Heap::insert(void* x) // ��������� ����� ������� x � ����
	{
		int i;
		if (!isFull()) 
		{
			storage[i = ++size - 1] = x; 
			while (i > 0 && isLess(storage[parent(i)], storage[i])) 
			{ 
				swap(parent(i), i); 
				i = parent(i); 
			}
		}
	}
	
	void* Heap::extractMax() // ������� ������������ ������� �� ����
	{
		void* rc = nullptr; 
		if (!isEmpty())
		{
			rc = storage[0];
			storage[0] = storage[size - 1]; 
			size--;
			heapify(0); 
		} 
		return rc;
	}

	void Heap::scan(int i) const //����� �������� ��������� �� �����
	{
		int probel = 20;
		cout << '\n';
		if (size == 0)
			cout << "���� �����";
		for (int u = 0, y = 0; u < size; u++) 
		{
			cout << setw(probel + 10) << setfill(' '); 
			((AAA*)storage[u])->print(); 
			if (u == y) 
			{ 
				cout << '\n';
				if (y == 0) 
					y = 2; 
				else
					y += y * 2; 
			} 
			probel /= 2; 
		}
		cout << '\n';
	}

	void* Heap::extractMin() // ������� ����������� ������� �� ����
	{
		void* rc = nullptr; 
		if (!isEmpty())
		{
			rc = storage[size - 1]; 
			storage[size - 1] = storage[0];
			size--; 
			heapify(size - 1); 
		}
		return rc;
	}

	void* Heap::extractI() // ������� i-�� ������� �� ����
	{
		int index;
		cout << "������� ������ ���������� ��������: ";
		cin >> index;
		void* rc = nullptr;
		if (!isEmpty())
		{
			rc = storage[index];
			storage[index] = storage[size - 1];
			size--;
			heapify(index); 
		}
		return rc;
	}

	void Heap::unionHeap(Heap* h2)
	{
		void* rc = nullptr;
		for (int i = 0; i < h2->size; i++) {
			rc = h2->storage[i];
			insert(rc);
		}
		heapify(0);
	}
}
