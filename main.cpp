#include "List.hpp"
#include <list>
#include "Vector.hpp"
#include <vector>
#include "Map.hpp"
#include <map>
#include "Stack.hpp"
#include <stack>
#include "Queue.hpp"
#include <queue>

#include <iostream>

template <typename T>
void	print_vector(std::vector<T> &vec)
{
	for (typename std::vector<T>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout<<*it<<std::endl;
}

template <typename T>
void	print_list(std::list<T> list)
{
	for (typename std::list<T>::iterator it = list.begin(); it != list.end(); it++)
	{
		std::cout<<*it<<"\n";
	}
}
struct is_odd {bool operator() (const int& value) { return (value%2)==1; }};

void	test_list()
{
	std::cout<<"TESTING LIST!\n";
	ft::list<std::string> a;
	ft::list<std::string> b;
	std::cout<<"Print a\n";
	print_list(a);
	b.push_back("Bonjour");
	b.push_back("Comment");
	b.push_back("Ca");
	b.push_back("Va");
	std::cout<<"Print b\n";
	print_list(b);
	std::cout<<"a size = "<<a.size()<<"\tb size = "<<b.size()<<std::endl;
	std::cout<<"a empty = "<<a.empty()<<"\tb empty = "<<b.empty()<<std::endl;
	std::cout<<"Max size a = "<<a.max_size()<<std::endl;
	std::cout<<"Asign 4 Bonjour to a:\n";
	a.assign(4, "Bonjour");
	print_list(a);
	std::cout<<"\nAsign items from b to a:\n";
	a.assign(++b.begin(), --b.end());
	print_list(a);
	std::cout<<"\nInserting 2 Salut in a:\n";
	a.insert(++a.begin(), 2, "Salut");
	print_list(a);
	std::cout<<"\nDeleting 2 Salut in a:\n";
	a.erase(++a.begin(), --a.end());
	print_list(a);
	std::cout<<"\nSwapping!\na:\n";
	a.swap(b);
	print_list(a);
	std::cout<<"b:\n";
	print_list(b);
	std::cout<<"\nResize b to 5\nb:\n";
	b.resize(5, "Vide");
	print_list(b);
	std::cout<<"Resize b to 1\nb:\n";
	b.resize(1, "Vide");
	print_list(b);
	std::cout<<"\nClear b\nb:\n";
	b.clear();
	print_list(b);
	std::cout<<"\nSplice from a to b\nBefore splice a:\n";
	print_list(a);
	std::cout<<"b:\n";
	print_list(b);
	b.splice(b.begin(), a, a.begin(), a.end());
	std::cout<<"After splice: ";
	std::cout<<"a:\n";
	print_list(a);
	std::cout<<"b:\n";
	print_list(b);

	ft::list<double> c, d;
	c.push_back(3);
	c.push_back(8);
	c.push_back(6);
	c.push_back(8);
	c.push_back(6);
	c.push_back(11);
	c.push_back(1);
	d.push_back(1);
	d.push_back(5);
	d.push_back(8);
	d.push_back(7);
	d.push_back(9);
	d.push_back(10);
	std::cout<<"\nNew list, c:\n";
	print_list(c);
	std::cout<<"\nSorting c\nc:\n";
	c.sort();
	print_list(c);
	std::cout<<"\nRemoving duplicates\nc:\n";
	c.unique();
	print_list(c);
	std::cout<<"\nRemoving odds\nc:\n";
	c.remove_if(is_odd());
	print_list(c);
	std::cout<<"\nMerging c and d\nc:\n";
	print_list(c);
	std::cout<<"d: \n";
	print_list(d);
	std::cout<<"Merge in c!\nc:\n";
	c.merge(d);
	print_list(c);
	std::cout<<"Reverse c\nc:\n";
	c.reverse();
	print_list(c);
}


void		test_real_list()
{
	std::cout<<"\n\nREAL LIST\n";
	std::list<std::string> x, y;
	std::cout<<"Print x\n";
	print_list(x);
	y.push_back("Bonjour");
	y.push_back("Comment");
	y.push_back("Ca");
	y.push_back("Va");
	std::cout<<"Print y\n";
	print_list(y);
	std::cout<<"x size = "<<x.size()<<"\ty size = "<<y.size()<<std::endl;
	std::cout<<"x empty = "<<x.empty()<<"\ty empty = "<<y.empty()<<std::endl;
	std::cout<<"Max size x = "<<x.max_size()<<std::endl;
	std::cout<<"Asign 4 Bonjour to x:\n";
	x.assign(4, "Bonjour");
	print_list(x);
	std::cout<<"\nAsign items from y to x:\n";
	x.assign(++y.begin(), --y.end());
	print_list(x);
	std::cout<<"\nInserting 2 Salut in x:\n";
	x.insert(++x.begin(), 2, "Salut");
	print_list(x);
	std::cout<<"\nDeleting 2 Salut in x:\n";
	x.erase(++x.begin(), --x.end());
	print_list(x);
	std::cout<<"\nSwapping!\na:\n";
	x.swap(y);
	print_list(x);
	std::cout<<"y:\n";
	print_list(y);
	std::cout<<"\nResize y to 5\nb:\n";
	y.resize(5, "Vide");
	print_list(y);
	std::cout<<"Resize y to 1\nb:\n";
	y.resize(1, "Vide");
	print_list(y);
	std::cout<<"\nClear y\nb:\n";
	y.clear();
	print_list(y);
	std::cout<<"\nSplice from x to y\nBefore splice x:\n";
	print_list(x);
	std::cout<<"b:\n";
	print_list(y);
	y.splice(y.begin(), x, x.begin(), x.end());
	std::cout<<"After splice: ";
	std::cout<<"a:\n";
	print_list(x);
	std::cout<<"b:\n";
	print_list(y);

	std::list<double> m, n;
	m.push_back(3);
	m.push_back(8);
	m.push_back(6);
	m.push_back(8);
	m.push_back(6);
	m.push_back(11);
	m.push_back(1);
	n.push_back(1);
	n.push_back(5);
	n.push_back(8);
	n.push_back(7);
	n.push_back(9);
	n.push_back(10);
	std::cout<<"\nNew list, m:\n";
	print_list(m);
	std::cout<<"\nSorting m\nm:\n";
	m.sort();
	print_list(m);
	std::cout<<"\nRemoving duplicates\nm:\n";
	m.unique();
	print_list(m);
	std::cout<<"\nRemoving odds\nm:\n";
	m.remove_if(is_odd());
	print_list(m);
	std::cout<<"\nMerging m and d\nm:\n";
	print_list(m);
	std::cout<<"d: \n";
	print_list(n);
	std::cout<<"Merge in m!\nm:\n";
	m.merge(n);
	print_list(m);
	std::cout<<"Reverse m\nm:\n";
	m.reverse();
	print_list(m);
}

void	test_my_vector()
{
	std::cout<<"TESTING vector!\n";
	ft::vector<char> a, b;
	std::cout<<"Print a\n";
	print_vector(a);
	b.push_back('a');
	b.push_back('b');
	b.push_back('c');
	b.push_back('d');
	std::cout<<"Print b\n";
	print_vector(b);
	std::cout<<"a size = "<<a.size()<<"\tb size = "<<b.size()<<std::endl;
	std::cout<<"a empty = "<<a.empty()<<"\tb empty = "<<b.empty()<<std::endl;
	std::cout<<"Max size a = "<<a.max_size()<<std::endl;
	std::cout<<"Asign 4 'x' to a:\n";
	a.assign(4, 'x');
	print_vector(a);
	std::cout<<"\nAsign items from b to a:\n";
	a.assign(++b.begin(), --b.end());
	print_vector(a);
	std::cout<<"\nInserting 2 'u' in a:\n";
	a.insert(++a.begin(), 2, 'u');
	print_vector(a);
	std::cout<<"\nDeleting 2 u in a:\n";
	a.erase(++a.begin(), --a.end());
	print_vector(a);
	std::cout<<"\nSwapping!\na:\n";
	a.swap(b);
	print_vector(a);
	std::cout<<"b:\n";
	print_vector(b);
	std::cout<<"\nResize b to 5\nb:\n";
	b.resize(5, 'o');
	print_vector(b);
	std::cout<<"Resize b to 1\nb:\n";
	b.resize(1, 'o');
	print_vector(b);
	std::cout<<"\nClear b\nb:\n";
	b.clear();
	print_vector(b);
}

void	test_real_vector()
{
	std::cout<<"TESTING REAL vector!\n";
	std::vector<char> a, b;
	std::cout<<"Print a\n";
	print_vector(a);
	b.push_back('a');
	b.push_back('b');
	b.push_back('c');
	b.push_back('d');
	std::cout<<"Print b\n";
	print_vector(b);
	std::cout<<"a size = "<<a.size()<<"\tb size = "<<b.size()<<std::endl;
	std::cout<<"a empty = "<<a.empty()<<"\tb empty = "<<b.empty()<<std::endl;
	std::cout<<"Max size a = "<<a.max_size()<<std::endl;
	std::cout<<"Asign 4 'x' to a:\n";
	a.assign(4, 'x');
	print_vector(a);
	std::cout<<"\nAsign items from b to a:\n";
	a.assign(++b.begin(), --b.end());
	print_vector(a);
	std::cout<<"\nInserting 2 'u' in a:\n";
	a.insert(++a.begin(), 2, 'u');
	print_vector(a);
	std::cout<<"\nDeleting 2 u in a:\n";
	a.erase(++a.begin(), --a.end());
	print_vector(a);
	std::cout<<"\nSwapping!\na:\n";
	a.swap(b);
	print_vector(a);
	std::cout<<"b:\n";
	print_vector(b);
	std::cout<<"\nResize b to 5\nb:\n";
	b.resize(5, 'o');
	print_vector(b);
	std::cout<<"Resize b to 1\nb:\n";
	b.resize(1, 'o');
	print_vector(b);
	std::cout<<"\nClear b\nb:\n";
	b.clear();
	print_vector(b);
}

void test_map()
{
	std::cout<<"\nTESTING MAP\n";
	ft::map<int, char> mapa, mapa2;
	std::cout<<"Size = "<<mapa.size()<<"\tEmpty = "<<mapa.empty()<<std::endl;
	ft::pair<int, char> par(3, 'a'), par2(15, 'c'), par3(1, 'h');
	ft::pair<int, char> par4(5, 'a'), par5(8, 'd'), par6(110, 'h');
	ft::map<int, char>::iterator it, it2, it3;
	std::cout<<"Inserting some values in different ways\n";
	mapa2.insert(ft::make_pair(1, 'z'));
	mapa2.insert(par5);
	mapa2.insert(par6);
	mapa.insert(par2);
	mapa2.insert(ft::make_pair(10, 'e'));
	mapa2[2] = 'c';
	mapa.insert(par3);
	print_map(mapa);
	std::cout<<"Erasing some values\n";
	mapa.erase(++mapa.begin(), --mapa.end());
	print_map(mapa);
	std::cout<<"Creating another map\n";
	print_map(mapa2);
	mapa2.swap(mapa);
	std::cout<<"Swapping maps\n"<<"Map1: \n";
	print_map(mapa);
	std::cout<<"Map2:\n";
	print_map(mapa2);
	std::cout<<"Back Map1, find(2) => "<<mapa.find(2)->second<<std::endl;
	ft::pair<ft::map<int, char>::iterator, ft::map<int, char>::iterator> ret;
	std::cout<<"Testing equal range (2):\n";
	ret =  mapa.equal_range(2);
	std::cout<<"lower "<<ret.first->first<<" => "<<ret.first->second<<"\n";
	std::cout<<"upper "<<ret.second->first<<" => "<<ret.second->second<<"\n";
	std::cout<<"New map with invert order\n";
	ft::map<int, int, std::greater<int> > rev_map;
	rev_map[1] = 2;
	rev_map[3] = 1;
	rev_map[8];
	rev_map[20] = 2;
	rev_map[7] = 1;
	print_map(rev_map);
}

void test_real_map()
{
	std::cout<<"\nREAL MAP\n";
	std::map<int, char> mapa, mapa2;
	std::cout<<"Size = "<<mapa.size()<<"\tEmpty = "<<mapa.empty()<<std::endl;
	std::pair<int, char> par2(15, 'c'), par3(1, 'h');
	std::pair<int, char> par5(8, 'd'), par6(110, 'h');
	std::map<int, char>::iterator it, it2, it3;
	std::cout<<"Inserting some values in different ways\n";
	mapa2.insert(std::make_pair(1, 'z'));
	mapa2.insert(par5);
	mapa2.insert(par6);
	mapa.insert(par2);
	mapa2.insert(std::make_pair(10, 'e'));
	mapa2[2] = 'c';
	mapa.insert(par3);
	for (std::map<int, char>::iterator it = mapa.begin(); it!=mapa.end(); ++it)
    	std::cout << it->first << " => " << it->second << '\n';
	std::cout<<"Erasing some values\n";
	mapa.erase(++mapa.begin(), --mapa.end());
	for (std::map<int, char>::iterator it = mapa.begin(); it!=mapa.end(); ++it)
    	std::cout << it->first << " => " << it->second << '\n';
	std::cout<<"Creating another map\n";
	for (std::map<int, char>::iterator it = mapa2.begin(); it!=mapa2.end(); ++it)
    	std::cout << it->first << " => " << it->second << '\n';
	mapa2.swap(mapa);
	std::cout<<"Swapping maps\n"<<"Map1: \n";
	for (std::map<int, char>::iterator it = mapa.begin(); it!=mapa.end(); ++it)
    	std::cout << it->first << " => " << it->second << '\n';
	std::cout<<"Map2:\n";
	for (std::map<int, char>::iterator it = mapa2.begin(); it!=mapa2.end(); ++it)
    	std::cout << it->first << " => " << it->second << '\n';
	std::cout<<"Back Map1, find(2) => "<<mapa.find(2)->second<<std::endl;
	std::pair<std::map<int, char>::iterator, std::map<int, char>::iterator> ret;
	std::cout<<"Testing equal range (2):\n";
	ret =  mapa.equal_range(2);
	std::cout<<"lower "<<ret.first->first<<" => "<<ret.first->second<<"\n";
	std::cout<<"upper "<<ret.second->first<<" => "<<ret.second->second<<"\n";
	std::cout<<"New map with invert order\n";
	std::map<int, int, std::greater<int> > rev_map;
	rev_map[1] = 2;
	rev_map[3] = 1;
	rev_map[8];
	rev_map[20] = 2;
	rev_map[7] = 1;
	for (std::map<int, int, std::greater<int> >::iterator it = rev_map.begin(); it!=rev_map.end(); ++it)
    	std::cout << it->first << " => " << it->second << '\n';;
}

	void	test_stack()
{
	ft::stack<int> s;
	std::cout<<"\nTESTING STACK\n";
	std::cout<<"Size = "<<s.size()<<"\tEmpty = "<<s.empty()<<std::endl;
	s.push(3);
	std::cout<<"Pushing 3.\tTop => "<<s.top()<<std::endl;
	s.push(5);
	std::cout<<"Now 5.\t\tTop => "<<s.top()<<std::endl;
	std::cout<<"Size = "<<s.size()<<"\tEmpty = "<<s.empty()<<std::endl;
	s.pop();
	std::cout<<"Pop.\t\tTop => "<<s.top()<<std::endl;
	std::cout<<"stack == itself => "<<(s == s)<<std::endl;
	std::cout<<"stack != itself => "<<(s != s)<<std::endl;
}

	void	test_real_stack()
{
	std::cout<<"\nTESTING REAL STACK\n";
	std::stack<int> s;
	std::cout<<"Size = "<<s.size()<<"\tEmpty = "<<s.empty()<<std::endl;
	s.push(3);
	std::cout<<"Pushing 3.\tTop => "<<s.top()<<std::endl;
	s.push(5);
	std::cout<<"Now 5.\t\tTop => "<<s.top()<<std::endl;
	std::cout<<"Size = "<<s.size()<<"\tEmpty = "<<s.empty()<<std::endl;
	s.pop();
	std::cout<<"Pop.\t\tTop => "<<s.top()<<std::endl;
	std::cout<<"stack == itself => "<<(s == s)<<std::endl;
	std::cout<<"stack != itself => "<<(s != s)<<std::endl;
}
void	test_queue()
{
	ft::queue<int> s;
	std::cout<<"\nTESTING STACK\n";
	std::cout<<"Size = "<<s.size()<<"\tEmpty = "<<s.empty()<<std::endl;
	s.push(3);
	std::cout<<"Pushing 3.\tTop => "<<s.back()<<"\tFront => "<<s.front()<<std::endl;
	s.push(5);
	std::cout<<"Now 5.\t\tTop => "<<s.back()<<"\tFront => "<<s.front()<<std::endl;
	std::cout<<"Size = "<<s.size()<<"\tEmpty = "<<s.empty()<<std::endl;
	s.pop();
	std::cout<<"Pop.\t\tTop => "<<s.back()<<"\tFront => "<<s.front()<<std::endl;
	std::cout<<"stack == itself => "<<(s == s)<<std::endl;
	std::cout<<"stack != itself => "<<(s != s)<<std::endl;
}
void	test_real_queue()
{
	std::queue<int> s;
	std::cout<<"\nTESTING REAL STACK\n";
	std::cout<<"Size = "<<s.size()<<"\tEmpty = "<<s.empty()<<std::endl;
	s.push(3);
	std::cout<<"Pushing 3.\tTop => "<<s.back()<<"\tFront => "<<s.front()<<std::endl;
	s.push(5);
	std::cout<<"Now 5.\t\tTop => "<<s.back()<<"\tFront => "<<s.front()<<std::endl;
	std::cout<<"Size = "<<s.size()<<"\tEmpty = "<<s.empty()<<std::endl;
	s.pop();
	std::cout<<"Pop.\t\tTop => "<<s.back()<<"\tFront => "<<s.front()<<std::endl;
	std::cout<<"stack == itself => "<<(s == s)<<std::endl;
	std::cout<<"stack != itself => "<<(s != s)<<std::endl;
}

void	test()
{
	ft::list<std::string> b;
	b.push_back("Bonjour");
	b.push_back("Comment");
	b.push_back("Ca");
	b.push_back("Va");
}

int     main(void)
{
//	test();
	test_list();
	test_real_list();
//	test_my_vector();
//	test_real_vector();
//	test_stack();
//	test_real_stack();
//	test_queue();
//	test_real_queue();
//	test_map();
//	test_real_map();
//	while (1){}
}

