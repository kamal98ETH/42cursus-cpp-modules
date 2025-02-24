/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:39:59 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/02/13 18:22:42 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Default constructor of Brain is called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = "[EMPTY]";
	}
}

Brain::Brain(const Brain& other)
{
	std::cout << "Copy constructor of Brain is called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = other.ideas[i];
	}
}

Brain&	Brain::operator=(const Brain& other)
{
	std::cout << "Copy assignment operator of Brain is called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		{
			ideas[i] = other.ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "destructor of Brain is called" << std::endl;
}