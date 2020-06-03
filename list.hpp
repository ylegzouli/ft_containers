#ifndef LIST_HPP
# define LIST_HPP

# include <cstdlib>
# include <cstring>
# include <iostream>
# include "reverse_iterator.hpp"

namespace	ft
{
	template <typename T>
	class		List;
//__________________________________________________________

	template <typename T>
	class		ListIter
	{
		// ----------------------------------------------
		public:
			typedef typename List<T>::intern	intern;
			typedef	T 							value_type;
			typedef T&							reference;
			typedef T*							pointer;

		// ----------------------------------------------
		private:
			intern		*_elem;
		
		// ----------------------------------------------
		public:
			ListIter() 					{ _elem = NULL; }
			ListIter(ListIter &ref)		{ _elem = ref._elem; }
			ListIter(intern *elem2)		{ _elem = elem2; }
			~ListIter()					{}	
			ListIter	&operator=(const ListIter &ref)
										{ _elem = ref._elem;
			 								return (*this); }
			bool		operator==(const ListIter &ref) const
										{ return (_elem == ref._elem); }
			bool		operator!=(const ListIter &ref) const
										{ return (_elem != ref._elem); }
			ListIter	&operator--()	{ if (_elem) _elem = _elem->prev;
										  return (*this); }
			ListIter	operator--(int)	{ ListIter copy = *this;
										  --(*this);
										  return (copy); }
			ListIter	&operator++()	{ if (_elem) _elem = _elem->next;
										  return (*this); }
			ListIter	operator++(int)	{ ListIter copy = *this;
										  ++(*this);
										  return (copy); }
			ListIter	operator+(int nb)
										{ for (int i = 0; i < nb; i++)
											(*this)++;	
										  return (*this); }
			ListIter	operator-(int nb)
										{ for (int i = 0; i < nb; i++)
											(*this)--;	
										  return (*this); }
			T&			operator*() const
										{ return (_elem->content); }
			T*			operator->() const
										{ return (&_elem->content); }
			intern		*get_elem()		{ return (_elem); }

	};

//__________________________________________________________

	template <typename T>
	class		List
	{
		public:
	// ---------------------------------------
	//	Member types:
	//		une liste de typedef ? lesquels ? pourquoi ? A voir.
		typedef T value_type;
		typedef T& reference;
		typedef const T& const_reference;
		typedef T* pointer;
		typedef const T* const_pointer;
		typedef std::ptrdiff_t difference_type;
		typedef size_t size_type;
		typedef ListIter<T> iterator;
		typedef ListIter<const T> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

	// ---------------------------------------
	//	Structure de liste
		class	intern
		{
			public:
				T		content;
				intern	*prev;
				intern	*next;
		};

	// ---------------------------------------
	//	constructor / destructor / operateur =
		List()
		{
			_list = new intern;
			memset(&(_list->content), 0, sizeof(T));
			_list->prev = NULL;
			_list->next = NULL;
			_size = 0;
		}

		explicit List(size_type n, const value_type& val = value_type())
		{
			_list = new intern;
			memset(&(_list->content), 0, sizeof(T));
			_list->prev = NULL;
			_list->next = NULL;
			_size = 0;
			assign(n, val);	
		}
/*		
		template <class InputIter>
		List(InputIter first, InputIter last)
		{
			_list = new intern;
			memset(&(_list->content), 0, sizeof(T));
			_list->prev = NULL;
			_list->next = NULL;
			_size = 0;
    		assign(first, last);
		}
*/
		List(const List &ref)
		{
			_list = new intern;
			memset(&(_list->content), 0, sizeof(T));
			_list->prev = NULL;
			_list->next = NULL;
			_size = 0;
			*this = ref;
		}

		~List()
		{
			clear();
		}

		List	&operator=(const List &ref)
		{
			intern	*l = ref._list;

			clear();
			while (l)
			{
				push_back(l->content);
				l = l->next;
			}
			return (*this);
		}

	// ---------------------------------------
	//	Iterateurs
		ListIter<T>		begin()
		{
			ListIter<T>		iter(_list);
			return (iter);
		}

		const_iterator	begin() const
		{
			ListIter<T>		iter(_list);
			return (iter);
		}

		iterator	end()
		{
			ListIter<T>		iter;
			intern	*elem = _list;
			if (_size == 0)
			{
				iter = iterator(_list);
				return (iter);
			}
			while (elem->next)
				elem = elem->next;
			iter = iterator(elem);
			return (iter);
		}

		const_iterator	end() const
		{
			ListIter<T>		iter;
			intern	*elem = _list;
			if (_size == 0)
			{
				iter = iterator(_list);
				return (iter);
			}
			while (elem->next)
				elem = elem->next;
			iter = iterator(elem);
			return (iter);
		}
/*
		reverse_iterator		rbegin()
		{
			intern	*elem = _list;
			if (_size == 0)
				return (reverse_iterator(_list));
			while (elem->next)
				elem = elem->next;
			return (reverse_iterator(elem));
		}

		reverse_iterator		rend()
		{
			return (reverse_iterator(_list));
		}
*/
	// ---------------------------------------
	// 	Capacity
		bool	empty() const
		{
			return (_size == 0);
		}

