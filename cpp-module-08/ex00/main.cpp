/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:09:53 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/05/21 18:57:40 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main()
{
	std::vector<int>			nums;
	std::vector<int>::iterator it;

	nums.push_back(42);
	nums.push_back(1337);
	nums.push_back(1937);

	try
	{
		it = easyfind(nums, 1337);
		std::cout << "Value: " << *it << ", found at index: " << it - nums.begin() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "exception thrown: " << e.what() << std::endl;
	}

	try
	{
		it = easyfind(nums, 4242);
	}
	catch(const std::exception& e)
	{
		std::cerr << "exception thrown: " << e.what() << std::endl;
	}

	return (0);
}
