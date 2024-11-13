/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:18:16 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/11/03 01:43:41 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"


void	HumanA::attack(void)
{
	std::cout << HumanA::name << " attacks with their " << HumanA::weapon.getType() << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << HumanA::name << " is dead" << std::endl;
}
