#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

template<typename T>
class Magazin
{
public:
	Magazin();
	~Magazin();

	void push_back(T data);
	void delete_back();
	int GetSize() { return Size; }
	T& operator[](const int index);
private:


	template<typename T>
	class Node
	{
	public:
		Node *pNext;
		T data;
		Node(T data = T() , Node *pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	
	int Size;
	Node<T> *head;
};

template<typename T>
Magazin<T>::Magazin()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
Magazin<T>::~Magazin()
{

}

template<typename T>
void Magazin<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data); //если равен нулю создаем
	}
	else
	{
		Node<T>* current = this->head; // указатель на ноду присваеваем голову
		while (current->pNext != nullptr) //будет работать пока не найдет последний елемент
		{
			current = current->pNext; // в поле присваеваем указатель на следующий елемент для цикла как ++
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
	
}
template<typename T>
void Magazin<T>::delete_back()
{
	if (head)
	{
		Node<T> *curNode = head;
		Node<T> *prevNode = NULL;

		while (curNode->pNext)
		{
			prevNode = curNode;
			curNode = curNode->pNext;
		}

		if (prevNode) prevNode->pNext = NULL;
		delete curNode;
	}
	Size--;
	
}
template<typename T>
T & Magazin<T>::operator[](const int index)
{
	int counter = 0;

	Node<T> *current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return counter->data;
		}
		current = current->pNext;
		counter++;
	}	
	
}
