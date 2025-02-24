/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:24:37 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/02/23 02:08:46 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : type("AMateria") {}

AMateria::AMateria(std::string const & t) : type(t) {}

AMateria::AMateria(const AMateria& other) : type(other.type) {}

AMateria&	AMateria::operator=(const AMateria& other)
{
	if (this != &other)
		type = other.type;
	return (*this);
}

AMateria::~AMateria(void) {}

std::string const & AMateria::getType() const
{
	return (type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* used amateria action at " << target.getName() << " *" << std::endl;
}
