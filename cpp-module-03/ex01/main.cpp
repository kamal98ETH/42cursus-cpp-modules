/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:02:04 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/02/10 22:06:32 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	// create object with default name
	std::cout << " -> Create default ScavTrap\n";
	ScavTrap	dflt;

	// create object with given name
	std::cout << " -> Create named ScavTrap\n";
	ScavTrap	named("3ntr");

	// copy the default object using copy constructor to create a third object
	std::cout << " -> Create copy of default ScavTrap\n";
	ScavTrap	third(dflt); // or: ScavTrap	third = dflt;
	third.beRepaired(20);
	
	// copy the named object using copy assignement operator to replace the third object
	std::cout << " -> reassign the third object to named ScavTrap\n";
	third = named;
	third.beRepaired(20);

	// attack multiple times untill half energy is consumed this will kill dflt after 5 attacks the rest of attacks won't damage it anymore
	std::cout << " -> named attacks default that will take damage\n";
	for (int i = 0; i < 25; i++)
	{
		named.attack("random");
		dflt.takeDamage(20);
	}
	
	// heal multiple times untill the rest is consumed
	std::cout << " -> named repears itself\n";
	for (int i = 0; i < 25; i++)
		named.beRepaired(20);

	// try to attack and heal now when you have 0 energy
	std::cout << " -> named attacks and repears itself\n";
	named.attack("random");
	named.beRepaired(20);
		
	// check if the dead object can attack or heal
	std::cout << " -> dflt attacks and repears after death\n";
	dflt.attack("3ntr");
	dflt.beRepaired(20);
	
	// put third object in gate keeper mode
	std::cout << " -> third object in gate keeper mode\n";
	third.guardGate();
	
	return (0);
}
