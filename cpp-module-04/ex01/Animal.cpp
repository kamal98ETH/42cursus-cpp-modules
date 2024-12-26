/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 01:01:03 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/12/02 04:27:33 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("Animal")
{
	std::cout << "Default constructor of Animal is called" << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Copy constructor of Animal is called" << std::endl;
}

Animal&	Animal::operator=(const Animal &other)
{
	std::cout << "Copy assignment operator of Animal is called" << std::endl;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "destructor of Animal is called" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (type);
}

void	Animal::makeSound(void) const
{
	std::cout << type << " : (made an animal sound)" << std::endl;
}
