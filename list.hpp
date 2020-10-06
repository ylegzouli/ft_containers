#ifndef LIST_HPP
# define LIST_HPP

#include <iostream>
#include "limits"

namespace ft
{

template <class T>
class element
{
	public:
	element<T>(T value, element<T> *next, element<T> *prev);
	~element();
	element<T>(element<T> const &copy);
	element<T> &operator = (element<T> const &copy);

	T	Value;
    element<T>	*Next;
	element<T>	*Prev;
};

template <class T>
element<T>::element(T value, element<T> *next, element<T> *prev):
	Value(value), Next(next), Prev(prev) {};

template <class T>
element<T>::~element(){};

template <class T>
element<T>::element(element<T> const &copy):
	Value(copy.Value), Prev(copy->Prev), Next(copy->Next) {};

template <class T>
element<T>&		element<T>::operator = (element<T> const &copy)
{
	this->Value = copy.Value;
	this->Prev = copy->Prev;
	this->Next = copy->Next;
	return(*this);
}

template <class T>
class list
{
	friend class element<T>;
	friend class iterator;
	friend class reverse_iterator;
	private:
    element<T>	*First;
    element<T>	*End;

    public:
    list<T>();
    ~list();
	list(list const &copy);
    list	&operator = (list const &copy);

	class iterator
	{
		protected:
		friend class list;
		element<T>	*Ptr;

		public:
		iterator(element<T> *element = NULL);
		~iterator();
		iterator(iterator const &copy);
		iterator	&operator=(iterator const &copy);

		T&	operator*();
		T*	operator->();

		iterator operator++();
		iterator operator++(int);
		iterator operator--();
		iterator operator--(int);

		bool operator != (iterator const &it);
		bool operator == (iterator const &it);
	};
	class reverse_iterator: public iterator
	{
		private:
		friend class list;
		iterator Ptr;

		public:
		reverse_iterator(element<T> *element = NULL);
		~reverse_iterator();
		reverse_iterator(reverse_iterator const &copy);
		reverse_iterator	&operator=(reverse_iterator const &copy);

		T&	operator*();
		T*	operator->();

		reverse_iterator operator++();
		reverse_iterator operator++(int);
		reverse_iterator operator--();
		reverse_iterator operator--(int);
		bool operator != (reverse_iterator const &it);
		bool operator == (reverse_iterator const &it);
	};

	iterator	begin();
	iterator	end();
    reverse_iterator	rbegin();
	reverse_iterator	rend();

	size_t	size();
	bool	empty();
	size_t	max_size() const;

	const T		&front() const;
	T			&front();
	const T		&back() const;
	T			&back();

	void push_back (const T &value);
	void push_front (const T &value);
	void pop_front();
	void pop_back();
	iterator erase(iterator pos);
	reverse_iterator erase(reverse_iterator pos);
	iterator erase(iterator first, iterator last);
	iterator insert(iterator pos, T const &val);
	void insert (iterator pos, size_t n, T const &val);
	void insert(iterator pos, iterator first, iterator last);
	void assign(iterator first, iterator last);
	void assign(size_t n, T const &val);
	void clear();
	void resize (size_t n, T val = T());
	void swap (list<T> &list);

