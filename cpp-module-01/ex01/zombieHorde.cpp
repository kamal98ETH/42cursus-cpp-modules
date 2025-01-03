/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:45:22 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/01/03 15:43:20 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie*	zombies = new (std::nothrow) Zombie[N];

	if (!zombies)
	{
		std::cerr << "Heap allocation failed" << std::endl;
		exit(1);
	}
	for (int i = 0; i < N; i++)
	{
		zombies[i].setName(name);
	}
	return (zombies);
}
