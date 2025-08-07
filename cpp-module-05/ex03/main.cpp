/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:23:17 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/08/07 01:12:23 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int	main()
{
	Intern someRandomIntern;
	Bureaucrat	highGrade("King", 1);
	AForm* rrf;
	AForm* ppf;
	AForm* scf;
	AForm* noform;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	ppf = someRandomIntern.makeForm("presidential pardon", "Home");
	scf = someRandomIntern.makeForm("shrubbery creation", "School");
	noform = someRandomIntern.makeForm("no form", "Invalid");
	
	highGrade.signForm(*rrf);
	highGrade.signForm(*ppf);
	highGrade.signForm(*scf);

	highGrade.executeForm(*rrf);
	highGrade.executeForm(*ppf);
	highGrade.executeForm(*scf);

	delete rrf;
	delete ppf;
	delete scf;
	delete noform;
	return (0);
}
