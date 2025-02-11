/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:47:51 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/02/10 21:22:25 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "Default constructor of ScavTrap is called" << std::endl;
	_name = "random";
	_hitPts = 100;
	_energyPts = 50;
	_attackDmg = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Secondary constructor of ScavTrap is called" << std::endl;
	_name = name;
	_hitPts = 100;
	_energyPts = 50;
	_attackDmg = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "Copy constructor of ScavTrap is called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "Copy assignment operator of ScavTrap is called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "destructor of ScavTrap is called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	std::cout << "ScavTrap " << _name;
	if (_hitPts > 0 && _energyPts > 0)
	{
		std::cout 	<< " attacks "
					<< target
					<< ", causing "
					<< _attackDmg
					<< " points of damage!" << std::endl;
		_energyPts--;
	}
	else
	{
		if (_hitPts == 0)
			std::cout << " can't attack because it's dead!" << std::endl;
		else
			std::cout << " can't attack because energy points is 0!" << std::endl;
	}
}

void 	ScavTrap::guardGate(void)
{
	std::cout 	<< "ScavTrap "
				<< _name
				<< " is now in Gate keeper mode!" << std::endl;
}
