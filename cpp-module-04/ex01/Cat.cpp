/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 01:27:11 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/12/02 20:50:20 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Default constructor of Cat is called" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &other)
{
	std::cout << "Copy constructor of Cat is called" << std::endl;
}

Cat&	Cat::operator=(const Cat &other)
{
	std::cout << "Copy assignment operator of Cat is called" << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "destructor of Cat is called" << std::endl;
	delete brain;
}

void	Cat::makeSound(void) const
{
	std::cout << type << " : meow, meow" << std::endl;
}

