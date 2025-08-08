/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 02:02:14 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/08/08 00:43:00 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main()
{
	Array<int>	arr(3);

	arr[0] = 5;
	arr[1] = 15;
	arr[2] = 25;

	for (std::size_t i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << ", ";
	}
	std::cout << std::endl;

	Array<int>	arr2(arr);

	for (std::size_t i = 0; i < arr2.size(); i++)
	{
		std::cout << arr2[i] << ", ";
	}
	std::cout << std::endl;

	Array<int>	arr3(4);
	arr3 = arr2;

	for (std::size_t i = 0; i < arr3.size(); i++)
	{
		std::cout << arr3[i] << ", ";
	}
	std::cout << std::endl;

	try
	{
		std::cout << arr[10] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
