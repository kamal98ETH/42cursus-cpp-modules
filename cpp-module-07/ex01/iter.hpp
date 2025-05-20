/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 21:02:20 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/05/19 23:09:25 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename ArrayT, typename FuncT> void	iter(ArrayT *arr, std::size_t len, void (*func)(FuncT))
{
	for (std::size_t i = 0; i < len; i++)
		func(arr[i]);
}

#endif
