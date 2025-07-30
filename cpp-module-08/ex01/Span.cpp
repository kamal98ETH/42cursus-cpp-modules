/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:34:07 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/07/25 22:24:36 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void)
{
	_N = 0;
}

Span::Span(unsigned int N)
{
	_N = N;
}

Span::Span(const Span& other)
{
	_N = other._N;
	_container = other._container;
}

Span&	Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_N = other._N;
		_container = other._container;
	}
	return (*this);
}

Span::~Span() {}

void	Span::addNumber(int n)
{
	if (_container.size() >= _N)
		throw std::runtime_error("Container full");
	_container.push_back(n);
}

int	 	Span::shortestSpan(void)
{
	if (_container.size() < 2)
		throw std::runtime_error("Invalid number of integers");
	std::sort(_container.begin(), _container.end());
	int	span = INT_MAX;
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

