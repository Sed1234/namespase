#include <iostream>
#include <list>
#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include <initializer_list>
using quene::Quene;

void  fn_queue() {
	
	//b.enquene(9);
	//b.dequene();
	//b.dequene();
	//std::cout <<b.first_element;
	/*for (int i = 0; i < b.count(); i++)
	{
	std::cout << b.data[i] << std::endl;
	}*/

}

void main()
{
	LinkedList<int> l;
	l.addToTail(5);
	l.addToTail(10);
	l.addToTail(9);
	l.addToTail(8);
	l.addToTail(1);
	l.addToTail(8);
	l.addToTail(7);
	l.addToTail(8);
	size_t x = 1, y = 2;
	std::cout << l[x] << std::endl;
	auto result = l.searchByValue(8);
	for (auto it : result)
	{
		std::cout << it << ' ';
	}

	Quene<int> b(std::initializer_list<int> {1,3,4,6,7});
	b.enquene(5);
	b.enquene(4);
	std::cout << b[1] << std::endl;
	

	system("pause");
}