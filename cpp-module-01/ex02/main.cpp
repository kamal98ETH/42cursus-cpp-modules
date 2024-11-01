/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 00:11:18 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/11/01 23:58:51 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "The memory address of the string variable : " << &str << std::endl;
	std::cout << "The memory address held by stringPTR      : " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF      : " << &stringREF << std::endl << std::endl;

	std::cout << "The value of the string variable          : " << str << std::endl;
	std::cout << "The value pointed to by stringPTR         : " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF         : " << stringREF << std::endl;
	
	return (0);
}
