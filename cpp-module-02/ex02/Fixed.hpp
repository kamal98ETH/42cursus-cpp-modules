/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 02:56:47 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/11/16 03:08:39 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					number;
		static const int	numFractBits = 8;	
	public:
		Fixed(void);  // Default constructor
		Fixed(const int intNum);
		Fixed(const float floatNum);
		Fixed(const Fixed& other);  // Copy constructor
		Fixed& operator=(const Fixed& other);  // Assignment operator
		~Fixed(void);  // Destructor
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int 	toInt( void ) const;
		// for cout
		friend std::ostream& operator << (std::ostream &out, const Fixed &fixed);
		// The 6 comparison operators
		bool	operator>(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;
		// The 4 arithmetic operators
		Fixed	operator+(const Fixed& other);
		Fixed	operator-(const Fixed& other);
		Fixed	operator*(const Fixed& other);
		Fixed	operator/(const Fixed& other);
		// The 4 increment/decrement
		Fixed	&operator++(void); // Pre-increment
		Fixed	operator++(int); // Post-increment
		Fixed	&operator--(void); // Pre-decrement
		Fixed	operator--(int); // Post-decrement
		// The 4 max/min getters
		static Fixed&	min(Fixed& a, Fixed& b);
		static Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&	max(Fixed& a, Fixed& b);
		static Fixed&	max(const Fixed& a, const Fixed& b);
};

#endif
