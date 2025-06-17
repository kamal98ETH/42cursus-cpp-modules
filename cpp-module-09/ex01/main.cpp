/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:28:09 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/06/09 22:34:11 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	err(std::string err_msg)
{
	std::cout << err_msg << std::endl;
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (err("Wrong number of args"));
	std::string				arg = argv[1];
	std::string				valid = "01234567989+-*/";
	std::string::iterator	it = arg.begin();
	RPN						rpn;
	for (; it != arg.end(); it++)
	{
		if (valid.find(*it) == std::string::npos)
			break ;
		rpn.add(*it);
		it++;
		if ((it != arg.end() && *it != ' ') || it == arg.end())
			break ;
	}
	if (it != arg.end())
		return (err("Error"));
	std::cout << rpn.result() << std::endl;
	return (0);
}
