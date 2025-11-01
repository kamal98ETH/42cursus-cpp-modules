/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:36:55 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/09/20 23:00:45 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(const RPN& other)
{
	_s = other._s;
}

RPN&	RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		_s = other._s;
	}
	return (*this);
}

RPN::~RPN(void) {}

int	calculate(char op, int i1, int i2)
{
	switch (op)
	{
		case '*':
			return (i1 * i2);
		case '/':
			return (i1 / i2);
		case '-':
			return (i1 - i2);
		default:
			return (i1 + i2);
	}
}

void	RPN::add(char c)
{
	if (c >= '0' && c <= '9')
		_s.push(c - '0');
	else
	{
		if (_s.size() >= 2)
		{
			int	i1 = _s.top();
			_s.pop();
			int	i2 = _s.top();
			_s.pop();
			_s.push(calculate(c, i2, i1));
		}
	}
}

int		RPN::result(void) const
{
	if (_s.size())
		return (_s.top());
	return (0);
}
