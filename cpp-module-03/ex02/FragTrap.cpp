/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 22:32:46 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/11/28 22:53:00 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "Default constructor of FragTrap is called" << std::endl;
	name = "random";
	hitPts = 100;
	energyPts = 100;
	attackDmg = 30;
}

FragTrap::FragTrap(std::string n)
{
	std::cout << "Secondary constructor of FragTrap is called" << std::endl;
	name = n;
	hitPts = 100;
	energyPts = 100;
	attackDmg = 30;
}

FragTrap::~FragTrap(void)
{
	std::cout << "destructor of FragTrap is called" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (hitPts > 0 && energyPts > 0)
	{
		std::cout 	<< "FragTrap "
					<< name
					<< " attacks "
					<< target
					<< ", causing "
					<< attackDmg
					<< " points of damage!" << std::endl;
		energyPts--;
	}
}

void	FragTrap::takeDamage(unsigned int amount)
{
	std::cout 	<< "FragTrap "
				<< name
				<< " took "
				<< amount
				<< " points of damage!" << std::endl;
	hitPts -= amount;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (hitPts > 0 && energyPts > 0)
	{
		std::cout 	<< "FragTrap "
					<< name
					<< " repaired itself and restored "
					<< amount
					<< " of hit points!" << std::endl;
		hitPts += amount;
		energyPts--;
	}
}

void	FragTrap::highFivesGuys(void)
{
	std::cout 	<< "FragTrap "
				<< name
				<< " : High five time! 🖐️ Come on, don't leave me hanging!" << std::endl;
}
