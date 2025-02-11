/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 22:32:46 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/02/10 21:55:41 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "Default constructor of FragTrap is called" << std::endl;
	_name = "random";
	_hitPts = 100;
	_energyPts = 100;
	_attackDmg = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Secondary constructor of FragTrap is called" << std::endl;
	_name = name;
	_hitPts = 100;
	_energyPts = 100;
	_attackDmg = 30;
}


FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "Copy constructor of FragTrap is called" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	std::cout << "Copy assignment operator of FragTrap is called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}


FragTrap::~FragTrap(void)
{
	std::cout << "destructor of FragTrap is called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout 	<< "FragTrap "
				<< _name
				<< " : High five time! 🖐️ Come on, don't leave me hanging!" << std::endl;
}
