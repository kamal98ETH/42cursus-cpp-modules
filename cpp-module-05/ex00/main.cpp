/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:23:17 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/03/06 00:38:14 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	std::cout << "	-> unvalid obj with catch exception (too low):" << std::endl;
	try
	{
		Bureaucrat	tooLow("tooLow", 200);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Execption caught: " << e.what() << std::endl;
	}
	
	std::cout << "	-> unvalid obj with catch exception (too high):" << std::endl;
	try
	{
		Bureaucrat	tooHigh("tooHigh", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Execption caught: " << e.what() << std::endl;
	}

	std::cout << "	-> first valid obj (high grade):" << std::endl;
	Bureaucrat	name1("name1", 1);
	std::cout << name1;
	
	std::cout << "	-> second valid obj (low grade):" << std::endl;
	Bureaucrat	name2("name2", 150);
	std::cout << name2;
	
	std::cout << "	-> third valid obj (copy of second obj at construction):" << std::endl;
	Bureaucrat	name3(name2);
	std::cout << name3;
	
	std::cout << "	-> reassign second obj to the first obj:" << std::endl;
	name2 = name1;
	std::cout << name2;

	std::cout << "	-> acceed highest grade:" << std::endl;
	try
	{
		name1.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Execption caught: " << e.what() << std::endl;
	}
	std::cout << "	-> acceed lowest grade:" << std::endl;
	try
	{
		name3.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Execption caught: " << e.what() << std::endl;
	}

	return (0);
}
