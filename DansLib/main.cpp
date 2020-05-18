#include <iostream>
#include "DanLib.hpp"

int main()
{
	std::cout << "Factoral of 5 = " << factorial(5) << '\n';
	DansVector vec; 
	DansList lis;
	std::cout << "list should be empty (0 for false 1 for true) : " << lis.empty() << std::endl;
	lis.pushBack(10);
	std::cout << "lis has a front of " << lis.front() << std::endl;
	lis.pushBack(5);
	lis.pushBack(6);
	std::cout << "lis has a back of " << lis.back() << '\n';
	lis.printList();
	std::cout << lis.popBack() << " is the poped back of the list" << std::endl;
	lis.printList();
}