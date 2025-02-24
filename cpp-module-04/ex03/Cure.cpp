/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:05:29 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/02/23 02:13:42 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void)
{
	type = "cure";
}

Cure::Cure(const Cure& other) : AMateria(other) {}

Cure&	Cure::operator=(const Cure& other)
{
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

Cure::~Cure(void) {}

AMateria*	Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
