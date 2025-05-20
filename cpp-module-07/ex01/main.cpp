/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 21:01:59 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/05/19 23:18:34 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	increment(int &element)
{
	element++;
}

void	print_int(int element)
{
	std::cout << element << ", ";
}

void	add_suffix(std::string &element)
{
	element += "_sifix";
}

void	print_str(std::string element)
{
	std::cout << element << ", ";
}

int	main()
{
	int	array1[] = {0, 1, 2, 3, 4};

	::iter(array1, 5, print_int);
	std::cout << std::endl;
	::iter(array1, 5, increment);
	::iter(array1, 5, print_int);
	std::cout << std::endl;

	std::string	array2[] = {"str1", "str2", "str3"};

	::iter(array2, 3, print_str);
	std::cout << std::endl;
	::iter(array2, 3, add_suffix);
	::iter(array2, 3, print_str);
	std::cout << std::endl;
	
	return (0);
}