		size_t	size() const
		{
			return (_size);
		}

		size_t	max_size()
		{
			return (768614336404564650);
		}

	// ---------------------------------------
	//	Element access  										-> SEGFAULT si liste vide ?
		reference			front()
		{
			return (_list->content);
		}

		const_reference		front() const
		{
			return (_list->content);
		}

		reference			back()
		{
			intern		*elem = _list;
			while (elem->next)
				elem = elem->next;
			return (elem->content);
		}

		const_reference			back() const
		{
			intern		*elem = _list;
			while (elem->next)
				elem = elem->next;
			return (elem->content);
		}

	// ---------------------------------------
	//	Modifiers
		void		clear()
		{
			intern *elem = _list;
			intern *tmp;

			while (elem != NULL)
			{
				tmp = elem;
				elem = elem->next;
				delete tmp;
			}
			_list = NULL;
			_size = 0;
		}

		iterator	erase(iterator pos)
		{
			ListIter<T>		iter;
			intern	*elem = pos.get_elem();
			if (elem != NULL)
			{
				if (_size <= 1)
				{
					_size = 0;
					_list = NULL;
					return (iter);
				}
				else if (elem->prev == NULL)
				{
					elem = _list;
					_list = _list->next;
					_list->prev = NULL;
					delete elem;
				}
				else
				{
					elem->prev->next = elem->next;
					if (elem->next)
						elem->next->prev = elem->prev;
					_size--;
					delete elem;
					iter = iterator(elem->next);
					return (iter);
				}
			}
			_size--;
			iter = iterator(_list);
			return (iter);
		}

		iterator	erase(iterator first, iterator last)
		{
			iterator iter = first;
			while (iter != last)
				iter = erase(iter);
			return (iter);
		}

		iterator	insert(iterator position, const value_type &val)
		{
			iterator	iter;
			intern *e = new intern;
			e->content = val;
			intern *pos = position.get_elem();
			intern *prev = pos->prev;
			e->next = pos;
			e->prev = prev;
			prev->next = e;
			pos->prev = e;
			_size++;
			iter = iterator(e);
			return (iter);
		}

		void		insert(iterator pos, size_t n, const value_type &val)
		{
			size_t	i = 0;
			while (i < n)
			{
				insert(pos, val);
				i++;
			}
		}

		void		insert(iterator pos, iterator first, iterator last)
		{
			while (first != last)
			{
				insert(pos, *first);
				first++;
			}
			insert(pos, *first); // -> sur ? tester vrai list 
		}

		void		push_back(const T& val)
		{
			intern	*elem = new intern;
			intern	*ptr = _list;
			elem->content = val;
			elem->next = NULL;
			elem->prev = NULL;
			if ( _size == 0)
				_list = elem;
			else
			{
//				ptr->prev = elem;
				while (ptr->next != NULL)
					ptr = ptr->next;
				ptr->next = elem;
				elem->prev = ptr;
			}
			_size++;
		}

		void		push_front(const T& val)
		{
			intern	*elem = new intern;
			intern	*ptr = _list;
			elem->content = val;
			elem->next = NULL;
			elem->prev = NULL;
			if ( _size == 0)
				_list = elem;
			else
			{
				ptr->prev = elem;
				elem->next = ptr;
//				while (ptr->next != NULL)
//					ptr = ptr->next;
//				elem->prev = ptr
				_list = elem;
			}
			_size++;
		}
		
		void		pop_back()
		{
			iterator iter;
			iter = end();
			erase(iter);
		}

		void		pop_front()
		{
			iterator iter;
			iter = begin();
			erase(iter);
		}

		void		assign(size_t n, const T& val)
		{
			int		i;

			i = 0;
			clear();
			while(i < n)
			{
				push_back(val);	
				i++;
			}
		}

		void		resize(size_t n, T val = T())
		{
			iterator iter;
			iterator iter2;
			iter2 = end();
			if (n < _size)
			{
				iter = begin();
				iter = iter + n - 1;
				erase(iter, iter2);
			}
			else if (n > _size)
				insert(iter2, n, val);
		}

		void		swap(List &x)
		{
			size_t	size = _size;
			intern	*tmp = _list;
			_list = x._list;
			_size = x._size;
			x._list = tmp;
			x._size = size;
		}
/*
		template <class InputIter>
		void		assign(InputIter a, InputIter b)
		{
			clear();
			while (i < n)
			{
				push_back(*a);
				a++;
				i++;
			}
		}
*/
	// ---------------------------------------
	//	Operations

	// ---------------------------------------
	//	Temp
		int			get_size()
		{
			return (_size);
		}

		void		print()
		{
			intern		*tmp = _list;

			while (tmp)
			{
				std::cout << tmp->content << "\n";
				tmp = tmp->next;
			}
		}

	// ---------------------------------------
	//	Variables
		private:
			intern		*_list;
			size_t		_size;

	};
	// ---------------------------------------
	//	Non-member fuction overloads

	// ---------------------------------------
}

#endif
