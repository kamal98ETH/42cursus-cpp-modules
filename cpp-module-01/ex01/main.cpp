/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:45:57 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/10/31 23:32:42 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int	N;

	N = 5;
	Zombie	*zombies = zombieHorde(N, "zombie");
	Zombie	*current = zombies;
	for (int i = 0; i < N; i++)
	{
		current->announce();
		current++;
	}
	delete[] zombies;
	return (0);
}
