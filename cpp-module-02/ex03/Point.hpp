/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:13:44 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/11/17 04:21:33 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	Fixed	x;
	Fixed	y;
public:
	Point(void);  // Default constructor
	Point(const float X, const float Y);  // secondary constructor
	Point(const Point& other);  // Copy constructor
	Point& operator=(const Point& other);  // Assignment operator
	~Point(void);  // Destructor
	Fixed	getX(void) const;
	Fixed	getY(void) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif