/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 01:48:26 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/07/16 02:12:14 by kez-zoub         ###   ########.fr       */
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

bool	strMatch(std::string str1, std::string str2)
{
	std::string	newStr2;

	for (size_t i = 0; i < str2.size(); i++)
	{
		if (!std::isspace(str2[i]))
			newStr2 += std::tolower(str2[i]);
	}
	return (str1 == newStr2);
}

AForm*	Intern::makeForm(std::string formName, std::string formTarget)
{
	std::string forms[3] = {"shrubberycreation", "robotomyrequest", "presidentialpardon"};
	int	i = 0;
	while (i < 3 && !strMatch(forms[i], formName))
		i++;
	switch (i)
	{
		case 0:
			std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
			return (new ShrubberyCreationForm(formTarget));
		case 1:
			std::cout << "Intern creates RobotomyRequestForm" << std::endl;
			return (new RobotomyRequestForm(formTarget));
		case 2:
			std::cout << "Intern creates PresidentialPardonForm" << std::endl;
			return (new PresidentialPardonForm(formTarget));
		default:
			std::cerr << "ERROR: Form doesn't exist" << std::endl;
	}
	return (NULL);
}
