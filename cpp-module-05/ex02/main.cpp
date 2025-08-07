/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:23:17 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/08/07 00:53:11 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	testCases(AForm *sign, AForm* noSign, Bureaucrat B1, Bureaucrat B2, Bureaucrat B3)
{
	std::cout << "		* Sign with first bureaurat" << std::endl;
	B1.signForm(*sign);

	std::cout << "		* Sign with second bureaurat" << std::endl;
	B2.signForm(*sign);

	std::cout << "		* execute signed form with high grade bureaucrat" << std::endl;
	B3.executeForm(*sign);

	std::cout << "		* execute signed form with not a high enough grade bureaucrat" << std::endl;
	B1.executeForm(*sign);
	B2.executeForm(*sign);
	
	std::cout << "		* execute unsigned form with high grade bureaucrat" << std::endl;
	B3.executeForm(*noSign);
}

int	main()
{
	// for each form create bureaucrats (can signe and execute, can only sign, can only execute, can't do anything)
	// create 2 forms sign one and leave the other
	// try to execute the 2 forms with each bureaucrat

	AForm	*SCsign = new ShrubberyCreationForm("SCsigned");
	AForm	*SCnoSign = new ShrubberyCreationForm("SCnotSigned");

	AForm	*RRsign = new RobotomyRequestForm("RRsigned");
	AForm	*RRnoSign = new RobotomyRequestForm("RRnotSigned");

	AForm	*PPsign = new PresidentialPardonForm("PPsigned");
	AForm	*PPnoSign = new PresidentialPardonForm("PPnotSigned");

	std::cout << "	-> For ShrubberyCreationForm:" << std::endl;
	Bureaucrat	SC1("SC1", 146); // cant do anything
	Bureaucrat	SC2("SC2", 138); // can only sign
	Bureaucrat	SC3("SC3", 137); // can do everything
	testCases(SCsign, SCnoSign, SC1, SC2, SC3);
	
	std::cout << "	-> For RobotomyRequestForm:" << std::endl;
	Bureaucrat	RR1("RR1", 73); // cant do anything
	Bureaucrat	RR2("RR2", 46); // can only sign
	Bureaucrat	RR3("RR3", 45); // can do everything
	testCases(RRsign, RRnoSign, RR1, RR2, RR3);

	std::cout << "	-> For PresidentialPardonForm:" << std::endl;
	Bureaucrat	PP1("PP1", 26); // cant do anything
	Bureaucrat	PP2("PP2", 6); // can only sign
	Bureaucrat	PP3("PP3", 5); // can do everything
	testCases(PPsign, PPnoSign, PP1, PP2, PP3);

	delete SCsign;
	delete SCnoSign;
	delete RRsign;
	delete RRnoSign;
	delete PPsign;
	delete PPnoSign;
	
	return (0);
}
