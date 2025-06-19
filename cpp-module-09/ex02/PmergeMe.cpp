/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 23:51:15 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/06/19 02:26:10 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	print_vec(std::vector<int> vec, bool nl)
{
	std::cout << "[ ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (it != vec.end() -1)
			std::cout << *it << ", ";
		else
			std::cout << *it;
	}
	std::cout << " ]";
	if (nl)
		std::cout << std::endl;
}

void	print_vec_vec(std::vector<std::vector<int> > vec)
{
	std::cout << "[ ";
	for (std::vector<std::vector<int> >::iterator it = vec.begin(); it != vec.end(); it++)
	{
		print_vec(*it, false);
		if (it != vec.end() -1)
			std::cout << ", ";
	}
	std::cout << " ]";
	std::cout << std::endl;
}

PmergeMe::PmergeMe(void)
{
}

PmergeMe::~PmergeMe(void)
{
}

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

int	binary_insert(const std::vector<int> &vec, int left, int right, int value)
{
	while (left <= right)
	{
		int	mid = left + (right - left) /2;
		if (value == vec[mid])
			return (mid);
		else if (value > vec[mid])
			left = mid +1;
		else
			right = mid -1;
	}
	return (left);
}

int	binary_insert(const std::vector<std::vector<int> > &vec, int left, int right, int value)
{
	while (left <= right)
	{
		int	mid = left + (right - left) /2;
		if (value == vec[mid][0])
			return (mid);
		else if (value > vec[mid][0])
			left = mid +1;
		else
			right = mid -1;
	}
	return (left);
}

void	insert_batches(std::vector<int> &main, std::vector<std::vector<int> > &pairs)
{
	std::vector<int>	batches = get_Jacobsthal_batches_vec(pairs.size());
	for (std::vector<int>::iterator it = batches.begin(); it != batches.end(); it++)
	{
		std::vector<std::vector<int> >	pairs_batch(pairs.begin(), pairs.begin() + *it);
		pairs.erase(pairs.begin(), pairs.begin() + *it);
		// loop throu pairs and push a section of the pairs into the main sequence
		for (std::vector<std::vector<int> >::iterator it = pairs_batch.begin(); it != pairs_batch.end(); it++)
			main.push_back((*it)[0]);
		
		// loop at reverse order to insert the b section of the pairs into the main sequence using binary search
		std::vector<std::vector<int> >::iterator	insert = pairs_batch.end() -1;
		while (true)
		{
			// look for a<i> in the main sequence to insert b<i> before it since b<i> < a<i>
			int	right = main.size() -1;
			while (main[right] != (*insert)[0])
				right--;
			// we put right -1 because b<i> is always before a<i> so it makes more sence not to include a<i> in the binary searched vector
			int	insert_index = binary_insert(main, 0, right -1, (*insert)[1]);
			main.insert(main.begin() + insert_index, (*insert)[1]);
			if (insert == pairs_batch.begin())
				break;
			insert--;
		}
	}
}

void	insert_batches(std::vector<std::vector<int> > &main, std::vector<std::vector<int> > &groups, int lvl)
{
	std::vector<int>	batches = get_Jacobsthal_batches_vec(groups.size());
	for (std::vector<int>::iterator it = batches.begin(); it != batches.end(); it++)
	{
		std::vector<std::vector<int> >	batch(groups.begin(), groups.begin() + *it);
		groups.erase(groups.begin(), groups.begin() + *it);

		// loop throu pairs and push a section of the pairs into the main sequence
		for (std::vector<std::vector<int> >::iterator it = batch.begin(); it != batch.end(); it++)
			main.push_back(std::vector<int>((*it).begin(), (*it).begin() +lvl));

		// loop at reverse order to insert the b section of the pairs into the main sequence using binary search
		std::vector<std::vector<int> >::iterator	insert = batch.end() -1;
		while (true)
		{
			// look for a<i> in the main sequence to insert b<i> before it since b<i> < a<i>
			int	right = main.size() -1;
			while (main[right][0] != (*insert)[0])
				right--;
			// we put right -1 because b<i> is always before a<i> so it makes more sence not to include a<i> in the binary searched vector
			int	insert_index = binary_insert(main, 0, right -1, (*insert)[lvl]);
			main.insert(main.begin() + insert_index, std::vector<int>((*insert).begin() + lvl, (*insert).end()));
			if (insert == batch.begin())
				break;
			insert--;
		}
	}
}

