/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 01:27:11 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/02/12 03:08:41 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Default constructor of Cat is called" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Copy constructor of Cat is called" << std::endl;
}

Cat&	Cat::operator=(const Cat &other)
{
	std::cout << "Copy assignment operator of Cat is called" << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "destructor of Cat is called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << type << " : meow, meow" << std::endl;
}

