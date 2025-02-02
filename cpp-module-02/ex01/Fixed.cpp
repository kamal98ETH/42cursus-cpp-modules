/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:35:53 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/02/02 14:34:40 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fracBits = 8;

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const int intNum)
{
	std::cout << "Int constructor called" << std::endl;
	_value = intNum << _fracBits;
}

Fixed::Fixed(const float floatNum)
{
	std::cout << "Float constructor called" << std::endl;
	_value = (int)(roundf(floatNum * (1 << _fracBits)));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	_value = other._value;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_value = other._value;
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

int	Fixed::toInt( void ) const
{
	return (_value >> _fracBits);
}

float	Fixed::toFloat( void ) const
{
	return ((float)_value / (1 << _fracBits));
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
