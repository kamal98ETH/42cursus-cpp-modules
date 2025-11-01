/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 23:51:15 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/08/03 16:30:35 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	(void)other;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other)
{
	(void)other;
	return (*this);
}


PmergeMe::~PmergeMe(void){}

std::vector<int>	get_Jacobsthal_batches_vec(int m)
{
	std::vector<int>	batches;
	int	a = 1;
	int	b = 3;
	int	result = 3;
	while (result <= m)
	{
		batches.push_back(b-a);
		result = b + 2 * a;
		a = b;
		b = result;
	}
	if (m - a >= 0)
		batches.push_back(m-a +1);
	return (batches);
}

void	insert_batches(std::vector<int> &main, std::vector<int> &pend)
{
	std::vector<int>	batches = get_Jacobsthal_batches_vec(pend.size() -1);
	std::vector<int>::iterator	it_pend = pend.begin() +1;
	for (std::vector<int>::iterator it = batches.begin(); it != batches.end(); it++)
	{
		std::vector<int>::iterator	it_pend_batch_b = it_pend;
		std::vector<int>::iterator	it_pend_batch_e = it_pend + *it;
		it_pend += *it;
		
		std::vector<int>::iterator	insert = it_pend_batch_e -1;
		while (true)
		{
			std::vector<int>::iterator	it = std::upper_bound(main.begin(), main.end(), *insert);
			main.insert(it, *insert);
			if (insert == it_pend_batch_b)
				break;
			insert--;
		}
	}
}

bool t_num_cmp(t_num num1, t_num num2)
{
    return num1.val < num2.val;
}

void	insert_batches(std::vector<t_num> &main, std::vector<t_num> &pend)
{
	std::vector<int>	batches = get_Jacobsthal_batches_vec(pend.size() -1);
	std::vector<t_num>::iterator	it_pend = pend.begin() +1;
	for (std::vector<int>::iterator it = batches.begin(); it != batches.end(); it++)
	{
		std::vector<t_num>::iterator	it_pend_batch_b = it_pend;
		std::vector<t_num>::iterator	it_pend_batch_e = it_pend + *it;
		it_pend += *it;

		std::vector<t_num>::iterator	insert = it_pend_batch_e -1;
		while (true)
		{
			std::vector<t_num>::iterator	it = std::upper_bound(main.begin(), main.end(), *insert, t_num_cmp);
			main.insert(it, *insert);
			if (insert == it_pend_batch_b)
				break;
			insert--;
		}
	}
}

void	rec_vec_sort(std::vector<t_num> &vec)
{
	if (vec.size() <= 1)
		return ;
	t_num	straggler;
	bool	has_straggler = false;
	if (vec.size() % 2)
	{
		has_straggler = true;
		straggler = vec.back();
		vec.pop_back();
	}

	std::vector<t_num>	main;
	std::vector<t_num>	tmp;
	std::vector<std::size_t>	previous_indexes;
	int	i = 0;
	for (std::vector<t_num>::iterator it = vec.begin(); it < vec.end(); it += 2)
	{
		if ((*it).val > (*(it+1)).val)
		{
			previous_indexes.push_back((*it).old);
			(*it).old = i;
			main.push_back(*it);
			tmp.push_back(*(it+1));
		}
		else
		{
			previous_indexes.push_back((*(it+1)).old);
			(*(it+1)).old = i;
			main.push_back(*(it+1));
			tmp.push_back(*it);
		}
		i++;
	}
	
	rec_vec_sort(main);

	std::vector<t_num>	pend;
	for (std::vector<t_num>::iterator it = main.begin(); it < main.end(); it++)
	{
		pend.push_back(tmp[(*it).old]);
		(*it).old = previous_indexes[(*it).old];
	}
	

	main.insert(main.begin(), pend[0]);
	
	insert_batches(main, pend);
	
	if (has_straggler)
	{
		std::vector<t_num>::iterator	it = std::upper_bound(main.begin(), main.end(), straggler, t_num_cmp);
		main.insert(it, straggler);
	}

	vec = main;
}

void	PmergeMe::vec_sort(std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return ;
	int	straggler;
	bool	has_straggler = false;
	if (vec.size() % 2)
	{
		has_straggler = true;
		straggler = vec.back();
		vec.pop_back();
	}
	
	std::vector<t_num>	main_tnum;
	std::vector<int >	tmp;
	int	i = 0;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it += 2)
	{
		t_num	num;
		num.val = std::max(*it, *(it +1));
		num.old = i;
		main_tnum.push_back(num);
		tmp.push_back(std::min(*it, *(it +1)));
		i++;
	}

	rec_vec_sort(main_tnum);
	
	std::vector<int>	main;
	std::vector<int>	pend;
	
	for (std::vector<t_num>::iterator it = main_tnum.begin(); it < main_tnum.end(); it++)
	{
		main.push_back((*it).val);
		pend.push_back(tmp[(*it).old]);
	}
	
	main.insert(main.begin(), pend[0]);
	
	insert_batches(main, pend);
	
	if (has_straggler)
	{
		std::vector<int>::iterator	it = std::upper_bound(main.begin(), main.end(), straggler);
		main.insert(it, straggler);
	}

	vec = main;
}








