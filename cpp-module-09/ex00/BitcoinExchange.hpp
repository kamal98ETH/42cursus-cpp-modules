/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:57:14 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/07/30 03:27:11 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <iostream>
# include <sstream>
# include <cstdlib>
# include <cstring>
# include <map>
# include <algorithm>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	_c;
		bool	digit(std::string str);
		double	ft_stod(std::string s_price);
		bool	valideDate(std::string	date);
		void	processCsvFile(void);
		void	printHistory(const char* filename);
	public:
		BitcoinExchange(void);
		BitcoinExchange(const char* filename, int &ret);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&	operator=(const BitcoinExchange& other);
		~BitcoinExchange(void);
};




#endif
