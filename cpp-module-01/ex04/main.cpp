/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 03:01:05 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/01/01 16:42:28 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

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

std::string	readFile(char *filename)
{
	std::string		fileContent;
	char			one[1];
	std::ifstream	inFile(filename);

	if (!inFile.is_open())
	{
		std::cerr << "\e[31mERROR: Can't open file\e[0m" << std::endl;
		exit(1);
	}
	inFile.read(one, 1);
	while (!inFile.eof())
	{
		fileContent += one;
		inFile.read(one, 1);
	}
	inFile.close();
	return (fileContent);
}

void	writeFile(char *filename, std::string newContent)
{
	std::ofstream	outFile(std::string(filename) + ".replace");

	if (!outFile.is_open())
	{
		std::cerr << "\e[31mERROR: Can't open file\e[0m" << std::endl;
		exit(1);
	}
	outFile << newContent;
	outFile.close();
}

int	main(int argc, char **argv)
{
	std::string		newContent;

	if (argc != 4)
	{
		std::cerr << "\e[31mWrong number of parameters\e[0m" << std::endl;
		return (1);
	}
	newContent = findAndReplace(readFile(argv[1]), argv[2], argv[3]);
	writeFile(argv[1], newContent);
	return (0);
}
