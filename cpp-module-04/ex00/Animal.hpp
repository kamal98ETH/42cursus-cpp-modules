/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 01:01:12 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/02/12 03:08:33 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string	type;
	public:
		Animal(void);
		Animal(const Animal &other);
		Animal&	operator=(const Animal &other);
		virtual ~Animal(void);
		
		std::string		getType(void) const;
		virtual void	makeSound(void) const;
};

#endif