/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:45:22 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/10/31 23:31:55 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie*	zombies = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		zombies = new (zombies) Zombie(name);
		zombies++;
	}
	zombies -= N;
	return (zombies);
}
