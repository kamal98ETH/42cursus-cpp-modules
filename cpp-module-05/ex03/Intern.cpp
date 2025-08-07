/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 01:48:26 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/08/07 01:16:10 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern&	Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

Intern::~Intern(void) {}

AForm*	Intern::makeSC(std::string formTarget)
{
	std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
	return (new ShrubberyCreationForm(formTarget));
}

AForm*	Intern::makeRR(std::string formTarget)
{
	std::cout << "Intern creates RobotomyRequestForm" << std::endl;
	return (new RobotomyRequestForm(formTarget));
}

AForm*	Intern::makePP(std::string formTarget)
{
	std::cout << "Intern creates PresidentialPardonForm" << std::endl;
	return (new PresidentialPardonForm(formTarget));
}


AForm*	Intern::makeForm(std::string formName, std::string formTarget)
{
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*makers[3])(std::string) = {&Intern::makeSC, &Intern::makeRR, &Intern::makePP};
	int	i = 0;
	while (i < 3 && forms[i] != formName)
		i++;
	if (i < 3)
		return ((this->*makers[i])(formTarget));
	std::cerr << "ERROR: Form doesn't exist" << std::endl;
	return (NULL);
}
