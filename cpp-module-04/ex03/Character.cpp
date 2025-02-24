/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:56:35 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/02/23 18:44:26 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : name("character"), totalArchive(0), archive(NULL)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(std::string n) : name(n), totalArchive(0), archive(NULL)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character& other) : name(other.name), totalArchive(0), archive(NULL)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
		{
			inventory[i] = other.inventory[i]->clone();
			addArchive(inventory[i]);
		}
		else
			inventory[i] = NULL;
	}
}

Character&	Character::operator=(const Character& other)
{
	if (this != &other)
	{
		cleanArchive();
		name = other.name;
		archive = NULL;
		totalArchive = 0;
		for (int i = 0; i < 4; i++)
		{
			if (other.inventory[i])
			{
				inventory[i] = other.inventory[i]->clone();
				addArchive(inventory[i]);
			}
		}
	}
	return (*this);
}

Character::~Character(void)
{
	cleanArchive();
}


std::string const &	Character::getName(void) const
{
	return (name);
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			break ;
		}
	}
	addArchive(m);
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && inventory[idx])
		inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && inventory[idx])
		inventory[idx]->use(target);
}

void	Character::addArchive(AMateria *amateria)
{
	AMateria**	newArchive = new (std::nothrow) AMateria*[totalArchive +1];
	if (newArchive == NULL)
	{
		delete amateria;
		cleanArchive();
		exit(1);
	}
	for (int i = 0; i < totalArchive; i++)
		newArchive[i] = archive[i];
	newArchive[totalArchive] = amateria;
	totalArchive++;
	delete[] archive;
	archive = newArchive;
}

void	Character::cleanArchive(void)
{
	for (int i = 0; i < totalArchive; i++)
		delete archive[i];
	if (archive)
		delete[] archive;
}
