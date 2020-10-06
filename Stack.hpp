#ifndef STACK_HPP
# define STACK_HPP

#include <iostream>
#include "limits"
#include "Vector.hpp"

namespace ft
{
template <class T>
class stack : protected vector<T>
{
	private:
	vector<T>	 Cont;

	public:
	explicit	stack<T>(const vector<T>& cont = vector<T>());
				~stack();
				stack<T>(const stack<T>& copy);
	stack<T>	&operator=(const stack<T>& copy);
	bool 		empty() const;
	size_t 		size() const;
	T&			top();
	const T&	top() const;
	void		push(const T& val);
	void		pop();

	friend bool operator==(const stack<T> &a, const stack<T> &b)
	{return a.Cont == b.Cont;}
	friend bool operator!=(const stack<T> &a, const stack<T> &b)
	{return a.Cont != b.Cont;}
	friend bool operator<(const stack<T> &a, const stack<T> &b)
	{return a.Cont < b.Cont;}
	friend bool operator<=(const stack<T> &a, const stack<T> &b)
	{return a.Cont <= b.Cont;}
	friend bool operator>(const stack<T> &a, const stack<T> &b)
	{return a.Cont > b.Cont;}
	friend bool operator>=(const stack<T> &a, const stack<T> &b)
	{return a.Cont >= b.Cont;}
};

template <class T>
stack<T>::stack(const vector<T>& cont): Cont(cont){}

template <class T>
stack<T>::~stack(){}

template <class T>
stack<T>::stack(const stack<T>& copy): Cont(copy.Cont){}

template <class T>
stack<T>&	stack<T>::operator=(const stack<T>& copy)
{
	this->Cont = copy.Cont;
	return (*this);
}

template <class T>
bool	stack<T>::empty() const {return (Cont.empty());}

template <class T>
size_t	stack<T>::size() const {return (Cont.size());}

template <class T>
T&		stack<T>::top() {return (Cont.back());}

template <class T>
const T& stack<T>::top() const {return (Cont.back());}

template <class T>
void	stack<T>::push(const T& val) {Cont.push_back(val);}

template <class T>
void	stack<T>::pop() {Cont.pop_back();}

}
#endif
