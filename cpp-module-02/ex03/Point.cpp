/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:13:46 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/02/02 03:59:44 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void)
{
	x.setRawBits(0);
	y.setRawBits(0);
}

Point::Point(const float X, const float Y)
{
	x = Fixed(X);
	y = Fixed(Y);
}

Point::Point(const Point& other)
{
	x = other.x;
	y = other.y;
}

Point& Point::operator=(const Point& other)
{
	if (this != &other)
	{
		x = other.x;
		y = other.y;
	}
	return *this;
}

Point::~Point(void)
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed	Point::getX(void) const
{
	return (x);
}

Fixed	Point::getY(void) const
{
	return (y);
}
