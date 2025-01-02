/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:18:51 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/01/02 01:30:48 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) {};

HumanB::~HumanB(void)
{
	std::cout << HumanB::name << " is dead" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	HumanB::weapon = &weapon;
}

void	HumanB::attack(void)
{
	std::cout << HumanB::name << " attacks with their " << HumanB::weapon->getType() << std::endl;
}
