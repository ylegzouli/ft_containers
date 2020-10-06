#ifndef MAP_HELPER_HPP
# define MAP_HELPER_HPP

#include <iostream>
#include <limits>
#include <exception>
#include "Map.hpp"

namespace ft
{

template <class K, class T>
struct pair
{
    K first;
    T second;
    pair() {}
    pair(const K &a, const T &b) : first(a), second(b) {}
};

template <class K, class T>
bool operator == (const pair<K, T> &x, const pair<K, T> &y)
{
    return (x.first == y.first && x.second == y.second);
}

template <class K, class T>
bool operator < (const pair<K, T> &x, const pair<K, T> &y)
{
    return (x.first < y.first || (!(y.first < x.first) && x.second < y.second));
}

template <class K, class T>
pair<K, T> make_pair(const K &x, const T &y = T()) {return pair<K, T>(x, y);}

template <class K, class T>
pair<K, T> make_pair(K &x, T &y) {return pair<K, T>(x, y);}


template <class K, class T>
class node
{
	public:
	node(K key = K(), T value = T(), node *next = NULL, node *prev = NULL);
	~node();
	node(node const &copy);
	node &operator = (node const &copy);

	pair<K, T>	Value;
    node		*Next;
	node		*Prev;
};

template <class K, class T>
node<K, T>::node(K key, T value, node *next, node *prev):
		Next(next), Prev(prev)
	{
		this->Value.first = key;
		this->Value.second = value;
	};

template <class K, class T>
node<K, T>::~node(){};

template <class K, class T>
node<K, T>::node(node const &copy): Prev(copy->Prev), Next(copy->Next)
{
	this->Value.first = copy.Value.first;
	this->Value.second = copy.Value.second;
};

template <class K, class T>
node<K, T>&	node<K, T>::operator = (node const &copy)
{
	this->Value.first = copy.Value.first;
	this->Value.second = copy.Value.second;
	this->Prev = copy->Prev;
	this->Next = copy->Next;
	return(*this);
}

template <class K>
class set_node
{
	public:
	set_node(K key = K(), set_node *next = NULL, set_node *prev = NULL);
	~set_node();
	set_node(set_node const &copy);
	set_node &operator = (set_node const &copy);

	K			Value;
    set_node	*Next;
	set_node	*Prev;
};

template <class K>
set_node<K>::set_node(K key, set_node *next, set_node *prev):
		Value(key), Next(next), Prev(prev) {}

template <class K>
set_node<K>::~set_node(){};

template <class K>
set_node<K>::set_node(set_node const &copy):
	Prev(copy->Prev), Next(copy->Next), Value(copy->Value) {}

template <class K>
set_node<K>&	set_node<K>::operator = (set_node const &copy)
{
	this->Value = copy.Value;
	this->Prev = copy->Prev;
	this->Next = copy->Next;
	return(*this);
}

}

#endif
