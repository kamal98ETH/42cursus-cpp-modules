/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:13:49 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/11/17 05:52:12 by kez-zoub         ###   ########.fr       */
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

	if (pntCp == zero)
		return (false);
	if ((cp > 0 && pntCp < 0) || (cp < 0 && pntCp > 0))
		return (false);
	return (true);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	// Create two vectors:
		// Vector AB: This is the vector from point A to point B.   
		// Vector AC: This is the vector from point A to point C
	// Calculate the cross product of AB and AC:
		// CrossProduct(AB, AC) = (AB_x * AC_y) - (AB_y * AC_x)
	// Interpreting the Result:
		// If the cross product is positive, point C is to the left of the line AB.
		// If the cross product is negative, point C is to the right of the line AB.
		// If the cross product is zero, point C lies on the line AB.
			// Betweenness: if C lies on the line AB Point C must lie between points A and B. We can check this by comparing the distances between the points:
				// Calculate the distances AC, BC, and AB.
					// distance_AB = math.sqrt((B[0] - A[0])**2 + (B[1] - A[1])**2)
					// meaning: dist AB = sqrt((xb - xa)^2 + (yb - ya)^2)
				// If AC + BC = AB, then C lies between A and B
					// if this is the case the point is on the edge of the triangle then no need to do more
	
	// depending on the side we found the point on we need to find it on the same side on all the other vectors or on the edge of one of them

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
