/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:13:49 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/02/02 04:16:10 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	crossProduct(Point const a, Point const b, Point const c)
{
	Fixed	abX = b.getX() - a.getX();
	Fixed	abY = b.getY() - a.getY();
	Fixed	acX = c.getX() - a.getX();
	Fixed	acY = c.getY() - a.getY();

	return ((abX * acY) - (abY * acX));
}

bool	testVector(Point const first, Point const second, Point const point, Fixed const cp)
{
	Fixed	zero(0);
	Fixed	pntCp = crossProduct(first, second, point);

	if (pntCp == zero || (cp > zero && pntCp < zero) || (cp < zero && pntCp > zero))
		return (false);
	return (true);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	zero(0);
	Fixed	pointCp;
	Fixed	cp = crossProduct(a, b, c);
	
	if (cp == zero)
		return (false);
	if (!testVector(a, b, point, cp)
		|| !testVector(b, c, point, cp)
		|| !testVector(c, a, point, cp))
		return (false);
	return (true);
}
