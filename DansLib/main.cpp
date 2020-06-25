#include <iostream>
#include "DansLib.hpp"
//#include "DansList.hpp"

int main()
{
	std::cout << "List test.\n";
	DansList<int> lis;
	std::cout << "list should be empty (0 for false 1 for true) : " << lis.empty() << std::endl;
	lis.pushBack(10);
	std::cout << "lis has a front of " << lis.front() << std::endl;
	lis.pushBack(5);
	lis.pushBack(6);
	std::cout << "lis has a back of " << lis.back() << '\n';
	lis.printList();
	std::cout << lis.popBack() << " is the poped back of the list" << std::endl;
	lis.printList();
	DansList<char> charLis;
	charLis.pushBack('c');
	charLis.printList();
	charLis.pushBack('\n');
	charLis.printList();
	std::cout << "********************End test for List.****************************\n";

	std::cout << "vector test.\n";
	DansVector<int> vec;
	vec.pushBack(9);
	vec.printVector();
	std::cout << "********************End test for vector.****************************\n";

	std::cout << "Fraction test.\n";
	fraction f;
	std::cout << "Batic fraction call create a fraction of ones : "; f.printFraction();	std::cout << std::endl;
	fraction one(1,10);
	fraction two(4,20);
	one.printFraction(); std::cout << " = "; two.printFraction(); std::cout << " is: " << (one == two) << '\n';
	std::cout << one << '\n';
	std::cout << one << " < " << two << " is " << ((one<two)?"true":"false") << std::endl;
	std::cout << one << " / " << two << " = " << (one/two) << std::endl;
	std::cout << one.toFloat() << '\n';
	std::cout << "********************End test for Fraction.****************************\n";

	float random = 4.3;
	std::cout << "4.3^3= " << DansPow(4.3,3) << '\n';
}