/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 07:27:02 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/11/14 20:48:54 by kez-zoub         ###   ########.fr       */
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
		Fixed(const Fixed& other);  // Copy constructor
		Fixed& operator=(const Fixed& other);  // Assignment operator
		~Fixed(void);  // Destructor
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif
