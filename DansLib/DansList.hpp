#pragma once
#include "DansList.hpp"//find a way to link the two hpp files to they can be called from one 

template<class T>
class DansList
{
private:
	struct node 
	{
		T value;
		node *nextnode = nullptr;
		//node *previousnode = nullptr;//for a doublly linked list
	};
	node *head = new node;
	node *last = new node;
	int size;
	int maxSize;
public:
	~DansList()
	{
		node *curentnode = head;
		node *nextnode;
		for(int i = 0; i > size; i++)
		{
			nextnode = curentnode->nextnode;
			delete curentnode;
			curentnode = nextnode;
		}
	}
	DansList()
	{
		size = 0;
		maxSize = 500;
	}
	bool empty()
	{
		if(size == 0)
		{
			return true;
		}
		return false;
	}
	T front()
	{
		return head->value;
	}
	T back()
	{
		return last->value;
	}
	void pushBack(T value)
	{
		if(size == 0)
		{
			head->value = value;
			last = head;
			size = 1;
			return;
		}
		else
		{
			node *newNode = new node;
			newNode->value = value;
			last->nextnode = newNode;
			last = newNode;
			size += 1;
		}
	}
	int sizeofList()
	{
		return size;
	}
	void printList()
	{
		std::cout << "inthe list: \n";
		node *thisNode = head;
		for(int i = 0; i < size; i++)
		{
			std::cout << thisNode->value << ", ";
			thisNode = thisNode->nextnode;
		}
		std::cout << std::endl;
	}
	T popBack()
	{
		T tempValue;
		node *nexttoLast = head;
		if(empty())
		{
			return -1;//should throw an error 
		}
		else
		{
			for(int i = 0; i < size - 1; i++)
			{
				nexttoLast = nexttoLast->nextnode;
			}
			size--;
			tempValue = last->value;
			delete last; 
			last = nexttoLast;
			return tempValue;
		}
	}
	void pushFront(T value)
	{
		if(size == 0)
		{
			head->value = value;
			size = size + 1;
			last = head;
			return;
		}
		else
		{
			node *newnode = new node;
			newnode->value = value;
			newnode->nextnode = head;
			head = newnode;
			size++;
			return;
		}
	}
	T popFront()
	{
		T tempvalue;
		node *tempnode; 
		if(size == 0)
		{
			return -1;//should throw an error
		}
		else
		{
			tempvalue = head->value;
			tempnode = head->nextnode;
			delete head;
			head = tempnode;
			size -= 1;
			return tempvalue;
		}
	}
	int maxSizeOfList()
	{
		return maxSize;
	}
	//void sortAccending();
	//void reverse();


};