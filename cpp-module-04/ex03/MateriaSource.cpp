/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:59:19 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/02/23 17:27:13 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other.templates[i])
			templates[i] = other.templates[i]->clone();
		else
			templates[i] = NULL;
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (templates[i])
				delete templates[i];
		}
		for (int i = 0; i < 4; i++)
		{
			if (other.templates[i])
				templates[i] = other.templates[i]->clone();
			else
				templates[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (templates[i])
			delete templates[i];
	}
}

void MateriaSource::learnMateria(AMateria* amateria)
{
	for (int i = 0; i < 4; i++)
	{
		if (templates[i] == NULL)
		{
			templates[i] = amateria;
			return ;
		}
	}
	delete amateria;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (templates[i] && templates[i]->getType() == type)
			return (templates[i]->clone());
	}
	return (0);
}
