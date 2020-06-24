
#include "DansLib.hpp"
#include <iostream>

/*
*****************************************************************
****************  Random usful functions  ***********************
*****************************************************************
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
*********  fraction member fucntions  *************************
*****************************************************************
*/

/*private*/
int fraction::gcd(int a, int b)
{
	if(a == 0)
	{
		return b;
	}
	if(b == 0)
	{
		return a;
	}
	if(a == b)
	{
		return a;
	}
	if(a > b)
	{
		return gcd(a-b,b);
	}
	else
	{
		return gcd(a, b-a);
	}
}
fraction fraction::simplifyFraction(fraction OgFraction)
{
	bool wasNeg = false;
	if(OgFraction.numerator < 0)
	{
		wasNeg = true;
		OgFraction.numerator *= -1;
	}
	int d = gcd(OgFraction.numerator, OgFraction.denominator);

	float x = static_cast<float>(OgFraction.numerator) / static_cast<float>(d);
	float y = static_cast<float>(OgFraction.denominator) / static_cast<float>(d);

	if(wasNeg)
	{
		return fraction(static_cast<int>(x) * -1, static_cast<int>(y));
	}
	else
	{
		return fraction(static_cast<int>(x), static_cast<int>(y));
	}
}

/*?Public*/

fraction::fraction()
{
	fraction::numerator = 1;
	fraction::denominator = 1;
}
fraction::fraction(int num, int den)
{
	if(den < 1)
	{
		std::cout << "Denomitor must be greater than one (standard fraction created)." << std::endl;
		fraction::numerator = 1;
		fraction::denominator = 1;
	}
	fraction::numerator = num;
	fraction::denominator = den;
}

/*Will equal off of value not identiacl aperaance */
bool fraction::operator==(fraction other)
{
	fraction otherTemp = simplifyFraction(other);
	fraction thisTemp = simplifyFraction(fraction(fraction::numerator, fraction::denominator));

	if(thisTemp.numerator == otherTemp.numerator && thisTemp.denominator == otherTemp.denominator)
	{
		return true;
	}	
	else
	{
		return false;
	}
}
bool fraction::operator!=(fraction other)
{
	if(!(other == fraction(fraction::numerator, fraction::denominator)))
	{
		return true;
	}
	else 
	{
		return false;
	}
}
bool fraction::operator<(fraction other)
{
	float otherTemp = static_cast<float>(other.numerator) / static_cast<float>(other.denominator);
	float thisTemp = static_cast<float>(fraction::numerator) / static_cast<float>(fraction::denominator);
	if(thisTemp < otherTemp)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool fraction::operator>(fraction other)
{
	if(other < fraction(fraction::numerator, fraction::denominator))
	{
		return true;
	}
	else 
	{
		return false;
	}
}
fraction fraction::operator+(fraction other)
{
	fraction otherTemp = fraction(fraction::denominator * other.numerator, fraction::denominator * other.denominator);
	fraction thisTemp = fraction(fraction::numerator * other.denominator, fraction::denominator * other.denominator);
	fraction newfrac = fraction(otherTemp.numerator + thisTemp.numerator, thisTemp.denominator);
	return simplifyFraction(newfrac);
}
fraction fraction::operator-(fraction other)
{
	fraction otherTemp = fraction(fraction::denominator * other.numerator, fraction::denominator * other.denominator);
	fraction thisTemp = fraction(fraction::numerator * other.denominator, fraction::denominator * other.denominator);
	fraction newfrac = fraction(thisTemp.numerator - otherTemp.numerator, thisTemp.denominator);
	return simplifyFraction(newfrac);
}
fraction fraction::operator*(fraction other)
{
	return simplifyFraction(fraction(fraction::numerator * other.numerator, fraction::denominator * other.denominator));
}
fraction fraction::operator/(fraction other)
{
	int n = fraction::numerator * other.denominator;
	int d = denominator * other.numerator;
	return fraction(static_cast<float>(n)/static_cast<float>(gcd(n,d)),static_cast<float>(d)/static_cast<float>(gcd(n,d)));
}
float fraction::toFloat()
{
	return static_cast<float>(fraction::numerator) / static_cast<float>(fraction::denominator);
}
//will print the function (redundent with << operator)
void fraction::printFraction()
{
	std::cout << fraction::numerator << '/' << fraction::denominator;	
}
//will output using the << operator 
std::ostream& operator<<(std::ostream& os, const fraction& frac)
{
	os << frac.numerator << '/' << frac.denominator;
	return os;
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
	std::cout << "in the list: \n";
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
DansIntVector::DansIntVector()
{
	DansIntVector::size = 1;
	DansIntVector::arr = new int[1];
	DansIntVector::curentIndex = 0;
}
DansIntVector::DansIntVector(int n)
{
	DansIntVector::size = n;
	DansIntVector::arr = new int[n];
	DansIntVector::curentIndex = 0;
}

void DansIntVector::pushBack(int num)
{
	if(DansIntVector::curentIndex == size)
	{
		//container need to be resized
		return;
		/*new container should be double the size of the last one, 
		so the new size should be the size plus size times two (3 sizes large now)*/ 
		size = size + size + size; 
	}
	else if(DansIntVector::curentIndex < size)
	{
		DansIntVector::arr[DansIntVector::curentIndex++] = num;
	}
	else
	{
		//throw exception (this should not happen)
	}

}
void DansIntVector::printVector()
{
	for(int i = 0; i < DansIntVector::curentIndex; i++)
	{
		std::cout << DansIntVector::arr[i] << ',';
	} 
	std::cout << std::endl;
}