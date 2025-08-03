/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 23:51:19 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/08/03 16:25:10 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cstdlib>
# include <sys/time.h>
# include <vector>
# include <deque>
# include <algorithm>

typedef	struct s_num
{
	int			val;
	std::size_t	old;
}	t_num;


class PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe& other);
		PmergeMe&	operator=(const PmergeMe& other);
		~PmergeMe(void);

		void	vec_sort(std::vector<int> &vec);
		void	deq_sort(std::deque<int> &deq);
};



#endif
