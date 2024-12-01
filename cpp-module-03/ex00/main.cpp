/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:02:04 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/12/02 00:36:14 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	std::cout << " -> Create default claptrap\n";
	ClapTrap	dflt;
	std::cout << " -> Create named claptrap\n";
	ClapTrap	named("3ntr");

	std::cout << " -> named attacks default\n";
	named.attack("random");

	std::cout << " -> default takes damage from the attack\n";
	dflt.takeDamage(0);

	std::cout << " -> default repears itself\n";
	dflt.beRepaired(0);

	// more tests silvopli

	return (0);
}
