/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:13:35 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/11/17 06:07:39 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	Point	a(-2, 2);
	Point	b(-3, -2);
	Point	c(4, -1);
	Point	x(-1.21, 1.61);
	// test with : https://www.geogebra.org/
	std::cout << bsp(a, b, c, x) << std::endl;
	return (0);
}
