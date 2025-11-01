/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:39:17 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/08/07 02:22:53 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter(void) {}

t_type	ScalarConverter::get_type(const std::string& literal)
{
	if (!literal.size())
		return (NONE);
	if (literal == "nan" || literal == "nanf" || literal == "inf" || literal == "inff" || literal == "+inf" || literal == "-inf" || literal == "+inff" || literal == "-inff")
		return (FLOAT);
	if (literal.size() == 1 && !std::isdigit(literal[0]))
		return (CHAR);
	std::string::const_iterator	it = literal.begin();
	if (it != literal.end() && (*it == '-' || *it == '+'))
		it++;
	while (it != literal.end() && std::isdigit(*it))
		it++;
	if (it == literal.end())
		return (INT);
	if (*it == '.')
	{
		it++;
		while (it != literal.end() && std::isdigit(*it))
			it++;
		if (*(it -1) == '.' && (it -1 == literal.begin() || !std::isdigit(*(it -2))))
			return (NONE);
		if (it == literal.end())
			return (DOUBLE);
		if (*it == 'f')
			it++;
	}
	else if (*it == 'e' || *it == 'E')
	{
		if (it == literal.begin() || !std::isdigit(*(it -1)))
			return (NONE);
		it++;
		if (it != literal.end() && (*it == '+' || *it == '-'))
			it++;
		while (it != literal.end() && std::isdigit(*it))
			it++;
		if (it != literal.end() && !std::isdigit(*(it -1)))
			return (NONE);
	}
	if (it == literal.end())
		return (FLOAT);
	return (NONE);
}

void	ScalarConverter::handle_char(const std::string& literal, char &c, int &i, float &f, double &d)
{
	c = static_cast<char>(literal[0]);
	i = static_cast<int>(c);
	f = static_cast<float>(c);
	d = static_cast<double>(c);
}

void	ScalarConverter::handle_int(const std::string& literal, char &c, int &i, float &f, double &d)
{
	i = std::atoi(literal.c_str());
	c = static_cast<char>(i);
	f = static_cast<float>(i);
	d = static_cast<double>(i);
}
void	ScalarConverter::handle_float(const std::string& literal, char &c, int &i, float &f, double &d)
{
	f = std::atof(literal.c_str());
	c = static_cast<char>(f);
	i = static_cast<int>(f);
	d = static_cast<double>(f);
}
void	ScalarConverter::handle_double(const std::string& literal, char &c, int &i, float &f, double &d)
{
	d = std::atof(literal.c_str());
	c = static_cast<char>(d);
	i = static_cast<int>(d);
	f = static_cast<float>(d);
}

void	ScalarConverter::convert(const std::string& literal)
{
	t_type	t = get_type(literal);

	char	c;
	int		i;
	float	f;
	double	d;
	switch (t)
	{
		case NONE:
			std::cout << "Invalid number" << std::endl;
			return ;
		case CHAR:
			handle_char(literal, c, i, f, d);
			break;
		case INT:
			handle_int(literal, c, i, f, d);
			break;
		case FLOAT:
			handle_float(literal, c, i, f, d);
			break;
		case DOUBLE:
			handle_double(literal, c, i, f, d);
			break;
	}

	std::cout << "char: ";
	if (d > 31.0 && d < 127.0)
		std::cout << "'" << c << "'" << std::endl;
	else if (std::isnan(d) || std::isinf(d))
		std::cout << "impossible" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	std::cout << "int: ";
	if (std::isnan(d) || std::isinf(d) || d > INT_MAX || d < INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << i << std::endl;

	std::cout << "float: ";
	std::cout 	<< std::fixed << std::setprecision(1)
				<< f << "f" << std::endl;

	std::cout << "double: ";
	std::cout 	<< std::fixed << std::setprecision(1)
				<< d << std::endl;
}
