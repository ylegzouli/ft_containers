#include "list.hpp"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <assert.h>
#include <stdexcept>

int     test_list(int ac, char **av);

//.............................................................

int		main(int ac, char **av)
{
	int		ret;

	ret = test_list(ac, av);

	return (ret);
}

//........................ LIST ...............................

int		test_list(int ac, char **av)
{
	ft::List<int> 		liste;
	ft::List<int> 		liste2;
	ft::ListIter<int>	iter; 
	ft::ListIter<int>	iter2; 
	ft::ListIter<int>	iter3; 
//	ft::reverse_iterator<iterator> iter;

	liste.assign(10, 4);
	liste.print();
	std::cout << "size = " << liste.size() << "\n";
	std::cout << "----------\n";
	
	liste.clear();
	liste.print();
	std::cout << "size = " << liste.size() << "\n";
	std::cout << "----------\n";
	
	for (int i = 0; i < 10; i++)
		liste.push_back(i);
	liste.print();
	std::cout << "size = " << liste.size() << "\n";
	std::cout << "----------\n";
	
	iter = liste.begin();
	iter2 = liste.end();
	iter3 = liste.begin() + 7;
	std::cout << "iter = " << iter.get_elem()->content << "\n";
	std::cout << "iter2 = " << iter2.get_elem()->content << "\n";
	std::cout << "iter3 = " << iter3.get_elem()->content << "\n";
	std::cout << "----------\n";
	
	iter++;
	iter++;
	iter3 = iter3 - 4;
	std::cout << "iter = " << iter.get_elem()->content << "\n";
	std::cout << "iter2 = " << iter2.get_elem()->content << "\n";
	std::cout << "iter3 = " << iter3.get_elem()->content << "\n";
	std::cout << "----------\n";
	
//	liste.insert(iter, 3333333);
//	liste.print();
//	std::cout << "size = " << liste.size() << "\n";
//	std::cout << "----------\n";
	
	iter2--;
	liste.insert(iter, iter3, iter2);
	liste.print();
	std::cout << "size = " << liste.size() << "\n";
	std::cout << "----------\n";
	
	liste2.assign(10, 4);
	liste.swap(liste2);
	liste.print();
	std::cout << "size = " << liste.size() << "\n";
	liste2.print();
	std::cout << "size = " << liste2.size() << "\n";
	std::cout << "----------\n";
	

	liste.swap(liste2);
	liste.resize(8, 10);
	liste.print();
	std::cout << "size = " << liste.size() << "\n";
	std::cout << "----------\n";
	
	liste.clear();
	liste.print();
	std::cout << "size = " << liste.size() << "\n";
	std::cout << "----------\n";

//	while(1) {}
	return (0);
}
/*
void		print_list(ListIter<T> iter)
{

}
*/

//....................... VECTOR ..............................
//.............................................................