	void splice (iterator pos, list &list);
	void splice (iterator pos, list &list, iterator i);
	void splice (iterator pos, list &list, iterator first, iterator last);
	void remove(const T val);
	template <class Predicate> void remove_if (Predicate pred);
	void unique();
	template <class BinaryPredicate> void unique (BinaryPredicate binary_pred);
	void reverse();
	void sort();
	template <class Compare> void sort(Compare comp);
	void merge(list &list);
	template <class Compare> void merge(list &list, Compare comp);
};


template <class T>
list<T>::iterator::iterator(element<T> *element): Ptr(element){}

template <class T>
list<T>::iterator::~iterator(){};

template <class T>
list<T>::iterator::iterator(iterator const &copy): Ptr(copy.Ptr){}

template <class T>
typename list<T>::iterator& list<T>::iterator::operator=(iterator const &copy)
{
	this->Ptr = copy.Ptr;
	return(*this);
}

template <class T>
T&	list<T>::iterator::operator*() {return (this->Ptr->Value);}

template <class T>
T*	list<T>::iterator::operator->() {return &(this->Ptr->Value);}

template <class T>
typename list<T>::iterator list<T>::iterator::operator++()
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

template <class T>
typename list<T>::iterator list<T>::iterator::operator++(int)
{
	iterator old = *this;
	++*this;
	return (old);
}

template <class T>
typename list<T>::iterator list<T>::iterator::operator--()
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

template <class T>
typename list<T>::iterator list<T>::iterator::operator--(int)
{
	iterator old = *this;
	--*this;
	return (old);
}

template <class T>
bool list<T>::iterator::operator!=(iterator const &it){return (this->Ptr != it.Ptr);}

template <class T>
bool list<T>::iterator::operator==(iterator const &it){return (this->Ptr == it.Ptr);}


template <class T>
list<T>::reverse_iterator::reverse_iterator(element<T> *element)
{
	this->Ptr = iterator(element);
}

template <class T>
list<T>::reverse_iterator::~reverse_iterator(){}

template <class T>
list<T>::reverse_iterator::reverse_iterator(reverse_iterator const &copy)
{
	this->Ptr = copy.Ptr;
}

template <class T>
typename list<T>::reverse_iterator&
list<T>::reverse_iterator::operator=(reverse_iterator const &copy)
{
	this->Ptr = copy.Ptr;
	return(*this);
}

template <class T>
T&	list<T>::reverse_iterator::operator*(){return(*this->Ptr);}

template <class T>
T*	list<T>::reverse_iterator::operator->(){return(&this->Ptr);}

template <class T>
typename list<T>::reverse_iterator
list<T>::reverse_iterator::operator++()
{
	--this->Ptr;
	return (*this);
}

template <class T>
typename list<T>::reverse_iterator
list<T>::reverse_iterator::operator++(int)
{
	list<T>::reverse_iterator old(*this);
	--this->Ptr;
	return (old);
}

template <class T>
typename list<T>::reverse_iterator
list<T>::reverse_iterator::operator--()
{
	++this->Ptr;
	return (*this);
}

template <class T>
typename list<T>::reverse_iterator
list<T>::reverse_iterator::operator--(int)
{
	list<T>::reverse_iterator old(*this);
	++this->Ptr;
	return (old);
}

template <class T>
bool list<T>::reverse_iterator::operator != (reverse_iterator const &it)
{return (this->Ptr != it.Ptr);}

template <class T>
bool list<T>::reverse_iterator::operator == (reverse_iterator const &it)
{return (this->Ptr == it.Ptr);}

template <class T>
list<T>::list()
{
	element<T> *end = new element<T>(T(), NULL, NULL);
	end->Prev = end;
	end->Next = end;
	this->End = end;
	this->First = end;
}

template <class T>
list<T>::~list()
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

template <class T>
list<T>::list(list const &copy)
{
	element<T> *end = new element<T>(T(), NULL, NULL);
	end->Prev = end;
	end->Next = end;
	this->End = end;
	this->First = end;
    for (element<T> * it = copy.First; it != copy.End; it = it->Next)
       	this->push_back(it->Value);
}

template <class T>
list<T>&	list<T>::operator = (list const &copy)
{
	this->First = copy.First;
	this->End = copy.End;
	return(*this);
}

template <class T>
typename list<T>::iterator	list<T>::begin()
{
	iterator it(this->First);
	return (it);
}

template <class T>
typename list<T>::iterator	list<T>::end()
{
	iterator it(this->End);
	return (it);
}

template <class T>
typename list<T>::reverse_iterator	list<T>::rbegin()
{
	reverse_iterator it(this->First);
	return (it);
}

template <class T>
typename list<T>::reverse_iterator	list<T>::rend()
{
	reverse_iterator it(this->End);
	return (it);
}

template <class T>
size_t	list<T>::size()
{
	size_t size = 0;
	for (iterator it = this->begin(); it != this->end(); it++)
		++size;
	return(size);
}

template <class T>
bool	list<T>::empty() { return(this->size() == 0);}

template <class T>
size_t	list<T>::max_size() const
{return(std::numeric_limits<size_t>::max() / sizeof(element<T>));}


template <class T>
const T&	list<T>::front() const { return(this->First->Value);}

template <class T>
T&	list<T>::front() { return(this->First->Value);}

template <class T>
const T&	list<T>::back() const { return(this->End->Prev->Value);}

template <class T>
T&	list<T>::back() { return(this->End->Prev->Value);}

template <class T>
void	list<T>::push_back (const T &value)
{
	if (this->First == this->End)
		this->push_front(value);
	else
	{
		element<T> *n = new element<T>(value, this->End, this->End->Prev);
		n->Prev->Next = n;
		n->Next->Prev = n;
	}
}

template <class T>
void	list<T>::push_front (const T &value)
{
	element<T> *n = new element<T>(value, this->End->Next, this->End);
	n->Next->Prev = n;
	n->Prev->Next = n;
	this->First = n;
}

template <class T>
void	list<T>::pop_front()
{
	if (this->empty() == false)
	{
		this->End->Next = this->First->Next;
		this->First->Next->Prev = this->End;
		delete this->First;
		this->First = this->End->Next;
	}
}

template <class T>
void	list<T>::pop_back()
{
	if (this->empty() == false)
	{
		element<T> *save = this->End->Prev;
		if (save == this->First)
			this->First = save->Prev;
		this->End->Prev = this->End->Prev->Prev;
		this->End->Prev->Next = this->End;
		delete save;
	}
}

template <class T>
typename list<T>::iterator	list<T>::erase(iterator pos)
{
	if (pos != this->end())
	{
		if (pos.Ptr == this->First)
			this->First = pos.Ptr->Next;
		pos.Ptr->Prev->Next = pos.Ptr->Next;
		pos.Ptr->Next->Prev = pos.Ptr->Prev;
		delete(pos.Ptr);
		++pos;
	}
	return pos;
}

template <class T>
typename list<T>::iterator	list<T>::erase(iterator first, iterator last)
{
	size_t diff = 0;
	for (iterator copy = first; copy != last; copy++)
		++diff;
	for (size_t i = 0; i < diff; i++)
		first = erase(first);
	return (first);
}

template <class T>
typename list<T>::iterator	list<T>::insert(iterator pos, T const &val)
{
	element<T> *el = new element<T>(val, pos.Ptr, pos.Ptr->Prev);
	el->Prev->Next = el;
	pos.Ptr->Prev = el;
	if (this->End->Next == el)
	{
		this->First = NULL;
		this->First = el;
	}
	return(pos);
}

template <class T>
void	list<T>::insert(iterator pos, size_t n, T const &val)
{
	for (size_t i = 0; i < n; i++)
		pos = this->insert(pos, val);
}

template <class T>
void	list<T>::insert(iterator pos, iterator first, iterator last)
{
	list<T> copy;
	iterator save = first;
	while (save.Ptr != last.Ptr)
	{
		copy.push_back(save.Ptr->Value);
		++save;
	}
	save = copy.begin();
	while (save != copy.end())
	{
		pos = insert(pos, save.Ptr->Value);
		++save;
	}
}

template <class T>
void	list<T>::assign(iterator first, iterator last)
{
	list<T> copy;
	iterator save = first;
	while (save.Ptr != last.Ptr)
	{
		copy.push_back(*save);
		++save;
	}
	this->clear();
	save = copy.begin();
	iterator it = this->begin();
	while (save != copy.end())
	{
		it = insert(it, *save);
		++save;
	}
}

template <class T>
void	list<T>::assign(size_t n, T const &val)
{
	this->clear();
	this->insert(this->begin(), n, val);
}

template <class T>
void	list<T>::clear()
{
	if (this->empty() == false)
	{
		iterator it = ++this->begin();
		while (it.Ptr->Prev != this->End)
		{
			delete(it.Ptr->Prev);
			++it;
		}
	}
	this->End->Prev = this->End;
	this->End->Next = this->End;
	this->First = this->End;
}

template <class T>
void	list<T>::resize (size_t n, T val)
{
	iterator it =  this->end();
	int diff = (int)n - (int)this->size();
	if (diff > 0)
	{
		for (int i = 0; i < diff; i++)
			it = this->insert(it, val);
	}
	if (diff < 0)
	{
		while (this->size() > n)
			this->erase(--this->end());
	}
}

template <class T>
void	list<T>::swap (list<T> &list)
{
	std::swap(this->First, list.First);
	std::swap(this->End, list.End);
}

template <class T>
void	list<T>::splice (iterator pos, list &list)
{
	if (pos == this->begin())
		this->First = list.First;
	pos.Ptr->Prev->Next = list.First;
	list.First->Prev = pos.Ptr->Prev;
	pos.Ptr->Prev = list.End->Prev;
	pos.Ptr->Prev->Next = pos.Ptr;
	list.First = list.End;
	list.End->Prev = list.End;
	list.End->Next = list.End;
}

template <class T>
void	list<T>::splice (iterator pos, list &list, iterator i)
{
	if (i == list.begin())
		list.First = i.Ptr->Next;
	if (pos == this->begin())
		this->First = i.Ptr;
	i.Ptr->Next->Prev = i.Ptr->Prev;
	i.Ptr->Prev->Next = i.Ptr->Next;
	pos.Ptr->Prev->Next = i.Ptr;
	i.Ptr->Prev = pos.Ptr->Prev;
	pos.Ptr->Prev = i.Ptr;
	pos.Ptr->Prev->Next = pos.Ptr;
}

template <class T>
void	list<T>::splice (iterator pos, list &list, iterator first, iterator last)
{
	first.Ptr->Prev->Next = last.Ptr;
	pos.Ptr->Prev->Next = first.Ptr;
	first.Ptr->Prev = pos.Ptr->Prev;
	pos.Ptr->Prev = last.Ptr->Prev;
	pos.Ptr->Prev->Next = pos.Ptr;
	if(pos == this->begin())
		this->First = first.Ptr;
	last.Ptr->Prev = first.Ptr->Prev;
	if(first == list.begin())
		list.First = last.Ptr;
}

template <class T>
void	list<T>::remove(const T val)
{
	for (iterator it = this->begin(); it != this->end(); it++)
	{
		if (*it == val)
			it = erase(it);
	}
}

template <class T>
template <class Predicate>
void	list<T>::remove_if (Predicate pred)
{
	for (iterator it = this->begin(); it != this->end(); it++)
	{
		if (pred(*it))
			it = erase(it);
	}
}

template <class T>
void	list<T>::unique()
{
	iterator it2 = ++this->begin();
	for (iterator it = this->begin(); it != this->end(); it++)
	{
		while (*it == *it2)
			it2 = erase(it2);
		++it2;
	}
}

template <class T>
template <class BinaryPredicate>
void	list<T>::unique (BinaryPredicate binary_pred)
{
	iterator it2 = ++this->begin();
	for (iterator it = this->begin(); it != this->end(); it++)
	{
		while (binary_pred(*it, *it2))
			it2 = erase(it2);
		++it2;
	}
}

template <class T>
void	list<T>::reverse()
{
	iterator it = this->begin();
	iterator stop = --this->end();
	while (it != stop)
	{
		it.Ptr->Prev->Next = it.Ptr->Prev->Prev;
		it.Ptr->Prev->Prev = it.Ptr;
		++it;
	}
	it.Ptr->Prev->Next = it.Ptr->Prev->Prev;
	it.Ptr->Prev->Prev = it.Ptr;
	it.Ptr->Next = it.Ptr->Prev;
	it.Ptr->Prev = this->End;
	this->First = this->End->Next;
}

template <class T>
void	list<T>::sort()
{
	iterator stop = --this->end();
	T val;
	for (list<T>::iterator it = this->begin(); it != this->end(); it++)
	{
		for (list<T>::iterator it = this->begin(); it != stop; it++)
		{
			if(it.Ptr->Next->Value < *it)
			{
				val = *it;
				it.Ptr->Value = it.Ptr->Next->Value;
				it.Ptr->Next->Value = val;
			}
		}
		--stop;
	}
}

template <class T>
template <class Compare>
void	list<T>::sort(Compare comp)
	{
	iterator stop = --this->end();
	T val;
	for (list<T>::iterator it = this->begin(); it != this->end(); it++)
	{
		for (list<T>::iterator it = this->begin(); it != stop; it++)
		{
			if(comp(it.Ptr->Next->Value, *it))
			{
				val = *it;
				it.Ptr->Value = it.Ptr->Next->Value;
				it.Ptr->Next->Value = val;
			}
		}
		--stop;
	}
}

template <class T>
void	list<T>::merge(list &list)
{
	this->splice(this->end(), list);
	this->sort();
}

template <class T>
template <class Compare>
void	list<T>::merge(list &list, Compare comp)
{
	this->splice(this->end(), list);
	this->sort(comp);
}

template <class T>
bool operator == (list<T> &list1, list<T> &list2)
{
	return(list1.size() == list2.size() ? true : false);
}

template <class T>
bool operator != (list<T> &list1, list<T> &list2)
{
	return(list1.size() != list2.size() ? true : false);
}

template <class T>
bool operator < (list<T> &list1, list<T> &list2)
{
	typename list<T>::iterator it1 = list1.begin();
	typename list<T>::iterator it2 = list2.begin();
	while(*it1 == *it2)
	{
		if (it1 == list1.end() && it2 == list2.end())
			return (false);
		++it1;
		++it2;
	}
	if (*it1 < *it2 || it1 == list1.end())
		return (true);
	return (false);
}

template <class T>
bool operator > (list<T> &list1, list<T> &list2)
{
	typename list<T>::iterator it1 = list1.begin();
	typename list<T>::iterator it2 = list2.begin();
	while(*it1 == *it2)
	{
		if (it1 == list1.end() && it2 == list2.end())
			return (false);
		++it1;
		++it2;
	}
	if (*it1 > *it2 || it2 == list2.end())
		return (true);
	return (false);
}

template <class T>
bool operator >= (list<T> &list1, list<T> &list2)
{
	typename list<T>::iterator it1 = list1.begin();
	typename list<T>::iterator it2 = list2.begin();
	while(*it1 == *it2)
	{
		if (it1 == list1.end() && it2 == list2.end())
			return (true);
		++it1;
		++it2;
	}
	if (*it1 >= *it2 || it2 == list2.end())
		return (true);
	return (false);
}

template <class T>
bool operator <= (list<T> &list1, list<T> &list2)
{
	typename list<T>::iterator it1 = list1.begin();
	typename list<T>::iterator it2 = list2.begin();
	while(*it1 == *it2)
	{
		if (it1 == list1.end() && it2 == list2.end())
			return (true);
		++it1;
		++it2;
	}
	if (*it1 <= *it2 || it1 == list1.end())
		return (true);
	return (false);
}


template <class T>
void swap (list<T> &x, list<T> &y) {x.swap(y);}

template <class T>
void print_list(list<T> list)
{
	for (typename ft::list<T>::iterator it = list.begin(); it != list.end(); it++)
		std::cout<<*it<<"\n";
}

}
#endif
