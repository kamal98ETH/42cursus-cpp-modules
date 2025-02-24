/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 01:06:18 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/02/13 18:25:56 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Default constructor of Dog is called" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Copy constructor of Dog is called" << std::endl;
}

Dog&	Dog::operator=(const Dog &other)
{
	std::cout << "Copy assignment operator of Dog is called" << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "destructor of Dog is called" << std::endl;
	delete brain;
}

void	Dog::makeSound(void) const
{
	std::cout << type << " : woof, woof" << std::endl;
}
