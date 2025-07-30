/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:34:17 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/07/25 22:53:33 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <stdexcept>
# include <climits>

class Span
{
	private:
		unsigned int		_N;
		std::vector<int>	_container;
	public:
		Span(void);
		Span(unsigned int N);
		Span(const Span& other);
		Span&	operator=(const Span& other);
		~Span();

		void	addNumber(int n);
		template <typename T>
		void	addManyNumbers(T first, T last)	
		{
			std::vector<int>	tmp(first, last);
			if (_container.size() + tmp.size() > _N)
				throw std::runtime_error("Container full");
			_container.insert(_container.end(), tmp.begin(), tmp.end());
		};
		int	 	shortestSpan(void);
		int		longestSpan(void);
};

#endif
