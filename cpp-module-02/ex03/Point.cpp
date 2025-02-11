/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:13:46 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/02/04 00:57:40 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void)
{
	_x.setRawBits(0);
	_y.setRawBits(0);
}

Point::Point(const float x, const float y)
{
	_x = Fixed(x);
	_y = Fixed(y);
}

Point::Point(const Point& other)
{
	_x = other._x;
	_y = other._y;
}

Point& Point::operator=(const Point& other)
{
	if (this != &other)
	{
		_x = other._x;
		_y = other._y;
	}
	return *this;
}

Point::~Point(void)
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed	Point::getX(void) const
{
	return (_x);
}

Fixed	Point::getY(void) const
{
	return (_y);
}
