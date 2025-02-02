/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 02:56:44 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/02/02 14:35:13 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fracBits = 8;

Fixed::Fixed(void)
{
	// std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const int intNum)
{
	// std::cout << "Int constructor called" << std::endl;
	_value = intNum << _fracBits;
}

Fixed::Fixed(const float floatNum)
{
	// std::cout << "Float constructor called" << std::endl;
	_value = (int)(roundf(floatNum * (1 << _fracBits)));
}

Fixed::Fixed(const Fixed& other)
{
	// std::cout << "Copy constructor called" << std::endl;
	_value = other._value;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_value = other._value;
	return *this;
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits( int const raw )
{
	// std::cout << "setRawBits member function called" << std::endl;
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

// The 6 comparison operators
bool	Fixed::operator>(const Fixed& other) const
{
	return (_value > other._value);
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (_value < other._value);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (_value >= other._value);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (_value <= other._value);
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (_value == other._value);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (_value != other._value);
}

// The 4 arithmetic operators
Fixed	Fixed::operator+(const Fixed &other)
{
	Fixed	result;
	
	result.setRawBits(_value + other._value);
	return result;
}

Fixed	Fixed::operator-(const Fixed &other)
{
	Fixed	result;
	
	result.setRawBits(_value - other._value);
	return result;
}

Fixed	Fixed::operator*(const Fixed &other)
{
	Fixed	result;

	result.setRawBits((long long)_value * other._value >> _fracBits);
	return result;
}

Fixed	Fixed::operator/(const Fixed &other)
{
	Fixed	result;

	result.setRawBits(((long long)_value << _fracBits) / other._value);
	return result;
}

// The 4 increment/decrement
Fixed&	Fixed::operator++(void)
{
	_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	_value++;
	return (tmp);
}

Fixed&	Fixed::operator--(void)
{
	_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;
	_value--;
	return (tmp);
}

// The 4 max/min getters
Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a <= b)
		return (a);
	return (b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a <= b)
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a >= b)
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a >= b)
		return (a);
	return (b);
}
