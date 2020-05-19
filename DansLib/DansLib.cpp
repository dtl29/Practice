
#include "DansLib.hpp"
#include <iostream>

/*

*/
int factorial(int num)
{
	if(num > 1)
	{
		return num * factorial(num-1);
	}
	return 1;
}

/*
*****************************************************************
*********  DansIntList member fucntions  *************************
*****************************************************************
*/

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
// pre: n/a                                        *
// post: destroyed object                          *
//**************************************************
DansIntList::~DansIntList()
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

DansIntList::DansIntList()
{
	size = 0;
	maxSize = 500;
}

bool DansIntList::empty()
{
	if(size == 0)
	{
		return true;
	}
	return false;
}
int DansIntList::front()
{
	return head->value;
}

int DansIntList::back()
{
	return last->value;
}

void DansIntList::pushBack(int value)
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

int DansIntList::sizeofList()
{
	return size;
}

void DansIntList::printList()
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

int DansIntList::popBack()
{
	int tempValue;
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

void DansIntList::pushFront(int value)
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

int DansIntList::popFront()
{
	int tempvalue;
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
int DansIntList::maxSizeOfList()
{
	return maxSize;
}


/*
*****************************************************************
*********  DansVector member fucntions  *************************
*****************************************************************
*/
DansVector::DansVector()
{
	DansVector::size = 1;

}
DansVector::DansVector(int n)
{
	DansVector::size = n;
}

void DansVector::PushBack()
{

}