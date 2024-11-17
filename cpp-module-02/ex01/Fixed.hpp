/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:35:57 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/11/15 01:47:18 by kez-zoub         ###   ########.fr       */
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
		friend std::ostream& operator << (std::ostream &out, const Fixed &fixed);
};

#endif
