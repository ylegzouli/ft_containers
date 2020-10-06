#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include "limits"

namespace ft
{

template <class T>
class vector
{
	protected:
	size_t 	Size;
	size_t	Capacity;
	T		*Array;
	void alloc_mem();

	public:
	vector<T>();
	~vector();
	vector(vector const &copy);
	vector	&operator = (vector const &copy);

	class iterator
	{
		protected:
		friend class vector;
		T	*Ptr;

		public:
		iterator(T	*ptr = NULL);
		~iterator();
		iterator(iterator const &copy);
		iterator	&operator=(iterator const &copy);

		T	&operator*();
		T	*operator->();
		T	&operator[](int n);
		iterator operator++();
		iterator operator++(int);
		iterator operator--();
		iterator operator--(int);

		bool operator != (iterator const &it);
		bool operator == (iterator const &it);
		bool operator < (iterator const &it);
		bool operator > (iterator const &it);
		bool operator <= (iterator const &it);
		bool operator >= (iterator const &it);

		iterator operator+(int n);
		iterator operator+=(int n);
		iterator operator-=(int n);
		iterator operator-(int n);
		friend iterator operator+(int n, iterator it)
		{
			iterator it2(it.Ptr + n);
			return (it2);
		}
		friend iterator operator-(int n, iterator it)
		{
			iterator it2(it.Ptr - n);
			return (it2);
		}
	};
	class reverse_iterator: protected iterator
	{
		protected:
		friend class vector;
		iterator	*Ptr;

		public:
		reverse_iterator(T	*ptr = NULL);
		~reverse_iterator();
		reverse_iterator(reverse_iterator const &copy);
		reverse_iterator	&operator=(reverse_iterator const &copy);

		T	&operator*();
		T	*operator->();
		T	&operator[](int n);
		reverse_iterator operator++();
		reverse_iterator operator++(int);
		reverse_iterator operator--();
		reverse_iterator operator--(int);

		bool operator != (reverse_iterator const &it);
		bool operator == (reverse_iterator const &it);
		bool operator < (reverse_iterator const &it);
		bool operator > (reverse_iterator const &it);
		bool operator <= (reverse_iterator const &it);
		bool operator >= (reverse_iterator const &it);

		reverse_iterator operator+(int n);
		reverse_iterator operator+=(int n);
		reverse_iterator operator-=(int n);
		reverse_iterator operator-(int n);
		friend reverse_iterator operator+(int n, reverse_iterator it)
		{
			reverse_iterator it2(it.Ptr - n);
			return (it2);
		}
		friend reverse_iterator operator-(int n, reverse_iterator it)
		{
			reverse_iterator it2(it.Ptr + n);
			return (it2);
		}
	};

	iterator			begin();
	iterator			end();
	reverse_iterator	rbegin();
	reverse_iterator	rend();


	size_t	size() const;
	size_t	capacity() const;
	bool	empty() const;
	size_t	max_size() const;
	void 	resize (size_t n, T val = T());
	void	reserve (size_t n);

	T			&operator[](size_t n);
	const T		&operator[](size_t n) const;
	T			&at(size_t n);
	const T		&at(size_t n) const;
	T 			&back();
	T			&front();
	const T		&front() const;
	const T 	&back() const;

