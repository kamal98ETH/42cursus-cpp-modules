/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 02:56:44 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/11/16 03:09:02 by kez-zoub         ###   ########.fr       */
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

// for cout
std::ostream & operator << (std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}

// The 6 comparison operators
bool	Fixed::operator>(const Fixed& other) const
{
	return (this->number > other.number);
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->number < other.number);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->number >= other.number);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->number <= other.number);
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->number == other.number);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->number != other.number);
}

// The 4 arithmetic operators
Fixed	Fixed::operator+(const Fixed &other)
{
	Fixed	result;
	
	result.setRawBits(this->number + other.number);
	return result;
}

Fixed	Fixed::operator-(const Fixed &other)
{
	Fixed	result;
	
	result.setRawBits(this->number - other.number);
	return result;
}

Fixed	Fixed::operator*(const Fixed &other)
{
	Fixed	result;

	long long	res = (long long)this->number * (long long)other.number;
	result.setRawBits((int)(res >> this->numFractBits));
	return result;
}

Fixed	Fixed::operator/(const Fixed &other)
{
	Fixed	result;

	result.setRawBits(((this->number << this->numFractBits) / other.number));
	return result;
}

// The 4 increment/decrement
Fixed&	Fixed::operator++(void)
{
	this->number++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	this->number++;
	return (tmp);
}

Fixed&	Fixed::operator--(void)
{
	this->number--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;
	this->number--;
	return (tmp);
}

// The 4 max/min getters
Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a <= b)
		return (a);
	return (b);
}

Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a <= b)
		return ((Fixed &)a);
	return ((Fixed &)b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a >= b)
		return (a);
	return (b);
}

Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a >= b)
		return ((Fixed &)a);
	return ((Fixed &)b);
}
