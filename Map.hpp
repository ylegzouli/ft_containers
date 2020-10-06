#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include <limits>
#include <exception>
#include "Map_helper.hpp"

namespace ft
{

template <class K, class T, class Compare = std::less<K> >
class map
{
	friend class node<K, T>;
	friend class iterator;
	friend class rev_iterator;
    private:
    node<K, T>	*First;
    node<K, T>	*End;
	Compare		Comp;

    public:
    map<K, T, Compare>(const Compare &comp = Compare());
    ~map();
	map(map const &copy);
    map	&operator = (map const &copy);

	size_t	size();
	bool	empty();
	size_t	max_size() const;

	T &operator[](const K &key);

	class iterator
	{
		private:
		friend class map;
		node<K, T>	*Ptr;

		public:
		iterator(node<K, T> *node = NULL);
		~iterator();
		iterator(iterator const &copy);
		iterator	&operator=(iterator const &copy);

		pair<K, T> *operator->();
		pair<K, T> &operator*();

		iterator operator++();
		iterator operator++(int);
		iterator operator--();
		iterator operator--(int);

		bool operator != (iterator const &it);
		bool operator == (iterator const &it);
	};
	class reverse_iterator: protected iterator
	{
		private:
		iterator Ptr;

		public:
		reverse_iterator(pair<K, T> *pair = NULL);
		~reverse_iterator();
		reverse_iterator(reverse_iterator const &copy);
		reverse_iterator	&operator=(reverse_iterator const &copy);

		pair<K, T> *operator->();
		pair<K, T> &operator*();

		reverse_iterator operator++();
		reverse_iterator operator++(int);
		reverse_iterator operator--();
		reverse_iterator operator--(int);
		bool operator != (reverse_iterator const &it);
		bool operator == (reverse_iterator const &it);
	};

    iterator			begin();
	iterator			end();
	reverse_iterator	rbegin();
	reverse_iterator	rend();

	pair<iterator, bool>	insert(const pair<K, T> &val);
	iterator 				insert(iterator pos, const pair<K, T> &val);
	void					insert(iterator first, iterator last);
	void					erase(iterator pos);
	size_t					erase (const K &key);
	void					erase(iterator first, iterator last);
	void					swap(map<K, T, Compare> &map);
	void					clear();

	Compare key_comp() const;
	Compare value_comp() const;

