/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:48:55 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/05/24 04:02:57 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
	// private:
	// 	/* data */
	public:
		typedef typename Container::iterator iterator;

		// MutantStack(void);
		// ~MutantStack(void);

		iterator	begin();
		iterator	end();
		// class iterator
		// {
		// 	private:
		// 		/* data */
		// 	public:
		// 		iterator();
		// 		~iterator();

		// 		// The 6 comparison operators
		// 		bool	operator>(const iterator& other) const;
		// 		bool	operator<(const iterator& other) const;
		// 		bool	operator>=(const iterator& other) const;
		// 		bool	operator<=(const iterator& other) const;
		// 		bool	operator==(const iterator& other) const;
		// 		bool	operator!=(const iterator& other) const;
		// 		// The 4 arithmetic operators
		// 		iterator	operator+(const iterator& other);
		// 		iterator	operator-(const iterator& other);
		// 		iterator	operator*(const iterator& other);
		// 		iterator	operator/(const iterator& other);
				
		// 		iterator	&operator++(void);
		// 		iterator	operator++(int);
		// 		iterator	&operator--(void);
		// 		iterator	operator--(int);

		// 		T& operator*() const;
		// };
		// MutantStack::iterator	begin(void);
		// MutantStack::iterator	end(void);
};

#include "MutantStack.tpp"

#endif
