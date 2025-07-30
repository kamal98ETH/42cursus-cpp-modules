/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:57:12 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/07/30 03:27:45 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cerr << "Error: could not open file." << std::endl, 1);
	int	ret = 0;
	BitcoinExchange btc(argv[1], ret);

	return (ret);
}
