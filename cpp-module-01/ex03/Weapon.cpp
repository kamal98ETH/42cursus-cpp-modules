/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:15:00 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/11/03 01:09:48 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	Weapon::type = type;
}

const std::string&	Weapon::getType(void)
{
	std::string&	strRef = Weapon::type;
	return (strRef);
}

void	Weapon::setType(std::string newType)
{
	Weapon::type = newType;
}
