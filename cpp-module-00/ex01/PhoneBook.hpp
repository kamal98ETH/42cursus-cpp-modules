/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:14:55 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/09/24 19:04:21 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

using namespace std;

int valid_input_number(string str);

class PhoneBook
{
	private:
		Contact	contacts[8];

	public:
		void	add(Contact contact)
		{
			for (int i = 7; i > 0; i--)
			{
				contacts[i] = contacts[i -1];
			}
			contacts[0] = contact;
		}

		void	search()
		{
			string			indexStr;
			int					index;

			print_limited_str("index");
			cout << "|";
			print_limited_str("first name");
			cout << "|";
			print_limited_str("last name");
			cout << "|";
			print_limited_str("nickname");
			cout << endl;
			for (int i = 0; i < 8; i++)
				contacts[i].printContactRow(i +1);
			cout << "Select a contact..." << endl;
			getline(cin, indexStr);
			index = valid_input_number(indexStr);
			while (index == -1)
			{
				cout << "Unvalid index!! please select a contact's index (1-8)..." << endl;
				getline(cin, indexStr);
				index = valid_input_number(indexStr);
			}
			contacts[index].printContact();
		}
};

#endif
