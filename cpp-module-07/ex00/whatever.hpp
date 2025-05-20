/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:30:22 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/05/19 20:52:40 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T> void swap(T &x, T &y)
{
	T	tmp = x;
	
	x = y;
	y = tmp;
}

template <typename T> T min(T x, T y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

template <typename T> T max(T x, T y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

#endif
