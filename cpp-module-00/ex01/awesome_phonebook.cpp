/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   awesome_phonebook.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:27:21 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/09/24 19:08:10 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "PhoneBook.hpp"

using namespace std;

void	print_limited_str(string str)
{
	int			length;
	string	substring;

	length = str.size();
	if (length > 10)
		str[9] = '.';
	substring = str.substr(0, 10);
	for (length = substring.size(); length < 10; length++)
		cout << " ";
	cout << substring;
}

int valid_input_number(string str)
{
    stringstream ss(str);
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
    ss >> number;
	if (number > 0 && number < 9)
		return (number);
	else
		return (-1);
}

string	fill_contact_info(string message)
{
	string	info;

	cout << message << endl;
	getline(cin, info);
	while (info.empty())
	{
		cout << "Input empty, please type a valid input!!!" << endl;
		getline(cin, info);
	}
	return (info);
}

Contact	get_contact(void)
{
	Contact		contact;
	string	first_name;
	string	last_name;
	string	nickname;
	string	phone_number;
	string	darkest_secret;

	first_name = fill_contact_info("Contact's first name...");
	last_name = fill_contact_info("Contact's last name...");
	nickname = fill_contact_info("Contact's nickname...");
	phone_number = fill_contact_info("Contact's phone number...");
	darkest_secret = fill_contact_info("Contact's darkest secret...");
	contact.setContact(first_name, last_name, nickname, phone_number, darkest_secret);
	return (contact);
}

int	main()
{
	PhoneBook	myPhoneBook;
	string	input;

	while (1)
	{
		cout << "Enter a command (ADD, SEARCH,or EXIT)..." << endl;
		getline(cin, input);
		if (input == "ADD")
		{
			myPhoneBook.add(get_contact());
			cout << "Contact added successfully!" << endl;
		}
		else if (input == "SEARCH")
		{
			myPhoneBook.search();
		}
		else if (input == "EXIT")
		{
			cout << "Program exited!" << endl;
			return (0);
		}
		else
		{
			//error msg
		}
	}
}
