/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:16:05 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/09/24 19:03:44 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "PhoneBook.hpp"

using namespace std;

void	print_limited_str(string str);

class Contact
{
	private:
		string	first_name;
		string	last_name;
		string	nickname;
		string	phone_number;
		string	darkest_secret;

	public:
		void	setContact(string first, string last,
							string nick, string number,
							string secret)
		{
			first_name = first;
			last_name = last;
			nickname = nick;
			phone_number = number;
			darkest_secret = secret;
		}

		void	printContactRow(int index)
		{
			stringstream	indexStream;
			
			indexStream << index;
			print_limited_str(indexStream.str());
			cout << "|";
			print_limited_str(first_name);
			cout << "|";
			print_limited_str(last_name);
			cout << "|";
			print_limited_str(nickname);
			cout << endl;
		}

		void	printContact(void)
		{
			cout << "First name      : " << first_name << endl;
			cout << "Last name       : " << last_name << endl;
			cout << "Nickname        : " << nickname << endl;
			cout << "Phone number    : " << phone_number << endl;
			cout << "Darkest sercret : " << darkest_secret << endl; 
		}
};

#endif
