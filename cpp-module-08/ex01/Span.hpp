/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:34:17 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/08/08 01:05:34 by kez-zoub         ###   ########.fr       */
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
		void	addManyNumbers(std::vector<int>::iterator first, std::vector<int>::iterator last);
		int	 	shortestSpan(void);
		int		longestSpan(void);
};

#endif
