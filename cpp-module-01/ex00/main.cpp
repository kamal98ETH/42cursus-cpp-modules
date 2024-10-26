/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:01:50 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/10/26 17:20:12 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::cout << "zombie in stack" << std::endl;
	randomChump("stack");
	std::cout << "zombie in heap" << std::endl;
	Zombie	*heap_zombie = newZombie("heap");
	heap_zombie->announce();
	delete heap_zombie;
	return (0);
}
