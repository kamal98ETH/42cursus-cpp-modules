/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 04:30:37 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/02/11 22:36:30 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "Default constructor of WrongCat is called" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "Copy constructor of WrongCat is called" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat &other)
{
	std::cout << "Copy assignment operator of WrongCat is called" << std::endl;
	if (this != &other)
		WrongAnimal::operator=(other);
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "destructor of WrongCat is called" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << type << " : not a meow meow" << std::endl;
}