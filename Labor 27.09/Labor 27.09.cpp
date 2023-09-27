// Labor 27.09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct Element
{
	// ������
	char data;
	// ����� ���������� �������� ������
	Element* Next;
};

// ����������� ������
class List
{
	// ����� ��������� �������� ������
	Element* Head;
	// ����� ��������� �������� ������
	Element* Tail;
	// ���������� ��������� ������
	int Count;

public:
	// �����������
	List();
	// ����������
	~List();

	// ���������� �������� � ������
	// (����� ������� ���������� ���������)
	void Add(char data);

	// �������� �������� ������
	// (��������� �������� �������)
	void Del();
	// �������� ����� ������
	void DelAll();

	// ���������� ����������� ������
	// (���������� ���������� � ��������� ��������)
	void Print();

	// ��������� ���������� ���������, ����������� � ������
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
	// ���������� ������ ����
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	// ����� ������� ��������
	DelAll();
}

int List::GetCount()
{
	// ���������� ���������� ���������
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
	// �������� ������ ��������
	Element* temp = new Element;

	// ���������� �������
	temp->data = data;
	// ��������� ������� �����������
	temp->Next = NULL;
	// ����� ������� ���������� ��������� ��������� ������
	// ���� �� �� ������ �����������
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	// ����� ������� ���������� ������������
	// ���� �� ������ �����������
	else {
		Head = Tail = temp;
	}
}

void List::Del()
{
	// ���������� ����� ��������� ��������
	Element* temp = Head;
	// ������������� ������ �� ��������� �������			
	Head = Head->Next;			
	// ������� ������ �������� �������	
	delete temp;
}

void List::DelAll()
{
	// ���� ��� ���� ��������
	while (Head != 0)
		// ������� �������� �� ������
		Del();
}

void List::Print()
{
	// ���������� ����� ��������� ��������
	Element* temp = Head;
	// ���� ��� ���� ��������
	while (temp != 0)
	{
		// ������� ������
		cout << temp->data << " ";
		// ��������� �� ��������� �������
		temp = temp->Next;
	}

	cout << "\n";
}

// �������� ������
void main()
{
	// ������� ������ ������ List
	List lst;

	// �������� ������
	char s[] = "Hello, World !!!\n";
	// ������� ������
	cout << s << "\n\n";
	// ���������� ����� ������
	int len = strlen(s);
	// �������� ������ � ������
	for (int i = 0; i < len; i++)
		lst.Add(s[i]);
	// ������������� ���������� ������

	// ��������� ������� � ������	
	lst.Print();
	lst.Newelem('$', 3);
	lst.Print();

	// ������� ������� 
	int rezult = lst.FindElem('W');	
	if (rezult != -1) 
	{
		cout << "Index 'W' element: " << rezult << endl;	
	}
	else {
		cout << "There is no such element\n";	
	}

	// ������� ��� �������� ������	
	lst.Del();	
	lst.Del();
	lst.Del();
	//������������� ���������� ������
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
