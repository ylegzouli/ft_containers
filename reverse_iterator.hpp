#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace ft
{

	template <typename IteratorType>
	class reverse_iterator
	{
		typedef typename IteratorType::value_type value_type;
		typedef typename IteratorType::pointer pointer;
		typedef typename IteratorType::reference reference;
		private:
			IteratorType it;

		public:
			reverse_iterator(){}
			reverse_iterator(IteratorType it2): it(it2) {}
			reverse_iterator(const reverse_iterator& a): it(a.it) {}
			~reverse_iterator() {}
			reverse_iterator &operator=(const reverse_iterator& c) {it = c.it; return *this;}
			bool operator==(const reverse_iterator& a) const {return it == a.it;}
			bool operator!=(const reverse_iterator& a) const {return it != a.it;}
			bool operator<(const reverse_iterator& a) const {return it > a.it;}
			bool operator>(const reverse_iterator& a) const {return it < a.it;}
			bool operator<=(const reverse_iterator& a) const {return it >= a.it;}
			bool operator>=(const reverse_iterator& a) const {return it <= a.it;}
			reference operator*() const {return (*it);}
			pointer operator->() const { return it.operator->(); }
			reverse_iterator& operator++() {--it; return *this;}
			reverse_iterator operator++(int input) 
			{
				(void) input;
				reverse_iterator it2(it--);
				return it2;
			}
			reverse_iterator& operator--() { ++it; return *this; }
			reverse_iterator operator--(int input)
			{
				(void)input;
				reverse_iterator it2(it++);
				return it2;
			}
/*			reverse_iterator operator+(int n)
			{
				return reverse_iterator( IteratorType (it - n) );
			}
			reverse_iterator operator-(int n) 
			{
				return reverse_iterator( IteratorType (it + n) );
			}*/
	};
}

#endif
