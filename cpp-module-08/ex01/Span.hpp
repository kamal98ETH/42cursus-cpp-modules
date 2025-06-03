/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:34:17 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/05/23 19:40:42 by kez-zoub         ###   ########.fr       */
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
		unsigned int		_max;
		std::vector<int>	_container;
	public:
		Span(void);
		Span(unsigned int N);
		~Span();

		void	addNumber(int n);
		template <typename T> void	addManyNumbers(T first, T last)	
		{
			std::vector<int>	tmp(first, last);
			if (_container.size() + (last - first) > _max)
				throw std::runtime_error("Container full");
			_container.insert(_container.end(), tmp.begin(), tmp.end());
		};
		int	 	shortestSpan(void);
		int		longestSpan(void);
};

#endif
