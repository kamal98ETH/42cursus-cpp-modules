/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 23:51:19 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/06/16 23:12:45 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>

typedef struct s_pair
{
	int	a;
	int	b;
}	t_pair;

class PmergeMe
{
	private:
		/* data */
	public:
		PmergeMe(void);
		~PmergeMe(void);
};

void	vec_sort(std::vector<int> &vec);

#endif
