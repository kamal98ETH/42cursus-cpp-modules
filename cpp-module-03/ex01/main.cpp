/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:02:04 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/12/02 00:36:22 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	scav;
	ScavTrap	secScav("named");

	scav.attack("named");
	secScav.takeDamage(10);
	secScav.beRepaired(10);

	secScav.guardGate();
	
	for (int i = 1; i <= 55; i++)
	{
		std::cout << i << " : ";
		secScav.beRepaired(10);
	}
	
	// more tests silvopli

	return (0);
}
