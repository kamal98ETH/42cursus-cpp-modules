/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 23:02:06 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/12/02 00:33:10 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	std::cout << "Default constructor of DiamondTrap is called" << std::endl;
	name = "random";
	ClapTrap::name = name + "_clap_name";
	hitPts = FragTrap::hitPts;
	energyPts = ScavTrap::energyPts;
	attackDmg = FragTrap::attackDmg;
}

DiamondTrap::DiamondTrap(std::string n)
{
	std::cout << "Second constructor of DiamondTrap is called" << std::endl;
	name = n;
	ClapTrap::name = name + "_clap_name";
	hitPts = FragTrap::hitPts;
	energyPts = ScavTrap::energyPts;
	attackDmg = FragTrap::attackDmg;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "destructor of DiamondTrap is called" << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	std::cout 	<< "DiamondTrap "
				<< name
				<< " took "
				<< amount
				<< " points of damage!" << std::endl;
	hitPts -= amount;
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	if (hitPts > 0 && energyPts > 0)
	{
		std::cout 	<< "DiamondTrap "
					<< name
					<< " repaired itself and restored "
					<< amount
					<< " of hit points!" << std::endl;
		hitPts += amount;
		energyPts--;
	}
}

void	DiamondTrap::whoAmI(void)
{
	std::cout 	<< "DiamondTrap name is : "
				<< name
				<< " and ClapTrap name is : "
				<< ClapTrap::name
				<< std::endl;
}
