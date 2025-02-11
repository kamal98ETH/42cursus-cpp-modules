/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:02:40 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/02/05 14:36:29 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "Default constructor of ClapTrap is called" << std::endl;
	_name = "random";
	_hitPts = 10;
	_energyPts = 10;
	_attackDmg = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Secondary constructor of ClapTrap is called" << std::endl;
	_name = name;
	_hitPts = 10;
	_energyPts = 10;
	_attackDmg = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy constructor of ClapTrap is called" << std::endl;
	_name = other._name;
	_hitPts = other._hitPts;
	_energyPts = other._energyPts;
	_attackDmg = other._attackDmg;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Copy assignment operator of ClapTrap is called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hitPts = other._hitPts;
		_energyPts = other._energyPts;
		_attackDmg = other._attackDmg;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "destructor of ClapTrap is called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << _name;
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

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout 	<< "ClapTrap " << _name;
	if (_hitPts > 0)
	{
		if (amount > _hitPts)
			amount = _hitPts;
		std::cout 	<< " took "
					<< amount
					<< " points of damage!" << std::endl;
		_hitPts -= amount;
		if (_hitPts == 0)
			std::cout 	<< "ClapTrap "
						<< _name
						<< " is dead 💀!" << std::endl;
	}
	else
		std::cout << " can't take damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << _name;
	if (_hitPts > 0 && _energyPts > 0)
	{
		std::cout 	<< " repaired itself and restored "
					<< amount
					<< " of hit points!" << std::endl;
		_hitPts += amount;
		_energyPts--;
	}
	else
	{
		if (_hitPts == 0)
			std::cout << " can't be repaired because it's dead!" << std::endl;
		else
			std::cout << " can't be repaired because energy points is 0!" << std::endl;
	}
}
