/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 06:20:17 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/03/22 07:02:44 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Default", 25, 5), target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) {}
PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	(void)other;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

void	PresidentialPardonForm::action(void) const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	canExecute(executor);
	action();
}
