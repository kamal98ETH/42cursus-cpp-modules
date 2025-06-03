/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:27:22 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/05/21 03:41:23 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}
