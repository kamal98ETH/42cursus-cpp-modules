/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:18:16 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/01/02 00:44:41 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {}

void	HumanA::attack(void)
{
	std::cout << HumanA::name << " attacks with their " << HumanA::weapon.getType() << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << HumanA::name << " is dead" << std::endl;
}
