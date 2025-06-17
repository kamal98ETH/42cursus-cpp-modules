/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:57:12 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/06/08 21:44:43 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	err_message(std::string str)
{
	std::cerr << str << std::endl;
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (err_message("Error: could not open file."));
	std::ifstream	file(argv[1]);
	if (!file.is_open())
		return (err_message("Error: could not open file."));
	
	return (0);
}
