/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 01:06:18 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/12/02 20:51:01 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Default constructor of Dog is called" << std::endl;
	// type = "Dog";
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &other)
{
	std::cout << "Copy constructor of Dog is called" << std::endl;
}

Dog&	Dog::operator=(const Dog &other)
{
	std::cout << "Copy assignment operator of Dog is called" << std::endl;
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
