#pragma once
#include <iostream>
template <typename T>
class List
{

public:
	List();
	~List();
	void push_back(T inf_about_student);
	int getsizeList() { return sizeList; }
	void pop_front();//�������� �������� � ������ ������
	void clear();
	void push_front(T inf_about_student);//���������� ������� � ������ ������
	void insert(T inf_about_student, int index);
	void remove(int index);
	void pop_back();
	
	T& operator[](const int index);

private:
	template <typename T>
	class node
	{
	public:
		T inf_about_student;
		node* next;//��������� �� ��������� �������
		node(T inf = T(), node* next = nullptr)
		{
			this->inf_about_student = inf;
			this->next = next;
		}
	};
	int sizeList;
	node<T>* head;
};

template <typename T>
List<T>::List()
{
	sizeList = 0;
	head = nullptr;
}

template<typename T>
void List<T>::push_back(T inf_about_student)
{
	if (head == nullptr)
	{
		head = new node<T>(inf_about_student);
	}
	else
	{
		node<T>* currentObject = this->head;
		while (currentObject->next != nullptr)
		{
			currentObject = currentObject->next;
		}
		currentObject->next = new node<T>(inf_about_student);
	}
	sizeList++;
}

template<typename T>
void List<T>::pop_front()
{
	node<T>* temp = head;
	head = head->next;
	delete temp;
	sizeList--;
}

template<typename T>
void List<T>::clear()
{
	while (sizeList)
	{
		pop_front();
	}
}

template<typename T>
void List<T>::push_front(T inf_about_student)
{
	head = new node<T>(inf_about_student, head);
	sizeList++;
}

template<typename T>
void List<T>::insert(T inf_about_student, int index)
{
	if (index == 0)
	{
		push_front(inf_about_student);
	}
	else
	{
		node <T>* previousObject = this->head;//��������� ���������
		for (int i = 0; i < index - 1; i++)
		{
			previousObject = previousObject->next; // ��������� �� ��������� �������
		}
		node<T>* newObject = new node<T>(inf_about_student, previousObject->next);
		previousObject->next = newObject;
		sizeList++;
	}
}

template<typename T>
void List<T>::remove(int index)
{
	if (index == 0)
	{
		pop_front();

	}
	else
	{
		node <T>* previousObject = this->head;//��������� ��������� � ����������� �������� head
		for (int i = 0; i < index - 1; i++)
		{
			previousObject = previousObject->next; // ��������� �� ��������� �������
		}
		node<T>* oldObject = previousObject->next;//����� ������ ������� ��������, �� ������� �������� ���������� �������
		previousObject->next = oldObject->next;
		delete oldObject;
		sizeList--;
	}
}

template<typename T>
void List<T>::pop_back()
{
	remove(sizeList - 1);
}

template<typename T>
List<T>::~List()
{
	clear();

}