std::deque<int>	get_Jacobsthal_batches_deq(int m)
{
	std::deque<int>	batches;
	int	a = 1;
	int	b = 3;
	int	result = 3;
	while (result <= m)
	{
		batches.push_back(b-a);
		result = b + 2 * a;
		a = b;
		b = result;
	}
	if (m - a >= 0)
		batches.push_back(m-a +1);
	return (batches);
}

void	insert_batches(std::deque<int> &main, std::deque<int> &pend)
{
	std::deque<int>	batches = get_Jacobsthal_batches_deq(pend.size() -1);
	std::deque<int>::iterator	it_pend = pend.begin() +1;
	for (std::deque<int>::iterator it = batches.begin(); it != batches.end(); it++)
	{
		std::deque<int>::iterator	it_pend_batch_b = it_pend;
		std::deque<int>::iterator	it_pend_batch_e = it_pend + *it;
		it_pend += *it;
		
		std::deque<int>::iterator	insert = it_pend_batch_e -1;
		while (true)
		{
			std::deque<int>::iterator	it = std::upper_bound(main.begin(), main.end(), *insert);
			main.insert(it, *insert);
			if (insert == it_pend_batch_b)
				break;
			insert--;
		}
	}
}

void	insert_batches(std::deque<t_num> &main, std::deque<t_num> &pend)
{
	std::deque<int>	batches = get_Jacobsthal_batches_deq(pend.size() -1);
	std::deque<t_num>::iterator	it_pend = pend.begin() +1;
	for (std::deque<int>::iterator it = batches.begin(); it != batches.end(); it++)
	{
		std::deque<t_num>::iterator	it_pend_batch_b = it_pend;
		std::deque<t_num>::iterator	it_pend_batch_e = it_pend + *it;
		it_pend += *it;

		std::deque<t_num>::iterator	insert = it_pend_batch_e -1;
		while (true)
		{
			std::deque<t_num>::iterator	it = std::upper_bound(main.begin(), main.end(), *insert, t_num_cmp);
			main.insert(it, *insert);
			if (insert == it_pend_batch_b)
				break;
			insert--;
		}
	}
}

void	rec_vec_sort(std::deque<t_num> &vec)
{
	if (vec.size() <= 1)
		return ;
	t_num	straggler;
	bool	has_straggler = false;
	if (vec.size() % 2)
	{
		has_straggler = true;
		straggler = vec.back();
		vec.pop_back();
	}

	std::deque<t_num>	main;
	std::deque<t_num>	tmp;
	std::deque<std::size_t>	previous_indexes;
	int	i = 0;
	for (std::deque<t_num>::iterator it = vec.begin(); it < vec.end(); it += 2)
	{
		if ((*it).val > (*(it+1)).val)
		{
			previous_indexes.push_back((*it).old);
			(*it).old = i;
			main.push_back(*it);
			tmp.push_back(*(it+1));
		}
		else
		{
			previous_indexes.push_back((*(it+1)).old);
			(*(it+1)).old = i;
			main.push_back(*(it+1));
			tmp.push_back(*it);
		}
		i++;
	}
	
	rec_vec_sort(main);

	std::deque<t_num>	pend;
	for (std::deque<t_num>::iterator it = main.begin(); it < main.end(); it++)
	{
		pend.push_back(tmp[(*it).old]);
		(*it).old = previous_indexes[(*it).old];
	}
	

	main.insert(main.begin(), pend[0]);
	
	insert_batches(main, pend);
	
	if (has_straggler)
	{
		std::deque<t_num>::iterator	it = std::upper_bound(main.begin(), main.end(), straggler, t_num_cmp);
		main.insert(it, straggler);
	}

	vec = main;
}

void	PmergeMe::deq_sort(std::deque<int> &vec)
{
	if (vec.size() <= 1)
		return ;
	int	straggler;
	bool	has_straggler = false;
	if (vec.size() % 2)
	{
		has_straggler = true;
		straggler = vec.back();
		vec.pop_back();
	}
	
	std::deque<t_num>	main_tnum;
	std::deque<int >	tmp;
	int	i = 0;
	for (std::deque<int>::iterator it = vec.begin(); it != vec.end(); it += 2)
	{
		t_num	num;
		num.val = std::max(*it, *(it +1));
		num.old = i;
		main_tnum.push_back(num);
		tmp.push_back(std::min(*it, *(it +1)));
		i++;
	}

	rec_vec_sort(main_tnum);
	
	std::deque<int>	main;
	std::deque<int>	pend;
	
	for (std::deque<t_num>::iterator it = main_tnum.begin(); it < main_tnum.end(); it++)
	{
		main.push_back((*it).val);
		pend.push_back(tmp[(*it).old]);
	}
	
	main.insert(main.begin(), pend[0]);
	
	insert_batches(main, pend);
	
	if (has_straggler)
	{
		std::deque<int>::iterator	it = std::upper_bound(main.begin(), main.end(), straggler);
		main.insert(it, straggler);
	}

	vec = main;
}
