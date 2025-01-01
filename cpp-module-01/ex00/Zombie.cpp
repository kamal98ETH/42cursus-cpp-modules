/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kez-zoub <kez-zoub@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:01:46 by kez-zoub          #+#    #+#             */
/*   Updated: 2025/01/01 23:34:19 by kez-zoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) 
{
	name = "default";
}

Zombie::Zombie(std::string n)
{
	name = n;
};

Zombie::~Zombie(void)
{
	std::cout << Zombie::name << ": Deeeaaaaaaaaaddddddddd..." << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << Zombie::name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
