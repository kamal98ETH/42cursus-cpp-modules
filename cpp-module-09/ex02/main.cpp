/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 23:50:39 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/08/03 16:32:05 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	print_vec(std::vector<int> vec)
{
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (it != vec.end() -1)
			std::cout << *it << " ";
		else
			std::cout << *it;
	}
	std::cout << std::endl;
}

bool isValidPositiveInteger(char* c_str, int &num)
{
	std::string	str = c_str;
    if (str.empty())
		return false;
    if (str.length() > 1 && str[0] == '0')
		return false;
    if (str.length() > 10)
		return false;
    for (size_t i = 0; i < str.length(); ++i)
	{
        if (str[i] < '0' || str[i] > '9')
			return false;
    }
    if (str.length() == 10) {
        std::string max_int = "2147483647";
        if (str > max_int)
			return false;
    }
	num = std::atoi(c_str);
    return true;
}

double getTimeInUsec(void)
{
    struct timeval tv;
    gettimeofday(&tv, 0);
    return (tv.tv_sec * 1e6 + tv.tv_usec);
}

bool	test(std::vector<int> vec)
{
	for (std::vector<int>::iterator it = vec.begin(); it < vec.end() -1; it++)
	{
		if (*it > *(it+1))
			return (false);
	}
	return (true);
}

bool	test(std::deque<int> vec)
{
	for (std::deque<int>::iterator it = vec.begin(); it < vec.end() -1; it++)
	{
		if (*it > *(it+1))
			return (false);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	std::vector<int>	vec;
	std::deque<int>		deq;
	for (int i = 1; i < argc; i++)
	{
		int	num;
		if (!isValidPositiveInteger(argv[i], num))
		{
			std::cerr << "Error" << std::endl;
			return (1);
		}
		vec.push_back(num);
		deq.push_back(num);
	}
	
	std::cout << "Before: ";
	print_vec(vec);

	PmergeMe	sort_algo;
	double	start = getTimeInUsec();
	sort_algo.vec_sort(vec);
	double	end = getTimeInUsec();

	std::cout << "After: ";
	print_vec(vec);
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << end - start << " us" << std::endl;

	start = getTimeInUsec();
	sort_algo.deq_sort(deq);
	end = getTimeInUsec();
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << end - start << " us" << std::endl;

	if (test(vec) && test(deq))
		std::cout << "OK\n";
	else
		std::cout << "KO\n";

	return (0);
}
