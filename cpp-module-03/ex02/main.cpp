/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:02:04 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/11/28 22:56:59 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	defaultt;
	FragTrap	named("frago");

	defaultt.attack("frago");
	named.takeDamage(30);
	named.beRepaired(30);

	defaultt.highFivesGuys();

	// more tests silvopli
	
	return (0);
}
