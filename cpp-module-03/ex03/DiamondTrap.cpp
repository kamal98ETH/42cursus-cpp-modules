/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 23:02:06 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/02/11 03:48:23 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	std::cout << "Default constructor of DiamondTrap is called" << std::endl;
	_name = "random";
	ClapTrap::_name = "random_clap_name";
	_hitPts = 100;
	_energyPts = 50;
	_attackDmg = 30;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	std::cout << "Secondary constructor of DiamondTrap is called" << std::endl;
	_name = name;
	ClapTrap::_name = name + "_clap_name";
	_hitPts = 100;
	_energyPts = 50;
	_attackDmg = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "Copy constructor of DiamondTrap is called" << std::endl;
	_name = other._name;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "Copy assignment operator of DiamondTrap is called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		_name = other._name;
	}
	return (*this);
}


DiamondTrap::~DiamondTrap(void)
{
	std::cout << "destructor of DiamondTrap is called" << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout 	<< "DiamondTrap name is : "
				<< _name
				<< " and ClapTrap name is : "
				<< ClapTrap::_name
				<< std::endl;
}
