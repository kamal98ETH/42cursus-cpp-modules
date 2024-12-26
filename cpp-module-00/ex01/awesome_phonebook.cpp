/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   awesome_phonebook.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:27:21 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/12/26 15:05:58 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	myPhoneBook;
	std::string	input;

	while (1)
	{
		std::cout << "Enter a command (ADD, SEARCH,or EXIT)..." << std::endl;
		std::getline(std::cin, input);
		if (input == "ADD")
			myPhoneBook.add();
		else if (input == "SEARCH")
			myPhoneBook.search();
		else if (input == "EXIT")
		{
			std::cout << "Program exited!" << std::endl;
			return (0);
		}
		else
			std::cout << "NOT A VALID COMMAND!" << std::endl;
		if (std::cin.eof())
		{
			std::cerr << "End Of File detected! exiting..." << std::endl;
			exit(1);
		}
	}
}
