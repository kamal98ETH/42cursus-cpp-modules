/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 06:20:24 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/07/16 02:18:59 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequest", 72, 45), target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequest", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	(void)other;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

void	RobotomyRequestForm::action(void) const
{
	std::srand(std::time(0));
	std::cout << "ddgg ddgg ddgg\n99ff 99ff 99ff\nnnnnyewwwwwww" << std::endl;
	if (std::rand() % 2)
		std::cout << target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "The robotomy failed successfully" << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	canExecute(executor);
	action();
}
