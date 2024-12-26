/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:02:30 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/12/26 00:59:23 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::setContact(std::string f, std::string l, std::string n, std::string p, std::string d)
{
	first_name = f;
	last_name = l;
	nickname = n;
	phone_number = p;
	darkest_secret = d;
}

std::string	Contact::getFirstName(void)
{
	return (first_name);
}

std::string	Contact::getLastName(void)
{
	return (last_name);
}

std::string	Contact::getNickname(void)
{
	return (nickname);
}

std::string	Contact::getPhoneNumber(void)
{
	return (phone_number);
}

std::string	Contact::getDarkestSecrect(void)
{
	return (darkest_secret);
}

void	Contact::copy(Contact contact)
{
	first_name = contact.getFirstName();
	last_name = contact.getLastName();
	nickname = contact.getNickname();
	phone_number = contact.getPhoneNumber();
	darkest_secret = contact.getDarkestSecrect();
}

void	print_limited_str(std::string str)
{
	int			length;
	std::string	substring;

	length = str.size();
	if (length > 10)
		str[9] = '.';
	substring = str.substr(0, 10);
	for (length = substring.size(); length < 10; length++)
		std::cout << " ";
	std::cout << substring;
}


void	Contact::printOneContact(int index)
{
	std::stringstream	ss;

	ss << index;
	print_limited_str(ss.str());
	std::cout << "|";
	print_limited_str(first_name);
	std::cout << "|";
	print_limited_str(last_name);
	std::cout << "|";
	print_limited_str(nickname);
	std::cout << std::endl;
}

void	Contact::printFullContact(void)
{
	std::cout << "First name      : " << first_name << std::endl;
	std::cout << "Last name       : " << last_name << std::endl;
	std::cout << "Nickname        : " << nickname << std::endl;
	std::cout << "Phone number    : " << phone_number << std::endl;
	std::cout << "Darkest sercret : " << darkest_secret << std::endl; 
}
