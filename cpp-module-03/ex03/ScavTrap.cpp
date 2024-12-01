/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:47:51 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/11/28 22:29:04 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "Default constructor of ScavTrap is called" << std::endl;
	name = "random";
	hitPts = 100;
	energyPts = 50;
	attackDmg = 20;
}

ScavTrap::ScavTrap(std::string n)
{
	std::cout << "Second constructor of ScavTrap is called" << std::endl;
	name = n;
	hitPts = 100;
	energyPts = 50;
	attackDmg = 20;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "destructor of ScavTrap is called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (hitPts > 0 && energyPts > 0)
	{
		std::cout 	<< "ScavTrap "
					<< name
					<< " attacks "
					<< target
					<< ", causing "
					<< attackDmg
					<< " points of damage!" << std::endl;
		energyPts--;
	}
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	std::cout 	<< "ScavTrap "
				<< name
				<< " took "
				<< amount
				<< " points of damage!" << std::endl;
	hitPts -= amount;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (hitPts > 0 && energyPts > 0)
	{
		std::cout 	<< "ScavTrap "
					<< name
					<< " repaired itself and restored "
					<< amount
					<< " of hit points!" << std::endl;
		hitPts += amount;
		energyPts--;
	}
}

void 	ScavTrap::guardGate(void)
{
	std::cout 	<< "ScavTrap "
				<< name
				<< "  is now in Gate keeper mode!" << std::endl;
}
