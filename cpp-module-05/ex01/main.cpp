/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:23:17 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/03/06 00:49:36 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int	main()
{
	std::cout << "	-> Case where everything works:" << std::endl;
	Form	form1("form1", 30, 30);
	std::cout << form1;
	Bureaucrat	bureaucrat("bureaucrat", 10);
	std::cout << bureaucrat;
	bureaucrat.signForm(form1);
	std::cout << form1;
	
	std::cout << "	-> Bureaucrat too low to sign:" << std::endl;
	Form	form2("form2", 9, 9);
	std::cout << form2;
	bureaucrat.signForm(form2);
	std::cout << form2;

	std::cout << "	-> Form too low:" << std::endl;
	try
	{
		Form	tooLow1("tooLow1", 151, 9);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Execption caught: " << e.what() << std::endl;
	}
	try
	{
		Form	tooLow2("tooLow2", 9, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Execption caught: " << e.what() << std::endl;
	}
	try
	{
		Form	tooLow3("tooLow3", 151, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Execption caught: " << e.what() << std::endl;
	}

	std::cout << "	-> Form too high:" << std::endl;
	try
	{
		Form	tooHigh1("tooHigh1", 0, 9);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Execption caught: " << e.what() << std::endl;
	}
	try
	{
		Form	tooHigh2("tooHigh2", 9, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Execption caught: " << e.what() << std::endl;
	}
	try
	{
		Form	tooHigh3("tooHigh3", 0, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Execption caught: " << e.what() << std::endl;
	}

	std::cout << "	-> Sign form with low grade bureaucrat:" << std::endl;
	try
	{
		form2.beSigned(bureaucrat);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Execption caught: " << e.what() << std::endl;
	}

	return (0);
}
