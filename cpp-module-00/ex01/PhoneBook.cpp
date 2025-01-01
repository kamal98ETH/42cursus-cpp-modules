/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:16:39 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/01/01 21:32:40 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	getValidStr(std::string prpt)
{
	std::string	input;

	while (1)
	{
		std::cout << prpt << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cerr << "End Of File detected! exiting..." << std::endl;
			exit(1);
		}
		if (!input.empty())
			break ;
		std::cout << "Input empty, please type a valid input!!!" << std::endl;
	}
	return (input);
}

void	PhoneBook::add(void)
{
	std::string	f;
	std::string	l;
	std::string	n;
	std::string	p;
	std::string	d;

	for (int i = 7; i > 0; i--)
		contacts[i].copy(contacts[i -1]);
	f = getValidStr("Contact's first name...");
	l = getValidStr("Contact's last name...");
	n = getValidStr("Contact's nickname...");
	p = getValidStr("Contact's phone number...");
	d = getValidStr("Contact's darkest secret...");
	contacts[0].setContact(f, l, n, p, d);
	std::cout << "Contact added successfully!" << std::endl;
}

int valid_input_number(std::string str)
{
    int number;
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (!str[i])
		return (-1);
	for (; str[i]; i++)
		if (str[i] < '0' || str[i] > '9')
			return (-1);
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '0')
		i++;
	if (str.length() - i > 3)
		return (-1);
    number = std::atoi(str.c_str());
	if (number >= 0 && number < 8)
		return (number);
	return (-1);
}

void	PhoneBook::search(void)
{
	int	index;

	std::cout << "     index|first name| last name|  nickname" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "         " << i << "|";
		contacts[i].printOneContact();
	}
	index = valid_input_number(getValidStr("Enter index number of contact to be displayed..."));
	while (index == -1)
	{
		std::cout << "Unvalid index!! please select a contact's index (0-7)..." << std::endl;
		index = valid_input_number(getValidStr("Enter index number of contact to be displayed..."));
	}
	contacts[index].printFullContact();
}
