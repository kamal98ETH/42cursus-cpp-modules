/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:39:17 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/07/17 21:10:52 by kez-zoub         ###   ########.fr       */
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
	if (literal == "nan")
		return (FLOAT);
	if (literal.size() == 1 && !std::isdigit(literal[0]))
		return (CHAR);
	std::string::const_iterator	it = literal.begin();
	if (*it == '-' || *it == '+')
		it++;
	while (std::isdigit(*it))
		it++;
	if (it == literal.end())
		return (INT);
	if (*it == '.')
	{
		it++;
		while (std::isdigit(*it))
			it++;
		if (it == literal.end())
			return (DOUBLE);
		if (*it == 'f')
			it++;
	}
	if (it == literal.end())
		return (FLOAT);
	return (NONE);
}

void	ScalarConverter::handle_char(const std::string& literal, char &c, int &i, float &f, double &d)
{
	// convert it from string to its actual type
	c = static_cast<char>(literal[0]);
	// then convert it explicitly to the three other data types
	i = static_cast<int>(c);
	f = static_cast<float>(c);
	d = static_cast<double>(c);
}

void	ScalarConverter::handle_int(const std::string& literal, char &c, int &i, float &f, double &d)
{
	// convert it from string to its actual type
	i = std::atoi(literal.c_str());
	// then convert it explicitly to the three other data types
	c = static_cast<char>(i);
	f = static_cast<float>(i);
	d = static_cast<double>(i);
}
void	ScalarConverter::handle_float(const std::string& literal, char &c, int &i, float &f, double &d)
{
	// convert it from string to its actual type
	f = std::atof(literal.c_str());
	// then convert it explicitly to the three other data types
	c = static_cast<char>(f);
	i = static_cast<int>(f);
	d = static_cast<double>(f);
}
void	ScalarConverter::handle_double(const std::string& literal, char &c, int &i, float &f, double &d)
{
	// convert it from string to its actual type
	d = std::atof(literal.c_str());
	// then convert it explicitly to the three other data types
	c = static_cast<char>(d);
	i = static_cast<int>(d);
	f = static_cast<float>(d);
}

void	ScalarConverter::convert(const std::string& literal)
{
	// You have to first detect the type of the literal passed as parameter
	t_type	t = get_type(literal);
	if (t == NONE)
	{
		std::cout << "Invalid number" << std::endl;
		return ;
	}
	char	c;
	int		i;
	float	f;
	double	d;
	switch (t)
	{
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

	// Lastly, display the results as shown below.
	std::cout << "char: ";
	if (d > 31.0 && d < 127.0)
		std::cout << "'" << c << "'" << std::endl;
	else if (std::isnan(d))
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
