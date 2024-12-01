/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:02:04 by kez-zoub          #+#    #+#             */
/*   Updated: 2024/12/02 00:34:01 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	first;
	DiamondTrap	second("diamond");

	first.attack("test");
	first.takeDamage(30);

	first.whoAmI();
	second.whoAmI();
	// more tests silvopli
	
	return (0);
}
