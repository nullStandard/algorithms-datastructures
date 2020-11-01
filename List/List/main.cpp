#include <iostream>
#include "List.h"

int main()
{
	List list;



	std::cout << list.getLength() << std::endl;

	for (int i = 0; i < list.getLength(); ++i)
		std::cout << list[i] << std::endl;

	list.insert(0, 6);

	for (int i = 0; i < list.getLength(); ++i)
		std::cout << list[i] << std::endl;

	std::cout << list.getLength() << std::endl;

	system("pause");
}