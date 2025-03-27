/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:23:17 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/03/27 22:20:21 by kez-zoub         ###   ########.fr       */
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
	ppf = someRandomIntern.makeForm("pr esi dENTIAL Pardon", "Home");
	scf = someRandomIntern.makeForm("shRUbbER YC reation", "School");
	noform = someRandomIntern.makeForm("1shRUbbER YC reation", "Invalid");
	
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
