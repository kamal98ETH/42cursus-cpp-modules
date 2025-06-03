/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:34:07 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/05/22 04:36:04 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void)
{
	_max = 0;
}

Span::Span(unsigned int N)
{
	_max = N;
}

Span::~Span()
{
}

void	Span::addNumber(int n)
{
	if (_container.size() == _max)
		throw std::runtime_error("Container full");
	_container.push_back(n);
}

int	 	Span::shortestSpan(void)
{
	if (_container.size() < 2)
		throw std::runtime_error("Invalid number of integers");
	int	span = INT_MAX;
	std::sort(_container.begin(), _container.end());
	for (std::vector<int>::iterator it = _container.begin(); it < _container.end() -1; it++)
	{
		if (*(it +1) - *it < span)
			span = *(it +1) - *it;
	}
	return (span);
}

int		Span::longestSpan(void)
{
	if (_container.size() < 2)
		throw std::runtime_error("Invalid number of integers");
	return (
		*std::max_element(_container.begin(), _container.end()) -
		*std::min_element(_container.begin(), _container.end())
	);
}

