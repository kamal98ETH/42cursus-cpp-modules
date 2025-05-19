/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:39:17 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/05/16 03:09:40 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	ScalarConverter::convert(const std::string& literal)
{
	char	*end;

	double	number = std::strtod(literal.c_str(), &end);
	if (*end == 'f')
		end++;
	if (*end)
	{
		std::cout << "Invalid number" << std::endl;
		return ;
	}

	std::cout << "char: ";
	if (number > 31.0 && number < 127.0)
		std::cout << "'" << static_cast<char>(number) << "'" << std::endl;
	else if (std::isnan(number))
		std::cout << "impossible" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	std::cout << "int: ";
	if (std::isnan(number) || std::isinf(number))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(number) << std::endl;

	std::cout << "float: ";
	std::cout 	<< std::fixed << std::setprecision(1)
				<< static_cast<float>(number) << "f" << std::endl;


	std::cout << "double: ";
	std::cout 	<< std::fixed << std::setprecision(1)
				<< number << std::endl;
}
