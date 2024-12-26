/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:56:35 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/12/19 16:34:31 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
	name = "character";
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
	
}

Character::Character(std::string n)
{
	name = n;
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
	
}

std::string const & Character::getName(void) const
{
	return (name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx <= 0 && idx < 4 && inventory[idx])
		inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx <= 0 && idx < 4 && inventory[idx])
	{
		inventory[idx]->use(target);
	}
}