	iterator					find(const K &key);
	size_t						count(const K &key) const;
	iterator					lower_bound (const K key);
	iterator					upper_bound (const K key);
	pair<iterator, iterator>	equal_range (const K &k);
};


template <class K, class T, class Compare>
map<K, T, Compare>::iterator::iterator(node<K, T> *element): Ptr(element){}

template <class K, class T, class Compare>
map<K, T, Compare>::iterator::~iterator(){};

template <class K, class T, class Compare>
map<K, T, Compare>::iterator::iterator(iterator const &copy): Ptr(copy.Ptr){}

template <class K, class T, class Compare>
typename map<K, T, Compare>::iterator& map<K, T, Compare>::iterator::operator=(iterator const &copy)
{
	this->Ptr = copy.Ptr;
	return(*this);
}

template <class K, class T, class Compare>
pair<K, T>* map<K, T, Compare>::iterator::operator->() {return (&this->Ptr->Value);}

template <class K, class T, class Compare>
pair<K, T>& map<K, T, Compare>::iterator::operator*() {return (this->Ptr->Value);}

template <class K, class T, class Compare>
typename map<K, T, Compare>::iterator map<K, T, Compare>::iterator::operator++()
{
	if (this->Ptr->Next != NULL)
		this->Ptr = this->Ptr->Next;
	else
	{
		while (this->Ptr->Prev != NULL)
			--*this;
	}
	return(*this);
}

template <class K, class T, class Compare>
typename map<K, T, Compare>::iterator map<K, T, Compare>::iterator::operator++(int)
{
	iterator old = *this;
	++*this;
	return (old);
}

template <class K, class T, class Compare>
typename map<K, T, Compare>::iterator map<K, T, Compare>::iterator::operator--()
{
	if (this->Ptr->Prev != NULL)
		this->Ptr = this->Ptr->Prev;
	else
	{
		while (this->Ptr->Next != NULL)
			++*this;
	}
	return(*this);
}

template <class K, class T, class Compare>
typename map<K, T, Compare>::iterator map<K, T, Compare>::iterator::operator--(int)
{
	iterator old = *this;
	--*this;
	return (old);
}

template <class K, class T, class Compare>
bool map<K, T, Compare>::iterator::operator!=(iterator const &it){return (this->Ptr != it.Ptr);}

template <class K, class T, class Compare>
bool map<K, T, Compare>::iterator::operator==(iterator const &it){return (this->Ptr == it.Ptr);}


template <class K, class T, class Compare>
map<K, T, Compare>::reverse_iterator::reverse_iterator(pair<K, T> *pair)
{
	this->Ptr = iterator(pair);
}

template <class K, class T, class Compare>
map<K, T, Compare>::reverse_iterator::~reverse_iterator(){}

template <class K, class T, class Compare>
map<K, T, Compare>::reverse_iterator::reverse_iterator(reverse_iterator const &copy)
{
	this->Ptr = copy.Ptr;
}

template <class K, class T, class Compare>
typename map<K, T, Compare>::reverse_iterator&
map<K, T, Compare>::reverse_iterator::operator=(reverse_iterator const &copy)
{
	this->Ptr = copy.Ptr;
	return(*this);
}

template <class K, class T, class Compare>
pair<K, T>&	map<K, T, Compare>::reverse_iterator::operator*(){return(*this->Ptr);}

template <class K, class T, class Compare>
pair<K, T>*	map<K, T, Compare>::reverse_iterator::operator->(){return(&this->Ptr);}

template <class K, class T, class Compare>
typename map<K, T, Compare>::reverse_iterator
map<K, T, Compare>::reverse_iterator::operator++()
{
	--this->Ptr;
	return (*this);
}

template <class K, class T, class Compare>
typename map<K, T, Compare>::reverse_iterator
map<K, T, Compare>::reverse_iterator::operator++(int)
{
	map<K, T, Compare>::reverse_iterator old(*this);
	--this->Ptr;
	return (old);
}

template <class K, class T, class Compare>
typename map<K, T, Compare>::reverse_iterator
map<K, T, Compare>::reverse_iterator::operator--()
{
	++this->Ptr;
	return (*this);
}

template <class K, class T, class Compare>
typename map<K, T, Compare>::reverse_iterator
map<K, T, Compare>::reverse_iterator::operator--(int)
{
	map<K, T, Compare>::reverse_iterator old(*this);
	++this->Ptr;
	return (old);
}

template <class K, class T, class Compare>
bool map<K, T, Compare>::reverse_iterator::operator != (reverse_iterator const &it)
{return (this->Ptr != it.Ptr);}

template <class K, class T, class Compare>
bool map<K, T, Compare>::reverse_iterator::operator == (reverse_iterator const &it)
{return (this->Ptr == it.Ptr);}


template <class K, class T, class Compare>
map<K, T, Compare>::map(const Compare &comp): Comp(comp)
{
	node<K, T> *end = new node<K, T>();
	end->Prev = end;
	end->Next = end;
	this->End = end;
	this->First = end;
	}

template <class K, class T, class Compare>
map<K, T, Compare>::~map()
{
	if (this->empty() == false)
	{
		iterator it2;
		iterator it = this->begin(); 
		while (it != this->end())
		{
			it2 = it++;
			delete(it2.Ptr);
		}
		delete(it.Ptr);
	}
	else
		delete this->End;
}

template <class K, class T, class Compare>
map<K, T, Compare>::map(map const &copy)
{
	node<K, T> *end = new node<K, T>();
	end->Prev = end;
	end->Next = end;
	this->End = end;
	this->First = end;
	this->Comp = copy.Comp;
    for (node<K, T> *it = copy.First; it != copy.End; it = it->Next)
       	this->push_back(it->Value);
}

template <class K, class T, class Compare>
map<K, T, Compare>&	map<K, T, Compare>::operator = (map const &copy)
{
	this->First = copy.First;
	this->End = copy.End;
	this->Comp = copy.Comp;
	return(*this);
}

template <class K, class T, class Compare>
size_t	map<K, T, Compare>::size()
{
	size_t size = 0;
	for (iterator it = this->begin(); it != this->end(); it++)
		++size;
	return(size);
}

template <class K, class T, class Compare>
bool	map<K, T, Compare>::empty() {return(this->size() == 0);}

template <class K, class T, class Compare>
size_t	map<K, T, Compare>::max_size() const
{return(std::numeric_limits<size_t>::max() / sizeof(node<K, T>));}

template <class K, class T, class Compare>
T&	map<K, T, Compare>::operator[](const K &key)
{
	iterator it = find(key);
	if(it == this->end())
	{
		iterator it = (this->insert(make_pair((const K) key, T()))).first;
		return (it->second);
	}
	return it->second;
}

template <class K, class T, class Compare>
typename map<K, T, Compare>::iterator map<K, T, Compare>::begin()
{
	iterator it(this->First);
	return (it);
}

template <class K, class T, class Compare>
typename map<K, T, Compare>::iterator map<K, T, Compare>::end()
{
	iterator it(this->End);
	return (it);
}

template <class K, class T, class Compare>
typename map<K, T, Compare>::reverse_iterator map<K, T, Compare>::rbegin()
{
	reverse_iterator it(this->First);
	return (it);
}

template <class K, class T, class Compare>
typename map<K, T, Compare>::reverse_iterator map<K, T, Compare>::rend()
{
	reverse_iterator it(this->End);
	return (it);
}

template <class K, class T, class Compare>
pair<typename map<K, T, Compare>::iterator, bool>
map<K, T, Compare>::insert(const pair<K, T> &val)
{
	iterator pos = this->lower_bound(val.first);
	node<K, T> *n = NULL;
	if (pos == this->end())
	{
		n = new node<K, T>(val.first, val.second, this->End, this->End->Prev);
		n->Next->Prev = n;
		n->Prev->Next = n;
		if (n->Next == n->Prev)
			this->First = n;
		pos = --this->end();
	}
	else if (pos->first == val.first)
		return (make_pair(pos, false));
	else
	{
		n = new node<K, T>(val.first, val.second, pos.Ptr, pos.Ptr->Prev);
		if (pos == this->begin())
			this->First = n;
		n->Next->Prev = n;
		n->Prev->Next = n;
		--pos;
	}
	return (make_pair(pos, true));
}


template <class K, class T, class Compare>
typename map<K, T, Compare>::iterator
map<K, T, Compare>::insert(iterator pos, const pair<K, T> &val)
{
	(void)pos;
	iterator ret;
	ret = this->insert(val).first;
	return (ret);
}

template <class K, class T, class Compare>
void map<K, T, Compare>::insert(iterator first, iterator last)
{
	map<K, T> copy;
	iterator save = first;
	while (save != last)
	{
		copy.insert(save.Ptr->Value);
		++save;
	}
	save = copy.begin();
	while (save != copy.end())
	{
		this->insert(save.Ptr->Value);
		++save;
	}
}

template <class K, class T, class Compare>
void map<K, T, Compare>::erase(iterator pos)
{
	if (pos != this->end())
	{
		if (pos.Ptr == this->First)
			this->First = pos.Ptr->Next;
		pos.Ptr->Prev->Next = pos.Ptr->Next;
		pos.Ptr->Next->Prev = pos.Ptr->Prev;
		delete pos.Ptr;
	}
}

template <class K, class T, class Compare>
size_t map<K, T, Compare>::erase (const K &key)
{
	iterator it = this->find(key);
	if (it == this->end())
		return (0);
	this->erase(it);
	return (1);
}

template <class K, class T, class Compare>
void map<K, T, Compare>::erase(iterator first, iterator last)
{
	size_t diff = 0;
	for (iterator it = first; it != last; it++)
		++diff;
	for (size_t i = 0; i < diff; i++)
	{
		erase(first);
		++first;
	}
}

template <class K, class T, class Compare>
void	map<K, T, Compare>::swap(map<K, T, Compare> &map)
{
	std::swap(this->First, map.First);
	std::swap(this->End, map.End);
}

template <class K, class T, class Compare>
void map<K, T, Compare>::clear() { this->erase(this->begin(), this->end()); }

template <class K, class T, class Compare>
Compare map<K, T, Compare>::key_comp() const {return (this->Comp);}

template <class K, class T, class Compare>
Compare map<K, T, Compare>::value_comp() const {return (this->Comp);}


template <class K, class T, class Compare>
typename map<K, T, Compare>::iterator map<K, T, Compare>::find(const K &key)
{
	for (iterator it = this->begin(); it != this->end(); it++)
	{
		if (key == it->first)
			return (it);
	}
	return (this->end());
}

template <class K, class T, class Compare>
size_t	map<K, T, Compare>::count(const K &key) const
{
	for (iterator it = this->begin(); it != this->end(); it++)
	{
		if (key == it->first)
			return (1);
	}
	return (0);
}

template <class K, class T, class Compare>
typename map<K, T, Compare>::iterator map<K, T, Compare>::lower_bound (const K key)
{
	for(iterator it = this->begin(); it != this->end(); it++)
	{
		if(it->first == key || !Comp(it->first, key))
			return (it);
	}
	return (this->end());
}

template <class K, class T, class Compare>
typename map<K, T, Compare>::iterator map<K, T, Compare>::upper_bound (const K key)
{
	iterator it = this->begin();
	if (Comp(key , this->begin()->first) && this->size())
		return (this->begin());
	while(it != this->end())
	{
		if (Comp(key, it->first))
			return (it);
		++it;
	}
	return (this->end());
}

template <class K, class T, class Compare>
pair<typename map<K, T, Compare>::iterator, typename map<K, T, Compare>::iterator>
map<K, T, Compare>::equal_range (const K &k)
{
	if (this->find(k) == this->end())
		return (make_pair<iterator, iterator>(upper_bound(k), upper_bound(k)));
	return (make_pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
}

}

template <class K, class T, class Compare>
void	print_map(ft::map<K, T, Compare> &map)
{
	for (typename ft::map<K, T, Compare>::iterator it = map.begin(); it!=map.end(); ++it)
    	std::cout << it->first << " => " << it->second << '\n';
}

#endif
