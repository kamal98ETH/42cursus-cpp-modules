/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:02:04 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/02/10 21:19:15 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	// create object with default name
	std::cout << " -> Create default claptrap\n";
	ClapTrap	dflt;

	// create object with given name
	std::cout << " -> Create named claptrap\n";
	ClapTrap	named("3ntr");

	// copy the default object using copy constructor to create a third object
	std::cout << " -> Create copy of default ClapTrap\n";
	ClapTrap	third(dflt); // or: ClapTrap	third = dflt;
	third.beRepaired(0);
	
	// copy the named object using copy assignement operator to replace the third object
	std::cout << " -> reassign the third object to named ClapTrap\n";
	third = named;
	third.beRepaired(0);

	// attack multiple times untill half energy is consumed
	std::cout << " -> named attacks default that will take damage\n";
	for (int i = 0; i < 5; i++)
	{
		named.attack("random");
		dflt.takeDamage(0);
	}
	
	// heal multiple times untill the rest is consumed
	std::cout << " -> named repears itself\n";
	for (int i = 0; i < 5; i++)
		named.beRepaired(0);

	// try to attack and heal now when you have 0 energy
	std::cout << " -> named attacks and repears itself\n";
	named.attack("random");
	named.beRepaired(0);
		
	// kill an object and check if it can attack or heal
	std::cout << " -> named attacks and repears after death\n";
	named.takeDamage(100);
	named.attack("random");
	named.beRepaired(0);

	// give damage to dead object
	std::cout << " -> named takes damage after death\n";
	named.takeDamage(1);
	
	return (0);
}
