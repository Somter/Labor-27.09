// Labor 27.09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct Element
{
	// Данные
	char data;
	// Адрес следующего элемента списка
	Element* Next;
};

// Односвязный список
class List
{
	// Адрес головного элемента списка
	Element* Head;
	// Адрес головного элемента списка
	Element* Tail;
	// Количество элементов списка
	int Count;

public:
	// Конструктор
	List();
	// Деструктор
	~List();

	// Добавление элемента в список
	// (Новый элемент становится последним)
	void Add(char data);

	// Удаление элемента списка
	// (Удаляется головной элемент)
	void Del();
	// Удаление всего списка
	void DelAll();

	// Распечатка содержимого списка
	// (Распечатка начинается с головного элемента)
	void Print();

	// Получение количества элементов, находящихся в списке
	int GetCount();
	void Newelem(char elem, int position);	
	int FindElem(char elem);		

	void DelPos(int i)
	{
		Element* temp = Head;
		while (i > 2)
		{
			temp = temp->Next;
			i--;
		}
		Element* del = temp->Next;
		temp->Next = del->Next;
		delete del;

	}
};

List::List()
{
	// Изначально список пуст
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	// Вызов функции удаления
	DelAll();
}

int List::GetCount()
{
	// Возвращаем количество элементов
	return Count;
}

void List::Newelem(char elem, int position)	
{
	Element* temp = Head;	
	while (position > 2)	
	{
		temp = temp->Next;	
		position--;	
	}
	Element* NewElem = temp->Next;		
	temp->Next = NewElem;				
	NewElem->data = elem;		
}

int List::FindElem(char elem)	
{
	int index = 0;	
	Element* temp = Head;	
	while (temp->data != 0) 
	{
		if (temp->data == elem) 
		{
			return index;	
		}
		temp = temp->Next;		
		index++;	
	}	
	return -1;	

}


void List::Add(char data)
{
	// создание нового элемента
	Element* temp = new Element;

	// заполнение данными
	temp->data = data;
	// следующий элемент отсутствует
	temp->Next = NULL;
	// новый элемент становится последним элементом списка
	// если он не первый добавленный
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	// новый элемент становится единственным
	// если он первый добавленный
	else {
		Head = Tail = temp;
	}
}

void List::Del()
{
	// запоминаем адрес головного элемента
	Element* temp = Head;
	// перебрасываем голову на следующий элемент			
	Head = Head->Next;			
	// удаляем бывший головной элемент	
	delete temp;
}

void List::DelAll()
{ 
	// Пока еще есть элементы
	while (Head != 0)
		// Удаляем элементы по одному
		Del();
}

void List::Print()
{
	// запоминаем адрес головного элемента
	Element* temp = Head;
	// Пока еще есть элементы
	while (temp != 0)
	{
		// Выводим данные
		cout << temp->data << " ";
		// Переходим на следующий элемент
		temp = temp->Next;
	}

	cout << "\n";
}

// Тестовый пример
void main()
{
	// Создаем объект класса List
	List lst;

	// Тестовая строка
	char s[] = "Hello, World !!!\n";
	// Выводим строку
	cout << s << "\n\n";
	// Определяем длину строки
	int len = strlen(s);
	// Загоняем строку в список
	for (int i = 0; i < len; i++)
		lst.Add(s[i]);
	// Распечатываем содержимое списка

	// Добавляем элемент в строку	
	lst.Print();
	lst.Newelem('$', 3);
	lst.Print();

	// Находим элемент 
	int rezult = lst.FindElem('W');	
	if (rezult != -1) 
	{
		cout << "Index 'W' element: " << rezult << endl;	
	}
	else {
		cout << "There is no such element\n";	
	}

	// Удаляем три элемента списка	
	lst.Del();	
	lst.Del();
	lst.Del();
	//Распечатываем содержимое списка
	lst.Print();

}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