void	rec_vec_sort(std::vector<std::vector<int> > &vec, std::size_t lvl)
{
	if (vec.size() <= 1)
		return ;
	std::vector<int>	straggler;
	if (vec.size() % 2)
	{
		straggler = vec.back();
		vec.pop_back();
	}

	// make groups
	std::vector<std::vector<int> >	groups;
	for (std::vector<std::vector<int> >::iterator it = vec.begin(); it < vec.end(); it += 2)
	{
		std::vector<int>	group;
		if ((*it)[0] > (*(it +1))[0])
		{
			group.insert(group.end(), (*it).begin(), (*it).end());
			group.insert(group.end(), (*(it+1)).begin(), (*(it+1)).end());
		}
		else
		{
			group.insert(group.end(), (*(it+1)).begin(), (*(it+1)).end());
			group.insert(group.end(), (*it).begin(), (*it).end());
		}
		groups.push_back(group);
	}
	
	// recursively sort the pairs
	rec_vec_sort(groups, lvl * 2);

	// make main and pend sequences
	std::vector<std::vector<int> >	main;
	main.push_back(std::vector<int>(groups[0].begin() +lvl, groups[0].end()));
	main.push_back(std::vector<int>(groups[0].begin(), groups[0].begin() +lvl));
	groups.erase(groups.begin());
	
	// get batches for insert and do binary inserts
	insert_batches(main, groups, lvl);
	
	// insert straggler
	if (straggler.size() != 0)
	{
		int index = binary_insert(main, 0, main.size() -1, straggler[0]);
		main.insert(main.begin() + index, straggler);
	}

	vec = main;
}

void	PmergeMe::vec_sort(std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return ;
	int	straggler = -1;
	if (vec.size() % 2)
	{
		straggler = vec.back();
		vec.pop_back();
	}
	
	// make pairs (ordred)
	std::vector<std::vector<int> >	pairs;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it += 2)
	{
		std::vector<int>	pair;
		pair.push_back(std::max(*it, *(it +1)));
		pair.push_back(std::min(*it, *(it +1)));
		pairs.push_back(pair);
	}

	// recursively sort the pairs
	rec_vec_sort(pairs, 2);
	
	// make main and pend sequences
	std::vector<int>	main;
	main.push_back(pairs[0][1]);
	main.push_back(pairs[0][0]);
	pairs.erase(pairs.begin());
	
	// get batches for insert and do binary inserts
	insert_batches(main, pairs);
	
	// insert straggler
	if (straggler != -1)
	{
		int index = binary_insert(main, 0, main.size() -1, straggler);
		main.insert(main.begin() + index, straggler);
	}

	vec = main;
}

// deque
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

int	binary_insert(const std::deque<int> &vec, int left, int right, int value)
{
	while (left <= right)
	{
		int	mid = left + (right - left) /2;
		if (value == vec[mid])
			return (mid);
		else if (value > vec[mid])
			left = mid +1;
		else
			right = mid -1;
	}
	return (left);
}

int	binary_insert(const std::deque<std::deque<int> > &vec, int left, int right, int value)
{
	while (left <= right)
	{
		int	mid = left + (right - left) /2;
		if (value == vec[mid][0])
			return (mid);
		else if (value > vec[mid][0])
			left = mid +1;
		else
			right = mid -1;
	}
	return (left);
}

void	insert_batches(std::deque<int> &main, std::deque<std::deque<int> > &pairs)
{
	std::deque<int>	batches = get_Jacobsthal_batches_deq(pairs.size());
	for (std::deque<int>::iterator it = batches.begin(); it != batches.end(); it++)
	{
		std::deque<std::deque<int> >	pairs_batch(pairs.begin(), pairs.begin() + *it);
		pairs.erase(pairs.begin(), pairs.begin() + *it);
		// loop throu pairs and push a section of the pairs into the main sequence
		for (std::deque<std::deque<int> >::iterator it = pairs_batch.begin(); it != pairs_batch.end(); it++)
			main.push_back((*it)[0]);
		
		// loop at reverse order to insert the b section of the pairs into the main sequence using binary search
		std::deque<std::deque<int> >::iterator	insert = pairs_batch.end() -1;
		while (true)
		{
			// look for a<i> in the main sequence to insert b<i> before it since b<i> < a<i>
			int	right = main.size() -1;
			while (main[right] != (*insert)[0])
				right--;
			// we put right -1 because b<i> is always before a<i> so it makes more sence not to include a<i> in the binary searched vector
			int	insert_index = binary_insert(main, 0, right -1, (*insert)[1]);
			main.insert(main.begin() + insert_index, (*insert)[1]);
			if (insert == pairs_batch.begin())
				break;
			insert--;
		}
	}
}

