
#include "DanLib.hpp"
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
*********  DansList member fucntions  *************************
*****************************************************************
*/

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
// pre: n/a                                        *
// post: destroyed object                          *
//**************************************************
DansList::~DansList()
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

DansList::DansList()
{
	size = 0;
	maxSize = 500;
}

bool DansList::empty()
{
	if(size == 0)
	{
		return true;
	}
	return false;
}
int DansList::front()
{
	return head->value;
}
int DansList::back()
{
	return last->value;
}
void DansList::pushBack(int value)
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

int DansList::sizeofList()
{
	return size;
}

void DansList::printList()
{
	std::cout << "The list: \n";
	node *thisNode = head;
	for(int i = 0; i < size; i++)
	{
		std::cout << thisNode->value << ", ";
		thisNode = thisNode->nextnode;
	}
	std::cout << std::endl;
}

int DansList::popBack()
{
	int tempInt;
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
		tempInt = last->value;
		delete last; 
		last = nexttoLast;
		return tempInt;
	}
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