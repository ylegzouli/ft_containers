#ifndef QUEUE_HPP
# define QUEUE_HPP

#include <iostream>
#include "limits"
#include "List.hpp"

namespace ft
{
template <class T>
class queue : protected list<T>
{
	private:
	list<T>	 Cont;

	public:
	explicit	queue<T>(const list<T>& cont = list<T>());
				~queue();
				queue<T>(const queue<T>& copy);
	queue<T>	&operator=(const queue<T>& copy);
	bool 		empty();
	size_t 		size();
	T&			front();
	const T&	front() const;
	T&			back();
	const T&	back() const;
	void		push(const T& val);
	void		pop();

	friend bool operator==(queue<T> &a, queue<T> &b)
	{return a.Cont == b.Cont;}
	friend bool operator!=(queue<T> &a, queue<T> &b)
	{return a.Cont != b.Cont;}
	friend bool operator<(const queue<T> &a, const queue<T> &b)
	{return a.Cont < b.Cont;}
	friend bool operator<=(const queue<T> &a, const queue<T> &b)
	{return a.Cont <= b.Cont;}
	friend bool operator>(const queue<T> &a, const queue<T> &b)
	{return a.Cont > b.Cont;}
	friend bool operator>=(const queue<T> &a, const queue<T> &b)
	{return a.Cont >= b.Cont;}
};

template <class T>
queue<T>::queue(const list<T>& cont): Cont(cont){}

template <class T>
queue<T>::~queue(){}

template <class T>
queue<T>::queue(const queue<T>& copy): Cont(copy.Cont){}

template <class T>
queue<T>&	queue<T>::operator=(const queue<T>& copy)
{
	this->Cont = copy.Cont;
	return (*this);
}

template <class T>
bool	queue<T>::empty() {return (Cont.empty());}

template <class T>
size_t	queue<T>::size() {return (Cont.size());}

template <class T>
T&		queue<T>::front() {return (Cont.front());}

template <class T>
const T& queue<T>::front() const {return (Cont.front());}

template <class T>
T&		queue<T>::back() {return (Cont.back());}

template <class T>
const T& queue<T>::back() const {return (Cont.back());}

template <class T>
void	queue<T>::push(const T& val) {Cont.push_back(val);}

template <class T>
void	queue<T>::pop() {Cont.pop_front();}

}
#endif
