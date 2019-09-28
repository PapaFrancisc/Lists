#include <iostream>

using namespace std;
#define tab "\t"
//#define BASE_CHECK

template <typename T> class  List {

	template <typename T>class Element
	{
		T Data;
		Element<T>* pNext;
		Element<T>* pPrev;
	public:
		Element(T Data, Element<T>* pNext = nullptr, Element<T>* pPrev = nullptr);

		~Element();

		/*int operator* ()
		{
		return this->Data;
		}
		const int operator* () const
		{
		return this->Data;
		}*/
		operator T&();

		friend class List<T>;
	};
	Element<T>* Head;
	Element<T>* Tail;
	int size;
public:

	class Iterator
	{
		Element<T>* Temp;
	public:
		Iterator(Element<T>* Temp = nullptr)
		{
			this->Temp = Temp;
			cout << "ITConstructor:\t" << this << endl;
		}
		~Iterator()
		{
			cout << "ITDestructor:\t\t" << this << endl;
		}
		Iterator& operator++()
		{
			Temp = Temp->pNext;
			return *this;
		}

		Iterator operator++(int)
		{
			Iterator old = *this;
			Temp = Temp->pNext;
			return old;
		}
		T& operator*()
		{
			return Temp->Data;
		}
		const T& operator*() const
		{
			return Temp->Data;
		}
		bool operator ==(const Iterator& other) const
		{
			return this->Temp == other.Temp;
		}
		bool operator != (const Iterator& other) const
		{
			return this->Temp != other.Temp;
		}
	};
	T get_size() const
	{
		return this->size;
	}
	Iterator begin()
	{
		return this->Head;
	}
	const Iterator begin() const
	{
		return this->Head;
	}
	Iterator end()
	{
		return nullptr;
	}
	const Iterator end() const
	{
		return nullptr;
	}
	List()
	{
		Head = Tail = nullptr;
		size = 0;
		cout << "LConstructor:\t\t" << this << endl;
	}
	List(initializer_list<T> il) : List()
	{
		for (const int* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
	}
	~List()
	{
		while (Head) pop_front();
		cout << "LDestructor:\t\t" << this << endl;
	}
	// Operators:
	T& operator [](int Index)
	{
		Element<T>* Temp;
		if (Index < size / 2)
		{
			Temp = Head;
			for (int i = 0; i < Index; i++)Temp = Temp->pNext;
		}
		else
		{
			Temp = Tail;
			for (int i = size - 1; i > Index; i--) Temp = Temp->pPrev;
		}
		return Temp->Data;
	}

	const T& operator [](int Index) const
	{
		Element<T>* Temp;
		if (Index < size / 2)
		{
			Temp = Head;
			for (int i = 0; i < Index; i++)Temp = Temp->pNext;
		}
		else
		{
			Temp = Tail;
			for (int i = size - 1; i > Index; i--) Temp = Temp->pPrev;
		}
		return Temp->Data;
	}
	// Adding Elements
	void push_front(int Data)
	{
		Element<T>* New = new Element<T>(Data);
		if (Head == nullptr)
		{
			Head = Tail = New;
		}
		else
		{
			New->pNext = Head;
			Head->pPrev = New;
			Head = New;
		}
		size++;
	}
	void push_back(int Data)
	{
		Element<T>* New = new Element<T>(Data);
		if (Tail == nullptr)
		{
			Head = Tail = New;
		}
		else
		{
			New->pPrev = Tail;
			Tail->pNext = New;
			Tail = New;
		}
		size++;
	}
	void insert(int Index, int Data)
	{
		if (Index == 0)
		{
			push_front(Data);
			return;
		}
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}
		Element<T>* Temp = nullptr;
		if (Index <= (size / 2))
		{
			Temp = Head;
			for (int i = 0; i < Index; i++)
			{
				if (Temp->pNext == nullptr)break;
				Temp = Temp->pNext;
			}
		}
		else
		{
			Temp = Tail;
			for (int i = size - 1; i > Index; i--)
			{
				if (Temp->pPrev == nullptr)break;
				Temp = Temp->pPrev;
			}
		}
		/*Element* New = new Element(Data);
		New->pNext = Temp;
		New->pPrev = Temp->pPrev;
		Temp->pPrev->pNext = New;
		Temp->pPrev = New;*/
		Temp->pPrev = Temp->pPrev->pNext = new Element<T>(Data, Temp, Temp->pPrev);
		size++;
	}
	void pop_front()
	{
		if (Head == Tail)
		{
			delete Head;
			Head = Tail = nullptr;
			return;
		}
		Head = Head->pNext;
		delete Head->pPrev;
		Head->pPrev = nullptr;
		size--;
	}
	void pop_back()
	{
		if (Head == nullptr)return;
		if (Head->pNext == nullptr)
		{
			pop_front();
			return;
		}
		Tail = Tail->pPrev;
		delete Tail->pNext;
		Tail->pNext = nullptr;
		size--;
	}
	void erase(int Index)
	{
		if (Head == nullptr)return;
		if (Index == 0)
		{
			pop_front();
			return;
		}
		if (Index >= (size - 1))
		{
			pop_back();
			return;
		}

		Element<T>* Temp;
		if (Index <= (size / 2))
		{
			Temp = Head;
			for (int i = 0; i < Index; i++)
			{
				if (Temp->pNext == nullptr)break;
				Temp = Temp->pNext;
			}
		}
		else
		{
			Temp = Tail;
			for (int i = size - 1; i > Index; i--)
			{
				if (Temp->pPrev == nullptr)break;
				Temp = Temp->pPrev;
			}
		}
		Temp->pPrev->pNext = Temp->pNext;
		Temp->pNext->pPrev = Temp->pPrev;
		delete Temp;
		size--;
	}

	void print()
	{
		for (Element<T>* Temp = Head; Temp; Temp = Temp->pNext)
		{
			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		}
		cout << "Кол-во элементов в списке: " << size << endl;
	}
	void print_reverse()
	{
		for (Element<T>* Temp = Tail; Temp; Temp = Temp->pPrev)
		{
			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		}
		cout << "Кол-во элементов в списке: " << size << endl;
	}
};


template<typename T>
template<typename ET>
List<T>::Element<ET>::Element(ET Data, List<T>::Element<ET>* pNext, List<T>::Element<ET>* pPrev) : Data(Data), pNext(pNext), pPrev(pPrev)
{
	cout << "Econstructor:\t" << this << endl;
}
template<typename T>template<typename ET>List<T>::Element<ET>::~Element()
{
	cout << "EDestructor:\t" << this << endl;
}
/*int operator* ()
{
return this->Data;
}
const int operator* () const
{
return this->Data;
}*/
template<typename T>template<typename ET>List<T>::Element<ET>::operator ET&()
{
	return this->Data;
}

void main()
{
	setlocale(LC_ALL, "");
	int n = 5;
	List<int> lst1 = { 3,4,5,6,7 };
	lst1.print();
	//for (int i = 0; i < lst1.get_size(); i++)lst1[i] = rand() % 100;
	for (int i = 0; i < lst1.get_size(); i++)
	{
		cout << lst1[i] << tab;
	}
	cout << endl;
	for (int i : lst1)
	{
		cout << i << tab;
	}
	cout << endl;
#ifdef BASE_CHECK
	cout << "Введите размер списка: "; cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}
	list.push_front(123);
	list.print();
	list.insert(3, 5);
	list.pop_front();
	list.pop_back();
	list.print();
	list.erase(3);
	list.print();
#endif // BASE_CHECK

}
