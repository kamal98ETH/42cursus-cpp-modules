/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:18:51 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/11/03 02:56:25 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::~HumanB(void)
{
	std::cout << HumanB::name << " is dead" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	HumanB::weapon = &weapon;
	std::cout << "Address in set weapon: " << HumanB::weapon << std::endl;
}


void	HumanB::attack(void)
{
	std::cout << HumanB::name << " attacks with their " << HumanB::weapon->getType() << std::endl;
}
