/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:58:36 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/05/23 18:13:10 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int	main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	int myArray[] = {6, 3, 17, 9, 11};
    std::vector<int> nums(myArray, myArray + sizeof(myArray) / sizeof(int));
	Span sp2 = Span(5);
	sp2.addManyNumbers(nums.begin(), nums.end());
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
	
	const int	N = 30000;
	Span	monsterSp = Span(N);
	std::srand(std::time(0));
	for (int i = 0; i < N; i++)
		monsterSp.addNumber(std::rand());
	try
	{
		monsterSp.addNumber(std::rand());
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception thrown: " << e.what() << std::endl;
	}
	std::cout << monsterSp.shortestSpan() << std::endl;
	std::cout << monsterSp.longestSpan() << std::endl;

	return (0);
}
