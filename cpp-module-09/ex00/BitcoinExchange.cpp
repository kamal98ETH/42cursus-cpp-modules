/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:57:17 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/09/20 22:37:44 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool	BitcoinExchange::digit(std::string str)
{
	for (std::string::iterator it = str.begin(); it != str.end(); it++)
	{
		if (!std::isdigit(*it))
			return (false);
	}
	return (true);
}

bool	BitcoinExchange::valideDate(std::string date)
{
	if (date.size() != 10)
		return (false);
	std::string	s_year = std::string(date.begin(), date.begin() + 4);
	if (date[4] != '-')
		return (false);
	std::string	s_month = std::string(date.begin() +5, date.begin() + 7);
	if (date[7] != '-')
		return (false);
	std::string	s_day = std::string(date.begin() +8, date.end());
	if (!digit(s_year) || !digit(s_month) || !digit(s_day))
		return (false);
	int	year = std::atoi(s_year.c_str());
	int	month = std::atoi(s_month.c_str());
	int	day = std::atoi(s_day.c_str());
	int	max_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if (!(year % 4))
		max_month[1] = 29;
	if (month > 12 || day > max_month[month -1])
		return (false);
    return (true);
}

double	BitcoinExchange::ft_stod(std::string s_price)
{
	std::string::iterator i = s_price.begin();
	if (*i == '+' || *i == '-')
		i++;
	if (i == s_price.end() || (s_price.size() == 1 && (*i) == '.'))
		throw std::runtime_error("Invalid price");
	for (; i != s_price.end(); i++)
	{
		if (*i == '.')
		{
			i++;
			break;
		}
		else if (!std::isdigit(*i))
			throw std::runtime_error("Invalid price");
	}
	for (; i != s_price.end(); i++)
	{
		if (!std::isdigit(*i))
			throw std::runtime_error("Invalid price");
	}
	return (std::atof(s_price.c_str()));
}

void	BitcoinExchange::processCsvFile(void)
{
	std::ifstream	db("data.csv");
	std::string		line;
	if (!db.is_open())
		throw std::runtime_error("File can't open");
	std::getline(db, line);
	if (line != "date,exchange_rate")
		throw std::runtime_error("Invalid database");
	while (std::getline(db, line))
	{
		std::size_t	i = line.find(',');
		if (i == std::string::npos)
			throw std::runtime_error("Invalid database");
		std::string	time = std::string(line.begin(), line.begin() +i);
		if (!valideDate(time))
			throw std::runtime_error("bad input => " + time);
		double	price = ft_stod(std::string(line.begin() +i+1, line.end()));
		_c[time] = price;
	}
	db.close();
}

void	BitcoinExchange::printHistory(const char* filename)
{
	std::ifstream	input(filename);
	std::string		line;
	if (!input.is_open())
		throw std::runtime_error("File can't open");
	std::getline(input, line);
	if (line != "date | value")
		throw std::runtime_error("Invalid input");
	while (std::getline(input, line))
	{
		try
		{
			std::size_t	i = line.find(" | ");
			if (i == std::string::npos)
				throw std::runtime_error("bad input => " + line);
			std::string	time = std::string(line.begin(), line.begin() +i);
			if (!valideDate(time))
				throw std::runtime_error("bad input => " + time);
			std::map<std::string, double>::const_iterator it = _c.upper_bound(time);
			if (it != _c.begin())
			{
				it--;
				double	value = ft_stod(std::string(line.begin() +i+3, line.end()));
				if (value < 0.0)
					throw std::runtime_error("not a positive number.");
				else if (value > 1000.0)
					throw std::runtime_error("too large a number.");
				double	amount =  value * (*it).second;
				std::cout 	<< std::string(line.begin(), line.begin() +i)
							<< " => "
							<< std::string(line.begin() +i+3, line.end())
							<< " = "
							<< amount
							<< std::endl;
			}
			else
				throw std::runtime_error("price not found");
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	input.close();
}

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const char* filename, int &ret)
{
	try
	{
		processCsvFile();
		printHistory(filename);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		if (std::string(e.what()) == "File can't open")
			ret = 1;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	if (this != &other)
	{
		_c = other._c;
	}
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		_c = other._c;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}