void	insert_batches(std::deque<std::deque<int> > &main, std::deque<std::deque<int> > &groups, int lvl)
{
	std::deque<int>	batches = get_Jacobsthal_batches_deq(groups.size());
	for (std::deque<int>::iterator it = batches.begin(); it != batches.end(); it++)
	{
		std::deque<std::deque<int> >	batch(groups.begin(), groups.begin() + *it);
		groups.erase(groups.begin(), groups.begin() + *it);

		// loop throu pairs and push a section of the pairs into the main sequence
		for (std::deque<std::deque<int> >::iterator it = batch.begin(); it != batch.end(); it++)
			main.push_back(std::deque<int>((*it).begin(), (*it).begin() +lvl));

		// loop at reverse order to insert the b section of the pairs into the main sequence using binary search
		std::deque<std::deque<int> >::iterator	insert = batch.end() -1;
		while (true)
		{
			// look for a<i> in the main sequence to insert b<i> before it since b<i> < a<i>
			int	right = main.size() -1;
			while (main[right][0] != (*insert)[0])
				right--;
			// we put right -1 because b<i> is always before a<i> so it makes more sence not to include a<i> in the binary searched vector
			int	insert_index = binary_insert(main, 0, right -1, (*insert)[lvl]);
			main.insert(main.begin() + insert_index, std::deque<int>((*insert).begin() + lvl, (*insert).end()));
			if (insert == batch.begin())
				break;
			insert--;
		}
	}
}

void	rec_deq_sort(std::deque<std::deque<int> > &deq, std::size_t lvl)
{
	if (deq.size() <= 1)
		return ;
	std::deque<int>	straggler;
	if (deq.size() % 2)
	{
		straggler = deq.back();
		deq.pop_back();
	}

	// make groups
	std::deque<std::deque<int> >	groups;
	for (std::deque<std::deque<int> >::iterator it = deq.begin(); it < deq.end(); it += 2)
	{
		std::deque<int>	group;
		if ((*it)[0] > (*(it +1))[0])
		{
			group.insert(group.end(), (*it).begin(), (*it).end());
			group.insert(group.end(), (*(it+1)).begin(), (*(it+1)).end());
		}
		else
		{
			group.insert(group.end(), (*(it+1)).begin(), (*(it+1)).end());
			group.insert(group.end(), (*it).begin(), (*it).end());
		}
		groups.push_back(group);
	}
	
	// recursively sort the pairs
	rec_deq_sort(groups, lvl * 2);

	// make main and pend sequences
	std::deque<std::deque<int> >	main;
	main.push_back(std::deque<int>(groups[0].begin() +lvl, groups[0].end()));
	main.push_back(std::deque<int>(groups[0].begin(), groups[0].begin() +lvl));
	groups.erase(groups.begin());
	
	// get batches for insert and do binary inserts
	insert_batches(main, groups, lvl);
	
	// insert straggler
	if (straggler.size() != 0)
	{
		int index = binary_insert(main, 0, main.size() -1, straggler[0]);
		main.insert(main.begin() + index, straggler);
	}

	deq = main;
}

void	PmergeMe::deq_sort(std::deque<int> &deq)
{
	if (deq.size() <= 1)
		return ;
	int	straggler = -1;
	if (deq.size() % 2)
	{
		straggler = deq.back();
		deq.pop_back();
	}
	
	// make pairs (ordred)
	std::deque<std::deque<int> >	pairs;
	for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); it += 2)
	{
		std::deque<int>	pair;
		pair.push_back(std::max(*it, *(it +1)));
		pair.push_back(std::min(*it, *(it +1)));
		pairs.push_back(pair);
	}

	// recursively sort the pairs
	rec_deq_sort(pairs, 2);
	
	// make main and pend sequences
	std::deque<int>	main;
	main.push_back(pairs[0][1]);
	main.push_back(pairs[0][0]);
	pairs.erase(pairs.begin());
	
	// get batches for insert and do binary inserts
	insert_batches(main, pairs);
	
	// insert straggler
	if (straggler != -1)
	{
		int index = binary_insert(main, 0, main.size() -1, straggler);
		main.insert(main.begin() + index, straggler);
	}

	deq = main;
}
