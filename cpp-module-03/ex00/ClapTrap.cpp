/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:02:40 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/11/28 05:59:38 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "Default constructor of ClapTrap is called" << std::endl;
	name = "random";
	hitPts = 10;
	energyPts = 10;
	attackDmg = 0;
}

ClapTrap::ClapTrap(std::string n)
{
	std::cout << "Secondary constructor of ClapTrap is called" << std::endl;
	name = n;
	hitPts = 10;
	energyPts = 10;
	attackDmg = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy constructor of ClapTrap is called" << std::endl;
	this->name = other.name;
	this->hitPts = other.hitPts;
	this->energyPts = other.energyPts;
	this->attackDmg = other.attackDmg;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Copy assignment operator of ClapTrap is called" << std::endl;
	this->name = other.name;
	this->hitPts = other.hitPts;
	this->energyPts = other.energyPts;
	this->attackDmg = other.attackDmg;

	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "destructor of ClapTrap is called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (hitPts > 0 && energyPts > 0)
	{
		std::cout 	<< "ClapTrap "
					<< name
					<< " attacks "
					<< target
					<< ", causing "
					<< attackDmg
					<< " points of damage!" << std::endl;
		energyPts--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout 	<< "ClapTrap "
				<< name
				<< " took "
				<< amount
				<< " points of damage!" << std::endl;
	hitPts -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPts > 0 && energyPts > 0)
	{
		std::cout 	<< "ClapTrap "
					<< name
					<< " repaired itself and restored "
					<< amount
					<< " of hit points!" << std::endl;
		hitPts += amount;
		energyPts--;
	}
}
