/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:35:53 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/11/15 02:44:07 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->number = 0;
}

Fixed::Fixed(const int intNum)
{
	std::cout << "Int constructor called" << std::endl;
	this->number = intNum << this->numFractBits;
}

Fixed::Fixed(const float floatNum)
{
	std::cout << "Float constructor called" << std::endl;
	this->number = (int)(floatNum * (1 << this->numFractBits) + (floatNum >= 0 ? 0.5 : -0.5));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	number = other.number;
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->number);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->number = raw;
}

int	Fixed::toInt( void ) const
{
	return (this->number >> this->numFractBits);
}

float	Fixed::toFloat( void ) const
{
	return ((float)this->number / (1 << this->numFractBits));
}

std::ostream & operator << (std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
