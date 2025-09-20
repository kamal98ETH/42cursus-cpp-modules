/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:10:15 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/09/20 19:53:38 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <stdexcept>

template <typename T>
typename T::iterator	easyfind(T& container, int n)
{
	typename T::iterator	it = std::find(container.begin(), container.end(), n);

	if (it == container.end())
		throw std::runtime_error("Value not found");
	return (it);
};

#endif