	void		assign(iterator first, iterator last);
	void		assign (size_t n, const T &val);
	iterator	insert (iterator pos, const T &val);
	void		insert (iterator pos, size_t n, const T &val);
	void		insert (iterator pos, iterator first, iterator last);
	void		push_back(T value);
	void 		pop_back();
	iterator	erase (iterator pos);
	iterator	erase (iterator first, iterator last);
	void 		swap (vector &x);
	void 		clear();
};

template <class T>
vector<T>::iterator::iterator(T *ptr): Ptr(ptr){}

template <class T>
vector<T>::iterator::~iterator(){}

template <class T>
vector<T>::iterator::iterator(iterator const &copy): Ptr(copy.Ptr){}

template <class T>
typename vector<T>::iterator& vector<T>::iterator::operator=(iterator const &copy)
{
	this->Ptr = copy.Ptr;
	return(*this);
}

template <class T>
T&	vector<T>::iterator::operator*() {return (*this->Ptr);}

template <class T>
T*	vector<T>::iterator::operator->() {return (this->Ptr);}

template <class T>
T&	vector<T>::iterator::operator[](int n) {return(this->Ptr[n]);}

template <class T>
typename vector<T>::iterator vector<T>::iterator::operator++() {return(++this->Ptr);}

template <class T>
typename vector<T>::iterator vector<T>::iterator::operator++(int)
{
	iterator old(this->Ptr);
	this->Ptr++;
	return (old);
}

template <class T>
typename vector<T>::iterator vector<T>::iterator::operator--() {return(--this->Ptr);}

template <class T>
typename vector<T>::iterator vector<T>::iterator::operator--(int)
{
	iterator old(this->Ptr);
	this->Ptr--;
	return (old);
}

template <class T>
bool vector<T>::iterator::operator != (iterator const &it)
	{return (this->Ptr != it.Ptr);}

template <class T>
bool vector<T>::iterator::operator == (iterator const &it)
	{return (this->Ptr == it.Ptr);}

template <class T>
bool vector<T>::iterator::operator < (iterator const &it)
	{return (this->Ptr < it.Ptr);}

template <class T>
bool vector<T>::iterator::operator > (iterator const &it)
	{return (this->Ptr > it.Ptr);}

template <class T>
bool vector<T>::iterator::operator <= (iterator const &it)
	{return (this->Ptr <= it.Ptr);}

template <class T>
bool vector<T>::iterator::operator >= (iterator const &it)
	{return (this->Ptr >= it.Ptr);}

template <class T>
typename vector<T>::iterator vector<T>::iterator::operator+(int n)
{
	iterator it(this->Ptr + n);
	return (it);
}

template <class T>
typename vector<T>::iterator vector<T>::iterator::operator+=(int n)
{
	this->Ptr += n;
	return (*this);
}

template <class T>
typename vector<T>::iterator vector<T>::iterator::operator-=(int n)
{
	this->Ptr -= n;
	return (*this);
}

template <class T>
typename vector<T>::iterator vector<T>::iterator::operator-(int n)
{
	iterator it(this->Ptr - n);
	return (it);
}


template <class T>
vector<T>::reverse_iterator::reverse_iterator(T *ptr)
{
	this->Ptr = iterator(ptr);
}

template <class T>
vector<T>::reverse_iterator::~reverse_iterator(){}

template <class T>
vector<T>::reverse_iterator::reverse_iterator(reverse_iterator const &copy)
{this->Ptr = copy.Ptr;}

template <class T>
typename vector<T>::reverse_iterator&
vector<T>::reverse_iterator::operator=(reverse_iterator const &copy)
{
	this->Ptr = copy.Ptr;
	return(*this);
}

template <class T>
T&	vector<T>::reverse_iterator::operator*(){return(*this->Ptr);}

template <class T>
T*	vector<T>::reverse_iterator::operator->(){return(&this->Ptr);}

template <class T>
T&	vector<T>::reverse_iterator::operator[](int n){return(this->Ptr[n]);}

template <class T>
typename vector<T>::reverse_iterator
vector<T>::reverse_iterator::operator++()
{
	--this->Ptr;
	return (*this);
}

template <class T>
typename vector<T>::reverse_iterator
vector<T>::reverse_iterator::operator++(int)
{
	vector<T>::reverse_iterator old(*this);
	--this->Ptr;
	return (old);
}

template <class T>
typename vector<T>::reverse_iterator
vector<T>::reverse_iterator::operator--()
{
	++this->Ptr;
	return (*this);
}

template <class T>
typename vector<T>::reverse_iterator
vector<T>::reverse_iterator::operator--(int)
{
	vector<T>::reverse_iterator old(*this);
	++this->Ptr;
	return (old);
}

template <class T>
bool vector<T>::reverse_iterator::operator != (reverse_iterator const &it)
	{return (this != it);}

template <class T>
bool vector<T>::reverse_iterator::operator == (reverse_iterator const &it)
	{return (this == it);}

template <class T>
bool vector<T>::reverse_iterator::operator < (reverse_iterator const &it)
	{return (this->Ptr < it.Ptr);}

template <class T>
bool vector<T>::reverse_iterator::operator > (reverse_iterator const &it)
	{return (this->Ptr > it.Ptr);}

template <class T>
bool vector<T>::reverse_iterator::operator <= (reverse_iterator const &it)
	{return (this->Ptr <= it.Ptr);}

template <class T>
bool vector<T>::reverse_iterator::operator >= (reverse_iterator const &it)
	{return (this->Ptr >= it.Ptr);}

template <class T>
typename vector<T>::reverse_iterator vector<T>::reverse_iterator::operator+(int n)
{
	iterator it(this->Ptr - n);
	return (it);
}

template <class T>
typename vector<T>::reverse_iterator vector<T>::reverse_iterator::operator+=(int n)
{
	this->Ptr -= n;
	return (*this);
}

template <class T>
typename vector<T>::reverse_iterator vector<T>::reverse_iterator::operator-=(int n)
{
	this->Ptr += n;
	return (*this);
}

template <class T>
typename vector<T>::reverse_iterator vector<T>::reverse_iterator::operator-(int n)
{
	iterator it(this->Ptr + n);
	return (it);
}

template <class T>
void vector<T>::alloc_mem()
{
	this->Capacity == 0? this->Capacity = 1: this->Capacity *= 2;
	T *new_array = new T[this->Capacity + 1];
	for(size_t i = 0; i < this->size(); i++)
		new_array[i] = this->Array[i];
	for(size_t i = this->size(); i < this->capacity(); i++)
		new_array[i] = T();
	delete[] this->Array;
	this->Array = new_array;
}

template <class T>
vector<T>::vector(): Size(0), Capacity(0) {this->Array = new T[1];}

template <class T>
vector<T>::~vector() {delete this->Array;}

template <class T>
vector<T>::vector(vector const &copy): Size(copy.Size), Capacity(copy.Capacity)
{
	this->Array = new T[this->capacity() + 1];
	for (size_t i = 0; i < this->capacity(); i++)
		this->Array[i] = copy.Array[i];
}

template <class T>
vector<T>& vector<T>::operator = (vector const &copy)
{
	this->Capacity = copy.capacity();
	this->Size = copy.size();
	this->Array = new T[this->capacity() + 1];
	for (size_t i = 0; i < this->capacity(); i++)
		this->Array[i] = copy.array[i];
	return (*this);
}

template <class T>
typename vector<T>::iterator vector<T>::begin()
{
	iterator it(&this->Array[0]);
	return (it);
}

template <class T>
typename vector<T>::iterator vector<T>::end()
{
	iterator it(&this->Array[this->size()]);
	return (it);
}

template <class T>
typename vector<T>::reverse_iterator vector<T>::rbegin()
{
	reverse_iterator it(&this->Array[0]);
	return (it);
}

template <class T>
typename vector<T>::reverse_iterator vector<T>::rend()
{
	reverse_iterator it(&this->Array[this->size()]);
	return (it);
}


template <class T>
size_t	vector<T>::size() const {return (this->Size);}

template <class T>
size_t	vector<T>::capacity() const {return (this->Capacity);}

template <class T>
bool	vector<T>::empty() const {return(this->size() == 0);}

template <class T>
size_t	vector<T>::max_size() const
	{return(std::numeric_limits<size_t>::max() / sizeof(T));}

template <class T>
void 	vector<T>::resize (size_t n, T val)
{
	if (n < this->size())
		this->Size = n;
	else
	{
		for (size_t i = this->size(); i < n ;i++)
			this->push_back(val);
	}
}

template <class T>
void	vector<T>::reserve (size_t n)
{
	if (n > this->capacity())
	{
		this->Capacity = n;
		T *new_array = new T[this->Capacity + 1];
		for(size_t i = 0; i < this->size(); i++)
			new_array[i] = this->Array[i];
		for(size_t i = this->size(); i < this->capacity(); i++)
			new_array[i] = T();
		delete[] this->Array;
		this->Array = new_array;
	}
}

template <class T>
T&	vector<T>::operator[](size_t n) {return (this->Array[n]);}

template <class T>
const T&	vector<T>::operator[](size_t n) const {return (this->Array[n]);}

template <class T>
T&	vector<T>::at(size_t n)
{
	if (n < this->size())
		return (this->Array[n]);
	throw std::out_of_range("Introduced number is greater than vector size");
}

template <class T>
const T&	vector<T>::at(size_t n) const
{
	if (n < this->size())
		return (this->Array[n]);
	throw std::out_of_range("Introduced number is greater than vector size");
}

template <class T>
T&	vector<T>::back(){return (this->Array[this->size() - 1]);}

template <class T>
T&	vector<T>::front(){return (this->Array[0]);}

template <class T>
const T&	vector<T>::front() const { return(this->Array[0]);}

template <class T>
const T&	vector<T>::back() const {return (this->Array[this->size() - 1]);}

template <class T>
void vector<T>::assign(iterator first, iterator last)
	{
		this->clear();
		while (first != last)
		{
			this->push_back(*first);
			++first;
		}
	}

template <class T>
void vector<T>::assign (size_t n, const T &val)
{
	this->clear();
	for (size_t i = 0; i < n; i++)
		this->push_back(val);
}

template <class T>
typename vector<T>::iterator vector<T>::insert (iterator pos, const T &val)
{
	vector<T> copy;
	copy.assign(pos, this->end());
	while (this->end() - 1 != pos)
		this->pop_back();
	this->pop_back();
	this->push_back(val);
	for (iterator it = copy.begin(); it != copy.end(); it++)
		this->push_back(*it);
	iterator ret(this->end() - copy.size() - 1);
	return (ret);
}

template <class T>
void vector<T>::insert (iterator pos, size_t n, const T &val)
{
	vector<T> copy;
	copy.assign(pos, this->end());
	while (this->end() - 1  != pos)
		this->pop_back();
	this->pop_back();
	for (size_t i = 0; i < n; i++)
		this->push_back(val);
	for (iterator it = copy.begin(); it != copy.end(); it++)
		this->push_back(*it);
}

template <class T>
void vector<T>::insert (iterator pos, iterator first, iterator last)
{
	vector<T> copy, insert;
	copy.assign(pos, this->end());
	insert.assign(first, last);
	while (this->end() - 1  != pos)
		this->pop_back();
	this->pop_back();
	for (iterator it = insert.begin(); it != insert.end(); it++)
		this->push_back(*it);
	for (iterator it = copy.begin(); it != copy.end(); it++)
		this->push_back(*it);
}

template <class T>
void vector<T>::push_back(T value)
{
	if (this->size() == this->capacity())
		alloc_mem();
	this->Array[this->size()] = value;
	++this->Size;
}

template <class T>
void vector<T>::pop_back() {--this->Size;}

template <class T>
typename vector<T>::iterator vector<T>::erase (iterator pos)
{
	vector<T> copy;
	copy.assign(pos + 1, this->end());
	while (this->end() - 1 != pos)
		this->pop_back();
	this->pop_back();
	for (iterator it = copy.begin(); it != copy.end(); it++)
		this->push_back(*it);
	iterator ret(this->end() - copy.size());
	return (ret);
}

template <class T>
typename vector<T>::iterator vector<T>::erase (iterator first, iterator last)
{
	vector<T> copy;
	copy.assign(last, this->end());
	while (this->end() - 1 != first)
		this->pop_back();
	this->pop_back();
	for (iterator it = copy.begin(); it != copy.end(); it++)
		this->push_back(*it);
	iterator ret(this->end() - copy.size());
	return (ret);
}

template <class T>
void vector<T>::swap (vector &x)
{
	size_t size_save = this->size();
	size_t capacity_save = this->capacity();
	T	*array_save = this->Array;

	this->Size = x.size();
	this->Capacity = x.capacity();
	this->Array = x.Array;
	x.Array = array_save;
	x.Size = size_save;
	x.Capacity = capacity_save;
}

template <class T>
void vector<T>::clear() {this->Size = 0;}


template <class T>
bool operator == (const vector<T> &vec1, const vector<T> &vec2)
{
	return(vec1.size() == vec2.size());
}

template <class T>
bool operator != (const vector<T> &vec1, const vector<T> &vec2)
{
	return(vec1.size() != vec2.size());
}

template <class T>
bool operator < (const vector<T> &vec1, const vector<T> &vec2)
{
	typename vector<T>::iterator it1 = vec1.begin();
	typename vector<T>::iterator it2 = vec2.begin();
	while(*it1 == *it2)
	{
		if (it1 == vec1.end() && it2 == vec2.end())
			return (false);
		++it1;
		++it2;
	}
	if (*it1 < *it2 || it1 == vec1.end())
		return (true);
	return (false);
}

template <class T>
bool operator > (const vector<T> &vec1, const vector<T> &vec2)
{
	typename vector<T>::iterator it1 = vec1.begin();
	typename vector<T>::iterator it2 = vec2.begin();
	while(*it1 == *it2)
	{
		if (it1 == vec1.end() && it2 == vec2.end())
			return (false);
		++it1;
		++it2;
	}
	if (*it1 > *it2 || it2 == vec2.end())
		return (true);
	return (false);
}

template <class T>
bool operator >= (const vector<T> &vec1, const vector<T> &vec2)
{
	typename vector<T>::iterator it1 = vec1.begin();
	typename vector<T>::iterator it2 = vec2.begin();
	while(*it1 == *it2)
	{
		if (it1 == vec1.end() && it2 == vec2.end())
			return (true);
		++it1;
		++it2;
	}
	if (*it1 >= *it2 || it2 == vec2.end())
		return (true);
	return (false);
}

template <class T>
bool operator <= (const vector<T> &vec1, const vector<T> &vec2)
{
	typename vector<T>::iterator it1 = vec1.begin();
	typename vector<T>::iterator it2 = vec2.begin();
	while(*it1 == *it2)
	{
		if (it1 == vec1.end() && it2 == vec2.end())
			return (true);
		++it1;
		++it2;
	}
	if (*it1 <= *it2 || it1 == vec1.end())
		return (true);
	return (false);
}

template <class T>
void	swap(vector<T> &vec, vector<T> &vec2) {vec.swap(vec2);}

template <class T>
void	print_vector(vector<T> vec)
{
	for (typename vector<T>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout<<*it<<std::endl;
}

template <class T>
void	print_full_vector(vector<T> vec)
{
	std::cout<<"Full vector\n";
	for (size_t i = 0; i < vec.capacity(); i++)
		std::cout<<vec.Array[i]<<std::endl;
}

}

#endif
