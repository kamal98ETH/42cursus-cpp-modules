/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 03:01:05 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/11/05 23:18:21 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

std::string	findAndReplace(std::string original, std::string from, std::string to)
{
	std::string	newStr = "";
	int			pos = original.find(from);

	while (pos >= 0)
	{
		newStr += original.substr(0, pos) + to;
		original = &original[pos + from.size()];
		pos = original.find(from);
	}
	newStr += original;
	return (newStr);
}

int	main(int argc, char **argv)
{
	std::string		fileContent;
	std::string		newContent;
	char			one[1];
	std::fstream	file(argv[1], std::ios::in | std::ios::out | std::ios::trunc);

	if (argc != 4)
	{
		std::cerr << "\e[31mWrong number of parameters\n\e[0m";
		return (1);
	}

	if (file.is_open())
	{
		file.read(one, 1);
		while (!file.eof())
		{
			fileContent += one;
			file.read(one, 1);
		}
		newContent = findAndReplace(fileContent, argv[2], argv[3]);
		file << "newContent";
		file.close();
	}
	else
	{
		std::cerr << "\e[31mFile doesn't exist\n\e[0m";
		return (1);
	}
	return (0);
}
